#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "Agente.h"
#include <GL/glut.h>


class Mountain: public Agente
{
	public:
		Mountain(float, float);
		virtual ~Mountain();
		float base, height;

		void draw();
		void update(float);
	protected:

	private:
};

#endif // MOUNTAIN_H
