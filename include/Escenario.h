#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Player.h"
#include "Collision.h"
#include "Agente.h"
#include "Cara.h"
#include "Walls.h"
#include "CuboTexturizado.h"
#include "Nave.h"
#include "Mountain.h"

class Escenario
{
	public:
		Escenario(float);
		virtual ~Escenario();

		//Escenario Funcions
		void update(float);


		//Player Functions
		void playerUp(); //Funcion para determinar si el usuario puede avanzar

		void playerDown(); //Funcion para determinar si el usuario puede retroceder

		void playerLeft();//Funcion para girar hacia la izquierda
		void playerRight();//Funcion para girar hacia la derecha
		void updatePlayerPerspective(); //Funcion para actualizar la perspectiva del jugador

		//Collision Functions
		bool checkCollisions();
	protected:

	private:
		Player *player;
		Collision *c;
		static const int tam = 33; //Tamanio del arreglo de agentes
		Agente *a[tam]; //Arreglo de agentes
		Walls *wall; //Objeto de paredes para establecer el limite grafico del escenario
		float l = 0.0f;

};

#endif // ESCENARIO_H
