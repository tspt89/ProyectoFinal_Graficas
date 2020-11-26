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

		float l = 0.0f;
		char* filename = "RedLeavesTexture.bmp";
		GLuint	texture[NTextures];

		void draw();
		void loadTextureFromFile(char *);
	protected:

	private:
};

#endif // WALLS_H
