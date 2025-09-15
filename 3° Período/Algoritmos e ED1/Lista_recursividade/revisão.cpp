#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void print_txt(char *text, int num)
{
    if (num < 10)
    {
        cout << text << endl;
        num++;
        print_txt(text, num);
    }
    return;
}

void count_to_50(int elem)
{
    if (elem > 50)
        return;

    cout << elem << ", ";
    elem++;
    count_to_50(elem);
}

void count(int num)
{
    if (num > 0)
    {
        count_to_50(0);
        cout << endl;
        num--;
        count(num);
    }
}

void count_to_max(int elem, int max)
{
    if (elem <= max)
    {
        cout << elem << ", ";
        elem++;
        count_to_max(elem, max);
    }
}

void count_max(int num, int max)
{
    if (num > 0)
    {
        count_to_max(0, max);
        cout << endl;
        num--;
        count_max(num, max);
    }
}

void print_vec(vector<int> &vec, int idx)
{
    if (idx >= vec.size())
        return;

    cout << vec[idx] << ", ";
    idx++;
    print_vec(vec, idx);
}

void print_even(vector<int> &vec, int idx)
{
    if (idx >= vec.size())
        return;

    int last_idx = vec.size() - 1;
    // cout << idx << ", ";

    if (!(vec[last_idx - idx] % 2))
        cout << vec[last_idx - idx] << ", ";

    idx++;
    print_even(vec, idx);
}

void print_list(list<int> &lst, list<int>::iterator &it)
{
    if (it != lst.end())
    {
        cout << *it << ", ";
        it++;
        print_list(lst, it);
    }
}

void print_rev_recursive(forward_list<int>::iterator current_it, forward_list<int>::iterator end_it)
{
    if (current_it == end_it)
    {
        return;
    }

    forward_list<int>::iterator next_it = current_it;
    ++next_it;

    // Chama recursivamente para os elementos restantes
    print_rev_recursive(next_it, end_it);

    // Imprime o elemento atual depois que todos os elementos seguintes foram impressos
    cout << *current_it << " ";
}

// void print_rev(const forward_list<int> &lst)
// {
//     print_rev_recursive(lst.begin(), lst.end());
//     cout << endl;
// }

void remove_all(vector<int> &vec)
{
    if (vec.size() <= 0)
        return;

    vec.pop_back();
    remove_all(vec);
}

void print_stack(stack<int> stack)
{
    if (stack.size() <= 0)
        return;
    cout << stack.top() << endl;
    stack.pop();
    print_stack(stack);
}
void push_to(stack<int> &stk1, stack<int> &stk2)
{
    if (stk1.size() <= 0)
        return;
    int elem = stk1.top();
    stk1.pop();
    stk2.push(elem);

    push_to(stk1, stk2);
}

void copy(vector<int> &vec1, int idx, vector<int> &vec2)
{
    if (idx >= (vec1.size() - 1))
        return;

    vec2.push_back(vec1[idx]);
    copy(vec1, ++idx, vec2);
}

void copy(list<int> &list1, list<int>::iterator &it, list<int> &list2)
{
    if (it == list1.end())
        return;

    list2.push_back(*it);
    copy(list1, ++it, list2);
}

int main()
{
    // print_txt("receba", 0);
    // count(2);
    // count_max(2, 10);
    vector<int> v1 = {1, 2, 3, 4, 6, 6, 6};
    vector<int> v2;
    // stack<int> s1;
    // stack<int> s2;
    // s1.push(1);
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.push(5);
    list<int> l1 = {1, 2, 3, 4, 4, 5};
    list<int> l2;
    // forward_list<int> fl1 = {1, 2, 3, 4, 4, 5};
    // list<int>::iterator it = l1.begin();
    // forward_list<int>::iterator it = fl1.end();
    // print_vec(v1, 0);
    // print_even(v1, 0);
    // print_list(l1, it);
    // print_rev(fl1, it);
    // remove_all(v1);
    // cout << v1.size() << endl;
    // push_to(s1, s2);
    // print_stack(s2);
    // copy(v1, 0, v2);
    // print_vec(v2, 0);
    copy(l1, l1.begin(), l2);
    print_list(l2, l2.begin());
    return 0;
}