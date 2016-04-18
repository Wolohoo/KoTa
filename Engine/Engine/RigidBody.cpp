#include "RigidBody.h"


RigidBody::RigidBody(float width, float heigth, float mass, float inertia)
{
    m_width = width;
    m_height = heigth;
    m_mass = mass;
    m_inertia = inertia;
}


RigidBody::~RigidBody()
{
}

void RigidBody::setAngVel(glm::vec2 angularVelocity)
{
    m_angularVelocity;
}

glm::vec2 RigidBody::getAngVel()
{
    return m_velocity;
}

glm::vec2 RigidBody::getTorque()
{
    return m_force;
}

glm::vec2 RigidBody::getOrientation()
{
    return m_position;
}

