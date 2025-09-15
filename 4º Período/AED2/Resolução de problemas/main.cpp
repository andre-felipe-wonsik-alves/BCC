#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
bool haRepetidos(vector<T> &v){
    sort(v.begin(), v.end());

    for(int i = 0; i<v.size() - 1;i++){
        if(v[i] == v[i+1]) return true;

    }

    return false;
}

template<typename T>
T KesimoMaior(vector<T> &v, int k){
    sort(v.begin(), v.end());

    return v[v.size()-k];
}
int main(){
    vector<int> v = { 1, 8, 0, 9, 4, 2};
    vector<int> u = { 6, 0, 9, 2, 8, 1, 1};
    vector<string> s = {"banana", "melão",
    "mamão", "melão"};

    cout << haRepetidos(v) << "\n";
    cout << haRepetidos(u) << "\n";
    cout << haRepetidos(s) << "\n";
}