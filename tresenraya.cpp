#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define RESTORE "\033[1;0m"
#define DEBUG "\033[1;31m"
#define USER "\033[1;34m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
using namespace std;
const int  DIM_FIL = 10, DIM_COL = 10;


void imprimirTablero(char matriz[][DIM_COL], int util_fil, int util_col){
	
	cout << YELLOW << "\t-------Impresion del tablero------" << RESTORE << endl;
	for (int i = 0; i < util_fil; i++){
		cout << endl;
		for (int j = 0; j < util_col; j++){
			cout << "\t | ";
			cout << matriz[i][j];
			cout << "\t | ";
		}
	}
	cout << endl;
}

void imprimirResultado(int tipoganador){

	if (tipoganador == 1){
		cout << GREEN << "El ganador es el jugador 1" << RESTORE << endl;
	}else if (tipoganador == 2){
		cout << GREEN << "El ganador es el jugador 2" << RESTORE << endl;
	}else if (tipoganador == 0){
		cout << YELLOW << "Hay empate" << RESTORE << endl;
	}
}

void comprobarTableroCompletado(char matriz[][DIM_COL], int util_fil, int util_col, bool &tresenraya, int &tipoganador){
		
	int cuentacompletadas = 0;

	for (int i = 0; i < util_fil; i++){
		for (int j = 0; j < util_col; j++){
			if (matriz[i][j] == 'X' || matriz[i][j] == 'O'){
				cuentacompletadas++;
			}
		}
	}
	
	if (cuentacompletadas == 9){
		tipoganador = 0;
		tresenraya = true;
	}
}

