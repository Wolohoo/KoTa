#include "SimulationWorld.h"

#define WIDTH 400
#define HEIGHT 400

float windowWidth = WIDTH;
float windowHeight = HEIGHT;

SimulationWorld World(float windowWidth, float windowHeight);


void initBody(RigidBody &body, float BodyDensity, float BodyWidth, float BodyHeigth, float BodyRestitution)
{
    body.m_mass = BodyDensity * BodyWidth * BodyHeigth;
    body.m_restitution = BodyRestitution;

    body.m_width = BodyWidth;
    body.m_height = BodyHeigth;

    body.m_inertia = 1 / (body.m_mass / 12) * (BodyWidth * BodyWidth + BodyHeigth * BodyHeigth);

    body.aConfigurations[0].m_orientation = 0;
    body.aConfigurations[0].m_angularVelocity = 0;
    body.aConfigurations[0].m_torque = 0;

}

SimulationWorld::SimulationWorld(float windowWidth, float windowHeight) :
m_windowWidth(windowWidth),
m_windowHeight(windowHeight),
m_sourceConfIndex(0),
m_targetConfIndex(1)
{
    float const density = 0.01f;

    initBody(aBodies[0], density, (10.f), (10.f), (10.f));
    initBody(aBodies[1], density, (10.f), (10.f), (10.f));

    aBodies[0].aConfigurations[0].m_velocity = glm::vec2(40.f, 10.f);
    aBodies[0].aConfigurations[0].m_angularVelocity = 3.1415f;

    calculateVertices(0);
}


void SimulationWorld::simulate(float deltaTime)
{
    float currentTime = 0;
    float targetTime = deltaTime;

    while (currentTime < deltaTime)
    {
        calculateForces(m_sourceConfIndex);
        integrate(targetTime - currentTime);
        calculateVertices(m_targetConfIndex);
        checkForCollision(m_targetConfIndex);

        if (CollisionState == penetrating)
        {
            targetTime = (currentTime + targetTime) / 2;
        }

        else
        {
            if (CollisionState = colliding)
            {
                int counter = 0;

                do 
                {
                    resolve(m_targetConfIndex);
                    counter++;
                } while ((checkForCollision(m_targetConfIndex)==colliding) && (counter < 100));
            }
            currentTime = targetTime;
            targetTime = deltaTime;

            m_sourceConfIndex = m_sourceConfIndex ? 0 : 1;
            m_targetConfIndex = m_targetConfIndex ? 0 : 1;
        }
    }
}

void SimulationWorld::calculateForces(int confIndex)
{
    int counter ;

    for (counter = 0; counter < numberOfBodies; counter++)
    {
        RigidBody body = aBodies[counter];
        RigidBody::Configuration configuration = body.aConfigurations[confIndex];


        configuration.m_torque = 0;
        configuration.m_force = glm::vec2 (0);
        

    }
}

void SimulationWorld::integrate(float deltaTime)
{
    int counter;

    for (counter = 0; counter < numberOfBodies; counter++)
    {
        RigidBody::Configuration &source = aBodies[counter].aConfigurations[m_sourceConfIndex];
        RigidBody::Configuration &target = aBodies[counter].aConfigurations[m_targetConfIndex];

        target.m_position = source.m_position + deltaTime * source.m_velocity;
        target.m_orientation = source.m_orientation + deltaTime *source.m_angularVelocity;
        target.m_velocity = source.m_velocity + (deltaTime * aBodies[counter].m_mass) * source.m_force;
        target.m_angularVelocity = source.m_angularVelocity + (deltaTime * aBodies[counter].m_inertia)* source.m_torque;

    }
}

SimulationWorld::CollisionStates SimulationWorld::checkForCollision(int confIndex)
{
    CollisionState == clear;
    float const depth = 1.0f;

    float const halfWidth = windowWidth / 2;
    float const halfHeight = windowHeight / 2;

    for (int Body = 0; (Body < numberOfBodies) && (CollisionState == penetrating); Body++)
    {
        RigidBody::Configuration &Configuration = aBodies[Body].aConfigurations[confIndex];
        RigidBody::Configuration::boundingBox &box = Configuration.boundingbox;

        for (int counter = 0; (counter < 4) && (CollisionState == penetrating); counter++)
        {
            glm::vec2 Position = box.aVertices[counter];
            glm::vec2 ToCornerPerpenticular = glm::vec2(Position - Configuration.m_position);
            glm::vec2 Velocity = Configuration.m_velocity + Configuration.m_angularVelocity * ToCornerPerpenticular;

            for (int WallIndex = 0; (WallIndex < NumberOfWalls) && (CollisionState != penetrating); WallIndex++)
            {
                wall &Wall = aWalls[WallIndex];

                float axbyc = float(Wall.Normal.x*Velocity.x + Wall.Normal.y*Velocity.y);

                if (axbyc < -depth)
                {
                    CollisionState = penetrating;
                }
                else
                    if (axbyc < depth)
                    {
                        float RelativeVelocity = float(Wall.Normal.x*Velocity.x + Wall.Normal.y*Velocity.y);
                        if (RelativeVelocity < 0)
                        {
                            CollisionState = colliding;
                            m_collisionNormal = Wall.Normal;
                            m_collidingCornerIndex = counter;
                            m_collidingBodyIndex = Body;
                        }
                    }
            }

        }
    }
    return CollisionState;
}

void SimulationWorld::resolve(int confIndex)
{
    
    RigidBody body = aBodies[m_collidingBodyIndex];
    RigidBody::Configuration &configuration = body.aConfigurations[confIndex];

    glm::vec2 position = configuration.boundingbox.aVertices[m_collidingCornerIndex];

    glm::vec2 toCornerPerpendicular = glm::vec2 (-position.y, position.x);

    glm::vec2 velocity = configuration.m_velocity + configuration.m_angularVelocity * toCornerPerpendicular;

    float impulseNumerator = -(1 + body.m_restitution) * ((velocity.x*m_collisionNormal.x) + (velocity.y*m_collisionNormal.y));

    float perpendicularDot = ((toCornerPerpendicular.x*m_collisionNormal.x) + (toCornerPerpendicular.y*m_collisionNormal.y));

    float impulseDenomirator = body.m_mass + body.m_inertia * perpendicularDot * perpendicularDot;

    float impulse = impulseNumerator / impulseDenomirator;

    configuration.m_velocity += impulse * body.m_mass * m_collisionNormal;

    configuration.m_angularVelocity += impulse * body.m_inertia * perpendicularDot;

}

void SimulationWorld::calculateVertices(int confIndex)
{
    int counter;

    for (counter = 0; counter < numberOfBodies; counter++)
    {
        glm::mat2x2 const Rotation(aBodies[counter].aConfigurations[confIndex].m_orientation);

        glm::vec2 const position = aBodies[counter].aConfigurations[confIndex].m_position;

        RigidBody::Configuration::boundingBox &box = aBodies[counter].aConfigurations[confIndex].boundingbox;

        float const Width = aBodies[counter].m_width / 2.f;
        float const Height = aBodies[counter].m_height / 2.f;

        box.aVertices[0] = position + Rotation * glm::vec2(Width, Height);
        box.aVertices[1] = position + Rotation * glm::vec2(Width, -Height);
        box.aVertices[2] = position + Rotation * glm::vec2(-Width, -Height);
        box.aVertices[3] = position + Rotation * glm::vec2(-Width, Height);
    }

}
