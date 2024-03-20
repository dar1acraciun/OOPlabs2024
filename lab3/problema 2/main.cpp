#include <iostream>
#include "Canvas.h"
using namespace std;
int main() {
	Canvas c(7,7);
	c.DrawCircle(3, 3, 2, '*');
	c.FillCircle(3, 3, 2, '*');
	c.Print();
	c.Clear();
	cout << '\n';
	c.DrawRect(1, 1, 5, 5, '*');
	c.FillRect(1, 1, 5, 5, '*');
	c.Print();
	c.Clear();
	cout << '\n';
	c.DrawLine(1, 1, 6, 6, '*');
	c.Print();
	c.Clear();
}