bool comprobarPosicion(char matriz[][DIM_COL], int util_fil, int util_col, int &tipoganador){
	 
	int cuentaX = 0; 
	int cuentaO = 0;
	bool tresenraya = false;

	//Condiciones para 3 casos de 1 fila en horizontal
	for (int i = 0; i < util_fil; i++){
		if (matriz[0][i] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[0][i] == 'O'){
			cuentaO++;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para 3 casos de 2 fila horizontal
	for (int i = 0; i < util_fil; i++){
		if (matriz[1][i] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[1][i] == 'O'){
			cuentaO++;;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para 3 casos casos de 3 fila horizontal
	for (int i = 0; i < util_fil; i++){
		if (matriz[2][i] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[2][i] == 'O'){
			cuentaO++;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para 3 casos de 1 fila vertical
	for (int i = 0; i < util_fil; i++){
		if (matriz[i][0] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[i][0] == 'O'){
			cuentaO++;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para 3 casos de 2 fila vertical
	for (int i = 0; i < util_fil; i++){
		if (matriz[i][1] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[i][1] == 'O'){
			cuentaO++;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para 3 casos de 1 fila vertical
	for (int i = 0; i < util_fil; i++){
		if (matriz[i][2] == 'X'){
			cuentaX++;
			if (cuentaX == 3){
				tipoganador = 1;
				tresenraya = true;
			}
		}
		
		if (matriz[i][2] == 'O'){
			cuentaO++;
			if (cuentaO == 3){
				tipoganador = 2;
				tresenraya = true;
			}
		}
	}

	cuentaX = 0;
	cuentaO = 0;

	//Condiciones para diagonal 1
	if (matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){
		tipoganador = 1;
		tresenraya = true;
	}else if (matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O'){
		tipoganador = 2;
		tresenraya = true;
	}

	//Condiciones para la diagonal 2
	if (matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X'){
		tipoganador = 1;
		tresenraya = true;
	}else if (matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O'){
		tipoganador = 2;
		tresenraya = true;
	}

	comprobarTableroCompletado(matriz, util_fil, util_col, tresenraya, tipoganador);

	return tresenraya;
}
/**
 * @brief Se le pide al usuario que introduzca la posicion donde quiere colocar la ficha en el tablero.
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @pre Debe haberse inicializado el tablero a 'O' y debe haberse introcido los datos de los usuarios.
 * @post Se comprobará si esa posición está ocupada o no sabiendo si tiene una 'o' ó una 'X' ó 'O'.
 * @author Guillermo Santamaría Quesada
 * @version 1.0
 */
void pedirPosicion(char matriz[][DIM_COL], int util_fil, int util_col){
	
	int coordenada1 = 0, coordenada2 = 0; //Son las posiciones en el tablero donde el usuario va a situar su ficha.
	int turno_jugador = 1;
	bool check = false;
	int tipoganador = 0;

	imprimirTablero(matriz, util_fil, util_col); //Imprimimos el tablero para ver los cambios realizados en el tablero.
	while(comprobarPosicion(matriz, util_fil, util_col, tipoganador) == false){
		do{
			check = false;
			cout << "Introduce la posicion donde quieres colocar la ficha jugador[" << turno_jugador << "]" << endl;
			cin >> coordenada1 >> coordenada2;

			if(!cin){
				check = true;
				cin.clear();
				cin.ignore(256, '\n');

			}else if (coordenada1 > 2 || coordenada1 < 0 || coordenada2 > 2 || coordenada2 < 0){ //Si intenta colocar una ficha fuera del tablero.
				check = true;
				cout << DEBUG << "No puedes colocar una ficha fuera del tablero" << RESTORE << endl;

			}else if (matriz[coordenada1][coordenada2] == 'X' || matriz[coordenada1][coordenada2] == 'O'){ //Si intenta colocar una ficha donde ya hay una.
				check = true;
				cout << DEBUG << "No puedes colocar una ficha donde ya hay una" << RESTORE << endl;
			}

		}while(check == true); //Mientras que esa posicion esté ocupada me sigue preguntando nuevas coordenadas para colocar una pieza.
		

		if (turno_jugador == 1){
			matriz[coordenada1][coordenada2] = 'X';
			turno_jugador++;
			comprobarPosicion(matriz, util_fil, util_col, tipoganador);
		}else if (turno_jugador == 2){
			matriz[coordenada1][coordenada2] = 'O';
			turno_jugador--;
			comprobarPosicion(matriz, util_fil, util_col, tipoganador);
		}
		
		imprimirTablero(matriz, util_fil, util_col); //Imprimimos el tablero para ver los cambios realizados en el tablero.
	}
	
	imprimirResultado(tipoganador);
}

/**
 * @brief Menú que se imprime por pantalla nada más iniciar el programa
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @pre Debe inicializarse la matriz en el main como char y con 9 valores con la letra 'o'.
 * @post Se ejecutarán los módulos para iniciar el juego, introducir datos de jugadores o salir del juego.
 * @author Guillermo Santamaría Quesada
 * @version 1.0
 */
void menu(char matriz[][DIM_COL], int util_fil, int util_col){
	
	int opcion = 0;
	bool check = false;
	
	do{
		cout << endl;
		cout << CYAN << "\tBienvenido al tres en raya" << RESTORE << endl;
		cout << CYAN << "\t1. Jugar" << RESTORE << endl;
		cout << CYAN << "\t2. Introducir datos de Jugadores"<< RESTORE << endl;
		cout << CYAN << "\t3. Salir" << RESTORE << endl;

		cout << CYAN << "\n\tEscoge una opcion [1,2 o 3]: " << RESTORE;
		cin >> opcion;

		if(!cin){
			check = true;
			cin.clear();
			cin.ignore(256, '\n');
		}else if (opcion == 1){
			pedirPosicion(matriz, util_fil, util_col);
		}else if (opcion == 2){
			cout << "Disponible proximamente" << endl;
		}else if (opcion == 3){
			exit(-1);
		}
	}while(check = true);
}


int main (){
	
	char matriz[DIM_FIL][DIM_COL] = {{'_', '_', '_'},{'_', '_', '_'},{'_', '_', '_'}};
	int util_fil = 3, util_col = 3; //Inicializamos las utiles a 3 de las filas y columnas para formar el tablero del tres en raya.

	menu(matriz, util_fil, util_col);
}