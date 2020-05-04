#pragma once
#include "RepoFile.h"

template <class T> 
class RepoTXT :public RepoFile<T>
{
public:
	RepoTXT() {}
	~RepoTXT() {}
	RepoTXT(string);
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoTXT<T>::RepoTXT(string nume) :RepoFile<T>(nume)
{}

template<class T>
inline void RepoTXT<T>::loadFromFile()
{
	string line;
	ifstream f(RepoFile<T>::fileName);
	while (getline(f, line)) 
	{
		T ob(line, ' ');
		Repo<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepoTXT<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fileName);
	for (T crt : Repo<T>::elem) 
	{
		f << crt.toStringDelimiter(' ') << endl;
	}
}