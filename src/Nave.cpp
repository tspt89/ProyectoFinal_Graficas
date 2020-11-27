#include "Nave.h"

float vertexCoordsShip[18] = {
    //Ship Center
     0.0, 0.0, 0.0,    0.5, 0.0,-1.0,
     0.0, 0.0,-3.5,   -0.5, 0.0,-1.0,
     0.0, 0.5,-0.5,    0.0,-0.5,-1.0
};


float vertexColorsShip[18] = {
    //Ship Center
    1.0,0.5,0.0,   1.0,1.0,1.0,
    0.0,0.0,1.0,   1.0,1.0,1.0,
    1.0,0.5,0.0,   1.0,0.0,0.0
};

int elementArrayShip[44] = {
    //Plain 8
    0,1,    1,2,    2,3,    0,3,
    //Top
    0,1,    1,4,    4,0,
    3,0,    0,4,    4,3,
    4,1,    1,2,    2,4,
    //Bottom
    0,1,    1,5,    5,0,
    3,0,    0,5,    5,3,
    5,1,    1,2,    2,5,
};

Nave::Nave(float l) : Agente(l)
{
	//ctor
}

Nave::~Nave()
{
	//dtor
}

void Nave::update(float l){
	Agente::update(l);
}

void Nave::draw(){
	this->drawContorno();
}

void Nave::drawWing1(void){
    glPushMatrix();
    glScalef(0.3,0.0,0.5);
    glTranslatef(2.2,0.0,-1.0);
    glColor3f(0,0,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsShip);
    glDrawElements(GL_POLYGON,44,GL_UNSIGNED_INT,elementArrayShip);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void Nave::drawWing2(void){
    glPushMatrix();
    glScalef(0.3,0.0,0.5);
    glTranslatef(-2.2,0.0,-1.0);
    glColor3f(0,0,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsShip);
    glDrawElements(GL_POLYGON,44,GL_UNSIGNED_INT,elementArrayShip);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void Nave::drawContorno(void)
{
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    //glScalef(5,5,5);
	glTranslated(this->x,this->y,this->z);
    glRotatef(45,0.0f, 1.0f, 0.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsShip);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsShip);

    glDrawElements(GL_POLYGON,44,GL_UNSIGNED_INT,elementArrayShip);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    drawWing1();
    drawWing2();
    glPopMatrix();
}
