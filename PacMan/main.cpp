#include"Juego.h"
#include<conio.h>

int main() {
	//setlocale(LC_ALL, "spanish");
	Console::CursorVisible = false;
	Console::SetWindowSize(150, 45);
	creaMapa();
	Juego prueba;
	imprimeMapa();
	int descarte;
	int tecla = 0;
	bool jugar = true;
	bool ganar = false;
	long long tiempoBonus = 0; //me salia una advertencia fea, por eso el long long
	bool porTiempo = false;
	bool porVidas = false;
	prueba.getJugador()->imprimeMatriz();
	while (jugar) {
		if (_kbhit()) {
			descarte = _getch();
			if (descarte == 224) {
				tecla = _getch();
				prueba.getJugador()->mover(tecla);
				prueba.comePacDot();
				if (prueba.comeBonus()) {
					tiempoBonus = prueba.getTiempo();
					prueba.getJugador()->cambiaVelocidad(true);
				}
				else if (prueba.getTiempo() - tiempoBonus >= 5 || tiempoBonus == 0) {
					prueba.getJugador()->cambiaVelocidad(false);
				}

			}
		}
		prueba.moverFantasmas();
		prueba.getJugador()->imprimeMatriz();
		prueba.getJugador()->imprimeVidas();
		prueba.temporizador();
		prueba.imprimePacDots();
		prueba.fantasmaChocoPacman();
		if (prueba.getTiempo() >= 120) {
			jugar = false;
			ganar = false;
			porTiempo = true;
		}
		if (prueba.getJugador()->getVidas() < 1) {
			ganar = false;
			jugar = false;
			porVidas = true;
			prueba.getJugador()->imprimeVidas();
		}
		if (prueba.getCantidadPacDots() == 0) {
			jugar = false;
			ganar = true;
		}
	}
	char salida;
	Console::SetCursorPosition(67, 19);
	cout << "JUEGO TERMINADO" << endl;
	Console::SetCursorPosition(57, 21);
	cout << "Presione la tecla F para continuar " << endl;
	while (true) {
		salida = _getch();
		salida = toupper(salida);
		if (salida == 'F')
			break;
	}
	//me muevo usando las teclas direccionales
	//solo tengo 3 vidas
	//tengo 120 segundos para ganar
	//los puntos azules me dan doble velocidad por 5 segundos
	//mi meta es comerme todos los puntos rojos antes de que se termine el tiempo o me quede
	//sin vidas !!
	//gracias por ver



	system("cls");
	//esta parte se puede mejorar, pero ya es mas algo estetico
	if (ganar) {
		cout << "FELICIDADES, GANASTE!!!" << endl;
	}
	else if (porTiempo) {
		cout << "Perdiste!!!! Se te acabo el tiempo!!!!!" << endl;
		cout << "\nSolo pudiste comer " << 100 - prueba.getCantidadPacDots() << " pacdots" << endl;
	}
	else {
		cout << "Perdiste!!!!! Te quedaste sin vidasss" << endl;
		cout << "\nSolo pudiste comer " << 100 - prueba.getCantidadPacDots() << " pacdots" << endl;
	}
	system("pause>nul");
	return 0;
}