#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
class Repo
{
private:
	int size;
	T* elements;
public:
	Repo();
	Repo(const Repo<T> &v);
	~Repo();

	Repo<T>& operator=(const Repo<T> &v);
	Repo<T> get_all();
	int get_size();
	T get_elem(int i);

	void add_elem(T el);
	void del_elem(T el);
	int find_elem(T el);
	void upd_elem(T& el1, T& el2);
};

template <class T>
Repo<T>::Repo() 
{
	size = 0;
	elements = new T[10];
}

template <class T>
Repo<T>::Repo(const Repo<T> &v) 
{
	size = v.size;
	elements = new T[v.size];
	for (int i = 0; i < v.size; i++)
		elements[i] = v.elements[i]->clone();
}

template <class T>
Repo<T>::~Repo() 
{
	if (elements) 
	{
		delete[] elements;
		elements = NULL;
	}
}

template <class T>
Repo<T>& Repo<T>::operator=(const Repo<T> &v) 
{
	if (this != &v) 
	{
		size = v.size;
		if (elements)
			delete[] elements;
		elements = new T[v.size];
		for (int i = 0; i < v.size; i++)
			elements[i] = v.elements[i]->clone();
	}
	return *this;
}

template<class T>
Repo<T> Repo<T>::get_all()
{
	return elements;
}

template <class T>
int Repo<T>::get_size() 
{
	return size;
}

template <class T>
T Repo<T>::get_elem(int i) 
{
	return elements[i];
}

template <class T>
void Repo<T>::add_elem(T el) 
{
	elements[size++] = el;
}
template <class T>
void Repo<T>::del_elem(T el)
{
	for (int i = 0; i < this->size - 1; i++)
		if (elements[i] == el)
		{
			for (int j = i; j < this->size - 1; j++)
				elements[j] = elements[j + 1];
			this->size--;
		}
	if (elements[this->size - 1] == el)
		this->size--;
}
template <class T>
int Repo<T>::find_elem(T el)
{
	for (int i = 0; i < this->size; i++)
		if (elements[i] == el)
			return i;
	return -1;
}
template <class T>
void Repo<T>::upd_elem(T& el1, T& el2)
{
	for (int i = 0; i < this->size; i++)
		if (elements[i] == el1)
			elements[i] = el2;
}