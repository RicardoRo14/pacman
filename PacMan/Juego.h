#pragma once
#include<iostream>
//#include<Windows.h>
using namespace System;
using namespace std;
char matriz[40][150];
void creaMapa() {
	// '0'= marco de la consola
	//'1'= el fondo del juego
	//'2' = las paredes 
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 150; j++) {
			if (j == 0 || j == 149 || i == 0 || i == 39 || j == 1 || j == 148) {
				matriz[i][j] = '0';
			}
			else if (((i >= 7 && i <= 15) || (i >= 22 && i <= 32)) && (j == 9 || j == 10 || j == 11 || j == 140 || j == 139 || j == 138 || j == 137)) matriz[i][j] = '2';
			else if ((i == 7 || i == 32) && ((j >= 19 && j <= 70) || (j >= 78 && j <= 129)))matriz[i][j] = '2';
			else if ((i >= 14 && i <= 25) && (j >= 19 && j <= 129))matriz[i][j] = '2';
			else matriz[i][j] = '1';
		}
	}
}
void imprimeMapa() {

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 150; j++) {
			switch (matriz[i][j]) {
			case '0':
				Console::BackgroundColor = ConsoleColor::DarkGray;
				cout << " ";
				break;
			case '1':
				Console::BackgroundColor = ConsoleColor::Black;
				cout << " ";
				break;
			case '2':
				Console::BackgroundColor = ConsoleColor::DarkMagenta;
				cout << " ";
				break;
				case char(4) :
					Console::BackgroundColor = ConsoleColor::Black;
					Console::ForegroundColor = ConsoleColor(4);
					cout << char(4);
					break;
					case char(16) :
						Console::BackgroundColor = ConsoleColor::Black;
						Console::ForegroundColor = ConsoleColor(9);
						cout << char(16);
						break;

			}
		}
		//cout << endl;
	}
	Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
	Console::ForegroundColor = ConsoleColor::White;
}

class PacMan {
private:
	char jugador[4][5] = { ' ','¯','¯','¯',' ',
						'/',' ',' ','o','\\',
						'|',' ',' ',' ','<',
						'\\','_','_','_','/' };
	int x, y;//posicion en la matriz .... y es fila, x es columna
	int dx, dy;
	int color;
	int vidas;
	//void comePacDot(int cantidadPacDots) {
	//	for (int i = 0; i < cantidadPacDots; i++) {

	//	}
	//}
	//void comeBonus() {

