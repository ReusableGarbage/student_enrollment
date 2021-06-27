#ifndef arrdyncpp
#define arrdyncpp
#include <iostream>
#include "ArrDynamicky.h"

template <class T>
ArrDynamicky<T>::ArrDynamicky()
{
	sizeMem = initSize;
	nElements = 0;

	ptr = (T*)malloc(sizeMem * sizeof(T));

	if (ptr == NULL)
		throw "Error when constructing DynamicArray";
}


template <class T>
ArrDynamicky<T>::~ArrDynamicky()
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}


template <class T>
T& ArrDynamicky<T>::operator [] (int index)
{
	return ptr[index]; 
}

template <class T>
void ArrDynamicky<T>::add(const T& x)
{
	nElements++;

	if (nElements > sizeMem) //if the number of elements exceeds the allocated memort
	{
		sizeMem *= nasobek_velikosti; //we double the allocated memory

		ptr = (T*)realloc(ptr, sizeof(T) * sizeMem); //and we reallocate the whole arrat

		if (ptr == NULL)
			throw "Error adding an element to Dynamic Array";
	}

	ptr[nElements - 1] = x; //putting the element into the first empty index
}

template <class T>
void ArrDynamicky<T>::addSortAsc(const T& x)
{
	if (nElements == 0) add(x);
	else
	{
		nElements++;

		if (nElements > sizeMem) // same as add(const T& x)
		{
			sizeMem *= nasobek_velikosti;

			ptr = (T*)realloc(ptr, sizeof(T) * sizeMem);

			if (ptr == NULL)
				throw "Error adding an element to Dynamic Array";
		}

		int y;
		for (y = nElements -2; (y >= 0 && ptr[y] > x);y--) // substracting 2, because 1 was added to the nElements++ in line 60
		{
			ptr[y + 1] = ptr[y];
		}
		ptr[y + 1] = x;
	}
}


template <class T>
int ArrDynamicky<T>::getSize()
{
	return nElements; 
}

template <class T>
void ArrDynamicky<T>::clear()
{
	nElements = 0; 
	ptr = (T*)realloc(ptr, sizeof(T) * initSize);
	sizeMem = initSize;
}

template <class T>
void ArrDynamicky<T>::delPos(int pos)
{
	if (nElements != 0)
	{
		if (nElements == 1) // if array contains only one element, we can just call clear() method
			clear();
		else
		{
			// shifting elements
			for (int i = pos; i < nElements - 1; i++)
				ptr[i] = ptr[i + 1];

			nElements--;
		}
	}
}

template <class T>
void ArrDynamicky<T>::delValue( int x)
{
	if (nElements != 0) 
	{
		if (nElements == 1) // if array contains only one element, we can just call clear() method
			clear();
		else
		{
			int i;
			for (i = 0; i < nElements; i++) {
				if (ptr[i] == x) delPos(i);
			}
		}
	}
}

#endif