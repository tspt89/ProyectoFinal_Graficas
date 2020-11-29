/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "Player.h"

Player::Player()
{
	//Asignacion inicial del usuario para iniciar la perspectiva
	EYE_X=0.0;
    EYE_Y=0.0;
    EYE_Z=0.0;
    CENTER_X=1;
    CENTER_Y=0;
    CENTER_Z=0;
    RadP = 1;
    UP_X=0;
    UP_Y=1;
    UP_Z=0;
    Theta = 0;
    dTheta = 4.0f;
}

Player::~Player()
{
	//dtor
}

//Funcion para avanzar
void Player::up(){
	EYE_X += Direction[0];
	EYE_Y += Direction[1];
	EYE_Z += Direction[2];
	CENTER_X = EYE_X + Direction[0];
	CENTER_Y = EYE_Y + Direction[1];
	CENTER_Z = EYE_Z + Direction[2];
}

//Funcion para retroceder
void Player::down(){
	EYE_X -= Direction[0];
	EYE_Y -= Direction[1];
	EYE_Z -= Direction[2];
	CENTER_X = EYE_X + Direction[0];
	CENTER_Y = EYE_Y + Direction[1];
	CENTER_Z = EYE_Z + Direction[2];
}

//Funcion para girar hacia la derecha
void Player::right(){
	Theta += dTheta;
	Theta = (Theta > 359.0) ? 0.0 : Theta;
	this->lookAt();
}

//Funcion para girar hacia la izquierda
void Player::left(){
	Theta -= dTheta;
	Theta = (Theta < 0.0) ? 359.0 : Theta;
	this->lookAt();
}

//Funcion para avanzar de acuerdo al angulo que se obtiene
void Player::lookAt(){
	Direction[0] = cos(DegToRad(Theta));
    Direction[2] = sin(DegToRad(Theta));
    CENTER_X = EYE_X + Direction[0];
    CENTER_Z = EYE_Z + Direction[2];
}

//Funcion para covertir grados a radianes
float Player::DegToRad(float g)
{
      return ((g*M_PI)/180.0);
}

//Funcion para atualizar la perspectiva del usuario
void Player::updatePerspective(){
	glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glutPostRedisplay();
}


