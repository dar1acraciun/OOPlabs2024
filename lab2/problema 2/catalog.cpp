#include "catalog.h"
#include <string.h>
#include <iostream>

	
void catalog::SetName(char Name[100]) {
	strcpy_s(this->name, Name);

}
void catalog::SetGradeMath( float grade) {
	this->math = grade;

}
float  catalog::GetGradeMath() {
	return this->math;

}
void catalog::SetGradeEnglish( float grade) {
	this->english = grade;

}
float catalog::GetGradeEnglish() {

	return this->english;

}
void catalog::SetGradeHistory( float grade) {
	this->history = grade;
}
float catalog::GetGradeHistory() {
	return this->history;
}
void catalog::GetAvarage() {
    this->avarage=(this->math + this->english + this->history) / 3;
}
int catalog::CompareMath(float x, float y) {
	if (this->math > this->math)
		return 1;
	if (this->math == this->math)
		return 0;
	return -1;

}
int catalog::CompareEnglish(float x,float  y) {
	if (x > y)
		return 1;
	if (this->english == this->english)
		return 0;
	return -1;

}
int catalog::CompareHistory(float x, float  y) {
	if (x > y)
		return 1;
	if (x ==y)
		return 0;
	return -1;

}
int catalog::CompareAvarage(float x, float y) {
	if (x> y)
		return 1;
	if (x == y)
		return 0;
	return -1;

}
void catalog::Print() {
	std::cout << this->name<<'\n';
	std::cout << "Note" << '\n';
	std::cout << "Math:" << " " << this->math << '\n';
	std::cout << "English:" << " " << this->english << "\n";
	std::cout << "History:" << " " << this->history << '\n';
	std::cout << "Avarage:" << " " << this->avarage << '\n';


}



