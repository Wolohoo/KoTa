#include "CollisionCalc.h"
#include "SimulationWorld.h"


bool CollisionCalc::checkForCollision()
{
    collisionState = false;
    penetrating = false;

    const float depthEps = 1.0f;
    const float halfWidth = windowWidth / 2.0f;
    const float halfHeight = windowHeight / 2.0f;

    do
    {

    } while (collisionState != penetrating);
}
