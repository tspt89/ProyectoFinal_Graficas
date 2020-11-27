#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include <GL/glut.h>
class Player
{
	public:
		Player();
		virtual ~Player();
		float EYE_X=0.0;
		float EYE_Y=1.0;
		float EYE_Z=0.0;
		float CENTER_X=1;
		float CENTER_Y=0;
		float CENTER_Z=0;

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
