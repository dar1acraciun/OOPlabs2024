#include "NumberList.h"
#include <iostream>


void NumberList::Init() {
	this->count= 0;

}
bool NumberList::Add(int x) {
	if (this->count > 9)
		return 0;
	else {
		this->numbers[count] = x;
		this->count = this->count + 1;
		return 1;
      }


}
void NumberList::Sort() {
	for (int i = 0; i < this->count - 1; i++)
		for (int j = i+1; j < this->count; j++)
			if (this->numbers[i] > this->numbers[j])
				std::swap(this->numbers[i], this->numbers[j]);


}
void NumberList::Print() {
	for (int i = 0; i < this->count; i++)
		std::cout << this->numbers[i]<<" ";
}
