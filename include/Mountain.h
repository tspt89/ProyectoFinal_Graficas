#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "Agente.h"
#include "RgbImage.h"
#include <GL/glut.h>
#define NTextures 2


class Mountain: public Agente
{
	public:
		Mountain(float, float, char *);
		virtual ~Mountain();
		float base, height;

		void draw();
		void update(float);
	protected:

	private:
	    void loadTextureFromFile(char *);
		char *texture_1,*texture_2,*texture_3;
		GLUquadric *quad;
		GLuint	texture[NTextures];
};

#endif // MOUNTAIN_H
