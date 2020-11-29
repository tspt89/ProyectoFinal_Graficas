/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "Cara.h"

float vertexCoordsCont[24] = {
			//Contorno plano 24
			-1.6, 4.0, 0.0,     1.6, 4.0, 0.0,
			 2.0, 3.0, 0.0,     1.5,-1.0, 0.0,
			 0.5,-2.0, 0.0,    -0.5,-2.0, 0.0,
			-1.5,-1.0, 0.0,    -2.0, 3.0, 0.0
};

float vertexCoordsBoca[15] = {
		//Boca 15
		-1.0,-0.5, 0.3,     0.0, 0.0, 0.3,  //p00, p01
		 1.0,-0.5, 0.3,     0.0,-1.5, 0.3,  //p02, p03
		 0.0,-0.2, 0.7                      //p04
};

float vertexCoordsOjoI[18] = {
	//Ojo izq 18
	-1.8, 2.5, 0.1,    -1.2, 3.0, 0.3,  //p13, p14
	-0.6, 2.5, 0.1,    -1.2, 2.0, 0.3,  //p15, p16
	-1.2, 2.8, 0.3,    -1.2, 2.4, 0.3,  //p17, p18
};

float vertexCoordsOjoD[18] = {
	//Ojo der 18
	 1.8, 2.5, 0.1,     1.2, 3.0, 0.3,
	 0.6, 2.5, 0.1,     1.2, 2.0, 0.3,
	 1.2, 2.8, 0.3,     1.2, 2.4, 0.3,
};

float vertexCoordsNarz[18] = {
	//Nariz
	-0.6, 2.5, 0.1,      0.6, 2.5, 0.1,
	-0.1, 1.5, 1.0,     -0.5, 0.8, 0.1,
	 0.1, 1.5, 1.0,      0.5, 0.8, 0.1
};

float vertexColorsCont[24] = {
	//Contorno plano 24
	1,1,1,   1,1,1,   1,1,1,   1,1,1,
	1,1,1,   1,1,1,   1,1,1,   1,1,1
};

float vertexColorsBoca[15] = {
	1,0,0.2,   1,0,0.2,   1,0,0.2,   0,0,0,
	0,0,0
};

float vertexColorsOjoI[18] = {
	0,0.2,1,  0,0.2,1,  0,0,1,
	0,0,1,  0,0,1,  0,0,1
};

float vertexColorsOjoD[18] = {
	0,0.2,1,  0,0.2,1,  0,0,1,
	0,0,1,  0,0,1,  0,0,1
};

float vertexColorsNarz[18] = {
	0.1,0.1,0.1,  1.0,1.0,1.0,  0.1,0.1,0.1,
	1.0,1.0,1.0,  0.1,0.1,0.1,  0.1,0.1,0.1,
};

int elementArrayCont[16] = {
	//Contorno plano 16
	0,1,    1,2,    2,3,    3,4,    4,5,    5,6,    6,7,    7,0
};

int elementArrayBoca[12] = {
	//Boca 12
	0,1,    1,2,    2,3,    3,0,    0,4,    4,2
};

int elementArrayOjoI[16] = {
	//Ojo izq 16
	0,1,    1,2,    2,3,    3,0,    0,4,    4,2,    2,5,    5,0
};

int elementArrayOjoD[16] = {
	//Ojo der 16
	0,1,    1,2,    2,3,    3,0,    0,4,    4,2,    2,5,    5,0
};

int elementArrayNarz[10] = {
	//Nariz 10
	0,2,    2,3,    5,3,    5,4,    4,1
};

Cara::Cara() : Agente(3.0f)
{
	//ctor
}

Cara::~Cara()
{
	//dtor
}

void Cara::drawNarz(void){
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsNarz);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsNarz);


    glDrawElements(GL_POLYGON,10,GL_UNSIGNED_INT,elementArrayNarz);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glPopMatrix();
}

void Cara::drawOjoD(void){
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsOjoD);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsOjoD);
    glDrawElements(GL_POLYGON,16,GL_UNSIGNED_INT,elementArrayOjoD);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    drawNarz();
    glPopMatrix();
}

void Cara::drawOjoI(void){
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsOjoI);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsOjoI);
    glDrawElements(GL_POLYGON,16,GL_UNSIGNED_INT,elementArrayOjoI);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    drawOjoD();
    glPopMatrix();
}

void Cara::drawBoca(void)
{
    glPushMatrix();
    glShadeModel(GL_SMOOTH);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsBoca);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsBoca);
    glDrawElements(GL_POLYGON,12,GL_UNSIGNED_INT,elementArrayBoca);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    drawOjoI();
    glPopMatrix();
}

void Cara::drawContorno(void)
{
    glPushMatrix();
    glTranslated(this->x,0,this->z);
    glRotatef(-40, 1.0f, 0.0f, 0.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoordsCont);
    glColorPointer(3, GL_FLOAT, 0, vertexColorsCont);
    glDrawElements(GL_POLYGON,16,GL_UNSIGNED_INT,elementArrayCont);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);



    drawBoca();
    glPopMatrix();
}

void Cara::update(float l){

	this->Agente::update(l);
}

void Cara::draw(){
	drawContorno();
}

