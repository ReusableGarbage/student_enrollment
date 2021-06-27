//class implementing DYNAMIC ARRAY using MALLOC and REALLOC
// methods delvalue and addSortASC are recommended for arrays of integers only

#pragma once
#ifndef arrdyn
#define arrdyn
template <class T>
class ArrDynamicky {
private:
    T* ptr;

    int nElements; // number of elements
    int sizeMem; // real size of array

    const static int initSize = 100; // starting size
    const static int nasobek_velikosti = 2; //size multiplier, used in the constructor and clear method

public:

    ArrDynamicky(); 
    ~ArrDynamicky();

    // overloading the [] operator
    T& operator [] (int index);

    // adding an element
    void add(const T& x);
    // inserting an INT to an ascending sorted array
    void addSortAsc(const T& x);
    // getting the number of elements
    int getSize();
    // empties and resets an arraz
    void clear();
    // deleting an element on the position pos
    void delPos(int pos);
    // delets a specific integer in the array
    void delValue( int x);

};

#endif