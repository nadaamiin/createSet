#include <iostream>
#include <vector>
#include <algorithm>

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
        T* arr = new T(vec.size());
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
int main(){
    set<double> s;
    s.insert(6.6);
    s.insert(7);
    cout << s.size() << endl;
    s.erase(7);
    s.print();
    cout << s.size() << endl;

    double* arr = s.array();
    cout << "Array contents: ";
    for (int i = 0; i < s.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free allocated memory
}