	//}

public:
	PacMan() {
		//dx y dy simula la velocidad de movimiento de pacman
		x = 2;
		y = 1;//
		dx = 1;
		dy = 1;
		color = 14;
		vidas = 3;
	}
	~PacMan() {

	}
	void reduceVidas() {
		vidas -= 1;
	}
	int getVidas() {
		return vidas;
	}
	void imprimeVidas() {
		Console::SetCursorPosition(2, 41);
		cout << "VIDAS RESTANTES" << endl;
		Console::SetCursorPosition(7, 42);
		cout.width(2);
		cout.fill('0');
		cout << vidas << endl;
	}
	void cambiaVelocidad(bool comioBonus) {
		if (comioBonus) {
			dx = 2;
			dy = 2;
		}
		else {
			dx = 1;
			dy = 1;
		}
	}
	void setX(int _x) {
		x = _x;
	}
	void setY(int _y) {
		y = _y;
	}
	void imprimeMatriz() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << jugador[0][0];
		cout << jugador[0][1];
		cout << jugador[0][2];
		cout << jugador[0][3];
		cout << jugador[0][4];
		Console::SetCursorPosition(x, y + 1);
		cout << jugador[1][0];
		cout << jugador[1][1];
		cout << jugador[1][2];
		cout << jugador[1][3];
		cout << jugador[1][4];
		Console::SetCursorPosition(x, y + 2);
		cout << jugador[2][0];
		cout << jugador[2][1];
		cout << jugador[2][2];
		cout << jugador[2][3];
		cout << jugador[2][4];
		Console::SetCursorPosition(x, y + 3);
		cout << jugador[3][0];
		cout << jugador[3][1];
		cout << jugador[3][2];
		cout << jugador[3][3];
		cout << jugador[3][4];
		matriz[y][x] = '5';
		matriz[y][x + 4] = '5';
		matriz[y + 3][x] = '5';
		matriz[y + 3][x + 4] = '5';//guardamos las esquinas del pacman en tiempo reall
		Console::ForegroundColor = ConsoleColor::White;
	}
	void borrarMatriz() {
		Console::SetCursorPosition(x, y);
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		Console::SetCursorPosition(x, y + 1);
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		Console::SetCursorPosition(x, y + 2);
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		Console::SetCursorPosition(x, y + 3);
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		cout << " ";
		matriz[y][x] = '1';
		matriz[y][x + 4] = '1';//borramos las esquinas del pacman en tiempo reall
		matriz[y + 3][x] = '1';
		matriz[y + 3][x + 4] = '1';
	}
	int findX = 0;
	int findY = 0;
	bool encontroAlgo = false;
	void recuerdaEspacio(int h, int k, bool encontro) {
		findX = h;
		findY = k;
		encontroAlgo = encontro;
	}
	int findBonusX = 0;
	int findBonusY = 0;
	bool chocoBonus = false;
	void recuerdaBonus(int h, int k, bool encontro) {
		findBonusX = h;
		findBonusY = k;
		chocoBonus = encontro;
	}
	void mover(int ch) {
		//posicion en la matriz .... y es fila, x es columna
		// '0'= marco de la consola
		//'1'= el fondo del juego
		//'2' = las paredes 
		switch (ch)
		{
		case 72://arriba
			if (dx == 1) {
				if (y != 1 && matriz[y - 1][x] != '2' && matriz[y - 1][x + 1] != '2' && matriz[y - 1][x + 2] != '2' && matriz[y - 1][x + 3] != '2' && matriz[y - 1][x + 4] != '2') {
					for (int i = 0; i < 5; i++) {
						if (matriz[y - 1][x + i] == char(4)) {
							recuerdaEspacio(x + i, y - 1, true);
						}
						if (matriz[y - 1][x + i] == char(16)) {
							recuerdaBonus(x + i, y - 1, true);
						}
					}
					borrarMatriz();
					y -= dy;
					imprimeMatriz();
				}
			}
			else {
				if (y != 2 && matriz[y - 2][x] != '2' && matriz[y - 2][x + 1] != '2' && matriz[y - 2][x + 2] != '2' && matriz[y - 2][x + 3] != '2' && matriz[y - 2][x + 4] != '2') {
					if (y != 1 && matriz[y - 1][x] != '2' && matriz[y - 1][x + 1] != '2' && matriz[y - 1][x + 2] != '2' && matriz[y - 1][x + 3] != '2' && matriz[y - 1][x + 4] != '2') {
						for (int i = 0; i < 5; i++) {
							if (matriz[y - 1][x + i] == char(4)) {
								recuerdaEspacio(x + i, y - 1, true);
							}
							if (matriz[y - 2][x + i] == char(4)) {
								recuerdaEspacio(x + i, y - 2, true);
							}
							if (matriz[y - 1][x + i] == char(16)) {
								recuerdaBonus(x + i, y - 1, true);
							}
							if (matriz[y - 2][x + i] == char(16)) {
								recuerdaBonus(x + i, y - 2, true);
							}
						}
						borrarMatriz();
						y -= dy;
						imprimeMatriz();
					}
				}
			}
			break;
		case 80://abajo
			if (dy == 1) {
				if (y != 35 && matriz[y + 4][x] != '2' && matriz[y + 4][x + 1] != '2' && matriz[y + 4][x + 2] != '2' && matriz[y + 4][x + 3] != '2' && matriz[y + 4][x + 4] != '2') {
					for (int i = 0; i < 5; i++) {
						if (matriz[y + 4][x + i] == char(4)) {
							recuerdaEspacio(x + i, y + 4, true);
						}
						if (matriz[y + 4][x + i] == char(16)) {
							recuerdaBonus(x + i, y + 4, true);
						}
					}
					borrarMatriz();
					y += dy;

					imprimeMatriz();
				}
			}
			else {
				//
				if (y != 34 && matriz[y + 5][x] != '2' && matriz[y + 5][x + 1] != '2' && matriz[y + 5][x + 2] != '2' && matriz[y + 5][x + 3] != '2' && matriz[y + 5][x + 4] != '2') {
					if (y != 35 && matriz[y + 4][x] != '2' && matriz[y + 4][x + 1] != '2' && matriz[y + 4][x + 2] != '2' && matriz[y + 4][x + 3] != '2' && matriz[y + 4][x + 4] != '2') {
						for (int i = 0; i < 5; i++) {
							if (matriz[y + 4][x + i] == char(4)) {
								recuerdaEspacio(x + i, y + 4, true);
							}
							if (matriz[y + 5][x + i] == char(4)) {
								recuerdaEspacio(x + i, y + 5, true);
							}
							if (matriz[y + 4][x + i] == char(16)) {
								recuerdaBonus(x + i, y + 4, true);
							}
							if (matriz[y + 5][x + i] == char(16)) {
								recuerdaBonus(x + i, y + 5, true);
							}
						}
						borrarMatriz();
						y += dy;

						imprimeMatriz();
					}
				}
			}
			break;
		case 75://izquierda
			if (dx == 1) {
				if (x != 2 && matriz[y][x - 1] != '2' && matriz[y + 1][x - 1] != '2' && matriz[y + 2][x - 1] != '2' && matriz[y + 3][x - 1] != '2') {
					for (int i = 0; i < 4; i++) {
						if (matriz[y + i][x - 1] == char(4)) {
							recuerdaEspacio(x - 1, y + i, true);
						}
						if (matriz[y + i][x - 1] == char(16)) {
							recuerdaBonus(x - 1, y + i, true);
						}
					}
					borrarMatriz();
					x -= dx;
					imprimeMatriz();
				}
			}
			else {
				if (x != 3 && matriz[y][x - 2] != '2' && matriz[y + 1][x - 2] != '2' && matriz[y + 2][x - 2] != '2' && matriz[y + 3][x - 2] != '2') {
					if (x != 2 && matriz[y][x - 1] != '2' && matriz[y + 1][x - 1] != '2' && matriz[y + 2][x - 1] != '2' && matriz[y + 3][x - 1] != '2') {
						for (int i = 0; i < 4; i++) {
							if (matriz[y + i][x - 1] == char(4)) {
								recuerdaEspacio(x - 1, y + i, true);
							}
							if (matriz[y + i][x - 2] == char(4)) {
								recuerdaEspacio(x - 2, y + i, true);
							}
							if (matriz[y + i][x - 1] == char(16)) {
								recuerdaBonus(x - 1, y + i, true);
							}
							if (matriz[y + i][x - 2] == char(16)) {
								recuerdaBonus(x - 2, y + i, true);
							}
						}
						borrarMatriz();
						x -= dx;
						imprimeMatriz();
					}
				}
			}
			break;
		case 77://derecha
			if (dx == 1) {
				if (x != 143 && matriz[y][x + 5] != '2' && matriz[y + 1][x + 5] != '2' && matriz[y + 2][x + 5] != '2' && matriz[y + 3][x + 5] != '2') {
					for (int i = 0; i < 4; i++) {
						if (matriz[y + i][x + 5] == char(4)) {
							recuerdaEspacio(x + 5, y + i, true);
						}
						if (matriz[y + i][x + 5] == char(16)) {
							recuerdaBonus(x + 5, y + i, true);
						}
					}
					borrarMatriz();
					x += dx;

					imprimeMatriz();
				}
			}
			else {
				if (x != 142 && matriz[y][x + 5] != '2' && matriz[y + 1][x + 5] != '2' && matriz[y + 2][x + 5] != '2' && matriz[y + 3][x + 5] != '2') {
					if (x != 143 && matriz[y][x + 6] != '2' && matriz[y + 1][x + 6] != '2' && matriz[y + 2][x + 6] != '2' && matriz[y + 3][x + 6] != '2') {
						for (int i = 0; i < 4; i++) {
							if (matriz[y + i][x + 5] == char(4)) {
								recuerdaEspacio(x + 5, y + i, true);
							}
							if (matriz[y + i][x + 6] == char(4)) {
								recuerdaEspacio(x + 6, y + i, true);
							}
							if (matriz[y + i][x + 5] == char(16)) {
								recuerdaBonus(x + 5, y + i, true);
							}
							if (matriz[y + i][x + 6] == char(16)) {
								recuerdaBonus(x + 6, y + i, true);
							}
						}
						borrarMatriz();
						x += dx;

						imprimeMatriz();
					}
				}
			}
			break;
		}
	}
};


