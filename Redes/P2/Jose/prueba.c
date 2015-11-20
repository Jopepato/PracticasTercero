#include "funciones.h"

int main(){
	int ** carton;
	int ** carton2;
	char buffer[500];
	carton = generaCarton();
	muestraCarton(carton);

	cartonABuffer(buffer, carton);

	printf("%s", buffer);

	bufferACarton(carton2, buffer);

	muestraCarton(carton2);
}