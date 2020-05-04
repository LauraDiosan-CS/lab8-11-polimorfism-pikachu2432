#pragma once
#include "RepoFile.h"

template  <class T> 
class RepoCSV : public RepoFile<T>
{
public:
	RepoCSV() {}
	~RepoCSV() {}
	RepoCSV(string);
	void loadFromFile();
	void saveToFile();
	
};

template<class T>
inline RepoCSV<T>::RepoCSV(string nume) :RepoFile<T>(nume)
{}

template<class T>
void RepoCSV<T>::loadFromFile()
{
	string line;

	ifstream f(RepoFile<T>::fileName);

	while (getline(f, line)) 
	{
		T ob(line, ',');
		Repo<T>::elem.push_back(ob);
	}
}

template<class T>
void RepoCSV<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fileName);
	for (T crt : Repo<T>::elem) 
	{
		f << crt.toStringDelimiter(',') << endl;
	}
}