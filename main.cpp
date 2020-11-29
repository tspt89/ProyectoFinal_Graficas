/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

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
//Variables para dibujar los ejes del sistema
float X_MIN=-50;
float X_MAX=50;
float Y_MIN=-50;
float Y_MAX=50;
float Z_MIN=-50;
float Z_MAX=50;

//Se define el tamanio del ambiente
float l = 40.0f;


//Creacion de variable escenario
Escenario *escenario = new Escenario(l);



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

//Funcion para dibujar el escenario y actualizarlo
void drawScene(void)
{
	escenario->update(l);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0,0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
}


void SpecialInput(int key, int x, int y)
{

    switch(key){
				//Flecha arriba, el usuario avanza en caso de ninguna colision
                case GLUT_KEY_UP:
                     escenario->playerUp();
                     break;

				//Flecha arriba, el usuario retorcede en caso de ninguna colision
                case GLUT_KEY_DOWN:
					escenario->playerDown();
					break;

				//Flecha izquierda para girar hacia ese lado
                case GLUT_KEY_LEFT:
                     escenario->playerLeft();
                     break;

                //Flecha derecha para girar hacia ese lado
                case GLUT_KEY_RIGHT:
                     escenario->playerRight();
                     break;
    }

    escenario->updatePlayerPerspective(); //Se actualiza perspectiva del usuario
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAxis();
    drawScene();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Proyecto Final");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}

