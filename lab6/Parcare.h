#pragma once
#include "masina.h"
class Parcare
{
private:
	masina** parcare;
	int nr,maxim;
public:
	void Create(int maxCapacity);
	bool Add(masina* c);
	void RemoveByName(char* name);
	int GetCount();
	bool isFull();
	void ShowAll();
	void ShowByColor(char* color);

};

