/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#include "Collision.h"

Collision::Collision()
{
	//ctor
}

Collision::~Collision()
{
	//dtor
}

/*Funcion que recibe como parametros coordenadas en el plano XZ del jugador  del agente,
* para que se determine la distancia entre ambos, y se pueda ver si entra dentro del radio
* de colision */
bool Collision::isColliding(float pX, float pZ, float aX, float aZ, float radius){
	float distance = sqrt(pow((pX - aX),2) + pow((pZ - aZ),2)); //Se saca la distancia entre dos puntos del player y del agente

	return (distance <= radius); //Return de un bool si la distancia es menor al radio.
}

/* Funcion para determinar si el agente o jugador se encuentra dentro del escenario,
	en caso de que no, sus coordenadas se asignan unos pixeles atras para que no se salga
	y se le impida avanzar.*/
bool Collision::isCollidingWall(float *pX, float *pY, float *pZ, float l){
	bool var = ((*pX > l) || (*pZ > l) || (*pX<= -l) || (*pZ<= -l));

	*pX= (*pX > l)? l - (0.07f * l) : *pX;
	*pZ= (*pZ > l)? l - (0.07f * l) : *pZ;
	*pX= (*pX<= -l) ? -l + (0.07f * l): *pX;
	*pZ= (*pZ<= -l) ? -l + (0.07f * l): *pZ;


	return var;
}
