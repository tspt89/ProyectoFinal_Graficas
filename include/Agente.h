#ifndef AGENTE_H
#define AGENTE_H

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

class Agente
{
	public:
		Agente(float);
		virtual ~Agente();

		void draw();
		int getDistance(float, float, float);
		void translate(float, float, float);
	protected:

	private:
		float 	x = 0.0f,
				y = 0.0f,
				z = 0.0f;
		float size = 1.0f;
};

#endif // AGENTE_H
