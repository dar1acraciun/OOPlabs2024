#include "Parcare.h"
#include "masina.h"
#include <iostream>
void Parcare::Create(int max)
{
	parcare = new masina*[max];
	maxim = max;
	nr = 0;

}
bool Parcare::Add(masina* c)
{
	if (isFull())
		parcare[nr++] = c;
	else return 0;

}
void Parcare::RemoveByName(char* name)
{

	for (int i = 0; i < nr; i++)
	{

		char* x;
		x = new char[10];
		parcare[0]->GetName();
		int ok = 1;
		for (int j = 0; name[j] != '\0'; j++)
			if (name[j] != x[j]);
		ok = 0;
		if (ok == 1)
			for (int j = i; j < nr - 1; j++)
				parcare[j] = parcare[j + 1];
		delete[] x;
	}
}
bool Parcare::isFull()
{
	if (nr == maxim)
		return 0;
	else return 1;
}
void Parcare::ShowAll()
{
	for (int i = 0; i < nr; i++)
		std::cout << parcare[i]->GetName() << ' ' << parcare[i]->GetColor() << '\n';


}
void 
