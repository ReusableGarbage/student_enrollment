# Student Enrollment
## C++ console project implementing:
###### - Binary Search Tree (BST.h, BST.cpp, Node.h, Node.cpp)
###### - Dynamic Array (ArrDynamicky.h, ArrDynamicky.cpp)
###### - Custom String Class (StringCustom.h, StringCustom.cpp)

This is a student project made to practice C++ by manually implementing
Binary Search Tree (**BST**) to store and order students enrolling into a class. Each node of the tree represents a student.

Nodes are differentiated by the **Student ID** and duplicity is not permitted. 
Each node also contains a **Student Name** which is implemeted by a custom string class.
Enrolled students can later be listed in the order of their ID, or in the order of enrollment.
This is implemented through Dynamic Arrays.

> Please do not use **Custom String Class** in any serious projects, this class was made for practice only. <br>
There is a reason, why most people use std:: string.

For testing the functionality Console Application was implemented. This console app is implemented in Menu.cpp and Menu.h

**Console application allows to:**
1.		Enroll a student
2.		Delete a student
3.		Find a student by their ID
4.		List enrolled students in the ascending order
5.		List enrolled students in the descending order
6.		List enrolled students in the order of their enrollement
7.		Export students into a text file
8.		Import students from a text file
