#pragma once
#include <iostream>

#define SHELF_SIZE 2

template <class T>
class EntertainmentCollection
{
private:
	T entertainment[SHELF_SIZE];
	int numEntertainment = 0;

public:
	EntertainmentCollection();
	void add(T e);
	T remove();
	int numItemsInCollection();
};

struct FullCollection : std::exception {
	const char* what() const throw ()
	{
		return "The collection is full.";
	}
};

struct EmptyCollection : std::exception {
	const char* what() const throw ()
	{
		return "The collection is empty.";
	}
};


template<class T>
EntertainmentCollection<T>::EntertainmentCollection()
{
}

template<class T>
void EntertainmentCollection<T>::add(T e)
{
	if (this->numEntertainment >= SHELF_SIZE)
		throw FullCollection();
	this->entertainment[this->numEntertainment++] = e;
}

template<class T>
T EntertainmentCollection<T>::remove()
{
	if (this->numEntertainment < 1)
		throw EmptyCollection();
	return this->entertainment[--this->numEntertainment];
}

template<class T>
int EntertainmentCollection<T>::numItemsInCollection()
{
	return this->numEntertainment;
}
