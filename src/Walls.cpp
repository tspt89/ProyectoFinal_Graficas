#include "Walls.h"

Walls::Walls(float _l)
{
	this->l = _l;
	this->h = _l * 0.4;
}

Walls::~Walls()
{
	//dtor
}

void Walls::loadTextureFromFile(char *filename)
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

void Walls::draw(){
	//Derecha
    filename = "SNESSIDES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(0.5f,0.2f,0.5f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-l,-2,l);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(l,h,l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,h,l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Izquierda
    filename = "SNESSIDES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
	glColor3f(0.5f,0.2f,0.5f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-l,-2,-l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-2,-l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(l,h,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,h,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Frente
	filename = "SNES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.2f,0.5f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(l,h,l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(l,-2,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(l,h,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Atras
	filename = "SNES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.2f,0.5f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-l,h,l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-l,-2,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,h,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Piso
	filename = "textura4.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	//glColor3f(0.65f,0.34f,0.34f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(l,-1,-l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-1,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-l,-1,l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,-1,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