// CLASE pacdot
class PacDot {
private:
	int valor;
	int x, y;
	int color;
public:
	PacDot(int _x, int _y) {//posicion en la matriz .... y es fila, x es columna
		valor = 4;
		color = 4;//rojo
		x = _x;
		y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getValor() {
		return valor;
	}
	~PacDot() {

	}
	//en la fila 3 y 37
	//tambien en la fila 11 y 28
	// en la columna 4 y 145
	//empieza en la columna 9 ,luego +4 y asi...

};


//CLASE BONUS


class Bonus {
private:
	int valor;
	int x, y;
	int color;
public:
	Bonus(int _x, int _y) {//posicion en la matriz .... y es fila, x es columna
		valor = 16;
		color = 9;//azul
		x = _x;
		y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getValor() {
		return valor;
	}
	~Bonus() {

	}
};



// CLASE FANTASMA


class Fantasma {//fantasma
private:
	char jugador[4][5] = { ' ','¯','¯','¯',' ',
						'/','o',' ','o','\\',
						'|',' ',' ',' ','|',
						'|',',',',',',','|' };
	int x, y;//posicion en la matriz .... y es fila, x es columna
	int dx, dy;
	int color;
	int direccion;
	int min, max;
	void validaEspacio(char espacio) {
		switch (espacio) {
		case '0':
			Console::BackgroundColor = ConsoleColor::DarkGray;
			cout << " ";
			break;
		case '1':
			Console::BackgroundColor = ConsoleColor::Black;
			cout << " ";
			break;
		case '2':
			Console::BackgroundColor = ConsoleColor::DarkMagenta;
			cout << " ";
			break;
			case char(4) :
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor(4);
				cout << char(4);
				break;
				case char(16) :
					Console::BackgroundColor = ConsoleColor::Black;
					Console::ForegroundColor = ConsoleColor(9);
					cout << char(16);
					break;

		}
	}
public:
	Fantasma(int _x, int _y, int _dx, int _dy, int _color, int _direccion, int _min, int _max) {
		//dx y dy simula la velocidad de movimiento del fantasma
		x = _x;//3
		y = _y;//35
		dx = _dx;
		dy = _dy;
		color = _color;// cambiar el color (10)
		direccion = _direccion;// direccion de movimiento del fantasma 1: es horizontal 2: es vertical
		min = _min;
		max = _max;
	}
	~Fantasma() {

	}

