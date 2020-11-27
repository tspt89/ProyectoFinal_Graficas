#include "Mountain.h"

Mountain::Mountain(float base, float height) : Agente(base)
{
	this->base = base;
	this->height = height;
}

Mountain::~Mountain()
{
	//dtor
}

void Mountain::draw(){
	glPushMatrix();
		glColor3f(0.5f,0.5f,0.5f);
		printf("MOUNTAIN: ( %3.2f, %3.2f, %3.2f)\n",this->x,this->y,this->z);
        glTranslated(this->x,-1.0f + this->y,this->z);
        glRotated(90, -1.0, 0.0, 0.0);
        glutSolidCone(this->base, this->height, 50, 50);
    glPopMatrix();
}

void Mountain::update(float l){

	this->Agente::update(l);
}
