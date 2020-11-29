// Detector de Colisiones
// Theo Salvador Perez Tovar - A01328274

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "Agente.h"
#include "Escenario.h"

#define NTextures 2
GLuint	texture[NTextures];
char* filename = "SNES.bmp";


//Variables dimensiones de la pantalla
int WIDTH=700;
int HEIGTH=700;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
//Variables para definir la posicion del observador
//Por default se inicializa en (0,0,0) y mirando hacia x positivo
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=0.0;
float EYE_Y=1.0;
float EYE_Z=0.0;
float CENTER_X=1;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
//Variables para dibujar los ejes del sistema
float X_MIN=-50;
float X_MAX=50;
float Y_MIN=-50;
float Y_MAX=50;
float Z_MIN=-50;
float Z_MAX=50;
//Variables para matrices de rotacion y traslación
float Theta=0;
//float Radio=1.0;
float PI = 3.14159265359;
float Direction[3] = {0.2,0.0,0.0};

//Recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
//Se aplica la formula r
float l = 40.0f;

Agente c1 (1);
Agente c2 (1.3f);

Escenario *escenario = new Escenario(l);

float RadToDeg(float r)
{
      return ((180.0*r)/PI);
}

float DegToRad(float g)
{
      return ((g*PI)/180.0);
}

void drawAxis()
{
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
 }

 void loadTextureFromFile(char *filename)
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

 void drawWalls(){
    //Derecha
    filename = "SNESSIDES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    //glColor3f(0.5f,0.2f,0.5f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-l,-2,l);
    glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(l,2,l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,2,l);
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
	glVertex3f(l,2,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,2,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Frente
	filename = "SNES.bmp";
    loadTextureFromFile( filename );
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	//glColor3f(0.5f,0.2f,0.5f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(l,2,l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(l,-2,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(l,2,-l);
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
	glVertex3f(-l,2,l);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-l,-2,l);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-l,-2,-l);
	glTexCoord2f(1.0,0.0);
	glVertex3f(-l,2,-l);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawCubes(void)
{
	//printf("X:%3.2f\tY:%3.2f\tZ:%3.2f\n",EYE_X,EYE_Y,EYE_Z);

	//drawWalls();

	/*c1.translate(-10.0f,0,0);
	c1.draw();

	c2.translate(5.0f,0,-1.0f);
	c2.draw();
	*/

	escenario->update(l);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
}



/*int checkCollisions(){
	int col = 1;
	if(c1.getDistance(CENTER_X,CENTER_Y,CENTER_Z) == 0){
		printf("Chocando objeto1!!\n");

		col = 0;
	} else if(c2.getDistance(CENTER_X,CENTER_Y,CENTER_Z) == 0){
		printf("Chocando objeto2!!\n");
		col =  0;
	} else if(CENTER_X >= l || CENTER_Z >= l){
		printf("PASA1 %3.2f\n",l);

		col = 0;
	} else if(CENTER_X <= -l || CENTER_Z <= -l){
		printf("PASA2\n");

		col = 0;
	}
	EYE_X= (EYE_X > l)? l-0.2f : EYE_X;
	EYE_Z= (EYE_Z > l)? l-0.2f : EYE_Z;
	EYE_X= (EYE_X <= -l) ? -l+0.1f : EYE_X;
	EYE_Z= (EYE_Z <= -l) ? -l+0.1f : EYE_Z;
	return col;

}*/


void SpecialInput(int key, int x, int y)
{

    switch(key){
                case GLUT_KEY_UP:

                     escenario->playerUp();

                     break;
                case GLUT_KEY_DOWN:

					escenario->playerDown();
					break;
                case GLUT_KEY_LEFT:
                     escenario->playerLeft();
                     break;
                case GLUT_KEY_RIGHT:
                     escenario->playerRight();
                     break;
    }

    escenario->updatePlayerPerspective();
}

//--------------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAxis();
    drawCubes();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Triangulo a color");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}

