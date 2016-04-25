
#include "SimulationWorld.h"
#include "Renderer.h"
#include "Physics.h"

int main()
{
    //RigidBody body1(5.0f,4.f,2.f,1.0f);
    //RigidBody body2(5.0f, 4.f, 2.f, 1.0f);
    SimulationWorld world1(400.f, 400.f);
    world1.simulate(1.f);

}