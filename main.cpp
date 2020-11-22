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

#include "Cube.h"

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
float l = 20.0f;

Cube c1 (1);
Cube c2 (1.3f);

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

 void drawWalls(){

	glBegin(GL_QUADS);
	glColor3f(1.0f,0.0f,0.0f);
	//Derecha
	glVertex3f(-l,-2,l);
	glVertex3f(l,-2,l);
	glVertex3f(l,2,l);
	glVertex3f(-l,2,l);

	glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(-l,-2,-l);
	glVertex3f(l,-2,-l);
	glVertex3f(l,2,-l);
	glVertex3f(-l,2,-l);

	glColor3f(0.5f,0.0f,0.5f);
	glVertex3f(l,2,l);
	glVertex3f(l,-2,l);
	glVertex3f(l,-2,-l);
	glVertex3f(l,2,-l);

	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-l,2,l) ;
	glVertex3f(-l,-2,l);
	glVertex3f(-l,-2,-l);
	glVertex3f(-l,2,-l);

	glEnd();
}

void drawCubes(void)
{
	printf("X:%3.2f\tY:%3.2f\tZ:%3.2f\n",EYE_X,EYE_Y,EYE_Z);

	drawWalls();

	c1.translate(-10.0f,0,0);
	c1.draw();

	c2.translate(5.0f,0,-1.0f);
	c2.draw();

}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
}

void LookAt()
{
    Direction[0] = cos(DegToRad(Theta));
    Direction[2] = sin(DegToRad(Theta));
    CENTER_X = EYE_X + Direction[0];
    CENTER_Z = EYE_Z + Direction[2];
}

int checkCollisions(){
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

}


void SpecialInput(int key, int x, int y)
{

    switch(key){
                case GLUT_KEY_UP:
					if(checkCollisions() == 0){
						printf("Chocando objeto!!\n");
						return;
					}
                     EYE_X += Direction[0];
                     EYE_Y += Direction[1];
                     EYE_Z += Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];

                     break;
                case GLUT_KEY_DOWN:
                	if(checkCollisions() == 0){
						printf("Chocando objeto!!\n");
						return;
					}
                     EYE_X -= Direction[0];
                     EYE_Y -= Direction[1];
                     EYE_Z -= Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];
                     break;
                case GLUT_KEY_LEFT:
                     Theta -= 1.0f;
                     Theta = (Theta < 0.0) ? 359.0 : Theta;
                     LookAt();
                      break;
                case GLUT_KEY_RIGHT:
                     Theta += 1.0f;
                     Theta = (Theta > 359.0) ? 0.0 : Theta;
                     LookAt();
                     break;
    }

    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glutPostRedisplay();
}

//--------------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
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

