#ifndef COLLISION_H
#define COLLISION_H

#include <stdio.h>
#include <math.h>
#include <unistd.h>
class Collision
{
	public:
		Collision();
		virtual ~Collision();
		bool isColliding(float,float,float,float,float);
		bool isCollidingWall(float*,float*,float*,float);
	protected:

	private:
};

#endif // COLLISION_H
