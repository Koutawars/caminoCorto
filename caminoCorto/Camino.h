#pragma once
#include <vector>

class Camino
{
public:
	Camino();
	Camino(std::pair<int, int> c, double h);
	Camino(const Camino&);

	std::vector<std::pair<int, int>> pasos;
	int getValor();
	std::pair<int, int> esta;
	double heuristica;
	void agregar(std::pair<int, int> a, double h);
	~Camino();
};

