# Practical 6: Runtime Polymorphism and Abstract Classes in C++

## Aim
To understand runtime polymorphism and abstract classes in C++.

## Objective
To demonstrate runtime polymorphism using virtual functions and abstract classes.

## Concepts Used

1. **Polymorphism:** One interface with different behaviours.
2. **Runtime Polymorphism:** Function selection at runtime.
3. **Virtual Function:** Allows a derived class to override a base class function.
4. **Abstract Class:** A class containing at least one pure virtual function.
5. **Pure Virtual Function:** A virtual function declared using `= 0`.

## Program Description
The program creates a Shape base class and a Rectangle derived class. It uses virtual functions and a base class pointer to display the rectangle details and calculate its area.

## Software Used
- Visual Studio Code
- C++ Compiler (G++)

## Compile and Run
```bash
g++ main.cpp -o polymorphism
./polymorphism
```

## Result
Successfully implemented runtime polymorphism and abstract classes using virtual functions in C++.