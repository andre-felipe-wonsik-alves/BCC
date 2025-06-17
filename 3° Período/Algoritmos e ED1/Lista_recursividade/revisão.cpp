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

void print_rev(const forward_list<int> &lst)
{
    print_rev_recursive(lst.begin(), lst.end());
    cout << endl;
}

int main()
{
    // print_txt("receba", 0);
    // count(2);
    // count_max(2, 10);
    // vector<int> v1 = {1, 2, 3, 4, 6, 6, 6};
    // list<int> l1 = {1, 2, 3, 4, 4, 5};
    forward_list<int> fl1 = {1, 2, 3, 4, 4, 5};
    // list<int>::iterator it = l1.begin();
    forward_list<int>::iterator it = fl1.end();
    // print_vec(v1, 0);
    // print_even(v1, 0);
    // print_list(l1, it);
    print_rev(fl1, it);

    return 0;
}