#pragma once
#include "ValidGarnitura.h"
#include "Persoane.h"
class ValidPersoane : public ValidGarnitura
{
public:
	ValidPersoane() {}
	~ValidPersoane() {}
	void valid(Garnitura* g);
};

void ValidPersoane::valid(Garnitura* g)
{
	ValidGarnitura::valid(g);
	Persoane* p = (Persoane*)g;
	if (p->get_nr_loc() < 0)
	{
		throw ValidExceptie("Nr. de locuri trebuie sa fie strict pozitiv!");
	}
}