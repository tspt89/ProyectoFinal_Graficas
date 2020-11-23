#include "Escenario.h"

Escenario::Escenario()
{
	this->player = new Player();
}

Escenario::~Escenario()
{
	//dtor
}

void Escenario::update(){
}

void Escenario::playerUp(){
	this->player->up();
}

void Escenario::playerDown(){
	this->player->down();
}

void Escenario::playerLeft(){
	this->player->left();
}

void Escenario::playerRight(){
	this->player->right();
}
