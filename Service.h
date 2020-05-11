#pragma once
#include "Marfa.h"
#include "Persoane.h"
#include "User.h"
#include "RepoCSV.h"
#include "RepoTXT.h"

class Service
{
private:
	RepoFile<Garnitura>* repo_g;
	RepoFile<User>* repo_u;

public:
	Service() {}
	Service(RepoFile<Garnitura>* rg, RepoFile<User>* ru);
	~Service() {}

	//bool log_in(string u, string p);
	//void log_out(string u, string p);
	
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
	//marfa
	void add_m(string m, string p, int n, string c, int d, int r);
	void upd_m(string m1, string p1, int n1, string c1, int d1, int r1, string m2, string p2, int n2, string c2, int d2, int r2);
	int find_m(string m, string p, int n, string c, int d, int r);
	void del_m(string m, string p, int n, string c, int d, int r);
	//persoane
	void add_p(string m, string p, int n, int nr, int d, int r);
	void upd_p(string m1, string p1, int n1, int nr1, int d1, int r1, string m2, string p2, int n2, int nr2, int d2, int r2);
	int find_p(string m, string p, int n, int nr, int d, int r);
	void del_p(string m, string p, int n, int nr, int d, int r);
};

Service::Service(RepoFile<Garnitura>* rg, RepoFile<User>* ru)
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