#pragma once
#include <assert.h>

#include "User.h"
#include "Garnitura.h"
#include "Repo.h"
#include "RepoFile.h"
#include "RepoTXT.h"
#include "RepoCSV.h"
#include "Service.h"

void test_u()
{
	User u1 = User("ana", "123parola");
	assert(u1.get_user() == "ana");
	assert(u1.get_pass() == "123parola");

	u1.set_user("anamaria");
	u1.set_pass("1234parola");
	assert(u1.get_user() == "anamaria");
	assert(u1.get_pass() == "1234parola");

	string u = u1.toString();
	assert(u == "anamaria 1234parola");

	u = u1.toStringDelimiter('+');
	assert(u == "anamaria+1234parola");

	cout << "Testele pentru clasa User functioneaza." << endl;
}

void test_g()
{
	Garnitura g1 = Garnitura("model", "prod", 8, 10, 20);
	assert(g1.get_model() == "model");
	assert(g1.get_prod() == "prod");
	assert(g1.get_nr_vag() == 8);
	assert(g1.get_disp() == 10);
	assert(g1.get_rez() == 20);

	g1.set_model("model1");
	g1.set_prod("prod1");
	g1.set_nr_vag(9);
	g1.set_disp(11);
	g1.set_rez(21);

	assert(g1.get_model() == "model1");
	assert(g1.get_prod() == "prod1");
	assert(g1.get_nr_vag() == 9);
	assert(g1.get_disp() == 11);
	assert(g1.get_rez() == 21);

	string u = g1.toString();
	assert(u == "model1 prod1 9 11 21");

	Garnitura g2 = Garnitura("model2", "prod2", 10, 12, 22);
	g1 = g2;
	assert(g1.get_model() == "model2");
	assert(g1.get_prod() == "prod2");
	assert(g1.get_nr_vag() == 10);
	assert(g1.get_disp() == 12);
	assert(g1.get_rez() == 22);

	cout << "Testele pentru clasa Garnitura functioneaza." << endl;
}
void test_m()
{
	Marfa m1 = Marfa("model", "prod", 8, "continut", 10, 20);
	assert(m1.get_model() == "model");
	assert(m1.get_prod() == "prod");
	assert(m1.get_nr_vag() == 8);
	assert(m1.get_continut() == "continut");
	assert(m1.get_disp() == 10);
	assert(m1.get_rez() == 20);

	m1.set_model("model1");
	m1.set_prod("prod1");
	m1.set_nr_vag(9);
	m1.set_continut("continut1");
	m1.set_disp(11);
	m1.set_rez(21);

	assert(m1.get_model() == "model1");
	assert(m1.get_prod() == "prod1");
	assert(m1.get_nr_vag() == 9);
	assert(m1.get_continut() == "continut1");
	assert(m1.get_disp() == 11);
	assert(m1.get_rez() == 21);

	string u = m1.toString();
	assert(u == "model1 prod1 9 continut1 11 21");

	Marfa m2 = Marfa("model2", "prod2", 10, "continut2", 12, 22);
	m1 = m2;
	assert(m1.get_model() == "model2");
	assert(m1.get_prod() == "prod2");
	assert(m1.get_nr_vag() == 10);
	assert(m1.get_continut() == "continut2");
	assert(m1.get_disp() == 12);
	assert(m1.get_rez() == 22);

	cout << "Testele pentru clasa Marfa functioneaza." << endl;
}
void test_p()
{
	Persoane m1 = Persoane("model", "prod", 8, 200, 10, 20);
	assert(m1.get_model() == "model");
	assert(m1.get_prod() == "prod");
	assert(m1.get_nr_vag() == 8);
	assert(m1.get_nr_loc() == 200);
	assert(m1.get_disp() == 10);
	assert(m1.get_rez() == 20);

	m1.set_model("model1");
	m1.set_prod("prod1");
	m1.set_nr_vag(9);
	m1.set_nr_loc(201);
	m1.set_disp(11);
	m1.set_rez(21);

	assert(m1.get_model() == "model1");
	assert(m1.get_prod() == "prod1");
	assert(m1.get_nr_vag() == 9);
	assert(m1.get_nr_loc() == 201);
	assert(m1.get_disp() == 11);
	assert(m1.get_rez() == 21);

	string u = m1.toString();
	assert(u == "model1 prod1 9 201 11 21");

	Persoane m2 = Persoane("model2", "prod2", 10, 202, 12, 22);
	m1 = m2;
	assert(m1.get_model() == "model2");
	assert(m1.get_prod() == "prod2");
	assert(m1.get_nr_vag() == 10);
	assert(m1.get_nr_loc() == 202);
	assert(m1.get_disp() == 12);
	assert(m1.get_rez() == 22);

	cout << "Testele pentru clasa Persoane functioneaza." << endl;
}

