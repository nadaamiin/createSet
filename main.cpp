#include <iostream>
#include <vector>

using namespace std;

template<class T>
class set{
private:
    vector<T> vec;
public:
    bool exist(T& element) const{
        for (auto it = vec.begin(); it != vec.end() - 1; ++it) {
            if(*it == element)
                return true;
        }
        return false;
    }
    void add(T& element){
        if(!exist(element))
            vec.push_back(element);
    }
    void remove(T& element){
        vec.pop_back(element);
    }
};
int main(){


}