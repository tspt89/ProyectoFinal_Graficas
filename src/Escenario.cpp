#include "Escenario.h"

#include <stdio.h>

Escenario::Escenario()
{
	this->player = new Player();

	//this->a[0] = new Cara();
	this->a[1] = new Agente(0.5);
	this->a[1]->translate(10.0f,0,0);


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
	printf("Player - %3.2f, %3.2f, %3.2f\n",this->player->CENTER_X,this->player->CENTER_Y,this->player->CENTER_Z);
	/*for(int i=0; i < tam-1; i++){
		a[i]->update(l);
		a[i]->draw();
	}*/

	a[1]->draw();

	usleep(100000);

}

bool Escenario::checkCollisions(){
	//float player[3], agent[3];
	//printf("Tam: %d -PLAYER: %3.2f, %3.2f, %3.2f\t\tObject: %3.2f, %3.2f, %3.2f\n",tam,player->CENTER_X, player->CENTER_Y,player->CENTER_Z,a[0]->x,a[0]->y,a[0]->z);
	bool isColliding = false;
	for(int i=1; i < tam; i++){
		printf("Agente %d\t:",i);
		isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[i]->x,a[i]->z,a[i]->getRadius());
		int rad = a[i]->getDistance(player->CENTER_X,player->CENTER_Y,player->CENTER_Z);
		if(isColliding)
			break;
	}
	//usleep(750000);
	printf("Object is colliding: %s\n",(isColliding)?"true":"false");
	return isColliding;
}
