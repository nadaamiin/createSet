#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;
// Using template to extend its usage for all data types
template<class T>
class set{
private:
    // Create a vector of template type
    vector<T> vec;
public:
    // Check if an element exist or not
    bool exist(const T& element) const{
        // Iterate through the vector and compares each element with the input.
        return any_of(vec.begin(), vec.end(), [&](const T& i) { return i == element; });
    }
    // Add element to the set
    void insert(const T& element){
        // Check if the element exist or not to avoid duplicates
        if(!exist(element))
            vec.push_back(element);
    }
    // Remove element from the set
    void erase(const T& element){
        // Loop on the vector
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            // Check if the element is in the vector
            if(*it == element){
                // Erase if exist
                vec.erase(it);
                return;
            }
        }
    }
    // Return size of the set
    int size() const{
        return vec.size();
    }
    // Create a dynamically allocated array that contains the elements of the set
    T* array() const{
        T* arr = new T[(vec.size())];
        // Copy each element in the vector to the array
        for (int i = 0; i < vec.size(); ++i) {
            arr[i] = vec[i];
        }
        return arr;
    }
    // Function to print the set elements
    void print() const{
        for (const auto& it : vec) {
            cout << it << " ";
        }
        cout << endl;
    }
};
int main() {
    set<int> set1;
    set1.insert(400);
    set1.insert(300);
    set1.insert(500);
    set1.insert(900);
    set1.insert(900); // Duplicate, so won't add
    set1.print();
    cout << "size = " << set1.size() << endl;
    set1.erase(100); // the set doesn't contain 100, so it will do nothing
    set1.erase(300);
    set1.print();
    cout << "size = " << set1.size() << endl;

    cout << set1.exist(100) << endl;
    cout << set1.exist(500) << endl;

    int *arr1 = set1.array();
    cout << "Contents of array: ";
    for (int i = 0; i < set1.size(); ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    delete[] arr1; // Free allocated memory

    cout << "------------------------------------------------------------------\n";

    set<double> set2;
    set2.insert(6.6);
    set2.insert(7.9);
    set2.print();
    cout << "size = " << set2.size() << endl;
    set2.erase(7.9);
    set2.erase(999.4); // the set doesn't contain 999.4, so it will do nothing
    set2.print();
    cout << "size = " << set2.size() << endl;

    double *arr2 = set2.array();
    cout << "Contents of array: ";
    for (int i = 0; i < set2.size(); ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    delete[] arr2; // Free allocated memory

    cout << "------------------------------------------------------------------\n";

    set<string> set3;
    set3.insert("C++");
    set3.insert("Python");
    set3.insert("Python"); // Duplicate, so won't add
    set3.insert("Java");
    set3.insert("SQL");
    set3.print();
    cout << "size = " << set3.size() << endl;
    set3.erase("Java");
    set3.print();
    cout << "size = " << set3.size() << endl;

    cout << set3.exist("Python") << endl;
    cout << set3.exist("Java") << endl;

    string *arr3 = set3.array();
    cout << "Contents of array: ";
    for (int i = 0; i < set3.size(); ++i) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    delete[] arr3; // Free allocated memory

    cout << "------------------------------------------------------------------\n";

    set<char> set4;
    set4.insert('n');
    set4.insert('b');
    set4.insert('v');
    set4.insert('v'); // Duplicate, so won't add
    set4.insert('m');
    set4.print();
    cout << "size = " << set4.size() << endl;
    set4.erase('v');
    set4.print();
    cout << "size = " << set4.size() << endl;

    cout << set4.exist('v') << endl;
    cout << set4.exist('b') << endl;

    char *arr4 = set4.array();
    cout << "Contents of array: ";
    for (int i = 0; i < set4.size(); ++i) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    delete[] arr4; // Free allocated memory

    cout << "------------------------------------------------------------------\n";

    set<bool> set5;
    set5.insert(true);
    set5.insert(true); // Duplicate, so won't add
    set5.insert(false);
    set5.insert(false); // Duplicate, so won't add
    set5.print();
    cout << "size = " << set5.size() << endl;
    set5.erase(false);
    set5.print();
    cout << "size = " << set5.size() << endl;

    bool *arr5 = set5.array();
    cout << "Contents of array: ";
    for (int i = 0; i < set5.size(); ++i) {
        cout << arr5[i] << " ";
    }
    cout << endl;

    delete[] arr5; // Free allocated memory

    cout << "------------------------------------------------------------------\n";

    set<Student> students;

    Student s1("Nada", 20230440, 18);
    Student s2("Menna", 20230571, 19);
    Student s3("Safia", 20231088, 18);
    Student s4("Safia", 20231088, 18);

    students.insert(s1);
    students.insert(s2);
    students.insert(s3);
    students.insert(s4); // Duplicate, so won't add

    students.print();
    cout << "size = " << students.size() << endl;

    students.erase(s1);
    students.print();

    cout << students.exist(s1) << endl;
    cout << students.exist(s2) << endl;
    cout << "size = " << students.size() << endl;

    Student *arr_stud = students.array();
    cout << "Contents of array: ";
    for (int i = 0; i < students.size(); ++i) {
        cout << arr_stud[i] << " ";
    }
    cout << endl;

    delete[] arr_stud; // Free allocated memory

}