void test_repo()
{
	Repo<Garnitura>* repo = new Repo<Garnitura>();
	Garnitura* g1 = new Marfa("KBT8", "Fleishmann", 8, "carbuni", 10, 20);
	Garnitura* g2 = new Persoane("A0JK", "Neumann", 10, 200, 4, 30);
	Garnitura* g3 = new Marfa("B1xC", "Aron", 11, "benzina", 9, 12);
	Garnitura* g4 = new Persoane("DIJ9", "Stora", 9, 150, 5, 28);

	repo->add_elem(g2);
	repo->add_elem(g3);
	repo->add_elem(g1);
	assert(repo->get_size() == 3);
	assert(*(repo->get_elem(0)) == *g2);
	assert(*(repo->get_elem(1)) == *g3);
	assert(*(repo->get_elem(2)) == *g1);

	repo->add_elem(g4);
	assert(repo->get_size() == 4);
	assert(*(repo->get_elem(0)) == *g2);
	assert(*(repo->get_elem(1)) == *g3);
	assert(*(repo->get_elem(2)) == *g1);
	assert(*(repo->get_elem(3)) == *g4);

	cout << "Testele pentru clasa Repo functioneaza." << endl;
}
void test_csv()
{
	
}
void test_txt()
{
	
}

void test_live()
{
	/*
	Marfa g1("104", "Fleishmann", 8, "carbuni", 30, 20);
	Marfa g2("104", "Aron", 11, "benzina", 12, 9);
	Persoane g3("106", "Alonso", 20, 300, 10, 2);
	Marfa g4("103", "Amarra", 20, "petrol", 40, 10);
	Marfa g5("105", "Fierra", 12, "lemn", 13, 11);
	
	Service service;
	try 
	{
		service.add_m("104", "Fleishmann", 8, "carbuni", 30, 20);
		service.add_m("104", "Aron", 11, "benzina", 12, 9);
		service.add_p("106", "Alonso", 20, 300, 10, 2);
		service.add_m("103", "Amarra", 20, "petrol", 40, 10);
		service.add_m("105", "Fierra", 12, "lemn", 13, 11);
	}
	catch (�) 
	{
		assert(false);
	}
	assert(service.get_size() == 5);
	assert(service.get_elem(0).get_model() == 104);
	assert(service.get_elem(1).get_model() == 105);
	assert(service.get_elem(2).get_model() == 106);
	assert(service.get_elem(3).get_model() == 103);
	assert(service.get_elem(4).get_model() == 107);
	*/
}

void test_service()
{
	Service s;

	s.add_u("user1", "parola1");
	s.add_u("user2", "parola2");
	s.add_u("user3", "parola3");

	assert(s.find_u("user2", "parola2") == 1);
	assert(s.find_u("user4", "parola4") == -1);

	s.del_u("user3", "parola3");
	assert(s.find_u("user3", "parola3") == -1);

	s.upd_u("user1", "parola1", "user10", "parola10");
	assert(s.find_u("user10", "parola10") == 0);

	cout << "Testele pentru clasa Service functioneaza." << endl;
}

void teste()
{
	test_u();
	test_g();
	test_m();
	test_p();

	test_repo();
	test_csv();
	test_txt();

	//test_service();
}