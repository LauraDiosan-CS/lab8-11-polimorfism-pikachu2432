#pragma once
#include "Garnitura.h"

class Persoane : public Garnitura
{
private:
	int nr_loc;
public:
	Persoane();
	Persoane(string m, string p, int n, int nr, int d, int r);
	Persoane(const Persoane& p);
	~Persoane();

	Garnitura* clone();
	
	void set_nr_loc(int n);
	int get_nr_loc();

	Persoane& operator=(const Persoane& p);
	bool operator==(const Persoane& rhs) const;

	string toString();

	//friend istream& operator>>(istream &is, Garnitura &v);
	friend ostream& operator<<(ostream &os, Persoane &v);
};

Persoane::Persoane() :Garnitura()
{
	nr_loc = 0;
}
Persoane::Persoane(string m, string p, int n, int nr, int d, int r) : Garnitura(m, p, n, d, r) 
{
	nr_loc = nr;
}
Persoane::Persoane(const Persoane& p) : Garnitura(p)
{
	nr_loc = p.nr_loc;
}
Persoane::~Persoane() {}

Garnitura* Persoane::clone()
{
	Persoane* nou = new Persoane();
	nou->set_model(model);
	nou->set_prod(prod);
	nou->set_nr_vag(nr_vag);
	nou->nr_loc = nr_loc;
	nou->set_disp(disp);
	nou->set_rez(rez);

	return nou;
}

void Persoane::set_nr_loc(int n)
{
	this->nr_loc = n;
}
int Persoane::get_nr_loc()
{
	return this->nr_loc;
}

Persoane& Persoane::operator=(const Persoane& p)
{
	Garnitura::operator=(p);
	this->set_nr_loc(p.nr_loc);
	return *this;
}

bool Persoane::operator==(const Persoane& rhs) const
{
	return (model == rhs.model) && (prod == rhs.prod) && (nr_vag == rhs.nr_vag) && (nr_loc == rhs.nr_loc) && (disp == rhs.disp) && (rez == rhs.rez);
}

string Persoane::toString()
{
	return model + ' ' + prod + ' ' + to_string(nr_vag) + ' ' + to_string(nr_loc) + ' ' + to_string(disp) + ' ' + to_string(rez);
}
/*
istream& operator>>(istream &is, Persoane &p)
{
	string model, prod;
	int nr_vag, nr_loc, disp, rez;

	cout << "Modelul: ";
	is >> model;
	cout << "Producatorul: ";
	is >> prod;
	cout << "Nr. de vagoane:";
	is >> nr_vag;
	cout << "Nr. de locuri:";
	is >> nr_loc;
	cout << "Garnituri disponibile:";
	is << disp;
	cout << "Garnituri rezervate:";
	is << rez;

	p.set_model(model);
	p.set_prod(prod);
	p.set_nr_vag(nr_vag);
	p.set_nr_loc(nr_loc);
	p.set_disp(disp);
	p.set_rez(rez);

	return is;
}
*/
ostream& operator<<(ostream &os, Persoane &p)
{
	os << p.model << " " << p.prod << " " << p.nr_vag << " " << p.nr_loc << " " << p.disp << " " << p.rez << endl;
	return os;
}