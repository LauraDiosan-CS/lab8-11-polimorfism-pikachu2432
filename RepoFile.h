#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <class T> 
class RepoFile
{
protected:
	vector<T*> elem;
	string fis;
public:
	RepoFile() {}
	~RepoFile() {}
	RepoFile(string nume);
	void set_fileName(string nume);

	vector<T*> get_all();
	int get_size();
	T* get_elem(int i);
	
	void add_elem(T* el);
	void upd_elem(T* el1, T* el2);
	int find_elem(T* el);
	void del_elem(T* el);

	void empty_repo();

	virtual void saveToFile() = 0;
	virtual void loadFromFile() = 0;
};

template<class T>
RepoFile<T>::RepoFile(string nume)
{
	fis = nume;
}
template<class T>
void RepoFile<T>::set_fileName(string nume)
{
	this->fileName = nume;
}

template<class T>
vector<T*> RepoFile<T>::get_all()
{
	return elem;
}

template<class T>
int RepoFile<T>::get_size()
{
	return elem.size();
}

template<class T>
T* RepoFile<T>::get_elem(int i)
{
	if (i >= 0 && i < this->get_size())
	{
		return this->elem[i]->clone();
	}
	return NULL;
}

template<class T>
void RepoFile<T>::add_elem(T* el)
{
	this->elem.push_back(el->clone());
	this->saveToFile();
}

template<class T>
void RepoFile<T>::upd_elem(T* el1, T* el2)
{
	for (int i = 0; i < elem.size(); i++)
	{
		if (*(this->get_elem(i)) == *el1)
		{
			delete this->elem[i];
			this->elem[i] = el2->clone();
			this->saveToFile();
			return;
		}
	}
}
template<class T>
int RepoFile<T>::find_elem(T* el)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (*(this->get_elem(i)) == *el)
			return i;
	}
	return -1;
}
template<class T>
void RepoFile<T>::del_elem(T* el)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (**(this->elem.begin() + i) == *el)
		{
			delete this->elem[i];
			this->elem.erase(this->elem.begin() + i);
			this->saveToFile();
			return;
		}
	}
}
template<class T>
void RepoFile<T>::empty_repo()
{
	for (int i = 0; i < this->get_size(); i++)
	{
		delete this->elem[i];
	}
	this->elem.clear();
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