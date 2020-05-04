#pragma once
#include "Repo.h"

template <class T> 
class RepoFile : public Repo<T>
{
protected:
	string fis;
public:
	RepoFile() {}
	~RepoFile() {}
	RepoFile(string nume);
	virtual void saveToFile();
	virtual void loadFromFile();
};

template<class T>
RepoFile<T>::RepoFile(string nume)
{
	fis = nume;
}

template<class T>
void RepoFile<T>::saveToFile()
{
	ofstream fout(fis);

	fout.close();
}

template<class T>
void RepoFile<T>::loadFromFile()
{
	ifstream fin(fis);

	fin.close();
}