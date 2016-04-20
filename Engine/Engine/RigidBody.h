#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <math.h>
#include <iostream>
#include <vector>
#include "glm/glm.hpp"

class RigidBody
{
public:
    RigidBody(float width, float heigth, float mass, float inertia);
    RigidBody(){};
    ~RigidBody( void );

    //methods
    void setAngVel(glm::vec2 angularVelocity);
    glm::vec2 getAngVel();
    void setTorque(glm::vec2 torque);
    glm::vec2 getTorque();
    void setOrientation(glm::vec2 orientation);
    glm::vec2 getOrientation(glm::vec2 position);
    

    //numerals
    float m_width, m_height;
    float m_mass;
    float m_inertia;
    float m_restitution;

    enum{numberOfConfigurations = 2};

    //config
    struct Configuration
    {
        glm::vec2 m_position;
        float m_orientation;
        glm::vec2 m_velocity;
        float m_angularVelocity;
        glm::vec2 m_force;
        float m_torque;

        struct boundingBox
        {
            glm::vec2 aVertices[4];

        }boundingbox;

    }aConfigurations[numberOfConfigurations];
};

#endif // !RIGIDBODY_H