	void imprimeMatriz() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << jugador[0][0];
		cout << jugador[0][1];
		cout << jugador[0][2];
		cout << jugador[0][3];
		cout << jugador[0][4];
		Console::SetCursorPosition(x, y + 1);
		cout << jugador[1][0];
		cout << jugador[1][1];
		cout << jugador[1][2];
		cout << jugador[1][3];
		cout << jugador[1][4];
		Console::SetCursorPosition(x, y + 2);
		cout << jugador[2][0];
		cout << jugador[2][1];
		cout << jugador[2][2];
		cout << jugador[2][3];
		cout << jugador[2][4];
		Console::SetCursorPosition(x, y + 3);
		cout << jugador[3][0];
		cout << jugador[3][1];
		cout << jugador[3][2];
		cout << jugador[3][3];
		cout << jugador[3][4];
		Console::ForegroundColor = ConsoleColor::White;
	}


	void borrarMatriz() {

		if (direccion == 1) {//movimiento horizontal
			Console::SetCursorPosition(x, y);
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			Console::SetCursorPosition(x, y + 1);
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			Console::SetCursorPosition(x, y + 2);
			for (int k = 0; k < 5; k++) {
				validaEspacio(matriz[y + 2][x + k]);
			}
			Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(x, y + 3);
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			cout << " ";
			matriz[y][x] = '1';
			matriz[y][x + 4] = '1';//borramos las esquinas del fantasma en tiempo reall
			matriz[y + 3][x] = '1';
			matriz[y + 3][x + 4] = '1';
		}
		else {//movimiento vertical
			Console::SetCursorPosition(x, y);
			cout << " ";
			cout << " ";
			validaEspacio(matriz[y][x + 2]);
			Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
			Console::ForegroundColor = ConsoleColor::White;
			cout << " ";
			cout << " ";
			Console::SetCursorPosition(x, y + 1);
			cout << " ";
			cout << " ";
			validaEspacio(matriz[y + 1][x + 2]);
			Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
			Console::ForegroundColor = ConsoleColor::White;
			cout << " ";
			cout << " ";
			Console::SetCursorPosition(x, y + 2);
			cout << " ";
			cout << " ";
			validaEspacio(matriz[y + 2][x + 2]);
			Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
			Console::ForegroundColor = ConsoleColor::White;
			cout << " ";
			cout << " ";
			Console::SetCursorPosition(x, y + 3);
			cout << " ";
			cout << " ";
			validaEspacio(matriz[y + 3][x + 2]);
			Console::BackgroundColor = ConsoleColor::Black;//regreso al color negro de fondo
			Console::ForegroundColor = ConsoleColor::White;
			cout << " ";
			cout << " ";
		}




	}
	bool tocoPacman = false;
	void mover() {
		//this_thread::sleep_for(chrono::milliseconds(200));  PRUEBA FALLIDA
		//posicion en la matriz .... y es fila, x es columna
		// 
		// '0'= marco de la consola
		//'1'= el fondo del juego
		//'2' = las paredes 
		// '5'=esquinas del pacman
		//'6'=esquinas del fantasma
		borrarMatriz();
		//valores de dx y dy de los fantasmas:  2 1 3 3 dx son 2 y 3, dy es 1
		if (direccion == 1) { //1 es horizontal
			if (x <= min || x + 4 >= max)dx *= -1;
			x += dx;


		}
		else {//2 es vertical
			if (y <= min || y + 3 >= max)dy *= -1;
			y += dy;

		}
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 5; i++) {
				if (matriz[y + j][x + i] == '5')tocoPacman = true;
			}
		}
		imprimeMatriz();

	}
};



