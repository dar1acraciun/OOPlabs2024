#include <iostream>
#include "NumberList.h"

using namespace std;
int main() {
	NumberList myClass;
	myClass.Init();
	myClass.Add(4);
	myClass.Add(6);
	myClass.Add(2);
	myClass.Sort();
	myClass.Print();
}