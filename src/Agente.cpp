#include "Agente.h"

Agente::Agente(float s)
{
	this->size = s;
}

Agente::~Agente()
{
	//dtor
}

void Agente::draw(){
	glPushMatrix();
    glTranslated(this->x,this->y,this->z);
    glColor3f(1.0,0.0,1.0);
    glutSolidCube(this->size);
    glPopMatrix();
}

int Agente::getDistance(float x, float y, float z){
	float radius = sqrt(pow(size,2) + pow(size/2,2));
	float distance = sqrt(pow((x-this->x),2) + pow((z-this->z),2));
	printf("RADIUS: %f\tX: %3.2f\tY: %3.2f\tZ: %3.2f\tDistance:%3.2f\n",radius,x,y,z,distance);

	return (distance <= radius) ? 0 : 1;
}

void Agente::translate(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}