// CLASE JUEGO
class Juego {
private:
	PacDot** pacdots;
	int cantidadPacdots;
	Bonus** listaBonus;
	int cantidadBonus;
	Fantasma** fantasmas;
	int cantidadFantasmas;
	long long tiempo;
	PacMan* jugador;

public:
	Juego() {
		jugador = new PacMan();
		tiempo = 0;
		//creo los fantasmas
		cantidadFantasmas = 4;
		fantasmas = new Fantasma * [cantidadFantasmas];//direccion: 1 es horizontal y 2 es vertical
		fantasmas[0] = new Fantasma(4, 35, 2, 2, 10, 1, 3, 146);// x,y,dx,dy,color,direccion
		fantasmas[1] = new Fantasma(142, 2, 1, 1, 11, 2, 1, 38);//min,max(se refiere a los limites de movimiento del fantasma)
		fantasmas[2] = new Fantasma(15, 27, 3, 1, 13, 1, 12, 136);//si pongo  mas rapido los fantasmas no se podra ganar el juego
		fantasmas[3] = new Fantasma(132, 9, 3, 1, 3, 1, 12, 136);//o sera casi imposible
		//nuevos fantasmas columna 12 y 149-12=137 ,fila 27 y 9
		//creo las direcciones de los pacdots
		cantidadPacdots = 100;//cumple con lo pedido
		pacdots = new PacDot * [cantidadPacdots];
		//creo las direcciones de los bonus
		cantidadBonus = 10;//cumple con lo pedido
		listaBonus = new Bonus * [cantidadBonus];
		//asigno las posiciones de los bonus
		listaBonus[0] = new Bonus(144, 3);
		listaBonus[1] = new Bonus(144, 37);
		listaBonus[2] = new Bonus(4, 37);
		listaBonus[3] = new Bonus(14, 29);
		listaBonus[4] = new Bonus(134, 29);
		listaBonus[5] = new Bonus(134, 11);
		listaBonus[6] = new Bonus(14, 11);
		listaBonus[7] = new Bonus(9, 19);
		listaBonus[8] = new Bonus(140, 19);
		listaBonus[9] = new Bonus(74, 33);
		int posX = 9;// variables temporales para asignar las posiciones de los pacdots
		int posY = 6;
		for (int i = 0; i < cantidadBonus; i++) {
			//guardando las posiciones de los bonus en la matriz
			matriz[listaBonus[i]->getY()][listaBonus[i]->getX()] = char(listaBonus[i]->getValor());
		}

		//(j >= 17 && j <= 131) limites para los pacdots
		for (int i = 0; i < 23; i++) {
			pacdots[i] = new PacDot(posX, 3);// x como columna y "y" como fila
			posX += 6;
		}
		posX = 9;
		for (int i = 23; i < 46; i++) {
			pacdots[i] = new PacDot(posX, 37);// x como columna y "y" como fila
			posX += 6;
		}
		posX = 19;
		for (int i = 46; i < 65; i++) {
			pacdots[i] = new PacDot(posX, 11);// x como columna y "y" como fila
			posX += 6;
		}
		posX = 19;
		for (int i = 65; i < 84; i++) {
			pacdots[i] = new PacDot(posX, 29);// x como columna y "y" como fila
			posX += 6;
		}
		//creando los pacdots verticales
		//posY vale 6
		for (int i = 84; i < 92; i++) {
			pacdots[i] = new PacDot(4, posY);// x como columna y "y" como fila
			posY += 4;
		}
		posY = 6;
		for (int i = 92; i < cantidadPacdots; i++) {
			pacdots[i] = new PacDot(144, posY);// x como columna y "y" como fila
			posY += 4;
		}
		//guardando las posiciones DE LOS PACDOTS en la matriz( TABLERO ):
		for (int i = 0; i < cantidadPacdots; i++) {
			matriz[pacdots[i]->getY()][pacdots[i]->getX()] = char(pacdots[i]->getValor());
		}
	}
	~Juego() {
		for (int i = 0; i < cantidadPacdots; i++) {
			delete pacdots[i];
		}
		delete[] pacdots;
		for (int i = 0; i < cantidadBonus; i++) {
			delete listaBonus[i];
		}
		delete[] listaBonus;
		for (int i = 0; i < cantidadFantasmas; i++) {
			delete fantasmas[i];
		}
		delete[] fantasmas;
		delete jugador;
	}
	void moverFantasmas() {
		_sleep(35);
		for (int i = 0; i < cantidadFantasmas; i++) {
			fantasmas[i]->mover();
		}
	}
	void temporizador() {
		tiempo += 60;//numero preciso para simular el tiempo transcurrido
		Console::SetCursorPosition(25, 41);
		cout << "TIEMPO(s)" << endl;
		Console::SetCursorPosition(27, 42);
		cout.width(3);
		cout.fill('0');
		cout << tiempo / 1000 << endl;
	}
	long long getTiempo() {
		return (tiempo / 1000);
	}
	PacMan* getJugador() {
		return jugador;
	}
	void eliminaBonus(int pos) {
		Bonus** aux;
		aux = new Bonus * [cantidadBonus - 1];
		for (int i = 0; i < pos; i++) {
			aux[i] = listaBonus[i];// advertencia tonta -_-
		}
		for (int i = pos; i < cantidadBonus - 1; i++) {
			aux[i] = listaBonus[i + 1];
		}
		delete[] listaBonus;
		cantidadBonus -= 1;
		listaBonus = aux;
	}
	void eliminaPacDot(int pos) {
		PacDot** aux;
		aux = new PacDot * [cantidadPacdots - 1];
		for (int i = 0; i < pos; i++) {
			aux[i] = pacdots[i];// advertencia tonta -_-
		}
		for (int i = pos; i < cantidadPacdots - 1; i++) {
			aux[i] = pacdots[i + 1];
		}
		delete[] pacdots;
		cantidadPacdots -= 1;
		pacdots = aux;
	}
	void imprimePacDots() {
		Console::SetCursorPosition(43, 41);
		cout << "PACDOTS COMIDOS" << endl;
		Console::SetCursorPosition(47, 42);
		cout.width(3);
		cout.fill('0');
		cout << 100 - cantidadPacdots << endl;
	}
	int getCantidadPacDots() {
		return cantidadPacdots;
	}

