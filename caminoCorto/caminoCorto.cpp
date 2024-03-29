// caminoCorto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include "Camino.h"

// constante teclas
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void imprimirMapa(std::vector<std::vector<char>> mapa, int  x, int j,int t);
bool comp(std::pair<int, int> a, std::pair<int, int> b);
Camino aStar(std::vector<std::vector<char>> mapa, std::pair<int, int> posIA, std::pair<int, int> posObj, int ancho, int alto);
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
		std::cout << "pensando..." << std::endl;
		Camino respuesta = aStar(mapa, ia, objetivo, ancho, alto);
		system("cls");
		int pasosIa = 0;
		while (!comp(objetivo, ia) && !comp(objetivo, player)) {
			imprimirMapa(mapa, ia.first,ia.second,1);
			imprimirMapa(mapa, player.first, player.second,0);
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
				mapa[ia.first][ia.second] = ' ';
				pasosIa++;
				ia.first = respuesta.pasos[pasosIa].first;
				ia.second = respuesta.pasos[pasosIa].second;
				mapa[ia.first][ia.second] = iaChar;
				mapa[objetivo.first][objetivo.second] = 'X';
				seMueve = false;
			}
			system("cls");
		}
		do {
			imprimirMapa(mapa, ia.first, ia.second,1);
			imprimirMapa(mapa, player.first, player.second,0);
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

void imprimirMapa(std::vector<std::vector<char>> mapa, int  x, int y, int t) {
	for (int i = 0; i < mapa.size(); i++) {
		for (int j = 0; j < mapa[i].size(); j++) {
			if (i == x && j == y) {
				if (t == 0) {
					std::cout << "[" << "P" << "] ";
				}
				else {
					std::cout << "[" << "I" << "] ";
				}
			}
			else if( t == 0 && mapa[i][j] != 'I'){
				std::cout << "[" << mapa[i][j] << "] ";
			}else if (t == 1 && mapa[i][j] != 'P') {
				std::cout << "[" << mapa[i][j] << "] ";
			}
			else {
				std::cout << "[" <<" " << "] ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

double heurist(std::pair<int, int> posIA, std::pair<int, int> posObj) {
	return std::abs(posIA.first - posObj.first) + std::abs(posIA.second - posObj.second);
}

bool estaOK(std::pair<int, int> a, int ancho, int alto) {
	return (a.first >= 0 && a.second >= 0 && a.first < alto && a.second < alto);
}

std::vector<std::pair<int, int>> expandir(std::pair<int, int> a) {
	std::vector<std::pair<int, int>> retornar = std::vector<std::pair<int, int>>();
	retornar.push_back(std::make_pair(a.first - 1, a.second));
	retornar.push_back(std::make_pair(a.first + 1, a.second));
	retornar.push_back(std::make_pair(a.first, a.second - 1));
	retornar.push_back(std::make_pair(a.first, a.second + 1));
	retornar.push_back(std::make_pair(a.first + 1, a.second - 1));
	retornar.push_back(std::make_pair(a.first + 1, a.second + 1));
	retornar.push_back(std::make_pair(a.first - 1, a.second - 1));
	retornar.push_back(std::make_pair(a.first - 1, a.second + 1));
	return retornar;
}

bool isVisitado(std::pair<int, int> a, std::vector<Camino> caminos) {
	for (int i = 0; i < caminos.size(); i++) {
		if (caminos[i].esta.first == a.first && caminos[i].esta.second == a.second) {
			return true;
		}
	}
	return false;
}

bool isVisitado(std::pair<int, int> a, std::vector<std::pair<int, int>> caminos) {
	for (int i = 0; i < caminos.size(); i++) {
		if (caminos[i].first == a.first && caminos[i].second == a.second) {
			return true;
		}
	}
	return false;
}


Camino aStar(std::vector<std::vector<char>> mapa, std::pair<int, int> posIA, std::pair<int, int> posObj, int ancho, int alto) {
	// inicializo variables
	std::vector<std::pair<int, int> > visitados = std::vector<std::pair<int, int> >();
	int index = 0;
	std::vector<Camino> caminos;
	Camino aux = Camino();
	// agregar a visitados y el comienzo del camino
	aux.agregar(posIA, heurist(posIA, posObj));
	caminos.push_back(aux);
	// while principal
	while (caminos.size() != 0) {
		// busco el menor (el que este mas cerca del objetivo)
		double menor = caminos[0].getValor();
		index = 0;
		for (int i = 0; i < caminos.size(); i++) {
			if (menor > caminos[i].getValor()) {
				menor = caminos[i].getValor();
				index = i;
			}
		}
		// pasar a cerrados
		std::pair<int, int> aux = caminos[index].esta;
		std::cout << "X: " << aux.first << " Y: " << aux.second << std::endl;
		visitados.push_back(aux);
		// si llego a la meta se sale del while
		if (aux.first == posObj.first && aux.second == posObj.second) break;
		// expandir
		std::vector<std::pair<int, int>> expandidos = expandir(aux);
		for (int i = 0; i < expandidos.size(); i++) {
			// no se sale de los bordes y no esta visitado
			if (estaOK(expandidos[i], ancho, alto)) {
				if (!isVisitado(expandidos[i], caminos) && !isVisitado(expandidos[i], visitados)) {
					Camino nuevo = caminos[index];
					nuevo.agregar(expandidos[i], heurist(expandidos[i], posObj));
					// se agrega a caminos activos
					caminos.push_back(nuevo);
				}
			}
		}
		// se borra de los caminos activos
		caminos.erase(caminos.begin() + index);
	}
	
	return caminos[index];
}
