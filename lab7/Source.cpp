#include <iostream>
#include <stdio.h>
#include "tree.h"
using namespace std;
float operator"" _kelvin(unsigned long long int x) {
	return x - 273.15;
}
float operator"" _Fanreheit(unsigned long long int x)
{
	return (x - 32) / 1.8;
}
int main() {
	float a = 300_kelvin;
	float b = 126_Fanreheit;
	tree<int> c(5);


}