#include <iostream>
#include <string>
#include <vector>

class Student {
    private:
       std::string name;
       int RollNumber;
       float marks;

    public:
       void input() {
              std::cout << "Enter student name: ";
              std::getline(std::cin, name);
              std::cout << "Enter roll number: ";
              std::cin >> RollNumber;
              std::cout << "Enter marks: ";
              std::cin >> marks;
         }
        void display() {
                std::cout << "Name: " << name << std::endl;
                std::cout << "Roll Number: " << RollNumber << std::endl;
                std::cout << "Marks: " << marks << std::endl;
        }
        int getRollNumber() {
                return RollNumber;
        }
};

std::vector<Student> students;

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    std::cout << "Student added successfully!" << std::endl;
}

void displayStudents() {
    if (students.empty()) {
        std::cout << "Student Record not found." << std::endl;
        return;
    }
    for (Student s : students) {
        s.display();
        std::cout << "-------------------" << std::endl;
    }
}

void searchStudent() {
    int rollNumber;
    std::cout << "Enter roll number to search: ";
    std::cin >> rollNumber;
    for (Student s : students) {
        if (s.getRollNumber() == rollNumber) {
            s.display();
            return;
        }
    }
    std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
}
int main() {

    int choice;

    do {
        std::cout << "--Student Management System--" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Display Students" << std::endl;
        std::cout << "3. Search Student" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {

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
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 3);
    return 0;
}