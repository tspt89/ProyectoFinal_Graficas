#include "Collision.h"

Collision::Collision()
{
	//ctor
}

Collision::~Collision()
{
	//dtor
}

bool Collision::isColliding(float pX, float pZ, float aX, float aZ, float radius){
	//printf("Player: %3.2f\t%3.2f\t%3.2f\t\tAgent: %3.2f\t%3.2f\t%3.2f\n",player[0],player[1],player[2],agent[0],agent[1],agent[2]);
	float distance = sqrt(pow((pX - aX),2) + pow((pZ - aZ),2));
	//printf("RADIUS: %f (r = %3.2f)\tX: %3.2f\tY: %3.2f\tZ: %3.2f\tDistance:%3.2f\t-->%s\n",radius,100,pX,0.0f,pZ,distance,(distance <= radius) ? "true":"false");
	//usleep(750000);
	//printf("Player = (%3.2f, %3.2f, %3.f) Agent = (%3.2f, %3.2f, %3.2f) - rad = %3.2f - dist = %3.2f\t%s\n",pX,0.0f,pZ,aX,0.0f,aZ,radius,distance,(distance <= radius) ? "true":"false");
	//usleep(1000000);
	return (distance <= radius);
}

bool Collision::isCollidingWall(float *pX, float *pY, float *pZ, float l){
	bool var = false;
	var = ((*pX > l) || (*pZ > l) || (*pX<= -l) || (*pZ<= -l));
	*pX= (*pX > l)? l - (0.07f * l) : *pX;
	*pZ= (*pZ > l)? l - (0.07f * l) : *pZ;
	*pX= (*pX<= -l) ? -l + (0.07f * l): *pX;
	*pZ= (*pZ<= -l) ? -l + (0.07f * l): *pZ;

	//printf("---- %3.2f - %3.2f - %3.2f\t\t\tIs colliding with walls: %s\n",*pX,*pY,*pZ,(var)?"true":"false");
	//usleep(300000);
	return var;
}
