#include "Escenario.h"

#include <stdio.h>

Escenario::Escenario(float _l)
{
	char * t1 = "SNES.bmp",* t2 = "SNESSIDES.bmp", *t3 = "textura4.bmp";
	char * tM = "mountain.bmp";
	char * tM2= "mountain2.bmp";

	this->l = _l;

	this->player = new Player();

	this->a[0] = new Cara();
		this->a[0]->translate(2.0f,0,0);

	this->a[1] = new Agente(0.5);
		this->a[1]->translate(-2.0f,0,2.0f);

	this->a[2] = new CuboTexturizado(0.5,t1,t2,t3);
		this->a[2]->translate(15.0f,0,0);

	this->a[3] = new Nave(7.0f);
		this->a[3]->translate(15.0f,0,15.0f);


	//Group 1
	this->a[4] = new Mountain(2.0f,5.0f,tM);
	this->a[4]->translate(20.0f,0.0f,0.0f);

	this->a[5] = new Mountain(2.0f,7.0f,tM);
	this->a[5]->translate(21.0f,0.0f,-4.0f);

	this->a[6] = new Mountain(2.0f,6.0f,tM);
	this->a[6]->translate(19.0f,0.0f,4.0f);

	this->a[7] = new Mountain(1.0f,5.5f,tM);
	this->a[7]->translate(18.0f,0.0f,-6.0f);

	this->a[8] = new Mountain(1.0f,3.0f,tM2);
	this->a[8]->translate(18.0f,0.0f,-2.5f);

	this->a[9] = new Mountain(2.5f,7.5f,tM2);
	this->a[9]->translate(24.0f,0.0f,7.0f);

	//Group 2
	this->a[10] = new Mountain(3.0f,10.0f,tM);
	this->a[10]->translate(34.0f,0.0f,-20.0f);

	this->a[11] = new Mountain(3.0f,11.0f,tM2);
	this->a[11]->translate(28.0f,0.0f,-21.0f);

	this->a[12] = new Mountain(3.0f,8.0f,tM);
	this->a[12]->translate(22.0f,0.0f,-20.0f);

	this->a[13] = new Mountain(3.0f,9.5f,tM2);
	this->a[13]->translate(16.0f,0.0f,-22.0f);

	this->a[14] = new Mountain(1.0f,3.0f,tM2);
	this->a[14]->translate(19.0f,0.0f,-16.0f);

	this->a[15] = new Mountain(1.5f,4.0f,tM);
	this->a[15]->translate(24.0f,0.0f,-16.0f);

	//Group 3
	this->a[16] = new Mountain(3.0f,12.0f,tM);
	this->a[16]->translate(-34.0f,0.0f,-15.0f);

	this->a[17] = new Mountain(3.0f,11.0f,tM2);
	this->a[17]->translate(-28.0f,0.0f,-16.0f);

	this->a[18] = new Mountain(3.0f,8.0f,tM);
	this->a[18]->translate(-22.0f,0.0f,-15.0f);

	this->a[19] = new Mountain(3.0f,9.5f,tM2);
	this->a[19]->translate(-16.0f,0.0f,-18.0f);

	this->a[20] = new Mountain(1.0f,3.0f,tM2);
	this->a[20]->translate(-19.0f,0.0f,-20.0f);

	this->a[21] = new Mountain(1.5f,4.0f,tM);
	this->a[21]->translate(-24.0f,0.0f,-22.0f);

	//Group 4
	this->a[22] = new Mountain(3.0f,8.0f,tM2);
	this->a[22]->translate(-34.0f,0.0f,4.0f);

	this->a[23] = new Mountain(3.0f,6.0f,tM2);
	this->a[23]->translate(-28.0f,0.0f,3.0f);

	this->a[24] = new Mountain(3.0f,5.0f,tM);
	this->a[24]->translate(-22.0f,0.0f,4.0f);

	this->a[25] = new Mountain(1.0f,3.0f,tM);
	this->a[25]->translate(-16.0f,0.0f,6.0f);

	this->a[26] = new Mountain(1.0f,3.0f,tM);
	this->a[26]->translate(-19.0f,0.0f,7.0f);

    //Group 5
    this->a[27] = new Mountain(3.0f,12.0f,tM2);
	this->a[27]->translate(15.0f,0.0f,34.0f);

	this->a[28] = new Mountain(3.0f,11.0f,tM);
	this->a[28]->translate(14.0f,0.0f,28.0f);

	this->a[29] = new Mountain(3.0f,8.0f,tM);
	this->a[29]->translate(14.0f,0.0f,22.0f);

	this->a[30] = new Mountain(3.0f,9.5f,tM);
	this->a[30]->translate(12.0f,0.0f,16.0f);

	this->a[31] = new Mountain(1.0f,3.0f,tM2);
	this->a[31]->translate(5.0f,0.0f,19.0f);

	this->a[32] = new Mountain(1.5f,4.0f,tM2);
	this->a[32]->translate(9.0f,0.0f,24.0f);

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
	bool isColliding = false;
	//Ciclo para actualizar y dibujar los agentes
	for(int i=0; i < 4; i++){
		a[i]->update(l);
		a[i]->draw();
	}

	for(int i = 0; i < tam; i++){
		for(int j=0; j < tam; j++){
			if(i != j){
				isColliding = c->isColliding(a[i]->x,a[i]->z,a[j]->x,a[j]->z,a[i]->getRadius());
				if(isColliding){
					printf("Changing direction... Collider active\n");
					a[i]->changeDirection(l);
					break;
				}
			}

		}

		if(isColliding) break;
	}

	wall->draw();

	//Dibujar agentes tipo Mountains
	for(int i=4; i < tam; i++){
		a[i]->draw();
	}

}

bool Escenario::checkCollisions(){
	//float player[3], agent[3];
	//printf("Tam: %d -PLAYER: %3.2f, %3.2f, %3.2f\t\tObject: %3.2f, %3.2f, %3.2f\n",tam,player->CENTER_X, player->CENTER_Y,player->CENTER_Z,a[0]->x,a[0]->y,a[0]->z);
	bool isColliding = false;
	for(int i=0; i < tam; i++){
		//printf("Agente %d\t\:",i);
		//----------COMENTAR / DESCOMENTAR PARA LAS COLISIONES-----//
		isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[i]->x,a[i]->z,a[i]->getRadius());
		//int rad = a[i]->getDistance(player->CENTER_X,player->CENTER_Y,player->CENTER_Z);
		if(isColliding)
			break;
	}
	//isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[2]->x,a[2]->z,a[2]->getRadius());

	//printf("EYE X: %3.2f, %3.2f, %3.2f\n",player->EYE_X,player->EYE_Y,player->EYE_Z);

	//----------COMENTAR / DESCOMENTAR PARA LAS COLISIONES-----//
	c->isCollidingWall(&player->EYE_X,&player->EYE_Y,&player->EYE_Z,this->l);
	this->updatePlayerPerspective();
	//printf("AFTER X: %3.2f, %3.2f, %3.2f\n",player->EYE_X,player->EYE_Y,player->EYE_Z);
	//usleep(750000);
	//printf("Object is colliding: %s\n",(isColliding)?"true":"false");
	return isColliding;
}
