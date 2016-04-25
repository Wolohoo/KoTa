#ifndef SIMULATIONWORLD_H
#define SIMULATIONWORLD_H

#include "RigidBody.h"

class SimulationWorld
{
public:
	SimulationWorld(float windowWidth,float windowHeight);
    ~SimulationWorld(){};
   
    void simulate(float deltaTime);
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


    enum { NumberOfWalls = 5 };
    struct wall
    {
        // define wall by plane equation
        glm::vec2 Normal;		// inward pointing
        float c;					// ax + by + c = 0

        // points for drawing wall
        glm::vec2 StartPoint;
        glm::vec2 EndPoint;
    } aWalls[NumberOfWalls];


    enum { numberOfBodies = 2 };
    RigidBody aBodies[numberOfBodies];
    


};

#endif

