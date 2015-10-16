#include "funciones.hpp"
#include "matriz.hpp"
#include "ClaseTiempo.hpp"

//Aqui haremos lo de las matrices recursivas e iterativas
int main(int argc, char ** argv){

	//Comprobamos que se han introducido todos los parametros pedido
	if(argc!=5){
		cout << "Numero de parametros introducidos incorrectos" << endl;
		exit(-1);
	}

	int minNivel, maxNivel, incremento, repeticion;
	int n,a,b;
	double det;
	vector<int> vectTiempoMedRecur;
	vector<int> vectTiempoMedIterat;
	vector<int> auxV;
	vector<int> muestras;
	double tiempo=0;
	//double tiempoTotalRecur=0.0;

	Clock detIterat;
	Clock detRecur;
	
	//Pasamos los parametros de comandos a las variables
	minNivel = atoi(argv[1]);
	maxNivel = atoi(argv[2]);
	incremento = atoi(argv[3]);
	repeticion = atoi(argv[4]);

	//Declaramos la matriz
	Matriz<int> m(n,n);
	cout << "Introduce el numero minimo del aleatorio: ";
	cin >> a;
	cout << "Introduce el numero maximo del aleatorio: ";
	cin >> b;

	//Hacemos el bucle con las repeticiones
	for(int i=minNivel; i<=maxNivel; i+=incremento){
		Matriz<int> auxM(i,i);
		for(int j=0; j<repeticion; j++){
			//Comprobamos por recursivo
			rellenaMatriz(auxM,i,i,a,b);
			auxM.verMatriz();

			detRecur.start();
			determRecursivo(auxM,i);
			detRecur.stop();
			tiempo = detRecur.elapsed();
			auxV.push_back(tiempo);
			//Cogemos el tiempo del iterativo
		}
		vectTiempoMedRecur.push_back(mediaVector(auxV));
		auxV.clear();
		muestras.push_back(i);
	}
	//Calculamos el determinante recursivo
	//Mostramos el vector de tiempos, junto con el vector de muestras
	muestraVector(muestras);
	muestraVector(vectTiempoMedRecur);


return 0;
}
