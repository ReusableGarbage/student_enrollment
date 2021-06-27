#include "StringCustom.h"

StringCustom::StringCustom()
{
    length = 0;
    data = new char[0];
}

StringCustom::~StringCustom()
{
    delete[] data;
}

StringCustom::StringCustom(char c)
{
    length = 1;
    data = new char(c);
}

StringCustom::StringCustom(const char* c)
{
    if (c) // pointer to the arr of chars points to something
    {
        int x = 0;
        while (c[x] != '\0') x++; //until we find the string terminator
        length = x + 1; //length+1 for the string terminator
        data = new char[x + 1];
        for (int y = 0; y < x; y++)
            data[y] = c[y];
        data[x] = '\0'; //adding the terminator !!IMPORTANT!!
    }
    else
    {
        length = 0;
        data = new char[0];
    }
}

StringCustom::StringCustom(const StringCustom& s)
{
    length = s.len();
    data = new char[length];
    for (int x = 0; x < length; x++)
        data[x] = s[x];
    //because this is a copy od a different string, the terminator is alreadz included
}

int StringCustom::len() const
{
    return length;
}


std::ostream& operator<< (std::ostream& os, const StringCustom& s)
{
    if (s.len() > 0)
    {
        for (int x = 0; x < s.len(); x++)
            os << s[x];
    }
    else os << ""; //if the string is empty, nothing will be printed

    return os;
}

std::istream& operator>> (std::istream& is, StringCustom& s)
{
    char* c = new char[1000];
    is >> c; //inserting into the arr
    s = StringCustom(c); //making a string from arr, viz. StringCustom(const char* c);
    delete[] c;

    return is;
}

char StringCustom::operator[] (int x) const
{
    if (x >= length) throw 1; //index out of bounds
    return data[x];
}

StringCustom& StringCustom::operator= (const StringCustom& s)
{
    if (this == &s) return *this; //strings are equivalent, no need to do anything

    delete data; //delete current data
    length = s.len();
    data = new char[length];
    for (int x = 0; x < (length-1); x++) //input new data
        data[x] = s[x];
    data[length-1] = '\0'; //dont forget the string terminator
    return *this;
}



StringCustom& StringCustom::operator+= (const StringCustom& s)
{
    //new string has the length of the two strings combined
    //deduct -1 because now we onlz need one string terminator
    int len = (length + s.len()) - 1; 
    char* str = new char[len];

    for (int x = 0; x < length - 1; x++)
        str[x] = data[x]; //ignore C6386, we're ensuring the termination later

    //appending the second string
    for (int y = 0; y < (s.len() - 1); y++)
        str[(length - 1) + y] = s[y];
    str[len - 1] = '\0'; // terminator

    delete data;
    length = len;
    data = str;
    return *this;
}

StringCustom operator+ (const StringCustom& s1, const StringCustom& s2)
{
    return StringCustom(s1) += s2;
}

bool operator== (const StringCustom& s1, const StringCustom& s2)
{
    if (s1.len() != s2.len()) return false; 

    int max = s1.len();
    int   x = 0;
    while ((x < max) && (s1[x] == s2[x])) x++; //x = number of identical chars
    return (x == max);
}