

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// Custom exception
class InvalidStudentData : public runtime_error {
public:
    InvalidStudentData(const string& message)
        : runtime_error(message) {}
};

class StudentNotFound : public runtime_error {
public:
    StudentNotFound(const string& message)
        : runtime_error(message) {}
};

// Base class
class Person {
protected:
    string name;

public:
    Person(const string& n) {
        if (n.empty() || n.find('|') != string::npos)
            throw InvalidStudentData("Invalid name.");

        name = n;
    }

    virtual void display() const = 0;

    virtual ~Person() {}
};

// Derived class
class Student : public Person {
private:
    int id;
    string course;
    double marks;

public:
    Student(int i, const string& n,
            const string& c, double m)
        : Person(n) {

        if (i <= 0)
            throw InvalidStudentData("ID must be positive.");

        if (c.empty() || c.find('|') != string::npos)
            throw InvalidStudentData("Invalid course.");

        if (m < 0 || m > 100)
            throw InvalidStudentData("Marks must be between 0 and 100.");

        id = i;
        course = c;
        marks = m;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getCourse() const {
        return course;
    }

    double getMarks() const {
        return marks;
    }

    string getGrade() const {
        if (marks >= 75)
            return "Distinction";
        else if (marks >= 60)
            return "First Class";
        else if (marks >= 40)
            return "Pass";
        else
            return "Fail";
    }

    void display() const override {
        cout << "\nStudent ID : " << id;
        cout << "\nName       : " << name;
        cout << "\nCourse     : " << course;
        cout << "\nMarks      : " << marks;
        cout << "\nGrade      : " << getGrade();
        cout << "\n--------------------------\n";
    }
};

// Student Portal class
class StudentPortal {
private:
    vector<Student> students;
    const string filename = "Practical 12/students.txt";

public:

    // Load records from file
    void loadStudents() {
        ifstream file(filename);

        if (!file) {
            return;
        }

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string idText, name, course, marksText;

            if (!getline(ss, idText, '|') ||
                !getline(ss, name, '|') ||
                !getline(ss, course, '|') ||
                !getline(ss, marksText)) {
                throw runtime_error("Invalid record in file.");
            }

            try {
                int id = stoi(idText);
                double marks = stod(marksText);

                bool duplicate = false;

                for (const Student& s : students) {
                    if (s.getId() == id) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate) {
                    students.emplace_back(
                        id, name, course, marks
                    );
                }

            } catch (const exception&) {
                throw runtime_error("Invalid student data in file.");
            }
        }

        file.close();
    }

    // Save records to file
    void saveStudents() const {
        ofstream file(filename);

        if (!file)
            throw runtime_error("Unable to save records.");

        for (const Student& s : students) {
            file << s.getId() << "|"
                 << s.getName() << "|"
                 << s.getCourse() << "|"
                 << s.getMarks() << "\n";
        }

        file.close();
    }

    // Add a student
    void addStudent() {
        try {
            int id;
            double marks;
            string name, course;

            cout << "\nEnter Student ID: ";
            if (!(cin >> id))
                throw InvalidStudentData("Invalid ID.");

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (const Student& s : students) {
                if (s.getId() == id)
                    throw InvalidStudentData("ID already exists.");
            }

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Course: ";
            getline(cin, course);

            cout << "Enter Marks (0-100): ";
            if (!(cin >> marks))
                throw InvalidStudentData("Invalid marks.");

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            students.emplace_back(id, name, course, marks);

            saveStudents();

            cout << "\nStudent added successfully!\n";
        }
        catch (const InvalidStudentData& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError: " << e.what() << "\n";
        }
        catch (const exception& e) {
            cout << "\nError: " << e.what() << "\n";
        }
    }

    // Display all students
    void displayStudents() const {
        if (students.empty()) {
            cout << "\nNo student records available.\n";
            return;
        }

        cout << "\n===== STUDENT RECORDS =====\n";

        for (const Student& s : students) {
            s.display();
        }
    }

    // Search student by ID
    void searchStudent() const {
        int id;

        cout << "\nEnter Student ID: ";

        if (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid ID.\n";
            return;
        }

        for (const Student& s : students) {
            if (s.getId() == id) {
                cout << "\nStudent Found!\n";
                s.display();
                return;
            }
        }

        try {
            throw StudentNotFound("Student record not found.");
        }
        catch (const StudentNotFound& e) {
            cout << "\nError: " << e.what() << "\n";
        }
    }
};

// Main function
int main() {
    StudentPortal portal;

    try {
        portal.loadStudents();
        cout << "Student records loaded successfully.\n";
    }
    catch (const exception& e) {
        cout << "File Error: " << e.what() << "\n";
        return 1;
    }

    int choice;

    do {
        cout << "\n========== STUDENT PORTAL ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPlease enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                portal.addStudent();
                break;

            case 2:
                portal.displayStudents();
                break;

            case 3:
                portal.searchStudent();
                break;

            case 4:
                cout << "\nThank you for using Student Portal!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
