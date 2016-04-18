#include "SimulationWorld.h"


SimulationWorld::SimulationWorld(float windowWidth, float windowHeight)
{
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}


SimulationWorld::~SimulationWorld()
{
}

SimulationWorld WORLD(400, 400);

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
    int counter;

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
        RigidBody::Configuration source;
        RigidBody::Configuration target;

        target.m_position = source.m_position + deltaTime * source.m_velocity;
        target.m_orientation = source.m_orientation + deltaTime *source.m_angularVelocity;
        target.m_velocity = source.m_velocity + (deltaTime * aBodies[counter].m_mass) * source.m_force;
        target.m_angularVelocity = source.m_angularVelocity + (deltaTime * aBodies[counter].m_inertia)* source.m_torque;

    }
}

SimulationWorld::CollisionStates SimulationWorld::checkForCollision(int confIndex)
{
    CollisionState = clear;
}

void SimulationWorld::resolve(int confIndex)
{
    RigidBody body = aBodies[m_collidingBodyIndex];
    RigidBody::Configuration &configuration = body.aConfigurations[confIndex];

    glm::vec2 position = configuration.boundingbox.aVertices[m_collidingCornerIndex];

    glm::vec2 toCornerPerpendicular = glm::vec2 (-position.y, position.x);

    glm::vec2 velocity = configuration.m_velocity + configuration.m_angularVelocity * toCornerPerpendicular;

    float impulseNumerator = -(1 + body.restitution) * ((velocity.x*m_collisionNormal.x) + (velocity.y*m_collisionNormal.y));

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
