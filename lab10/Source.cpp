#include <iostream>
#include <exception>
using namespace std;

class InvalidIndexException :public exception
{
    virtual const char* what() const throw()
    {
        return "Index in afara vectorului";
    }
};
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    int Curent,CurentIndex;// mai adaugati si alte date si functii necesare pentru iterator
    T** listaux;
    int size;
public:
    ArrayIterator(T** list,int index=0,int Size)
    {
       listaux = new T * (list);
       size = Size;
    }
    ArrayIterator& operator ++ ();
    {
        if (CurentIndex < Size)
            CurentIndex++;
        return*this;
    }
    ArrayIterator& operator -- ();
    {
        if (CurentIndex > 1)
            CurentIndex--;
        return*this;
    }
    bool operator= (ArrayIterator<T>& other);
    {
        return CurentIndex == other.CurentIndex;
    }
    bool operator!=(ArrayIterator<T>&);
    {
        return CurentIndex != other.CurentIndex;
    }
    T* GetElement()
    {

    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array();// Lista nu e alocata, Capacity si Size = 0
    {
        List = Nullptr;
        Capacity = 0;
        Size = 0;;
    }
    ~Array(); // destructor
    {
        delete[] List;
    }
    Array(int capacity)// Lista e alocata cu 'capacity' elemente
    {
        List = new T * [capacity];
        Capacity = capacity;


    }
    Array(const Array<T>& otherArray); // constructor de copiere
    {
        List = new T * [otherArray.Capacity];
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        for (int i = 0; i <= otherArray.Size; i++)
            List[i] = new T * (otherArray.List[i]);
    }
    T& operator[] (int index); // arunca exceptie daca index este out of range
    {
        if (index < 0 || index >= size) {
            throw IndexOutOfRangeException();
        }
        return *List[index];
    }
    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        InvalidIndexException eroare;
        if (Size >= Capacity) {
            throw eroare;
        }
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem)// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        InvalidIndexException eroare;
        if (index<0 || index>Capacity)
            throw eroare;
        else
        {
            for (int i = Size - 1; i > index; i--)
                List[i] = List[i - 1];
            List[index] = new T(newElem);
            Size++;
            return *this;
        }
    }
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        InvalidIndexException eroare;
        if (index<0 || index>Capacity || (Size + otherArray + size > Capacity))
            throw eroare;
        else
        {
            for (int i = Size - 1; i > index; i--)
                List[i + otherArray.Size] = List[i];
            for (int i = 0; i < otherArray.Size; i++)
                List[index + i] = new T(*otherArray.List[i]);
            Size += otherArray.Size;
            return *this;
        }
    }
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {  InvalidIndexException eroare;
        if (index < 0 || index>Size)
            throw eroare;
        else
        {
            for (int i = index; i < Size - 1; i++)
                List[i] = List[i + 1];
            size--;
            return *this;
        }
    }
    bool operator=(const Array<T>& otherArray)
    {
        for (int i = 0; i < Size; i++)
            if (List[i] != otherArray.List[i])
                return 0;
        return 1;
    }
   void Sort(); // sorteaza folosind comparatia intre elementele din T
   {
       int ok = 0;
       do {
           ok = 1;
           for(int i=0;i<Size-1;i++)
               if (*List[i]>*List[i + 1])
               {
                   swap(List[i], List[i + 1]);
                   ok = 0;
               }

       }while(ok==0);
   }
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    {
        int ok = 0;
        do {
            ok = 1;
            for (int i = 0; i < Size - 1; i++)
                if (Comparare(*List[i],*List[i + 1])>0)
                {
                    swap(List[i], List[i + 1]);
                    ok = 0;
                }

        } while (ok == 0);
    }
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
    {
        int ok = 0;
        do {
            ok = 1;
            for (int i = 0; i < Size - 1; i++)
                if (comparator->ComparareElements(*List[i],*List[i+1])>0)
                {
                    swap(List[i], List[i + 1]);
                    ok = 0;
                }

        } while (ok == 0);

    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    {
        int li = 0, ls = size;

        while (li < ls)
        {
            int m = (li + ls) / 2;
           if  (*List[m]==elem) {
                return m;
           }
           else if (elem >*List[m]) {
                li = m+ 1;
            } else {
                ls = m - 1;
            }
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    {
        int li = 0, ls = size;
        while (li < ls)
        {
            int m = (li + ls) / 2;

            if (List[m] == elem)
                return index;
            else if (Comparare(elem, *List[m]) > 0)
                li = m + 1;
            else ls = m;
        }
        return 0;
    }
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator
    {

        
        int li = 0, ls = size;

        while (li < ls)
        {
            m = (li + ls) / 2;
            int cmp = comparator->CompareElements(list[m], &elem);
            if (cmp == 0) {
                return m;
            }
            else if (cmp < 0) {
                li = m + 1;
            }
            else {
                ls = m - 1;
            }
        }
        return -1;
    }
    int Find(const T& elem); // cauta un element in Array
    {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
            if (Compare(*List[i],elem)==0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
    {
        for (int i = 0; i < Size; i++)
            if (comparator->Compare(*List[i], elem) == 0)
                return i;
        return -1;
    }
    int GetSize()
    {
        return Size;;
    }
    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, Size, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size, Size);
    }
};
int main() {
    try {
        Array<int> arr(10);
        arr += 3;
        arr += 1;
        arr += 4;
        arr += 2;
        arr += 5;

        std::cout << "Array elements: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
}