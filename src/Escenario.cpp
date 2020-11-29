#include "Escenario.h"

#include <stdio.h>

Escenario::Escenario(float _l)
{
	char * t1 = "SNES.bmp",* t2 = "SNESSIDES.bmp", *t3 = "textura4.bmp";
	char * tM = "mountain.bmp";
	char * tM2= "mountain2.bmp";

	//Se define el tamanio del escenario
	this->l = _l;

	//Declaracion del observador/usuario
	this->player = new Player();

	//Declaracion de Agentes en movimiento
	this->a[0] = new Cara();
		this->a[0]->translate(2.0f,0,0);

	this->a[1] = new Agente(0.5);
		this->a[1]->translate(-2.0f,0,2.0f);

	this->a[2] = new CuboTexturizado(0.5,t1,t2,t3);
		this->a[2]->translate(15.0f,0,0);

	this->a[3] = new Nave(7.0f);
		this->a[3]->translate(15.0f,0,15.0f);

	//Declaracion de Agentes estaticos dentro del escenario
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

	//Declaracion de las paredes con el largo que se puede obtener.
	this->wall = new Walls(_l);
}

Escenario::~Escenario()
{
	//dtor
}

//Funcion para determinar si el usuario puede avanzar
void Escenario::playerUp(){
	if(!checkCollisions()){ //En caso de que el usuario no este chocando, puede avanzar
		this->player->up();
	}
}

//Funcion para determinar si el usuario puede retroceder
void Escenario::playerDown(){
	if(!checkCollisions()){ //En caso de que el usuario no este chocando, puede retroceder
		this->player->down();
	}
}

void Escenario::playerLeft(){ //Funcion para girar hacia la izquierda
	this->player->left();
}

void Escenario::playerRight(){ //Funcion para girar hacia la derecha
	this->player->right();
}

void Escenario::updatePlayerPerspective(){ //Funcion para actualizar la perspectiva del jugador
	this->player->updatePerspective();
}

//Funcion para actualizar el escenario y los agentes
void Escenario::update(float l){
	bool isColliding = false;
	//Ciclo para actualizar y dibujar los agentes
	for(int i=0; i < 4; i++){
		a[i]->update(l);
		a[i]->draw();
	}


	//Ciclo para los agentes en movimiento, si colisionan con cualquier otro agente, puedan cambiar de direccion.
	//Para que no se queden colisionando por siempre.
	for(int i = 0; i < 4; i++){
		for(int j=0; j < tam; j++){
			if(i != j){ //Siempre y cuando no sean los mismos agentes
				isColliding = c->isColliding(a[i]->x,a[i]->z,a[j]->x,a[j]->z,a[i]->getRadius());

				if(isColliding){ //Si se encuentran en colision, cambian de direccion
					printf("Changing direction... Collider active\n");
					a[i]->changeDirection(l);
					break; //se rompe ciclo
				}
			}

		}

		if(isColliding) break; //Se rompe ciclo
	}

	wall->draw(); //Se dibujan las paredes

	//Dibujar agentes tipo Mountains
	for(int i=4; i < tam; i++){
		a[i]->draw();
	}

}

//Funcion para checar si el agente se encuentra chocando con algun agente, retorna true en ser asi.
//Y en caso de false, el usuario pueda moverse en el escenario
bool Escenario::checkCollisions(){
	bool isColliding = false;

	//Ciclo para recorrer todos los agentes declarados y checar si se encuentra en colision con alguno.
	for(int i=0; i < tam; i++){
		isColliding = c->isColliding(player->CENTER_X,player->CENTER_Z,a[i]->x,a[i]->z,a[i]->getRadius());
		//Si se encuentra en colision, inmediatamente se rompe el ciclo para indicar que si hay una colision
		if(isColliding)
			break;
	}

	//En caso de que el usuario no pueda salir del escenario.
	c->isCollidingWall(&player->EYE_X,&player->EYE_Y,&player->EYE_Z,this->l);

	//Se devuelve el ultimo valor que se le asigno al booleano, para determinar si el usuario puede avanzar
	return isColliding;
}
