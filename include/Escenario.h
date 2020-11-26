#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Player.h"
#include "Collision.h"
#include "Agente.h"
#include "Cara.h"
#include "Walls.h"

class Escenario
{
	public:
		Escenario(float);
		virtual ~Escenario();

		//Escenario Funcions
		void update(float);

		//Player Functions
		void playerUp();
		void playerDown();
		void playerLeft();
		void playerRight();
		void updatePlayerPerspective();

		//Collision Functions
		bool checkCollisions();
	protected:

	private:
		Player *player;
		Collision *c;
		static const int tam = 2;
		Agente *a[tam];
		Walls *wall;
		float l = 0.0f;

};

#endif // ESCENARIO_H
