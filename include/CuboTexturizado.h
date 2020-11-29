#ifndef CUBOTEXTURIZADO_H
#define CUBOTEXTURIZADO_H

#include "Agente.h"
#include "RgbImage.h"
#include <GL/glut.h>
#define NTextures 2



class CuboTexturizado: public Agente
{
	public:
		//Constructor que recibe como parametros el tamanio del cubo, y tres texturas para su dibujado. El tamanio del cubo
		//se manda a la clase padre Agente por medio de su constructor para su futuro uso del colisionador.
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
