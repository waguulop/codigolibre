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

/**
 * @brief Se imprime el tablero por pantalla de manera actualizada independientemente desde la función en la que se invoque.
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @pre Debe inicializarse la matriz desde el main para que tenga algunos valores y se pueda visualizar (en este caso sus valores iniciales son '_').
 * @post Se imprime por pantalla una simulación de tablero con un diseño simple mediante barras.
 * @author Guillermo Santamaría Quesada
 * @version 1.0
 */
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

/**
 * @brief Imprime el resultado dependiendo del tipo de ganador por pantalla.
 * @param tipoganador (E) se pasa por copia porque no necesitamos modificarlo, solo imprimir por pantalla el resultado según ha ido cambiando esta variable entera durante las condiciones para comprobar si hay tres en raya para uno de los jugadores o empate.
 * @pre Debe haberse completado la comprobación de condiciones en comprobarPosicion(); y comprobarTableroCompletado(); durante la ejecución de esos módulos cambia el valores de tipoganador y llega aquí para imprimirse.
 * @post Se imprime por pantalla el resultado de ganador jugador 1, ganador jugador 2 o empate de diferentes colores.
 * @author Guillermo Santamaría Quesada
 * @version 1.0
 */
void imprimirResultado(int tipoganador){

	cout << endl;
	if (tipoganador == 1){
		cout << GREEN << "\tEl ganador es el jugador 1" << RESTORE << endl;
	}else if (tipoganador == 2){
		cout << GREEN << "\tEl ganador es el jugador 2" << RESTORE << endl;
	}else if (tipoganador == 0){
		cout << YELLOW << "\tHay empate" << RESTORE << endl;
	}
}

/**
 * @brief Comprueba si el tablero está completo.
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @param tipoganador (E/S) declarada en pedirposicion() especifica el tipo de ganador que tendremos con un valor entero (0 si es empate, 1 si se cumple una condicion de tres en raya para la 'X' y 3 si se cumple una condición de tres en raya para la 'O'.
 * @pre Deben haberse ingresado valores en todas las posiciones disponibles de la matriz desde pedirPosicion();. Solo se invoca a esta función después de haber comprobado que no se cumple ninguna condición para tres en raya. Porque si hay algún tres en raya antes de que se complete el juego finalizará con un ganador.
 * @post Devuelve un booleano que indica si el tablero está completo (es decir, que hay 9 fichas en total colocadas en el tablero), en caso de que esté completo y se haya comprobado que no existe ninguna condición para tresenraya true tipoganador será 0, es decir, empate.
 * @return tablerocompletado, true si está completo y false si todavía no se ha completado.
 * @author Guillermo Santamaría Quesada
 * @version 1.0
 */
bool comprobarTableroCompletado(char matriz[][DIM_COL], int util_fil, int util_col, int &tipoganador){
		
	int cuentacompletadas = 0;
	bool tablerocompletado = false;

	for (int i = 0; i < util_fil; i++){
		for (int j = 0; j < util_col; j++){
			if (matriz[i][j] == 'X' || matriz[i][j] == 'O'){
				cuentacompletadas++;
			}
		}
	}
	
	if (cuentacompletadas == 9){
		tipoganador = 0;
		tablerocompletado = true;
	}

	return tablerocompletado;
}

/**
 * @brief Esta función contiene las condiciones necesarias para cada uno de los casos de 3 en raya. Si se cumple alguna de estas, tresenraya pasa a ser true.
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @param tipoganador (E/S) declarada en pedirposicion() especifica el tipo de ganador que tendremos con un valor entero (0 si es empate, 1 si se cumple una condicion de tres en raya para la 'X' y 3 si se cumple una condición de tres en raya para la 'O'.
 * @pre Uno de los jugadores debe introducir unas coordenadas para llamar a esta función continuamente e ir comprobando si en algún momento se cumple una condición de tres en raya, también se podría añadir que se comienza a comprobar esta función y sus condiciones cuando ambos jugadores han colocado en el tablero más de 2 fichas y mejorar el rendimiento del programa.
 * @post Termina de comprobar las diferentes condiciones y devuelve true o false dependiendo de si hay tres en raya o no, si no hay se comprobará que el tablero esté completo más adelante y por lo tanto habrá empate.
 * @return tresenraya si se cumple alguna condición en la que haya 3 valores iguales consecutivos (horizontal, vertical o diagonal).
 * @author Guillermo Santamaría Quesada
 * @version 1.2
 */
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

	return tresenraya;
}

