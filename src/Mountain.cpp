#include "Mountain.h"

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

void Mountain::draw(){

	glPushMatrix();
		glColor3f(0.5f,0.5f,0.5f);
		printf("MOUNTAIN: ( %3.2f, %3.2f, %3.2f)\n",this->x,this->y,this->z);
        glTranslated(this->x,-1.0f + this->y,this->z);
        glRotated(90, -1.0, 0.0, 0.0);
        //glutSolidCone(this->base, this->height, 50, 50);
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
