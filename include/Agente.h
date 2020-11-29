/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

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
		//Variables de control
		float dx = 0.1f, dy = 0.1f, dz = 0.1f;
		float Theta = 0.0f;
		float x = 0.0f,y = 0.0f,z = 0.0f;
		float size = 1.0f, radius = 0.0f;
		int c = 0, stepCounter = 0, limitSteps = 0;

		void translate(float, float, float); //Funcion para traslacion
		float getRadius(); //Obtener el radio
		void changeDirection(float l); //Se cambia el comportamiento del objeto

		virtual void update(float); //Se actualiza el comportamiento del objeto
		virtual void draw(); //Se dibuja el objeto

	private:
		void reset(float); //Se cambia el comportamiento del objeto
		//en caso de una colision

};

#endif // AGENTE_H
