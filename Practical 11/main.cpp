
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("students.csv");

    if (!file)
    {
        cout << "Error creating file!" << endl;
        return 1;
    }

    file << "Name,RollNo,Marks\n";
    file << "Pranoti,101,85\n";
    file << "Amit,102,90\n";
    file << "Riya,103,78\n";

    file.close();

    cout << "Student records saved successfully." << endl;

    ifstream readFile("students.csv");
    string line;

    cout << "\nStudent Records:\n";

    while (getline(readFile, line))
    {
        cout << line << endl;
    }

    readFile.close();

    return 0;
}
