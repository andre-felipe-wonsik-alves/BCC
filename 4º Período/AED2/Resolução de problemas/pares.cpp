#include <utility>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

std::pair<int,int> twosum(const vector<int>& v, int k){
    vector<int> v2 = v;

    sort(v2.begin(), v2.end());

    int esq = 0, dir = v2.size()-1;
    while(esq != dir){
        if(v2[esq] + v2[dir] == k) return make_pair(v2[esq], v2[dir]);
        if(v2[esq] + v2[dir] > k){
            dir--;
        }
        else{
            esq++;
        }
    }
    return make_pair(-1,-1);
}

int main(){
    vector<int> v = {9, 14, 2, 1, 17, 10};
    int k = 27;
    std::pair<int,int> p = twosum(v, k);
    cout << p.first << " + " << p.second << "\n";
}
