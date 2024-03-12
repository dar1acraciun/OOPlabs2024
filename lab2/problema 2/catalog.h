#pragma once
class catalog
{
private:
	char name[100];
	float math, english, history, avarage;


public:

	void SetName(char name[100]);
	void SetGradeMath(float grade);
	float GetGradeMath();
	void SetGradeEnglish(float grade);
	float GetGradeEnglish();
	void SetGradeHistory(float grade);
	float GetGradeHistory();
	void GetAvarage();
	void Print();



};
