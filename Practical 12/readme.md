# Practical 12: Student Portal

## Aim
To develop a console-based Student Portal using C++ concepts such as OOP, inheritance, polymorphism, STL, exception handling and file handling.

## Features
1. Add student records.
2. Display all student records.
3. Search students using Student ID.
4. Calculate student grades.
5. Save student records in a text file.
6. Load previously saved records.
7. Validate student details.
8. Handle errors using custom exceptions.

## OOP Concepts Used
- **Class and Objects:** Person, Student and StudentPortal.
- **Encapsulation:** Private data members.
- **Inheritance:** Student inherits from Person.
- **Polymorphism:** Virtual display() function.
- **Constructors:** Initialize student details.

## STL
The vector container stores student records in memory.

## Exception Handling
Custom exceptions:
- InvalidStudentData
- StudentNotFound

## File Handling
Student records are saved in `students.txt` and loaded when the application starts.

## Grade Calculation
| Marks | Grade |
|---|---|
| 75–100 | Distinction |
| 60–74 | First Class |
| 40–59 | Pass |
| Below 40 | Fail |

## Compilation
```bash
g++ -std=c++17 main.cpp -o studentportal
```

## Execution
```bash
./studentportal
```

## Conclusion
The Student Portal successfully demonstrates object-oriented programming, STL containers, exception handling and file handling through a console-based C++ application.