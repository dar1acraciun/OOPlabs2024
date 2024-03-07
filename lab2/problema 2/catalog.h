#pragma once
class catalog
{
private: 
	char name[100];
	float math, english, history,avarage;


public:
	
	void SetName(char name[100]);
	void SetGradeMath(float grade);
	float GetGradeMath();
	void SetGradeEnglish(float grade);
	float GetGradeEnglish();
	void SetGradeHistory(float grade);
	float GetGradeHistory();
	void GetAvarage();
	int CompareMath(float x, float y);
	int CompareEnglish(float x, float y);
	int CompareHistory(float x, float y);
	int CompareAvarage(float x, float y);
	void Print();
	


};

