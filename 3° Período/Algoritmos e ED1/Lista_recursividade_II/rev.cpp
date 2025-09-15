#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int sum(vector<int> &vec, int n)
{
    if (n <= 0)
        return 0; // condicao de parada

    int pos = vec.size() - n;
    int soma = 0;

    if (!(vec[pos] % 2))
    {
        return soma += vec[pos] + sum(vec, --n);
    }
    soma = sum(vec, --n);
    return soma;
}

int product(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
        return 1;

    int current = *it;
    ++it;
    return current * product(lst, it);
}

int min(vector<int> &vec, int n)
{
    if (n <= 0)
        return vec.back();
    int minimum = min(vec, --n);
    if (vec[(vec.size() - 1 - n)] < minimum)
    {
        return minimum = vec[(vec.size() - 1 - n)];
    }

    return minimum;
}

bool find(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
        return false;

    if (vec[vec.size() - n] == elem)
    {
        return true;
    }
    return find(vec, --n, elem);
}

int count(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
        return 0;
    int occ = 0;

    if (vec[vec.size() - n] == elem)
    {
        occ++;
    }
    return occ += count(vec, --n, elem);
}

void reverse(vector<int> &vec, int first, int last)
{
    if (first >= last)
        return;

    swap(vec[first], vec[last]);
    reverse(vec, ++first, --last);
}

bool palindrome(string &str, int first, int last)
{
    if (first >= last)
    {
        return true;
    }
    if (str[first] == str[last])
    {
        return palindrome(str, ++first, --last);
    }
    return false;
}

bool list_palindrome(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    if (first == last)
        return true;
    auto prev = last;
    --prev;
    if (first == prev)
        return true;
    if (*first != *prev)
        return false;
    return list_palindrome(lst, ++first, prev);
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    list<int> l1 = {1, 2, 3, 3, 2, 1};
    cout << sum(v1, 4) << endl;
    cout << product(l1, l1.begin());
    cout << min(v1, 4) << endl;
    cout << find(v1, 4, 2) << endl;
    cout << count(v1, 4, 4) << endl;
    reverse(v1, 0, 3);
    for (int elem : v1)
    {
        cout << elem << " ";
    }
    cout << endl;
    string palindromo = "banana";
    cout << palindrome(palindromo, 0, 4) << endl;
    cout << list_palindrome(l1, l1.begin(), l1.end()) << endl;
    return 0;
}