#include "Student.h"

using namespace std;
// Overload == operator for Student class
bool Student::operator==(const Student& other) const{
    return (name == other.name) && (id == other.id) && (age == other.age);
}
// Overload != operator for Student class
bool Student::operator!=(const Student& other) const{
    return (name != other.name) && (id != other.id) && (age != other.age);
}
// Overloads << operator for the Student class to print its attributes.
ostream& operator<<(ostream& out, const Student& s) {
    out << '[' << s.name << ", " << s.id << ", " << s.age << "]";
    return out;
}