	void comePacDot() {
		if (jugador->encontroAlgo) {
			for (int i = 0; i < cantidadPacdots; i++) {
				if (pacdots[i]->getX() == jugador->findX && pacdots[i]->getY() == jugador->findY) {
					eliminaPacDot(i);
					matriz[jugador->findY][jugador->findX] = '1';
				}
			}
			jugador->encontroAlgo = false;
		}
	}
	bool comeBonus() {
		bool comioBonus = false;
		if (jugador->chocoBonus) {
			for (int i = 0; i < cantidadBonus; i++) {
				if (listaBonus[i]->getX() == jugador->findBonusX && listaBonus[i]->getY() == jugador->findBonusY) {
					eliminaBonus(i);
					matriz[jugador->findBonusY][jugador->findBonusX] = '1';
					comioBonus = true;
				}
			}
			jugador->chocoBonus = false;
		}
		return comioBonus;
	}
	void fantasmaChocoPacman() {
		for (int i = 0; i < cantidadFantasmas; i++) {
			if (fantasmas[i]->tocoPacman) {
				jugador->reduceVidas();
				fantasmas[i]->tocoPacman = false;
				jugador->borrarMatriz();
				jugador->setX(2);
				jugador->setY(1);
				jugador->imprimeMatriz();
			}
		}
	}
};