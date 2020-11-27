#ifndef CUBOTEXTURIZADO_H
#define CUBOTEXTURIZADO_H

#include "Agente.h"
#include "RgbImage.h"
#include <GL/glut.h>
#define NTextures 2



class CuboTexturizado: public Agente
{
	public:
		CuboTexturizado(float, char *, char *, char *);
		virtual ~CuboTexturizado();

		void update(float);
		void draw();
	protected:

	private:
		void loadTextureFromFile(char *);
		char *texture_1,*texture_2,*texture_3;
		GLuint	texture[NTextures];

};

#endif // CUBOTEXTURIZADO_H
