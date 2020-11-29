/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef WALLS_H
#define WALLS_H

#include <GL/glut.h>
#include "RgbImage.h"

#define NTextures 2

class Walls
{
	public:
		Walls(float);
		virtual ~Walls();

		float l = 0.0f, h = 0.0f;
		char* filename = "RedLeavesTexture.bmp";
		GLuint	texture[NTextures];

		void draw();
		void loadTextureFromFile(char *);
	protected:

	private:
};

#endif // WALLS_H
