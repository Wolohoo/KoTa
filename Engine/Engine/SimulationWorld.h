#ifndef SIMULATIONWORLD_H
#define SIMULATIONWORLD_H

#include "RigidBody.h"

class SimulationWorld
{
public:
	SimulationWorld(float windowWidth,float windowHeight);
	~SimulationWorld();
   
    void simulate(float deltaTime);
    void initBody(RigidBody &body, float density, float width, float heigth, float restitution);
    float getTime(void);


protected:
    float m_windowWidth;
    float m_windowHeight;
    
    enum CollisionStates
    {
        penetrating,
        colliding,
        clear
    }CollisionState;

    glm::vec2 m_collisionNormal;
    int m_collidingBodyIndex;
    int m_collidingCornerIndex;

    int m_sourceConfIndex;
    int m_targetConfIndex;

    void calculateForces(int confIndex);
    void integrate(float deltaTime);
    CollisionStates checkForCollision(int confIndex);
    void resolve(int confIndex);
    void calculateVertices(int confIndex);

    enum { numberOfBodies = 2 };
    RigidBody aBodies[numberOfBodies];
    


};

#endif

