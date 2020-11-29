#include "Agente.h"

//Constructor
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

//Funcion para dibujar el objeto
void Agente::draw(){
	glPushMatrix();
	glRotatef(Theta,0,1,0);
    glTranslated(this->x,this->y,this->z);
    glColor3f(1.0,0.5,1.0);
    glutSolidCube(this->size);
    glPopMatrix();
}

//Funcion para transladar al objeto a ciertas coordenadas
void Agente::translate(float _x, float _y, float _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
}


//Obtencion del radio
float Agente::getRadius(){
	return this->radius;
}

//Actualizacion de la posicion del agente
void Agente::update(float l){
	int lastC = this->c; //Se guarda en temporal la ultima asignacion

	if(c == 0 || stepCounter == limitSteps){ //Si cambia de pasos o llega a colisionar, cambia de comportamiento
		stepCounter = 0; //Reinicio de pasos
		limitSteps = rand() % 50; //Numero random hasta 50 para definir max cant de pasos
		this->c = rand() % 5; //Asignacion random para obtener el comportamiento
		if(lastC == c) //Si el actual comportamiento es igual al anterior, se repite la asignacion
			this->c = rand() % 5;
		this->dx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 0.5f; //Random float para determinar cuanto avanzar o retroceder en X
		this->dz = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 0.5f; //Random float para determinar cuanto avanzar o retroceder en Z

	} else if(c == 1){ // Opcion 1
		this->x += this->dx;
		this->z += this->dz;
	} else if(c == 2){ // Opcion 2
		this->x -= this->dx;
		this->z -= this->dz;
	} else if(c == 3){ // Opcion 3
		this->x += this->dx;
		this->z -= this->dz;
	} else if(c == 4){ // Opcion 4
		this->x -= this->dx;
		this->z += this->dz;
	}

	stepCounter++; //Se agrega un paso
	reset(l); //Si es necesario (colision con pared), se cambia la direccion del objeto
}

//Funcion para determinar si continua o cambia de direccion al encontrarse con una pared el objeto
void Agente::reset(float l){
	if(x >= l || z >= l){
		stepCounter = 0;
		c = 2;

	} else if(x <= -l || z <= -l){
		stepCounter = 0;
		c = 1;
	}
}

void Agente::changeDirection(float l){
	int lastC = this->c; //Se guarda estado previo

	stepCounter = 0; //Se quita la cantidad de pasos
	limitSteps = rand() % (int)(l/2) + 10; //Random para determinar el limite de pasos
	this->c = rand() % 5; //Se determina el comportamiento del objeto

	if(lastC == c) //Si el anterior es igual al nuevo comportamiento, se intenta de nuevo
		this->c = rand() % 5;

	this->dx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //Random float para determinar cuanto avanzar o retroceder en X
	this->dz = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //Random float para determinar cuanto avanzar o retroceder en Z
}
