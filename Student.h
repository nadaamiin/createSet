#ifndef CREATESET_STUDENT_H
#define CREATESET_STUDENT_H
#include <iostream>

using namespace std;
class Student {
private:
    string name;
    int id;
    int age;
public:
    // Default constructor with default values
    Student() : name("No name"), id(0), age(0){};
    // Parameterized constructor
    Student(string name, int id, int age) : name(std::move(name)), id(id),age(age) {}
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    friend ostream& operator<<(ostream& out, const Student& s);
};


#endif //CREATESET_STUDENT_H
