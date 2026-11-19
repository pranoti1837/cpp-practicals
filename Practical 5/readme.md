# Practical 5: Single and Multilevel Inheritance in C++

## Aim
To understand single and multilevel inheritance in C++.

## Objective
To demonstrate how one class can inherit the properties and functions of another class.

## Concepts Used

1. **Inheritance:** Allows a class to acquire properties of another class.
2. **Base Class:** The parent class.
3. **Derived Class:** The child class.
4. **Single Inheritance:** One derived class inherits from one base class.
5. **Multilevel Inheritance:** A class inherits from a derived class, forming multiple levels.

## Program Description
The program uses three classes: Person, Student and Result. The Student class inherits from Person, and the Result class inherits from Student. It accepts and displays student details and marks.

## Software Used
- Visual Studio Code
- C++ Compiler (G++)

## Compile and Run
```bash
g++ main.cpp -o inheritance
./inheritance
```

## Result
Successfully implemented single and multilevel inheritance in C++.