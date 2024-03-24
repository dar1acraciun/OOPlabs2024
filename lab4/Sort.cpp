#include "Sort.h"
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
Sort::Sort(int number, int min, int max)
{
	this->v = (int*)malloc(number * sizeof(int));
	srand(1);
	this->size = number;
	for (int i = 0; i < number; i++)
		this->v[i] = min + rand() % (max - min + 1);
}
Sort::Sort(int number)
{
	this->size = number;
	this->v = (int*)malloc(number * sizeof(int));
	for (int i = 0; i < number; i++)
		std::cin >> this->v[i];

}
Sort::Sort(int* p, int number)
{
	this->size = number;
	this->v = (int*)malloc(number * sizeof(int));
	for (int i = 0; i < number; i++)
		this->v[i] = p[i];
}
Sort::Sort(int number, ...)
{ 
	this->v = (int*)malloc(number * sizeof(int));
	va_list vl;
	va_start(vl, number);
	this->size = number;
	for (int i = 0; i < number; i++)
		this->v[i] = va_arg(vl, int);


}
Sort::Sort(char* p, int number) {
	int nr = 0;
	this->size = number;
	this->v = (int*)malloc(number * sizeof(int));
	int j = 0;
	for (int i = 0; p[i]!='\0'; i++)
		if (p[i] == ',')
			this->v[j++] = nr, nr = 0;
		else
			nr = nr*10 + (p[i] - '0');
	this->v[j] = nr;
}
void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	if(ascendent==0)
	for (i = 1; i < this->size; i++) {
		key = this->v[i];
		j = i - 1;

		while (j >= 0 && this->v[j] > key) {
			this->v[j + 1] = this->v[j];
			j = j - 1;
		}
		this->v[j + 1] = key;
	}
	else 
		for (i = 1; i < this->size; i++) {
			key = this->v[i];
			j = i - 1;

			while (j >= 0 && this->v[j] <key) {
				this->v[j + 1] = this->v[j];
				j = j - 1;
			}
			this->v[j + 1] = key;
		}
}

void Sort::QuickSort(bool ascendent,int li,int ls)
{
	
	if (li < ls)
	{
		int m = (li + ls) / 2;
		int aux = this->v[li];
		this->v[li] = this->v[m];
		this->v[m] = aux;
		int i = li, j = ls, d = 0;
		if(ascendent==0)
			while (i < j)
			{
				if (this->v[i] > this->v[j])
				{
					std::swap(this->v[i], this->v[j]);
					d = 1 - d;
				}
				i += d;
				j -= 1 - d;

			}
		else
			while (i < j)
			{
				if (this->v[i] < this->v[j])
				{
					std::swap(this->v[i], this->v[j]);
					d = 1 - d;
				}
				i += d;
				j -= 1 - d;

			}
		QuickSort(ascendent, li, i - 1);
		QuickSort(ascendent, i + 1, ls);
	}
	
}
void Sort::BubbleSort(bool ascendent)
{
	int ok = 0;
	do {
		ok = 1;
		if(ascendent==0)
			for (int i = 0; i < this->size - 1; i++)
			{
				if (this->v[i] > this->v[i + 1])
					std::swap(this->v[i], this->v[i + 1]), ok = 0;
			}
		else
			for (int i = 0; i < this->size - 1; i++)
				if (this->v[i] > this->v[i + 1])
					std::swap(this->v[i], this->v[i + 1]), ok = 0;
	} while (ok == 0);
}
int Sort::GetElementsCount()
{
	return this->size;
}
int Sort::GetElementFromIndex(int index)
{
	return this->v[index];
}
void Sort::Print()
{
	
	for (int i = 0; i < this->size; i++)
		std::cout << this->v[i] << " ";
}

