#include "catalog.h"
#include <string.h>
#include <iostream>


void catalog::SetName(char Name[100]) {
	strcpy_s(this->name, Name);

}
void catalog::SetGradeMath(float grade) {
	this->math = grade;

}
float  catalog::GetGradeMath() {
	return this->math;

}
void catalog::SetGradeEnglish(float grade) {
	this->english = grade;

}
float catalog::GetGradeEnglish() {

	return this->english;

}
void catalog::SetGradeHistory(float grade) {
	this->history = grade;
}
float catalog::GetGradeHistory() {
	return this->history;
}
void catalog::GetAvarage() {
	this->avarage = (this->math + this->english + this->history) / 3;
}
void catalog::Print() {
	std::cout << this->name << '\n';
	std::cout << "Note" << '\n';
	std::cout << "Math:" << " " << this->math << '\n';
	std::cout << "English:" << " " << this->english << "\n";
	std::cout << "History:" << " " << this->history << '\n';
	std::cout << "Avarage:" << " " << this->avarage << '\n';


}