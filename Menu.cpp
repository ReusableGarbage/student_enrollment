#include "Menu.h"
#include <iostream>
#include <fstream>

void Menu::fillup()
{
	predmet.add(3, "Loren Hardin");
	predmet.add(2, "Ajwa Delaney");
	predmet.add(5, "Milly Brock");
	predmet.add(10, "Rocky Sanchez");
	predmet.add(1, "Irene Randolph");
	predmet.add(4, "Poppie Kaye");
	predmet.add(7, "Tyrone Pemberton");
	predmet.add(6, "Ananya Bean");

	arr.addSortAsc(3);
	arr.addSortAsc(2);
	arr.addSortAsc(5);
	arr.addSortAsc(10);
	arr.addSortAsc(1);
	arr.addSortAsc(4);
	arr.addSortAsc(7);
	arr.addSortAsc(6);

	arrNotSorted.add(3);
	arrNotSorted.add(2);
	arrNotSorted.add(5);
	arrNotSorted.add(10);
	arrNotSorted.add(1);
	arrNotSorted.add(4);
	arrNotSorted.add(7);
	arrNotSorted.add(6);

	std::cout << "\n\n Dummy data loaded\n\n";
	system("pause");
}

StringCustom Menu::checkCinString()
{
	StringCustom x;
	std::cin >> x;
	while (std::cin.fail()) {
		std::cout << "Error loading the string, try again: \n";
		std::cout << "	>";
		std::cin.clear();
		//using the ignore just to be sure
		std::cin.ignore(250, '\n');
		std::cin >> x;
	}
	return x;
}

int Menu::checkCinInt()
{
	int x;
	std::cin >> x;
	while (std::cin.fail() || x < 1) {
		std::cout << "\n==========================================\n";
		std::cout << "Error loading the integer, try again: \n";
		std::cout << "	>";
		std::cin.clear();
		std::cin.ignore(250, '\n');
		std::cin >> x;
	}
	return x;
}


void Menu::menuOptions()
{
	std::cout << "		Menu\n";
	std::cout << "==========================================\n";
	std::cout << "  1.		Enroll a student\n";
	std::cout << "  2.		Delete a student\n";
	std::cout << "  3.		Find a student by their ID\n";
	std::cout << "  4.		List enrolled students in the ascending order\n";
	std::cout << "  5.		List enrolled students in the descending order\n";
	std::cout << "  6.		List enrolled students in the order of their enrollement\n";
	std::cout << "  7.		Export students\n";
	std::cout << "  8.		Import students\n";
	std::cout << "  9.		Exit the program\n";
	std::cout << "==========================================\n";
	std::cout << "Type in the number and press enter: ";
}

void Menu::enroll()
{
	std::cout << "==========================================\n";
	std::cout << "	Enroll a student\n";
	std::cout << "==========================================\n";
	std::cout << "	Enter the student ID: \n";
	std::cout << "	>";

	this->idStudent = checkCinInt();

	if (predmet.isId(this->idStudent)) //check for duplicity
	{
		std::cout <<"\n==========================================\n";
		std::cout << "\n Student with this id is alreadz enrolled.\n";
		std::cout << "==========================================\n";
		system("pause");
	}
	else //duplicitz not found
	{
		std::cout << "\n	Enter the first name:\n";
		std::cout << "	>";
		this->name = checkCinString();
		std::cout << "\n	Enter the last name:\n";
		std::cout << "	>";
		this->lastName = checkCinString();
		this->wholeName = this->lastName + " " + this->name;

		//nejdrive dame moznost zkontrolovat si zadane udaje
		std::cout << "\n==========================================\n";
		std::cout << "	Overwiev\n";
		std::cout << "==========================================\n";
		std::cout << "	Student ID:	" << this->idStudent << "\n";
		std::cout << "	Name: " << this->wholeName << "\n";
		std::cout << "\n Please to confirm the enrollment type in 1\n";
		std::cout << "To cancel the enrollment, type in any other number. \n Press enter to proceed. \n";
		std::cout << "\n >";
		int temp;
		temp = checkCinInt();

		if (temp == 1)
		{
			predmet.add(this->idStudent, this->wholeName); //adding the student to the BST
			arr.addSortAsc(this->idStudent); //adding the student to a sorted array
			arrNotSorted.add(this->idStudent); //adding the student to an unsorted array
			std::cout << "Student was successfully enrolled.\n";
			system("pause");
		}
		else
		{
			std::cout << " \n Student was not enrolled.\n";
			system("pause");
		}
	}
}

