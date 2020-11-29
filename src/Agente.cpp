#include "Agente.h"

Agente::Agente(float s)
{
	this->size = s;
	this->radius = sqrt(pow(s,2) + pow(s,2));
	this->Theta = 0;
}

Agente::~Agente()
{
	//dtor
}

void Agente::draw(){
	glPushMatrix();
	glRotatef(Theta,0,1,0);
    glTranslated(this->x,this->y,this->z);
    glColor3f(1.0,0.5,1.0);
    glutSolidCube(this->size);
    glPopMatrix();
}

int Agente::getDistance(float x, float y, float z){
	float distance = sqrt(pow((x-this->x),2) + pow((z-this->z),2));
	printf("RADIUS AGENTE: %f (r = %f)\tX: %3.2f\tY: %3.2f\tZ: %3.2f\tDistance:%3.2f\n",this->radius,size,x,y,z,distance);
	printf("AGENTE: %3.2f, %3.2f, %3.2f - Theta: %3.2f\n",this->x,this->y,this->z,this->Theta);
	return (distance <= this->radius) ? 0 : 1;
}

void Agente::translate(float _x, float _y, float _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
}



float Agente::getRadius(){
	return this->radius;
}

void Agente::update(float l){
	int lastC = this->c;
	if(c == 0 || stepCounter == limitSteps){
		//if(stepCounter == limitSteps)
		//	printf("STEP COUNTER LIMIT IS REACHED\n");
		stepCounter = 0;
		limitSteps = rand() % (int)(l/2) + 10;
		//printf("LIMIT STEPS: %d\t\t",limitSteps);
		this->c = rand() % 5;
		if(lastC == c)
			this->c = rand() % 5;
		this->dx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		this->dy = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		//printf("dX:%3.2f\tdy: %3.2f\tC = %d\n",this->dx,this->dy,this->c);

		//sleep(2);
	} else if(c == 1){
		this->x += this->dx;
		this->z += this->dz;
	} else if(c == 2){
		this->x -= this->dx;
		this->z -= this->dz;
	}  else if(c == 3){
		this->x += this->dx;
		this->z -= this->dz;
	} else if(c == 4){
		this->x -= this->dx;
		this->z += this->dz;
	}

	stepCounter++;
	reset(l);
}

void Agente::reset(float l){
	if(x >= l || z >= l){
		/*printf("Before %3.2f %3.2f\t\t",this->x,this->z);
		float sign1 = pow(-1,rand()%10) * (rand() % (int)(l - 0.1*l));
		float sign2 = pow(-1,rand()%10) * (rand() % (int)(l - 0.1*l));
		this->translate(sign1,0,sign2);
		printf("Update %3.2f %3.2f\n",this->x,this->z);*/
		//printf("Enter if 1: + \tx= %3.2f z=%3.2f\n",x,z);
		stepCounter = 0;
		c = 2;

	} else if(x <= -l || z <= -l){
		//printf("Enter if 2: - \tx= %3.2f z=%3.2f\n",x,z);
		stepCounter = 0;
		c = 1;
	}
}

void Agente::changeDirection(float l){
	//printf("-->-->-->\tChanging direction!!\n");
	int lastC = this->c;
	if(stepCounter == limitSteps)
		//printf("STEP COUNTER LIMIT IS REACHED\n");
	stepCounter = 0;
	limitSteps = rand() % (int)(l/2) + 10;
	//printf("LIMIT STEPS: %d\t\t",limitSteps);
	this->c = rand() % 5;
	if(lastC == c)
		this->c = rand() % 5;

	this->dx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	this->dy = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
