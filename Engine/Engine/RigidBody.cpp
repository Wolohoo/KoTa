#include "RigidBody.h"


RigidBody::RigidBody(float width = 0, float heigth = 0, float mass = 0, float inertia = 0)
{
    m_width = width;
    m_height = heigth;
    m_mass = mass;
    m_inertia = inertia;
}


RigidBody::~RigidBody()
{
}


//
//void RigidBody::setAngVel(glm::vec2 angularVelocity)
//{
//    m_angularVelocity;
//}
//
//glm::vec2 RigidBody::getAngVel()
//{
//    return m_velocity;
//}
//
//glm::vec2 RigidBody::getTorque()
//{
//    return m_force;
//}
//
//glm::vec2 RigidBody::getOrientation()
//{
//    return m_position;
//}

