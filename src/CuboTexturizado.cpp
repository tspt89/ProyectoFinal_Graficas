/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "CuboTexturizado.h"

//Constructor que recibe como parametros el tamanio del cubo, y tres texturas para su dibujado. El tamanio del cubo
//se manda a la clase padre Agente por medio de su constructor para su futuro uso del colisionador.
CuboTexturizado::CuboTexturizado(float _l, char * text1, char * text2, char * text3) : Agente(_l)
{
	this->texture_1 = text1;
	this->texture_2 = text2;
	this->texture_3 = text3;
}

CuboTexturizado::~CuboTexturizado()
{
	//dtor
}

//Funcion para cargar la textura del archivo
void CuboTexturizado::loadTextureFromFile(char *filename)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( filename );

    //generate an OpenGL texture ID for this texture
    glGenTextures(2, &texture[0]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[0]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

//Funcion para cargar el cubo junto con sus texturas
void CuboTexturizado::draw(){

    loadTextureFromFile( this->texture_1 );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);  //cara frontal
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-size + x, -size + y,  size + z);
    glTexCoord2f(0.0, 5);
    glVertex3f( size + x, -size + y,  size + z);
    glTexCoord2f(5, 5);
    glVertex3f( size + x,  size + y,  size + z);
    glTexCoord2f(5, 0.0);
    glVertex3f(-size + x,  size + y,  size + z);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    loadTextureFromFile( this->texture_2 );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);  //cara trasera
    glTexCoord2f(0.0, 0.0);
    glVertex3f( size + x, -size + y, -size + z);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-size + x, -size + y, -size + z);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-size + x,  size + y, -size + z);
    glTexCoord2f(1.0, 0.0);
    glVertex3f( size + x,  size + y, -size + z);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);  //cara lateral izq
    glVertex3f(-size + x, -size + y, -size + z);
    glVertex3f(-size + x, -size + y,  size + z);
    glVertex3f(-size + x,  size + y,  size + z);
    glVertex3f(-size + x,  size + y, -size + z);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);  //cara lateral dcha
    glVertex3f( size + x, -size + y,  size + z);
    glVertex3f( size + x, -size + y, -size + z);
    glVertex3f( size + x,  size + y, -size + z);
    glVertex3f( size + x,  size + y,  size + z);
    glEnd();


    loadTextureFromFile( this->texture_3 );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);  //cara arriba
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-size + x,  size + y,  size + z);
    glTexCoord2f(0.0, 1.0);
    glVertex3f( size + x,  size + y,  size + z);
    glTexCoord2f(1.0, 1.0);
    glVertex3f( size + x,  size + y, -size + z);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-size + x,  size + y, -size + z);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);  //cara abajo
    glVertex3f( size + x, -size + y, -size + z);
    glVertex3f( size + x, -size + y,  size + z);
    glVertex3f(-size + x, -size + y,  size + z);
    glVertex3f(-size + x, -size + y, -size + z);
    glEnd();
}

//Funcion para actualizar variables de control
void CuboTexturizado::update(float l){
	//Dichas variables se actualizan en la clase padre.
	this->Agente::update(l);
}
