#pragma once
#include "Service.h"
class UI
{
public:
	Service s;

	void meniu_logare();
	void afisare_meniu();
	
	void inreg();
	void login();
	void logout();
	
	void afisare_prod();
	void afisare_nr_vag();
	void cumparaturi();

	void start();
};

void UI::meniu_logare()
{
	cout << "1. Doresc sa ma inregistrez, nu sunt in baza de date." << endl;
	cout << "2. Doresc sa ma loghez, sunt in baza de date." << endl;
	cout << "Introduceti nr. corespunzator operatiei." << endl;
}

void UI::afisare_meniu()
{
	cout << "Ce doriti sa efectuati?" << endl;
	cout << "1. Cautarea garniturilor dupa producator." << endl;
	cout << "2. Cautarea garniturilor dupa nr. de vagoane." << endl;
	cout << "3. Cumpararea unor garnituri." << endl;
	cout << "4. Logout." << endl;
	cout << "Introduceti nr. corespunzator operatiei sau 0 pt. iesire." << endl;
}
void UI::inreg()
{
	string u, p;
	cout << "Introduceti numele de utilizator dorit:";
	cin >> u;
	cout << "Introduceti parola dorita:";
	cin >> p;

	s.add_u(u, p);
	cout << "Ati fost inregistrat in baza de date!" << endl;
}
void UI::login()
{
	string u, p;
	cout << "Introduceti numele de utilizator dorit:";
	cin >> u;
	cout << "Introduceti parola dorita:";
	cin >> p;

	int ok = s.find_u(u, p);
	if (ok != -1)
		cout << "Ati fost logat cu succes!" << endl;
	else
	{
		cout << "Nu v-ati putut loga. Va rugam, reincercati!" << endl;
		login();
	}
}
void UI::logout()
{
	cout << "V-ati delogat cu succes!";
}

void UI::afisare_prod()
{
	for (Garnitura *g : s.sort_prod())
		cout << g << endl;
}
void UI::afisare_nr_vag()
{
	for (Garnitura *g : s.sort_nr_vag())
		cout << g << endl;
}

void UI::cumparaturi()
{
	cout << "Care este modelul gartinurii pe care doriti sa o cumparati?";
	string model; cin >> model;
	cout << "Cate garnituri doriti sa o cumparati?";
	int cant; cin >> cant;
	int ok = s.cumpara_garnituri(model, cant);
	if (ok == -2)
	{
		cout << "Modelul nu exista!" << endl;
		cumparaturi();
	}
	if (ok == -1)
	{
		cout << "Sunt disponibile mai putine garnituri decat ati solicitat." << endl;
		cumparaturi();
	}
	else
	{
		cout << "Garniturile au fost cumparate cu succes!" << endl;
	}
}

void UI::start()
{
	
	s.add_m("104", "Fleishmann", 8, "carbuni", 30, 20);
	bool ok = false;
	while (!ok)
	{
		cout << endl; meniu_logare(); cout << endl;
		int opt; cin >> opt;
		if (opt == 1)
			inreg();
		if (opt == 2)
			login();
		cout << endl; afisare_meniu(); cout << endl;

		
		cin >> opt;
		for (Garnitura *g : s.get_all_garnituri())
			cout << g->toString() << endl;
		switch (opt)
		{
		case 0: {ok = true; cout << "Aplicatie inchisa." << endl; }
		case 1: { afisare_prod(); break; }
		case 2: { afisare_nr_vag(); break; }
		case 3: { cumparaturi(); break; }
		case 4: { logout(); start(); break; }
		default: {cout << "Optiunea nu exista. Incercati alta optiune:" << endl; }
		}
	}
}