#pragma once
#include "Garnitura.h"

class Marfa : public Garnitura
{
private:
	string continut;
public:
	Marfa();
	Marfa(string m, string p, int n, string c, int d, int r);
	Marfa(const Marfa& m);
	~Marfa();

	Garnitura* clone();
	
	void set_continut(string c);
	string get_continut();

	Marfa& operator=(const Marfa& p);
	bool operator==(const Marfa& rhs) const;

	string toString();

	//friend istream& operator>>(istream &is, Garnitura &v);
	friend ostream& operator<<(ostream &os, Marfa &v);
};

Marfa::Marfa() :Garnitura() {}
Marfa::~Marfa() {}
Marfa::Marfa(string m, string p, int n, string c, int d, int r):Garnitura(m, p, n, d, r)
{
	continut = c;
}
Marfa::Marfa(const Marfa& m) : Garnitura(m)
{
	continut = m.continut;
}

Garnitura* Marfa::clone()
{
	Marfa* nou = new Marfa();
	nou->set_model(model);
	nou->set_prod(prod);
	nou->set_nr_vag(nr_vag);
	nou->set_continut(continut);
	nou->set_disp(disp);
	nou->set_rez(rez);
	
	return nou;
}

void Marfa::set_continut(string c)
{
	continut = c;
}
string Marfa::get_continut()
{
	return continut;
}

Marfa& Marfa::operator=(const Marfa& m)
{
	Garnitura::operator=(m);
	this->set_continut(m.continut);
	return *this;
}
bool Marfa::operator==(const Marfa& rhs) const
{
	return (model == rhs.model) && (prod == rhs.prod) && (nr_vag == rhs.nr_vag) && (continut == rhs.continut) && (disp == rhs.disp) && (rez == rhs.rez);
}

string Marfa::toString()
{
	return model + ' ' + prod + ' ' + to_string(nr_vag) + ' ' + continut + ' ' + to_string(disp) + ' ' + to_string(rez);
}
/*
istream& operator>>(istream &is, Marfa &m)
{
	string model,prod, c;
	int nr_vag, disp, rez;
	
	cout << "Modelul: ";
	is >> model;
	cout << "Producatorul: ";
	is >> prod;
	cout << "Nr. de vagoane:";
	is >> nr_vag;
	cout << "Continut:";
	is >> c;
	cout << "Garnituri disponibile:";
	is << disp;
	cout << "Garnituri rezervate:";
	is << rez;

	m.set_model(model);
	m.set_prod(prod);
	m.set_nr_vag(nr_vag);
	m.set_continut(c);
	m.set_disp(disp);
	m.set_rez(rez);

	return is;
}
*/
ostream& operator<<(ostream &os, Marfa &m)
{
	os << m.model << " " << m.prod << " " << m.nr_vag << " " << m.continut<<" " << m.disp << " " << m.rez << endl;
	return os;
}