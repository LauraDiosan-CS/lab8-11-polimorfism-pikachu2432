#pragma once
#include "RepoFile.h"

template  <class T> 
class RepoCSV : public RepoFile<T>
{
public:
	RepoCSV();
	~RepoCSV() {}
	RepoCSV(string nume);
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoCSV<T>::RepoCSV() : RepoFile() {}

template<class T>
inline RepoCSV<T>::RepoCSV(string nume):RepoFile<T>(nume) {}

template<class T>
void RepoCSV<T>::loadFromFile()
{
	ifstream f(RepoFile<T>::fis);
	if (f.is_open())
	{
		string line;
		this->empty_repo();
		while (getline(f, line))
		{
			Garnitura* g = NULL;
			if (line.substr(0, 2) == "M")
			{
				line.erase(0, 3);
				g = new Marfa(line, ',');
				if (this->find_elem(g) == -1)
				{
					RepoFile<T>::elem.push_back(g);
				}
			}
			else if (line.substr(0, 2) == "P")
				 {
					 line.erase(0, 3);
					 g = new Persoane(line, ',');
					 if (this->find_elem(g) == -1)
					 {
						 RepoFile<T>::elem.push_back(g);
					 }
				 }
		}
		f.close();
	}
}

template<class T>
void RepoCSV<T>::saveToFile()
{
	ofstream f(RepoFile<T>::fis);
	if (f.is_open())
	{
		for (T* crt : RepoFile<T>::elem)
		{
			f << crt.toStringDelimiter(',') << endl;
		}
	}
}