#include "recursividade.hpp"
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

Recursividade::Recursividade() {};

void Recursividade::print_txt(char *text, int num)
{
    if (num <= 0)
        return;
    cout << text << endl;
    print_txt(text, num - 1);
}

void Recursividade::count(int num)
{
    if (num <= 0)
        return;
    count_helper(0, 50);
    count(num - 1);
}

void Recursividade::count_helper(int current, int max)
{
    if (current > max)
        return;
    cout << current << " ";
    count_helper(current + 1, max);
}

void Recursividade::count_max(int num, int max)
{
    if (num <= 0)
        return;
    count_max_helper(0, max);
    cout << endl;
    count_max(num - 1, max);
}

void Recursividade::count_max_helper(int current, int max)
{
    if (current > max)
        return;
    cout << current << " ";
    count_max_helper(current + 1, max);
}

void Recursividade::print_vec(vector<int> &vec, int idx)
{
    if (idx >= vec.size())
        return;
    cout << vec[idx] << " ";
    print_vec(vec, idx + 1);
}

void Recursividade::print_even(vector<int> &vec, int idx)
{
    if (idx < 0)
        return;
    if (vec[idx] % 2 == 0)
    {
        cout << vec[idx] << " ";
    }
    print_even(vec, idx - 1);
}

void Recursividade::print_list(list<int> &lst, list<int>::iterator &it)
{
    if (it == lst.end())
        return;
    cout << *it << " ";
    ++it;
    print_list(lst, it);
}

void Recursividade::print_rev(forward_list<int> &lst, forward_list<int>::iterator &it)
{
    if (it == lst.end())
        return;
    auto next_it = it;
    ++next_it;
    print_rev(lst, next_it);
    cout << *it << " ";
}

void Recursividade::remove_all(vector<int> &vec)
{
    if (vec.empty())
        return;
    vec.pop_back();
    remove_all(vec);
}

void Recursividade::print_stack(stack<int> &stk)
{
    if (stk.empty())
        return;
    int element = stk.top();
    stk.pop();
    print_stack(stk);
    cout << element << " ";
    stk.push(element);
}

void Recursividade::push_to(stack<int> &stk1, stack<int> &stk2)
{
    if (stk1.empty())
        return;
    int element = stk1.top();
    stk1.pop();
    push_to(stk1, stk2);
    stk2.push(element);
}

void Recursividade::copy(vector<int> &vec1, int idx, vector<int> &vec2)
{
    if (idx >= vec1.size())
        return;
    vec2.push_back(vec1[idx]);
    copy(vec1, idx + 1, vec2);
}

void Recursividade::copy(list<int> &list1, list<int>::iterator &it, list<int> &list2)
{
    if (it == list1.end())
        return;
    list2.push_back(*it);
    ++it;
    copy(list1, it, list2);
}