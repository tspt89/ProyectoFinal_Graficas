#ifndef NAVE_H
#define NAVE_H

#include "Agente.h"

class Nave: public Agente
{
	public:
		//Constructor que recibe el tamanio para la clase agente
		Nave(float);
		virtual ~Nave();

		//Funciones para dibujar y actualizar las variables de control
		void draw();
		void update(float);
		void drawWing1();
		void drawWing2();
		void drawContorno();
	protected:

	private:
};

#endif // NAVE_H
