#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <class T>
class Repo
{
private:
	vector<T*> elem;
public:
	Repo();
	Repo(const Repo<T> &v);
	~Repo();

	Repo<T>& operator=(const Repo<T> &v);
	vector<T*> get_all();
	int get_size();
	T* get_elem(int i);

	void add_elem(T* el);
	void upd_elem(T* el1, T* el2);
	int find_elem(T* el);
	void del_elem(T* el);
};

template <class T>
Repo<T>::Repo()
{
}

template <class T>
Repo<T>::Repo(const Repo<T> &v)
{
	size = v.size;
	elem = new T[v.size];
	for (int i = 0; i < v.size; i++)
		elem[i] = v.elem[i]->clone();
}

template <class T>
Repo<T>::~Repo()
{
	if (elem)
	{
		delete[] elem;
		elem = NULL;
	}
}

template <class T>
Repo<T>& Repo<T>::operator=(const Repo<T> &v)
{
	if (this != &v)
	{
		size = v.size;
		if (elem)
			delete[] elem;
		elem = new T[v.size];
		for (int i = 0; i < v.size; i++)
			elem[i] = v.elem[i]->clone();
	}
	return *this;
}

template<class T>
vector<T*> Repo<T>::get_all()
{
	return elem;
}

template <class T>
int Repo<T>::get_size()
{
	return elem.size();
}

template <class T>
T* Repo<T>::get_elem(int i)
{
	return elem[i];
}

template<class T>
void Repo<T>::add_elem(T* el)
{
	this->elem.push_back(el->clone());
}

template<class T>
void Repo<T>::upd_elem(T* el1, T* el2)
{
	for (int i = 0; i < elem.size(); i++)
	{
		if (*(this->get_elem(i)) == *el1)
		{
			delete this->elem[i];
			this->elem[i] = el2->clone();
			return;
		}
	}
}
template<class T>
int Repo<T>::find_elem(T* el)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (*(this->get_elem(i)) == *el)
			return i;
	}
	return -1;
}
template<class T>
void Repo<T>::del_elem(T* el)
{
	for (int i = 0; i < this->elem.size(); i++)
	{
		if (**(this->elem.begin() + i) == *el)
		{
			delete this->elem[i];
			this->elem.erase(this->elem.begin() + i);
			return;
		}
	}
}