#ifndef COLLISIONCALC_H
#define COLLISIONCALC_H

class CollisionCalc
{
public:
    bool checkForCollision();

protected:
    bool collisionState;
    bool penetrating;
};

#endif
