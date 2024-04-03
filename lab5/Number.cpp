#include "Number.h"
#include <cstring> 
#include <iostream>

Number::Number(const char* value, int base) : base(base) {
    this->number = new char[strlen(value) + 1]; // Allocate memory
    strcpy_s(this->number, strlen(value) + 1, value); 
}

Number::~Number() {
    delete[] this->number; // Free memory
}

int Number::GetDigitsCount() {
    return strlen(this->number);
}
Number::Number(int x)  {
    
    this->base = 10;
   int nr = x, cnt = 0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    this->number = new char[cnt + 1];
    this->number[cnt] = '\0';
    cnt--;
    while (nr)
    {
        this->number[cnt--] = nr % 10;
        nr /= 10;

    }
}
Number::Number(const Number& ex) {
    this->base = ex.base;
    this->number = new char[strlen(ex.number)+1 ];
    strcpy_s(this->number, strlen(ex.number) + 1, ex.number); 
}

Number::Number(Number&& ex) {
    this->number = new char[strlen(ex.number) + 1]; 
    this->base = ex.base;
    strcpy_s(this->number, strlen(ex.number) + 1, ex.number);
    ex.number = nullptr;
}
int Number::GetBase() {
    return this->base;
}

void Number::Print() {
    std::cout << this->number << '\n';
}

Number Number::operator+(const Number ex) {
   
    int base = std::max(this->base, ex.base);

    Number n1(*this);
    Number n2(ex);    


    n1.SwitchBase(10);
    n2.SwitchBase(10);

   
    int maxSize = std::max(n1.GetDigitsCount(), n2.GetDigitsCount()) + 2;
    char* resultString = new char[maxSize];

    int carry = 0;
    int resultIndex = 0;

  
    for (int i = n1.GetDigitsCount() - 1, j = n2.GetDigitsCount() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int sum = carry;
        if (i >= 0) sum += n1.number[i] - '0';
        if (j >= 0) sum += n2.number[j] - '0';

        resultString[resultIndex++] = '0' + (sum % 10);
        carry = sum / 10;
    }

  
    resultString[resultIndex] = '\0';

    for (int i = 0; i < resultIndex / 2; ++i) {
        std::swap(resultString[i], resultString[resultIndex - i - 1]);
    }

    Number result(resultString, 10);
    result.SwitchBase(base);

 
    delete[] resultString;

    return result;
}

Number Number::operator-(Number ex) {
    int base = std::max(this -> base, ex.base);
    Number n1(this->number, this->base);
    n1.SwitchBase(10);
    ex.SwitchBase(10);
    int size = std::max(GetDigitsCount(), ex.GetDigitsCount()) + 2;
    char* p = new char[size];
    int i = GetDigitsCount() - 1, j = ex.GetDigitsCount() - 1, c = 0;
    int borrow = 0; 

    while (i >= 0) {
        int sub;
        if (this->number[i] >= '0') {
            sub = this->number[i--] - '0' - borrow;
            borrow = 0; 

            if (j >= 0) {
                if (sub >= (ex.number[j] - '0')) {
                    sub -= (ex.number[j--] - '0');
                }
                else {
                    sub += 10;
                    borrow = 1;
                    sub -= (ex.number[j--] - '0');
                }
            }
        }

        p[c++] = '0' + sub;
    }
    while (c > 1 && p[c - 1] == '0') {
        c--;
    }

    p[c] = '\0';
    for (int i = 0; i < c / 2; i++)
        std::swap(p[i], p[c - i - 1]);

    Number result(p, 10);
    result.SwitchBase(base);
    delete[] p;
    return result;
}
void Number::SwitchBase(int NewBase) {
    int nr = 0;
    if (this->base != 10) {
        long long p = 1;
        for (int i = strlen(this->number) - 1; i >= 0; i--) {
            if ('0' <= this->number[i] && this->number[i] <= '9')
                nr = nr + (this->number[i] - '0') * p;
            else if ('A' <= this->number[i] && this->number[i] <= 'Z')
                nr = nr + (this->number[i] - 'A' + 10) * p;

            p *= this->base;
        }
    }
    else {
        for (int i = 0; this->number[i] != '\0'; i++)
            nr = nr * 10 + (this->number[i] - '0');
    }

    char* p = new char[20]; 
    int contor = 0;
    while (nr) {
        int rest = nr % NewBase;
        if (rest >= 10)
            p[contor++] = 'A' + (rest - 10);
        else
            p[contor++] = '0' + rest;
        nr /= NewBase;
    }
    if (contor == 0)
        p[contor++] = '0';
    p[contor] = '\0';
    for (int i = 0; i < contor/ 2; i++)
        std::swap(p[i], p[contor - i - 1]);
    strcpy_s(this->number, strlen(p) + 1, p); 
    this->base = NewBase;
    delete[] p;
}
bool Number::operator>(Number ex)
{
    Number n1(this->number, this->base);
    n1.SwitchBase(10);
    ex.SwitchBase(10);
    if (n1.GetDigitsCount() > ex.GetDigitsCount())
        return 1;
    else if (n1.GetDigitsCount() < ex.GetDigitsCount())
        return 0;
    for (int i = 0; i < ex.GetDigitsCount(); i++)
        if (n1.number[i] - '0' > ex.number[i])
            return 1;
    return 0;

}
void Number::operator--()
{
    for (int i = 0; i < GetDigitsCount()-1; i++)
        this->number[i] = this->number[i + 1];

}
void Number::operator--(int number)
{
    this->number[GetDigitsCount() - 1] = '\0';
}
void Number ::operator+=(Number ex)
{
     Number n3(this->number, this->base),n4=n3+ex;
     this->number = n4.number;
     this->base = n4.base;

}
void Number::operator = (int x)
{
    int base = this->base;
    this->base = 10;

    int nr = x,cnt=0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    this->number = new char[cnt+1];
    this->number[cnt] = '\0';
    cnt--;
    while (nr)
    {
        this->number[cnt--] = nr % 10;
        nr /= 10;
        
    }
    SwitchBase(base);



 }
void Number::operator=(const char* p)
{
    strcpy_s(this->number, strlen(p) + 1, p);
    int base = this->base;
    this->base = 10;
    SwitchBase(base);
}
Number& Number::operator=(const Number& ex) {
    if (this != &ex) {
        delete[] this->number;
        this->base = ex.base;
        this->number = new char[strlen(ex.number) + 1];
        strcpy_s(this->number, strlen(ex.number) + 1, ex.number);
    }
    return *this;
}
