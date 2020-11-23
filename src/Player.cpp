#include "Player.h"

Player::Player()
{
	this->EYE_X=0.0;
	this->EYE_Y=1.0;
	this->EYE_Z=0.0;
	this->CENTER_X=1;
	this->CENTER_Y=0;
	this->CENTER_Z=0;
	this->UP_X=0;
	this->UP_Y=1;
	this->UP_Z=0;
}

Player::~Player()
{
	//dtor
}

void Player::up(){
	EYE_X += Direction[0];
	EYE_Y += Direction[1];
	EYE_Z += Direction[2];
	CENTER_X = EYE_X + Direction[0];
	CENTER_Y = EYE_Y + Direction[1];
	CENTER_Z = EYE_Z + Direction[2];
}

void Player::down(){
	EYE_X -= Direction[0];
	EYE_Y -= Direction[1];
	EYE_Z -= Direction[2];
	CENTER_X = EYE_X + Direction[0];
	CENTER_Y = EYE_Y + Direction[1];
	CENTER_Z = EYE_Z + Direction[2];
}

void Player::right(){
	Theta += 1.0f;
	Theta = (Theta > 359.0) ? 0.0 : Theta;
	this->lookAt();
}

void Player::left(){
	Theta -= 1.0f;
	Theta = (Theta < 0.0) ? 359.0 : Theta;
	this->lookAt();
}

void Player::lookAt(){
	Direction[0] = cos(DegToRad(Theta));
    Direction[2] = sin(DegToRad(Theta));
    CENTER_X = EYE_X + Direction[0];
    CENTER_Z = EYE_Z + Direction[2];
}

float Player::DegToRad(float g)
{
      return ((g*M_PI)/180.0);
}

void Player::updatePerspective(){
	glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glutPostRedisplay();
}
