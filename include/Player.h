#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <GL/glut.h>
class Player
{
	public:
		Player();
		virtual ~Player();

		void up();
		void down();
		void left();
		void right();
		void lookAt();
		void updatePerspective();
	protected:

	private:
		float EYE_X, EYE_Y, EYE_Z;
		float CENTER_X, CENTER_Y, CENTER_Z;
		float UP_X, UP_Y, UP_Z;
		float RadP;
		float Direction[3] = {1.0,0.0,0.0};
		float Theta;

		float DegToRad(float);
};

#endif // PLAYER_H
