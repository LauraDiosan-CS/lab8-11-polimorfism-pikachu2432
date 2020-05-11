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
	
	void start();
};

void UI::meniu_logare()
{
	cout << "1. Doresc sa ma inregistrez, nu sunt in baza de date." << endl;
	cout << "2. Doresc sa ma loghez, sunt in baza dde date." << endl;
	cout << "Introduceti nr. corespunzator operatiei." << endl;
}

void UI::afisare_meniu()
{
	cout << "Ce doriti sa efectuati?" << endl;
	cout << "1. " << endl;
	cout << "2. " << endl;
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

void UI::start()
{
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
		switch (opt)
		{
		case 0: {ok = true; cout << "Aplicatie inchisa." << endl; }
		case 1: { break; }
		case 2: { break; }
		default: {cout << "Optiunea nu exista. Incercati alta optiune:" << endl; }
		}
	}
}