#pragma once
#include <exception>
#include <iostream>
using namespace std;

class ValidExceptie : public exception 
{
private:
	string mesaj;
public:
	ValidExceptie(string m)
	{
		this->mesaj = m;
	}

	~ValidExceptie() {}

	virtual string what()
	{
		return mesaj;
	}
};