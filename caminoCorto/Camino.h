#pragma once
#include <vector>

class Camino
{
public:
	Camino();
	Camino(std::pair<int, int> c, int h);
	Camino(const Camino&);

	std::vector<std::pair<int, int>> pasos;
	int getValor();
	std::pair<int, int> esta;
	int heuristica;
	void agregar(std::pair<int, int> a, int h);
	~Camino();
};

