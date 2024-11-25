#include "Student.h"

using namespace std;
bool Student::operator==(const Student& other) const{
    return (name == other.name) && (id == other.id) && (age == other.age);
}
bool Student::operator!=(const Student& other) const{
    return (name != other.name) && (id != other.id) && (age != other.age);
}

