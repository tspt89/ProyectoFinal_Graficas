/*
*	Proyecto Final de Graficas Computacionales
*	Profesor: Dr. Ivan Olmos Pineda
*	Integrantes:
*		Israel Garcia Cavazos - A01329888
*		Theo Salvador Perez Tovar - A01328274
*	Periodo: Agosto-Diciembre 2020
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <GL/glut.h>
class Player
{
	public:
		Player();
		virtual ~Player();

		//Variables de control del usuario
		float EYE_X=0.0;
		float EYE_Y=1.0;
		float EYE_Z=0.0;
		float CENTER_X=1;
		float CENTER_Y=0;
		float CENTER_Z=0;

		//Funciones para moverse en el entorno grafico
		void up();
		void down();
		void left();
		void right();
		void lookAt();
		void updatePerspective();

	protected:

	private:

		float UP_X, UP_Y, UP_Z;
		float RadP;
		float Direction[3] = {1.0,0.0,0.0};
		float Theta, dTheta;

		float DegToRad(float);
};

#endif // PLAYER_H