void Menu::delEnroll()
{
	std::cout << "==========================================\n";
	std::cout << "	Deleting a student\n";
	std::cout << "==========================================\n";
	std::cout << "	Enter the student id\n";
	std::cout << "	>";
	this->idStudent = checkCinInt();
	
	if (predmet.isId(this->idStudent)) //student is enrolled
	{
		//listinf the student info
		std::cout << "\n==========================================\n";
		std::cout << "	Student info\n";
		std::cout << "==========================================\n";
		std::cout << "	Student ID:	" << this->idStudent << "\n";
		std::cout << "	Name: " << predmet.get(this->idStudent) << "\n";
		std::cout << "\n To confirm the deletion type in 1\n To cancel the deletion type in any other number. \n Press enter to proceed \n";
		std::cout << "\n >";
		int temp;
		temp = checkCinInt();

		if (temp == 1)
		{
			predmet.deleteById(this->idStudent); //deleting a student from BST
			arr.delValue(this->idStudent); 
			arrNotSorted.delValue(this->idStudent);
			std::cout << "Student was deleted from this class.\n";
			system("pause");
		}
		else
		{
			std::cout << " \n Student was not deleted.\n";
			system("pause");
		}
	}
	else //student not in BST
	{
		std::cout << "\n==========================================\n";
		std::cout << "\n Student with this ID is not enrolled into this class.\n";
		std::cout << "==========================================\n";
		system("pause");
	}
}

void Menu::findId() 
{
	std::cout << "==========================================\n";
	std::cout << "	List student info\n";
	std::cout << "==========================================\n";
	std::cout << "	Enter student ID\n";
	std::cout << "	>";
	this->idStudent = checkCinInt();
	if (predmet.isId(this->idStudent))//student je v BST
	{
		std::cout << "\n==========================================\n";
		std::cout << "	Overview\n";
		std::cout << "==========================================\n";
		std::cout << "	Student ID:	" << this->idStudent << "\n";
		std::cout << "	Name: " << predmet.get(this->idStudent) << "\n\n";
		system("pause");
	}
	else//student neni v BST
	{
		std::cout << "\n==========================================\n";
		std::cout << "\n Student with this ID is not enrolled into this class.\n";
		std::cout << "==========================================\n";
		system("pause");
	}
}

void Menu::sortAsc() {
	std::cout << "==========================================\n";
	std::cout << "	List enrolled students in the ascending order\n";
	if (arr.getSize() == 0)
		std::cout << "\n	There are no students enrolled\n\n\n";
	else
	{
		std::cout << "=================================================================\n";
		std::cout << "	ID	|	 Last name and First name		\n";
		std::cout << "=================================================================\n";
		for (int i = 0; i < arr.getSize(); i++)//going through the array
		{
			std::cout << "	" << arr[i] << "	|"; //getting the id
			std::cout << "	" << predmet.get(arr[i]) << "			\n"; //use the id to get the name from BST
			std::cout << "=================================================================\n";
		}
	}
	system("pause");
}

void Menu::sortDesc() {
	std::cout << "==========================================\n";
	std::cout << "	List enrolled students in the descending order\\n";
	if(arr.getSize() == 0)
		std::cout << "\n	There are no students enrolled\n\n\n";
	else
	{
		std::cout << "=================================================================\n";
		std::cout << "	ID	|	Last name and First name				\n";
		std::cout << "=================================================================\n";
		for (int i = arr.getSize() - 1; i >= 0 ; i--) // going through the array
		{
			std::cout << "	" << arr[i] << "	|"; //getting the id
			std::cout << "	" << predmet.get(arr[i]) << "			\n";//use the id to get the name from BST
			std::cout << "=================================================================\n";
		}
	}
	system("pause");
}

