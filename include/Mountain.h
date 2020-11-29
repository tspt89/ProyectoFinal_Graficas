#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "Agente.h"
#include "RgbImage.h"
#include <GL/glut.h>
#define NTextures 2


class Mountain: public Agente
{
	public:
		//Constructor que recibe la base, la altura, y el archivo de la textura
		Mountain(float, float, char *);
		virtual ~Mountain();
		float base, height;

		//Funciones para graficarlo y actualizar las variables de control en caso de ser necesario
		void draw();
		void update(float);
	protected:

	private:
		//Funcion para cargar la textura desde un archivo
	    void loadTextureFromFile(char *);
		//Nombre del archivo de la textura
		char *texture_1;
		GLUquadric *quad;
		GLuint	texture[NTextures];
};

#endif // MOUNTAIN_H
