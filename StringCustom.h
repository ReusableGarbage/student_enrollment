//this class implements a custom STRING CLASS
// implemented with a buffer with the string terminator '\0'
// lenght of the string is 1 char longer than the real string because of the terminator
//
// I would not recommend to use this class on serious projets.
// This class was made for practices only, please use the standard std::string instead

#pragma once
#ifndef STRING
#define STRING
#include <iostream>

class StringCustom {
private:
	//data of the string
	char* data;
	//string length including the terminator
	int length;

public:
	StringCustom();
	~StringCustom();
	//constructor for the string with only one char
	StringCustom(char c);
	// constructor for the pointer to the array of chars
	StringCustom(const char* c);
	// construtor for a string made of a string, mostlz used for the + and += operations with strings
	StringCustom(const StringCustom& s);

	// returns the string length
	int len() const;

	//overloading std << for printing
	friend std::ostream& operator<< (std::ostream& so, const StringCustom& s);
	//overloading std >> pro reading input, the string must not be longer than 1000 chars
	friend std::istream& operator>> (std::istream& so, StringCustom& s);

	//overloading [] for the direct access to a char on the index x
	char  operator[] (int x) const;

	//overloading operator =
	StringCustom& operator= (const StringCustom& s);
	//overloading  operator +=
	StringCustom& operator+= (const StringCustom& s);
	//overloading  operator +, viz. StringCustom& operator+= (const StringCustom& s)
	friend StringCustom operator+ (const StringCustom& s1, const StringCustom& s2);
	//overloading  operator ==
	friend bool operator== (const StringCustom& s1, const StringCustom& s2);
};

#endif