void Menu::notSorted() {
	std::cout << "==========================================\n";
	std::cout << "	List enrolled students in the order of their enrollement\n";

	if (arr.getSize() == 0)
		std::cout << "\n	There are no students enrolled\n\n\n";
	else
	{
		std::cout << "=================================================================\n";
		std::cout << "	ID	|	Last name and First name			\n";
		std::cout << "=================================================================\n";
		for (int i = 0; i < arrNotSorted.getSize(); i++) // going through the array
		{
			std::cout << "	" << arrNotSorted[i] << "	|"; //getting the id
			std::cout << "	" << predmet.get(arrNotSorted[i]) << "			\n"; //use the id to get the name from BST
			std::cout << "=================================================================\n";
		}
	}
	system("pause");
}

void Menu::exportFile()
{
	//students will be exported in the order they enrolled into the class
	int size = arrNotSorted.getSize();
	if (size > 0) //if there are any students to export
	{
		std::ofstream MyFile("studenti.txt");

		for (int i = 0; i < size; i++)
		{
			int temp = arrNotSorted[i];
			StringCustom temp2 = predmet.get(temp);
			int len = temp2.len() - 1;
			//a blank space will be used as a delimiter for easier import
			//insert ID
			MyFile << temp << " ";
			//We have to export the name without the last index, because the string terminator
			// is exported as a blank space, this would lead to double blank spaces
			for (int x = 0; x < len; x++)
				MyFile << temp2[x];
			//new line
			MyFile << "\n";


			std::cout << "Exported: id - " << temp << " , Student - " << predmet.get(temp) << "\n";
		}
		MyFile.close();
		system("pause");
	}
	else //if there are no students to be exported
	{
		std::cout << "There are no students enrolled, error exporting the students.";
		system("pause");
	}
}

void Menu::importFile()
{
	std::ifstream MyFile("studenti.txt");
	if (MyFile.is_open()) {
		while (MyFile >> idStudent >> lastName >> name)
		{
			if (predmet.isId(idStudent))//check the ID duplicitz
			{
				std::cout << "Student with ID: " << idStudent;
				std::cout << " was not imported. This student is already enrolled. \n";
			}
			else
			{
			wholeName = lastName + " " + name;
			predmet.add(idStudent, wholeName);
			arr.addSortAsc(idStudent);
			arrNotSorted.add(idStudent);
			//pokud by nebyli zapsani zadni studenti, nevypise se zadne hlaseni o importu
			std::cout << "Imported: id - " << idStudent << " , Student - " << lastName << " " << name << "\n";
			}
		}
	}
	MyFile.close();
	system("pause");
}


void Menu::runMenu() {

	do {
		system("cls");
		menuOptions();
		input = checkCinInt();
		switch (input)
		{
		case 1:
			enroll();
			break;
		case 2:
			delEnroll();
			break;
		case 3:
			findId();
			break;
		case 4:
			sortAsc();
			break;
		case 5:
			sortDesc();
			break;
		case 6:
			notSorted();
			break;
		case 7:
			exportFile();
			break;
		case 8:
			importFile();
			break;
		case 9:
			break;
		default:
			break;
		}
	} while (input != 9);
}

Menu::Menu()
{
	this->idStudent = 0;
	this->name = "NotSet";
	this->lastName = "NotSet";
	this->wholeName = name + lastName;

	// fillup();

	std::cout << "=================================================================\n";
	std::cout << "			Welcome\n";
	std::cout << "=================================================================\n";
	std::cout << "		This program is a school project\n";
	std::cout << "=================================================================\n";
	std::cout << "=================================================================\n";
	std::cout << " Author:\n";
	std::cout << "		Izajova Tatana\n";
	std::cout << "\n";

	system("pause");

	runMenu();

}


