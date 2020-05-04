#pragma once
#include <iostream>
#include <string>
using namespace std;

class Garnitura
{
protected:
	string model;
	string prod;
	int nr_vag;
	int disp;
	int rez;
public:
	Garnitura();
	virtual ~Garnitura();
	Garnitura(string m, string p, int n, int d, int r);
	Garnitura(const Garnitura &v);
	
	virtual Garnitura* clone();

	void set_model(string m);
	void set_prod(string p);
	void set_nr_vag(int n);
	void set_disp(int d);
	void set_rez(int r);

	string get_model();
	string get_prod();
	int get_nr_vag();
	int get_disp();
	int get_rez();

	virtual Garnitura& operator=(const Garnitura &v);
	bool operator==(const Garnitura& rhs) const;

	//friend istream& operator>>(istream &is, Garnitura &v);
	friend ostream& operator<<(ostream &os, Garnitura &v);

	virtual string toString();
};

Garnitura::Garnitura() {}
Garnitura::~Garnitura() {}

Garnitura::Garnitura(string m, string p, int n, int d, int r)
{
	model = m;
	prod = p;
	nr_vag = n;
	disp = d;
	rez = r;
}
Garnitura::Garnitura(const Garnitura &v)
{
	model = v.model;
	prod = v.prod;
	nr_vag = v.nr_vag;
	disp = v.disp;
	rez = v.rez;
}

Garnitura* Garnitura::clone()
{
	Garnitura* nou = new Garnitura();
	nou->set_model(model);
	nou->set_prod(prod);
	nou->set_nr_vag(nr_vag);
	nou->set_disp(disp);
	nou->set_rez(rez);
	return nou;
}

void Garnitura::set_model(string m)
{
	model = m;
}
void Garnitura::set_prod(string p)
{
	prod = p;
}
void Garnitura::set_nr_vag(int n)
{
	nr_vag = n;
}
void Garnitura::set_disp(int d)
{
	disp = d;
}
void Garnitura::set_rez(int r)
{
	rez = r;
}

string Garnitura::get_model()
{
	return model;
}
string Garnitura::get_prod()
{
	return prod;
}
int Garnitura::get_nr_vag()
{
	return nr_vag;
}
int Garnitura::get_disp()
{
	return disp;
}
int Garnitura::get_rez()
{
	return rez;
}

Garnitura& Garnitura::operator=(const Garnitura &v)
{
	this->set_model(v.model);
	this->set_prod(v.prod);
	this->set_nr_vag(v.nr_vag);
	this->set_disp(v.disp);
	this->set_rez(v.rez);
	return *this;
}
bool Garnitura::operator==(const Garnitura& rhs) const
{
	return (model == rhs.model) && (prod == rhs.prod) && (nr_vag == rhs.nr_vag) && (disp == rhs.disp) && (rez == rhs.rez);
}
/*
istream& operator>>(istream &is, Garnitura &v)
{
	string model, prod;
	int nr_vag, disp, rez;
	cout << "Modelul: ";
	is >> model;
	cout << "Producatorul: ";
	is >> prod;
	cout << "Nr. de vagoane:";
	is >> nr_vag;
	cout << "Garnituri disponibile:";
	is << disp;
	cout << "Garnituri rezervate:";
	is << rez;

	v.set_model(model);
	v.set_prod(prod);
	v.set_nr_vag(nr_vag);
	v.set_disp(disp);
	v.set_rez(rez);

	return is;
}*/
ostream& operator<<(ostream &os, Garnitura &v)
{
	os << v.model << " " << v.prod << " " << v.nr_vag << " " << v.disp << " " << v.rez << endl;
	return os;
}

string Garnitura::toString()
{
	return model + ' ' + prod + ' ' + to_string(nr_vag) + ' ' + to_string(disp) + ' ' + to_string(rez);
}