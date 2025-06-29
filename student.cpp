#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student{
	int rollNo;
	string name;
	float marks;
};

void addStudent(){
	ofstream outfile("students.txt",ios::app);
	Student s;
	cout << "Enter Roll Number:- ";
	cin >> s.rollNo;
	cin.ignore();
	cout << "Enter Your Name:- ";
	getline(cin, s.name);
	cout << "Enter Your Marks:- ";
	cin >> s.marks;
	
	outfile << s.rollNo << ", " << s.name << ", " << s.marks << endl;
	outfile.close();
	cout << "Student record Added!\n\n";
}

void displayStudents(){
	ifstream infile("students.txt");
	Student s;
	cout << "\n------ All Students Data -----\n";
	while(infile >> s.rollNo){
		infile.ignore();
		getline(infile, s.name, ',');
		infile >> s.marks;
		cout << "Roll No:- " << s.rollNo << ", Name:- " << s.name << ", Marks:- " << s.marks << endl;
 	}
 	infile.close();
}

void searchStudent(){
	ifstream infile("students.txt");
	int target;
	bool found = false;
	Student s;
	cout << "Enter Roll No. to Search:- ";
	cin >> target;
	while(infile >> s.rollNo){
		if(s.rollNo == target){
			infile.ignore();
			getline(infile, s.name, ',');
			infile >> s.marks;
			cout << "\n-----";
			cout << "Found: " << s.name << " with Marks: " << s.marks << endl;
			found = true;
			break;
		}
	}
	if(!found){
		cout << "\nDid not found Student with Roll No. " << target << endl;
	}
	infile.close();
}

void deleteStudent(){
	ifstream infile("students.txt");
	ofstream tempfile("temp.txt");
	int target;
	bool found = false;
	Student s;
	cout << "Enter Roll no. to Delete:- ";
	cin >> target;
	while(infile >> s.rollNo){
		infile.ignore();
		getline(infile, s.name, ',');
		infile >> s.marks;
		if(s.rollNo != target){
			tempfile << s.rollNo << ", " << s.name << ", " << s.marks << endl;
		}else{
			found = true;
		}
	}
	infile.close();
	tempfile.close();
	
	remove("students.txt");
	rename("temp.txt", "students.txt");
	
	if(found){
		cout << "\nRecord Deleted for Roll no. " << target << "\n";
	}else{
		cout << "\nCannot Found Record for Roll no. " << target << "\n";
	}
}

int main(){
	int choice;
	do {
		cout << "\n-----Student Record System-----\n";
		cout << "1. Add Student.\n";
		cout << "2. Display All Students.\n";
		cout << "3. Search Student by Roll Number.\n";
		cout << "4. Delete Student.\n";
		cout << "5. Exit.\n";
		cout << "Please Enter your Choice:- ";
		cin >> choice;
		
		switch(choice){
			case 1:
				addStudent();
				break;
			case 2:
				displayStudents();
				break;
			case 3:
				searchStudent();
				break;
			case 4:
				deleteStudent();
				break;
			case 5:
				cout << "Exiting... \n";
				break;
			default:
				cout << "Invalid Choice. Enter Correct Choice.\n";
		}
	}while(choice != 5);
	return 0;
}
