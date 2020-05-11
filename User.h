#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	string user, pass;
public:
	User() {}
	~User() {}
	User(string u, string p);
	User* clone();

	string get_user();
	string get_pass();
	
	void set_user(string);
	void set_pass(string);
	
	bool operator==(const User& u);
	
	string toString();
	string toStringDelimiter(char delimiter);
};

User::User(string u, string p)
{
	user = u;
	pass = p;
}

User* User::clone()
{
	User* nou = new User();
	nou->set_user(user);
	nou->set_pass(pass);
	return nou;
}

string User::get_user()
{
	return user;
}

string User::get_pass()
{
	return pass;
}

void User::set_user(string u)
{
	user = u;
}

void User::set_pass(string p)
{
	pass = p;
}

bool User::operator==(const User & u)
{
	return (user == u.user) and (pass == u.pass);
}

string User::toString()
{
	return user + " " + pass;
}

string User::toStringDelimiter(char delimiter)
{
	return user + delimiter + pass;
}