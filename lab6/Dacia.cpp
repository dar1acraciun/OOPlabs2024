#include "Dacia.h"
Dacia::Dacia(char* culoare)
{
	name = new char[5];
	name[0] = 'D';
	name[1] = 'a';
	name[2] = 'c';
	name[3] = 'i';
	name[4] = 'a';
	name[5] = '\0';
	color = new char[10];
	int i;
	for (i = 0; culoare[i] = '\0'; i++)
	{
		color[i] = culoare[i];
	}
	color[i] = '\0';


}
Dacia::~Dacia()
{
	delete[] name;
	delete[] color;

}
char* Dacia::GetColor()
{
	return color;
}
char* Dacia::GetName()
{
	return name;
}
