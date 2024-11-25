#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;
template<class T>
class set{
private:
    vector<T> vec;
public:
    bool exist(const T& element) const{
        return any_of(vec.begin(), vec.end(), [&](const T& i) { return i == element; });
    }
    void insert(const T& element){
        if(!exist(element))
            vec.push_back(element);
    }
    void erase(const T& element){
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if(*it == element){
                vec.erase(it);
                return;
            }
        }
    }
    int size() const{
        return vec.size();
    }
    T* array() const{
        T* arr = new T[(vec.size())];
        for (int i = 0; i < vec.size(); ++i) {
            arr[i] = vec[i];
        }
        return arr;
    }
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
    cout << set1.size() << endl;
    set1.erase(100);
    set1.erase(300);
    set1.print();
    cout << set1.size() << endl;

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
    cout << set2.size() << endl;
    set2.erase(7.9);
    set2.print();
    cout << set2.size() << endl;

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
    set3.insert("Java");
    set3.insert("SQL");
    cout << set3.size() << endl;
    set3.erase("Java");
    set3.print();
    cout << set3.size() << endl;

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

    set<Student> students;

    Student s1("Nada", 20230440, 18);
    Student s2("Menna", 20230571, 19);
    Student s3("Safia", 20231088, 18);

    students.insert(s1);
    students.insert(s2);
    students.insert(s3);
    students.insert(s3);

    students.print();

    students.erase(s1);
    students.print();

    cout << students.exist(s1) << endl;
    cout << students.exist(s2) << endl;

    cout << endl;

}