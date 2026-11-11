#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    explicit Person(string n = "Unknown") : name(n) {}
};

class Student : virtual public Person {
public:
    double cgpa = 0.0;
};

class Staff : virtual public Person {
public:
    string department = "General";
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, double g, string d)
        : Person(n), Student(), Staff() {
        cgpa = g;
        department = d;
    }
};

int main() {
    TeachingAssistant ta("Kavya", 8.7, "CSE");

    cout << "Name: " << ta.name << '\n';
    cout << "CGPA: " << ta.cgpa << '\n';
    cout << "Department: " << ta.department << '\n';

    return 0;
}


<img width="132" height="53" alt="image" src="https://github.com/user-attachments/assets/a93523d1-ea37-4809-84ed-5bf20de92f2c" />
