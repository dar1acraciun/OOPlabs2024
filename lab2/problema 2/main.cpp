#include <iostream>
#include "catalog.h"
using namespace std;
int main() {
	catalog c1,c2;
	char v[100] = "Ana";
	char s[100] = "Ion";
	c1.SetName(v);
	c2.SetName(s);
	c1.SetGradeEnglish(9.5);
	c2.SetGradeEnglish(8);
	c1.SetGradeMath(5.8);
	c2.SetGradeMath(7.3);
	c1.SetGradeHistory(3.7);
	c2.SetGradeHistory(4);
	c1.GetAvarage();
	c2.GetAvarage();
	c1.Print();
	c2.Print();
	cout << "comparare mate :" << c1.CompareMath(c1.GetGradeMath(), c2.GetGradeMath())<<'\n';
	cout << "comparare engleza :" << c1.CompareEnglish(c1.GetGradeEnglish(), c2.GetGradeEnglish())<<'\n';
	cout << "comparare istorie :" << c1.CompareHistory(c1.GetGradeHistory(), c2.GetGradeHistory());
	return 0;


	




}