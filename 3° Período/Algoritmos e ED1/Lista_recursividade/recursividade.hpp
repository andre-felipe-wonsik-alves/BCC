#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Recursividade
{
public:
    Recursividade();
    void print_txt(char *text, int num);
    void count(int num);
    void count_helper(int num, int max);
    void count_max(int num, int max);
    void count_max_helper(int num, int max);
    void print_vec(vector<int> &vec, int idx);
    void print_even(vector<int> &vec, int idx);
    void print_list(list<int> &lst, list<int>::iterator &it);
    void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it);
    void remove_all(vector<int> &vec);
    void print_stack(stack<int> &stk);
    void push_to(stack<int> &stk1, stack<int> &stk2);
    void copy(vector<int> &vec1, int idx, vector<int> &ec2);
    void copy(list<int> &list1, list<int>::iterator &it, list<int> &list2);
};