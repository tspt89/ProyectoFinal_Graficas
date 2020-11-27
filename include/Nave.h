#ifndef NAVE_H
#define NAVE_H

#include "Agente.h"

class Nave: public Agente
{
	public:
		Nave(float);
		virtual ~Nave();
		void draw();
		void update(float);
		void drawWing1();
		void drawWing2();
		void drawContorno();
	protected:

	private:
};

#endif // NAVE_H
