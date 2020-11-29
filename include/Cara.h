/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef CARA_H
#define CARA_H

#include "Agente.h"
#include <GL/glut.h>

class Cara: public Agente
{
	public:
		Cara();
		virtual ~Cara();

		void update(float);
		void draw();
	protected:

	private:
		//Funciones para el dibujo del objeto
		void drawContorno();
		void drawBoca();
		void drawOjoI();
		void drawOjoD();
		void drawNarz();



};

#endif // CARA_H
