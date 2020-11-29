#ifndef COLLISION_H
#define COLLISION_H

#include <stdio.h>
#include <math.h>
#include <unistd.h>
class Collision
{
	public:
		Collision();
		virtual ~Collision();
		/*Funcion que recibe como parametros coordenadas en el plano XZ del jugador  del agente,
		* para que se determine la distancia entre ambos, y se pueda ver si entra dentro del radio
		* de colision */
		bool isColliding(float,float,float,float,float);
		/* Funcion para determinar si el agente o jugador se encuentra dentro del escenario,
		en caso de que no, sus coordenadas se asignan unos pixeles atras para que no se salga
		y se le impida avanzar.*/
		bool isCollidingWall(float*,float*,float*,float);
	protected:

	private:
};

#endif // COLLISION_H
