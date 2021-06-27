//This class allows to enroll students into a class with a console application
//
//it is recommended to name an object according to the class
//For example:  Menu Cj2020;

#pragma once
#ifndef MENU
#define MENU


#include "BST.h"
//ArrDynamicky is a template, thus we have to include both .h and .cpp
#include "ArrDynamicky.h"
#include "ArrDynamicky.cpp"



class Menu {
private:
	//BST for a class, contains student id and student name
	BST predmet;
	//sorted array of students id
	ArrDynamicky<int> arr;
	//unsorted array of students id, represents the order they enrolled into a class
	ArrDynamicky<int> arrNotSorted;

	int idStudent;
	StringCustom name;
	StringCustom lastName;
	//name insterted into the node
	StringCustom wholeName;

	int input = 0;

	//filling up with a dummy data
	void fillup();
	//check if cin == StringCustom
	StringCustom checkCinString();
	//check if cin == int
	int checkCinInt();

	//list the menu options
	void menuOptions();

	//enroll a student
	void enroll();
	//delete enrolled student
	void delEnroll();
	//find a student by their id
	void findId();
	//List all enrolled students in Ascending order
	void sortAsc();
	//list all enrolled students in Descending order
	void sortDesc();
	//list all students in the order they enrolled into the class
	void notSorted();

	//export enrolled students into studenti.txt
	void exportFile();
	//import enrolled students into studenti.txt
	void importFile();
	//running the menu app
	void runMenu();



public:
	//only the constructor is public
	Menu();
};

#endif