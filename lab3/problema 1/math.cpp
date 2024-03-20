#include "math.h"
#include <stdarg.h>
#include <iostream>
#include <stdlib.h>

int math::Add(int n1,int n2) {
	return n1 + n2;

}
int math::Add(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}
int math::Add(double n1, double n2)
{ 
	return n1 + n2;
}
int math::Add(double n1, double n2, double n3)
{
	return n1 + n2 + n3;
}
int math::Mul(int n1, int n2) {
	return n1 * n2;
}
int math::Mul(int n1, int n2, int n3) {
	return n1 * n2 * n3;
}
int math::Mul(double n1, double n2) {
	return n1 * n2;
}
int math::Mul(double n1, double n2, double n3) {
	return n1 * n2 * n3;
}
int math::Add(int count, ...)
{
	va_list vl;
	int s = 0;
	va_start(vl, count);
	for (int i = 0; i < count; i++) {
		int  val;
	    val= va_arg(vl,int);
		s += val;
	}
	va_end(vl);
	return s;

}
char* math::Add(const char* p, const char* y)
{
	if (p == nullptr || y == nullptr)
		return nullptr;
	int size;
	char* suma;
	int k;
	if (strlen(p) > strlen(y))
		 size = strlen(p);
	else size = strlen(y);
	suma = (char*)malloc(size* sizeof(char));
	int i=strlen(p)-1,j = strlen(y)-1, carry = 0,c=0;
	for (int z = size-1; z >= 0; z--)
	{
		int add;
		if (i==-1)
			add =  y[j]-'0' + carry,j--;
		else if (j==-1)
			add = p[i] -'0'+ carry,i--;
		else add =  p[i]-'0' + y[j]-'0' + carry,i--,j--;
		suma[c++] = '0' + add % 10;
		if (add >= 10)
			carry = add / 10 % 10;
		else carry = 0;

			
	}suma[c] = '\0';
	for (int z = 0; z < c / 2; z++)
		std::swap(suma[z], suma[c - z-1]);
	return suma ;




	
}
