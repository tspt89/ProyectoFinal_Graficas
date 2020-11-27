#include "Escenario.h"

#include <stdio.h>

Escenario::Escenario(float _l)
{
	this->l = _l;
	this->player = new Player();

	this->a[0] = new Cara();
	this->a[1] = new Agente(0.5);
	//this->a[1]->translate(10.0f,0,0);
	char * t1 = "SNES.bmp",* t2 = "SNESSIDES.bmp", *t3 = "textura4.bmp";
	this->a[2] = new CuboTexturizado(0.5,t1,t2,t3);
	this->a[2]->translate(10.0f,0,0);

	//this->a[3] = new Nave(10.0f);
	this->a[3] = new Mountain(2.0f,5.0f);
	this->a[3]->translate(10.0f,0.0f,3.0f);
	this->wall = new Walls(_l);
}

Escenario::~Escenario()
{
	//dtor
}

void Escenario::playerUp(){
	if(!checkCollisions()){
		this->player->up();
	}
}

void Escenario::playerDown(){
	if(!checkCollisions()){
		this->player->down();
	}
}

void Escenario::playerLeft(){
	this->player->left();
}

void Escenario::playerRight(){
	this->player->right();
}

void Escenario::updatePlayerPerspective(){
	this->player->updatePerspective();
}

void Escenario::update(float l){
	//printf("Player - %3.2f, %3.2f, %3.2f\n",this->player->CENTER_X,this->player->CENTER_Y,this->player->CENTER_Z);
	bool isColliding = false;
	for(int i=0; i < tam-1; i++){
		for(int j = 0; j < tam; j++){
			if(i != j){
				isColliding = c->isColliding(a[i]->x,a[i]->z,a[j]->x,a[j]->z,a[i]->getRadius());
				printf("Agente %d:%d\t -> %s\n",i,j,(isColliding)?"true":"false");
				if(isColliding){
					a[i]->changeDirection(l);
				}
			}
		}
		a[i]->update(l);
		a[i]->draw();
	}
	wall->draw();
	a[3]->draw();
	//usleep(100000);

}

bool Escenario::checkCollisions(){
	//float player[3], agent[3];
	//printf("Tam: %d -PLAYER: %3.2f, %3.2f, %3.2f\t\tObject: %3.2f, %3.2f, %3.2f\n",tam,player->CENTER_X, player->CENTER_Y,player->CENTER_Z,a[0]->x,a[0]->y,a[0]->z);
	bool isColliding = false;
	for(int i=0; i < tam; i++){
		//printf("Agente %d\t\:",i);
		//----------COMENTAR / DESCOMENTAR PARA LAS COLISIONES-----//
		//isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[i]->x,a[i]->z,a[i]->getRadius());
		//int rad = a[i]->getDistance(player->CENTER_X,player->CENTER_Y,player->CENTER_Z);
		if(isColliding)
			break;
	}
	//isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[2]->x,a[2]->z,a[2]->getRadius());

	//printf("EYE X: %3.2f, %3.2f, %3.2f\n",player->EYE_X,player->EYE_Y,player->EYE_Z);

	//----------COMENTAR / DESCOMENTAR PARA LAS COLISIONES-----//
	//c->isCollidingWall(&player->EYE_X,&player->EYE_Y,&player->EYE_Z,this->l);
	this->updatePlayerPerspective();
	//printf("AFTER X: %3.2f, %3.2f, %3.2f\n",player->EYE_X,player->EYE_Y,player->EYE_Z);
	//usleep(750000);
	//printf("Object is colliding: %s\n",(isColliding)?"true":"false");
	return isColliding;
}
