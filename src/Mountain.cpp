#include "Mountain.h"

//Constructor que recibe la base, la altura, y el archivo de la textura
Mountain::Mountain(float base, float height,  char * text) : Agente(base)
{
	this->base = base;
	this->height = height;
	this->texture_1 = text;
}

Mountain::~Mountain()
{
	//dtor
}

//Funcion para cargar la textura desde un archivo
void Mountain::loadTextureFromFile(char *filename)
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


//Funciones para graficarlo y actualizar las variables de control en caso de ser necesario
void Mountain::draw(){

	glPushMatrix();
		glColor3f(0.5f,0.5f,0.5f);
        glTranslated(this->x,-1.0f + this->y,this->z);
        glRotated(90, -1.0, 0.0, 0.0);
        quad = gluNewQuadric();
        glEnable(GL_TEXTURE_2D);
        loadTextureFromFile( this->texture_1 );
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        gluQuadricTexture(quad,1);
        gluCylinder(quad,this->base, 0.0, this->height, 50, 50);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Mountain::update(float l){

	this->Agente::update(l);
}
