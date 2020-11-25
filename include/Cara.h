#ifndef CARA_H
#define CARA_H

#include "Agente.h"
#include <GL/glut.h>

class Cara: public Agente
{
	public:
		Cara();
		virtual ~Cara();

		void update(float);
		void draw();
	protected:

	private:
		void drawContorno();
		void drawBoca();
		void drawOjoI();
		void drawOjoD();
		void drawNarz();



};

#endif // CARA_H
