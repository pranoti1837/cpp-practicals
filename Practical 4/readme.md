
# Practical 4: RAII and Smart Pointers in C++

## Aim
To understand RAII and smart pointers in C++.

## Objective
To demonstrate automatic memory management using unique_ptr and shared_ptr.

## Concepts Used

1. **RAII:** Resource Acquisition Is Initialization. Resources are managed according to object lifetime.
2. **Smart Pointer:** Automatically manages dynamically allocated memory.
3. **unique_ptr:** Allows only one owner of an object.
4. **shared_ptr:** Allows multiple owners of an object.
5. **Destructor:** Automatically runs when an object is destroyed.

## Program Description
The program creates Student objects using unique_ptr and shared_ptr. It displays student details and demonstrates shared pointer reference counting.

## Software Used
- Visual Studio Code
- C++ Compiler (G++)

## Compile and Run
```bash
g++ main.cpp -o smartpointer
./smartpointer
```

## Result
Successfully demonstrated RAII and smart pointers for automatic memory management in C++.