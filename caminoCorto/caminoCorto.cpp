// caminoCorto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <windows.h>

// constante teclas
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void imprimirMapa(std::vector<std::vector<char>> mapa);
bool comp(std::pair<int, int> a, std::pair<int, int> b);



int main()
{
	srand(time(NULL));
	int ancho, alto;
	std::pair<int, int> ia, player, objetivo;
	char iaChar = 'I', pChar = 'P';
	std::vector<std::vector<char>> mapa;
	std::cout << "---- Elija tamaño del mapa ----" << std::endl;
	std::cout << "Ancho: ";
	std::cin >> ancho;
	std::cout << "Alto: ";
	std::cin >> alto;
	std::vector<char> aux = std::vector<char>();
	while (1) {
		mapa.clear();
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				aux.push_back(' ');
			}
			mapa.push_back(aux);
			aux.clear();
		}
		system("cls");
		// aleatorio y comienzan en el mismo lugar
		ia = std::make_pair(rand() % alto, rand() % ancho);
		player.first = ia.first;
		player.second = ia.second;
		// el objetivo es aleatorio
		objetivo = std::make_pair(rand() % alto, rand() % ancho);
		mapa[ia.first][ia.second] = iaChar;
		mapa[player.first][player.second] = pChar;
		mapa[objetivo.first][objetivo.second] = 'X'; 
		int c;
		bool seMueve = false, volver = false;
		while (!comp(objetivo, ia) && !comp(objetivo, player)) {
			imprimirMapa(mapa);
			c = _getch();
			printf("tecla: %d \n", c);
			if (c == 49) {
				if (player.first + 1 < alto && player.second - 1 > -1) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first + 1;
					player.second = player.second - 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 50) {
				if (player.first + 1 < alto) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first + 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 51) {
				if (player.first + 1 < alto && player.second + 1 < ancho) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first + 1;
					player.second = player.second + 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 52) {
				if (player.second - 1 > -1) {
					mapa[player.first][player.second] = ' ';
					player.second = player.second - 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 54) {
				if (player.second + 1 < ancho) {
					mapa[player.first][player.second] = ' ';
					player.second = player.second + 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 55) {
				if (player.first - 1 > -1 && player.second - 1 > -1) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first - 1;
					player.second = player.second - 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 56) {
				if (player.first - 1 > -1) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first - 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			else if (c == 57) {
				if (player.first - 1 > -1 && player.second + 1 < ancho) {
					mapa[player.first][player.second] = ' ';
					player.first = player.first - 1;
					player.second = player.second + 1;
					mapa[player.first][player.second] = pChar;
					seMueve = true;
				}
			}
			if (seMueve) {
				// mover ia
				mapa[ia.first][ia.second] = iaChar;
				mapa[objetivo.first][objetivo.second] = 'X';
				seMueve = false;
			}
			system("cls");
		}
		do {
			imprimirMapa(mapa);
			if (comp(objetivo, ia) && !comp(objetivo, player))
				std::cout << "------------  PERDISTE -------------" << std::endl;
			else if (!comp(objetivo, ia) && comp(objetivo, player))
				std::cout << "------------  GANASTE -------------" << std::endl;
			else
				std::cout << "------------  EMPATE -------------" << std::endl;
			std::cout << "Quieres volver a jugar? " << std::endl;
			if (!volver) {
				std::cout << "NO:[X]  SI:[ ]" << std::endl;
			}
			else {
				std::cout << "NO:[ ]  SI:[X]" << std::endl;
			}
			c = _getch();
			if (c == 13) {
				break;
			}
			else if (c == 77 || c == 54) {
				volver = !volver;
			}
			else if (c == 52 || c == 75) {
				volver = !volver;
			}
			system("cls");
		} while (1);
		if (!volver) break;
	}



	system("pause");
	return 0;
}

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
	return (a.first == b.first && a.second == b.second);
}

void imprimirMapa(std::vector<std::vector<char>> mapa) {
	for (int i = 0; i < mapa.size(); i++) {
		for (int j = 0; j < mapa[i].size(); j++) {
			std::cout << "[" << mapa[i][j] << "] ";
		}
		std::cout << std::endl;
	}
}