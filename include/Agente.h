#ifndef AGENTE_H
#define AGENTE_H

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

class Agente
{
	public:
		Agente(float);
		virtual ~Agente();
		float dx = 0.1f, dy = 0.1f, dz = 0.1f;
		float Ax,Ay,Az, Theta = 0.0f;
		float 	x = 0.0f,y = 0.0f,z = 0.0f;
		float size = 1.0f, radius = 0.0f;
		int c = 0;

		int getDistance(float, float, float);
		void translate(float, float, float);
		void getCoordinates(float[3]);
		float getRadius();
		virtual void update(float);
		virtual void draw();
	protected:

	private:
		void reset(float);

};

#endif // AGENTE_H
