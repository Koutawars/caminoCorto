#include "pch.h"
#include "Camino.h"


Camino::Camino()
{
	this->pasos = std::vector <std::pair<int, int>>();
}

Camino::Camino(std::pair<int, int> c, int h)
{
	this->pasos = std::vector <std::pair<int, int>>();
	this->esta = c;
	this->pasos.push_back(c);
	this->heuristica = h;
}

Camino::Camino(const Camino& a)
{
	this->pasos = std::vector <std::pair<int, int>>();
	this->esta = std::make_pair( a.esta.first, a.esta.second);
	this->heuristica = a.heuristica;
	for (int i = 0; i < a.pasos.size(); i++) {
		this->pasos.push_back(a.pasos[i]);
	}
}

int Camino::getValor() {
	return this->heuristica + this->pasos.size() - 1;
}

void Camino::agregar(std::pair<int, int> a, int h) {
	this->esta = a;
	this->pasos.push_back(a);
	this->heuristica = h;
}

Camino::~Camino()
{
}
