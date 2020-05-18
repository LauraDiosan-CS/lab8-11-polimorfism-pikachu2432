#pragma once
#include "Marfa.h"
#include "Persoane.h"
#include "User.h"
#include "Repo.h"
#include "RepoCSV.h"
#include "RepoTXT.h"
#include <algorithm>

class Service
{
private:
	Repo<Garnitura>* repo_g;
	Repo<User>* repo_u;

public:
	Service();
	Service(Repo<Garnitura>* rg, Repo<User>* ru);
	~Service() {}
	
	vector<Garnitura*> get_all_garnituri();
	vector<User*> get_all_users();

	//user
	void add_u(string u, string p);
	void upd_u(string u1, string p1, string u2, string p2);
	int find_u(string u, string p);
	void del_u(string u, string p);
	
	//garnitura
	void add_g(string m, string p, int n, int d, int r);
	void upd_g(string m1, string p1, int n1, int d1, int r1, string m2, string p2, int n2, int d2, int r2);
	int find_g(string m, string p, int n, int d, int r);
	void del_g(string m, string p, int n, int d, int r);
	//Garnitura* get_g(int pos) throw(RepoException);
	
	//marfa
	void add_m(string m, string p, int n, string c, int d, int r);
	void upd_m(string m1, string p1, int n1, string c1, int d1, int r1, string m2, string p2, int n2, string c2, int d2, int r2);
	int find_m(string m, string p, int n, string c, int d, int r);
	void del_m(string m, string p, int n, string c, int d, int r);
	//Marfa* get_m(int pos) throw(RepoException);
	
	//persoane
	void add_p(string m, string p, int n, int nr, int d, int r);
	void upd_p(string m1, string p1, int n1, int nr1, int d1, int r1, string m2, string p2, int n2, int nr2, int d2, int r2);
	int find_p(string m, string p, int n, int nr, int d, int r);
	void del_p(string m, string p, int n, int nr, int d, int r);
	//Persoane* get_p(int pos) throw(RepoException);

	vector<Garnitura*> sort_prod();
	vector<Garnitura*> sort_nr_vag();
	int cumpara_garnituri(string continut, int cantitate);
};
Service::Service()
{
	repo_g = new Repo<Garnitura>();
	repo_u = new Repo<User>();
}
Service::Service(Repo<Garnitura>* rg, Repo<User>* ru)
{
	this->repo_g = rg;
	this->repo_u = ru;

	this->repo_u->add_elem(new User("ale", "123"));
}

vector<Garnitura*> Service::get_all_garnituri()
{
	return repo_g->get_all();
}
vector<User*> Service::get_all_users()
{
	return repo_u->get_all();
}

void Service::add_u(string u, string p)
{
	User* u1 = new User(u, p);
	repo_u->add_elem(u1);
}
void Service::upd_u(string u1, string p1, string u2, string p2)
{
	User* u = new User(u1, p1);
	User* us = new User(u2, p2);
	repo_u->upd_elem(u, us);
}
int Service::find_u(string u, string p)
{
	User* u1 = new User(u, p);
	return repo_u->find_elem(u1);
}
void Service::del_u(string u, string p)
{
	User* u1 = new User(u, p);
	repo_u->del_elem(u1);
}

void Service::add_g(string m, string p, int n, int d, int r)
{
	Garnitura* g1 = new Garnitura(m, p, n, d, r);
	repo_g->add_elem(g1);
}
void Service::upd_g(string m1, string p1, int n1, int d1, int r1, string m2, string p2, int n2, int d2, int r2)
{
	Garnitura* g = new Garnitura(m1, p1, n1, d1, r1);
	Garnitura* ga = new Garnitura(m2, p2, n2, d2, r2);
	repo_g->upd_elem(g, ga);
}
int Service::find_g(string m, string p, int n, int d, int r)
{
	Garnitura* g1 = new Garnitura(m, p, n, d, r);
	return repo_g->find_elem(g1);
}
void Service::del_g(string m, string p, int n, int d, int r)
{
	Garnitura* g1 = new Garnitura(m, p, n, d, r);
	repo_g->del_elem(g1);
}

/*Garnitura* Service::get_g(int pos) throw(exception)
{
	return this->repo_g->get_elem(pos);
}*/

void Service::add_m(string m, string p, int n, string c, int d, int r)
{
	Garnitura* m1 = new Marfa(m, p, n, c, d, r);
	repo_g->add_elem(m1);
}
void Service::upd_m(string m1, string p1, int n1, string c1, int d1, int r1, string m2, string p2, int n2, string c2, int d2, int r2)
{
	Garnitura* m = new Marfa(m1, p1, n1, c1, d1, r1);
	Garnitura* ma = new Marfa(m2, p2, n2, c2, d2, r2);
	repo_g->upd_elem(m, ma);
}
int Service::find_m(string m, string p, int n, string c, int d, int r)
{
	Garnitura* m1 = new Marfa(m, p, n, c, d, r);
	return repo_g->find_elem(m1);
}
void Service::del_m(string m, string p, int n, string c, int d, int r)
{
	Garnitura* m1 = new Marfa(m, p, n, c, d, r);
	repo_g->del_elem(m1);
}
/*Marfa* Service::get_m(int pos) throw(RepoException)
{
	return this->repo_g->get_elem(pos);
}*/

void Service::add_p(string m, string p, int n, int nr, int d, int r)
{
	Garnitura* p1 = new Persoane(m, p, n, nr, d, r);
	repo_g->add_elem(p1);
}
void Service::upd_p(string m1, string p1, int n1, int nr1, int d1, int r1, string m2, string p2, int n2, int nr2, int d2, int r2)
{
	Garnitura* p = new Persoane(m1, p1, n1, nr1, d1, r1);
	Garnitura* pe = new Persoane(m2, p2, n2, nr2, d2, r2);
	repo_g->upd_elem(p, pe);
}
int Service::find_p(string m, string p, int n, int nr, int d, int r)
{
	Garnitura* p1 = new Persoane(m, p, n, nr, d, r);
	return repo_g->find_elem(p1);
}
void Service::del_p(string m, string p, int n, int nr, int d, int r)
{
	Garnitura* p1 = new Persoane(m, p, n, nr, d, r);
	repo_g->del_elem(p1);
}
/*Persoane::get_p(int pos) throw(RepoException)
{
	return this->repo_g->get_elem(pos);
}*/

bool compara_prod(Garnitura* g1, Garnitura* g2)
{
	return g1->get_prod() < g2->get_prod();
}
vector<Garnitura*> Service::sort_prod()
{
	vector<Garnitura*> garnituri = this->repo_g->get_all();
	sort(garnituri.begin(), garnituri.end(), compara_prod);
	return garnituri;
}

bool compara_vag(Garnitura* g1, Garnitura* g2)
{
	return g1->get_nr_vag() < g2->get_nr_vag();
}
vector<Garnitura*> Service::sort_nr_vag()
{
	vector<Garnitura*> garnituri = this->repo_g->get_all();
	sort(garnituri.begin(), garnituri.end(), compara_vag);
	return garnituri;
}
int Service::cumpara_garnituri(string model, int cantitate)
{
	vector<Garnitura*> garnituri = this->repo_g->get_all();
	for (Garnitura* g : garnituri)
	{
		if (g->get_model() == model)
			if (g->get_disp() >= cantitate)
			{
				g->set_disp(g->get_disp() - cantitate);
				return 0;
			}
			else
			{
				return -1;
			}
	}
	return -2;
}