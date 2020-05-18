#pragma once
#include "ValidGarnitura.h"
#include "Marfa.h"

class ValidMarfa : public ValidGarnitura 
{
public:
	ValidMarfa() {}
	~ValidMarfa() {}
	void valid(Garnitura* g);
};

void ValidMarfa::valid(Garnitura* g)
{
	ValidGarnitura::valid(g);
	Marfa* m = (Marfa*)g;
	if (m->get_continut().empty())
	{
		throw ValidExceptie("Garnitura trebuie sa trasporte un tip de marfa!");
	}
}