#include "Ferrarirosu.h"
Ferrarirosu::Ferrarirosu()
{
	name = new char[7];
	name[0] = 'F';
	name[1] = 'e';
	name[2] = 'r';
	name[3] = 'r';
	name[4] = 'a';
	name[5] = 'r'; 
	name[6] = 'i';
	name[7] = '\0';
	color = new char[5];
	color[0] = 'r';
	color[1] = 'o';
	color[2] = 's';
	color[3] = 'u';
	color[4] = '\0';
	


}
Ferrarirosu::~Ferrarirosu()
{
	delete[] name;
	delete[] color;

}
char* Ferrarirosu::GetColor()
{
	return color;
}
char* Ferrarirosu::GetName()
{
	return name;
}

