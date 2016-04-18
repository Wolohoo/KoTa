#include "SimulationWorld.h"
#include <glm.hpp>

#ifndef PHYSICS_H
#define PHYSICS_H

//Simulated world, size 400 x 400
SimulationWorld world(400, 400);

//Gravity, x = 0 and y = -9.81 as per normal
glm::vec2 gravity(0.0f, -9.81f);

void Run()
{
    static float lastTime;
    float time = lastTime + 0.02f;

    //world.simulate(time - lastTime);
    //world.render();

    lastTime = time;
}



#endif
