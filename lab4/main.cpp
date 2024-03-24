#include <iostream>
#include "Sort.h"

using namespace std;
int main() {
	char v[20] = "2,50,1,90";
	Sort c(v,4);
	c.QuickSort(0,0,3);
	c.Print();
}