bool filtrosDeEntradas(char matriz[][DIM_COL], int &coordenada1, int &coordenada2){

	bool check = false;

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

	return check;
}

/**
 * @brief En esta función se van asignando las coordenadas ingresadas desde perdirPosicion() a un jugador por turno. Se asigna una 'X' en la posición del tablero para el jugador 1 y se asigna una 'O' para la posición del tablero escogida por el jugador 2.
 * @param matriz[][] (E/S) es la matriz que vamos a utilizar para la formación del tablero e ir comprobando posiciones. Se pasa desde el main.
 * @param util_fil (E) es la cantidad de filas que tiene el tablero (3). Se pasa como copia porque no vamos a modificar el tablero en ningún momento.
 * @param util_col (E) es la cantidad de columnas que tiene el tablero (3). Se pasa como copia poruqe no vamos a modificar el tablero en ningún momento.
 * @param tipoganador (E/S) declarada en pedirposicion() especifica el tipo de ganador que tendremos con un valor entero (0 si es empate, 1 si se cumple una condicion de tres en raya para la 'X' y 3 si se cumple una condición de tres en raya para la 'O'.
 * @param coordenada1 (E/S) es la primera coordenada de tipo entero que le pasamos desde pedirPosicion() se pasa como referencia porque necesitamos llamar a comprobarPosición() en cada instante para ver si se cumple una condición para tresenraya.
 * @param coordenada1 (E/S) es la segunda coordenada de tipo entero que le pasamos desde pedirPosicion() se pasa como referencia porque necesitamos llamar a comprobarPosición() en cada instante para ver si se cumple una condición para tresenraya.
 * @param turno_jugador (E/S) declarada en pedirPosicion() se pasa como referencia porque la necesitamos para ir indicando al usuario por pantalla desde la función pedirPosicion() el turno de un jugador en cada instante.
 * @pre Debe ingresarse una posición del tablero donde queremos colocar una ficha, dependiendo del turno que tenga el jugador se asocia esa POSICION una 'X' o una 'O'.
 * @post Va iterando el turno de cada jugador y se va comprobando al mismo tiempo si se cumple una condición para tres en raya.
 * @author Guillermo Santamaría Quesada
 * @version 2.0
 */
void turnoJugador(char matriz[][DIM_COL], int util_fil, int util_col, int &tipoganador, int &coordenada1, int &coordenada2, int &turno_jugador){

	if (turno_jugador == 1){
		matriz[coordenada1][coordenada2] = 'X';
		turno_jugador++; //Pasamos el turno al jugador 2.
		comprobarPosicion(matriz, util_fil, util_col, tipoganador);
	}else if (turno_jugador == 2){
		matriz[coordenada1][coordenada2] = 'O';
		turno_jugador--; //Devolvemos el turno al jugador 1 para la siguiente iteración del bucle.
		comprobarPosicion(matriz, util_fil, util_col, tipoganador);
	}
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
	int tipoganador = 0;
	bool check = false;

	imprimirTablero(matriz, util_fil, util_col); //Imprimimos el tablero para ver los cambios realizados en el tablero.
	while(comprobarPosicion(matriz, util_fil, util_col, tipoganador) == false && check == false){
		do{
			cout << "Introduce la posicion donde quieres colocar la ficha jugador[" << turno_jugador << "]" << endl;
			cin >> coordenada1 >> coordenada2;

		}while(filtrosDeEntradas(matriz, coordenada1, coordenada2) == true); //Mientras que esa posicion esté ocupada me sigue preguntando nuevas coordenadas para colocar una pieza.
			//Si el tablero está completado y no se ha cumplido ninguna condición para tres en raya, tipoganador es 0, por lo tanto se imprime como resultado empate.

		turnoJugador(matriz, util_fil, util_col, tipoganador, coordenada1, coordenada2, turno_jugador);
		imprimirTablero(matriz, util_fil, util_col); //Imprimimos el tablero para ver los cambios realizados en el tablero.

		if (comprobarTableroCompletado(matriz, util_fil, util_col, tipoganador) == true && comprobarPosicion(matriz, util_fil, util_col, tipoganador) == false){
			tipoganador = 0;
			check = true;
		}
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