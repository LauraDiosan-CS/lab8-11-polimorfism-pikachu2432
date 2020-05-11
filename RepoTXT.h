#pragma once
#include "RepoFile.h"

template <class T> 
class RepoTXT : public RepoFile<T>
{
public:
	RepoTXT();
	~RepoTXT() {}
	RepoTXT(string);
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoTXT<T>::RepoTXT():RepoFile() {}

template<class T>
inline RepoTXT<T>::RepoTXT(string nume):RepoFile<T>(nume) {}

template<class T>
inline void RepoTXT<T>::loadFromFile()
{
	ifstream f(RepoFile<T>::fileName);
	if (f.is_open())
	{
		string line;
		while (getline(f, line))
		{
			T* ob(line, ' ');
			RepoFile<T>::elem.push_back(ob);
		}
		f.close();
	}
}

template<class T>
inline void RepoTXT<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fileName);
	if (f.is_open())
	{
		for (T* crt : RepoFile<T>::elem)
		{
			f << crt.toStringDelimiter(' ') << endl;
		}
	}
}