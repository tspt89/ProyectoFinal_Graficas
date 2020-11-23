#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "Player.h"

class Escenario
{
	public:
		Escenario();
		virtual ~Escenario();
		Player *player;

		void update();

		void playerUp();
		void playerDown();
		void playerLeft();
		void playerRight();

	protected:

	private:

};

#endif // ESCENARIO_H
