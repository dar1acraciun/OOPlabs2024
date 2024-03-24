#pragma once
class Sort
{
private:
    int* v;
    int size;
public:
    Sort(int number, int min, int max);
    Sort(int*p,int number);
    Sort(int nr);
    Sort(int count, ...);
    Sort(char* p, int number);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent,int li,int ls);
    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

