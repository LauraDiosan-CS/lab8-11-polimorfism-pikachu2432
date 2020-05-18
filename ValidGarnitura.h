#pragma once
#include <string>
#include "Garnitura.h"
#include "ValidExceptie.h"
using namespace std;

class ValidGarnitura 
{
public:
	ValidGarnitura() {}
	~ValidGarnitura() {}
	virtual void valid(Garnitura* g);
};

void ValidGarnitura::valid(Garnitura* g)
{
	if (g->get_model().empty())
	{
		throw ValidExceptie("Modelul Garniturii nu poate fi gol!");
	}
	if (g->get_prod().empty())
	{
		throw ValidExceptie("Numele producatorului nu poate fi gol!");
	}
	if (g->get_nr_vag() <= 0)
	{
		throw ValidExceptie("Nr. de vagoane trebuie sa fie strict pozitiv!");
	}
	if (g->get_disp() < 0)
	{
		throw ValidExceptie("Nr. de garnituri disponibile trebuie sa fie strict pozitiv!");
	}
	if (g->get_rez() < 0)
	{
		throw ValidExceptie("Nr. de garnituri rezervate trebuie sa fie strict pozitiv!");
	}
}