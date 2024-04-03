#pragma once
class Number
{
	int base;
	char* number;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	~Number();
	Number(const Number& ex);//copy
	Number(Number&& ex);//paste
	// add operators and copy/move constructor
	Number& operator=(const Number& ex);
	Number operator+(Number ex);
	Number operator-(Number ex);
	bool operator>(Number ex);
	void operator--(); //pentru --exemple
	void operator--(int numar); //pentru exemple--
	void operator+=(Number ex);
	void operator=(int x);
	void operator=(const char* p);
	void SwitchBase(int newBase);
	char Operator[](int x);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};


