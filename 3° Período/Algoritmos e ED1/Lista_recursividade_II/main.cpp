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
        return 0;

    if ((n - 1) % 2 == 0)
    {
        return vec[n - 1] + sum(vec, n - 1);
    }
    else
    {
        return sum(vec, n - 1);
    }
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
    if (n == 1)
        return vec[0];

    int minRest = min(vec, n - 1);
    return (vec[n - 1] < minRest) ? vec[n - 1] : minRest;
}

int min(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
        return lst.back();

    auto next_it = it;
    ++next_it;

    if (next_it == lst.end())
        return *it;

    int minRest = min(lst, next_it);
    return (*it < minRest) ? *it : minRest;
}

bool find(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
        return false;

    if (vec[n - 1] == elem)
        return true;
    return find(vec, n - 1, elem);
}

int count(vector<int> &vec, int n, int elem)
{
    if (n <= 0)
        return 0;

    int countRest = count(vec, n - 1, elem);
    if (vec[n - 1] == elem)
    {
        return 1 + countRest;
    }
    else
    {
        return countRest;
    }
}

void reverse(vector<int> &vec, int first, int last)
{
    if (first >= last)
        return;

    int temp = vec[first];
    vec[first] = vec[last];
    vec[last] = temp;

    reverse(vec, first + 1, last - 1);
}

void reverse(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    if (first == last)
        return;

    auto prev_last = last;
    --prev_last;

    if (first == prev_last)
        return;

    int temp = *first;
    *first = *prev_last;
    *prev_last = temp;

    ++first;
    reverse(lst, first, prev_last);
}

bool palindrome(string &str, int first, int last)
{
    if (first >= last)
        return true;

    if (str[first] != str[last])
        return false;

    return palindrome(str, first + 1, last - 1);
}

bool palindrome(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    if (first == last)
        return true;

    auto prev_last = last;
    --prev_last;

    if (first == prev_last)
        return true;

    if (*first != *prev_last)
        return false;

    ++first;
    return palindrome(lst, first, prev_last);
}

int main()
{
    cout << "=== Testando as funções recursivas ===" << endl;

    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    cout << "1. Soma posições pares: " << sum(vec1, vec1.size()) << endl;

    list<int> lst1 = {2, 3, 4};
    cout << "2. Produto da lista: " << product(lst1, lst1.begin()) << endl;

    vector<int> vec2 = {5, 2, 8, 1, 9};
    cout << "3. Menor elemento do vector: " << min(vec2, vec2.size()) << endl;

    list<int> lst2 = {5, 2, 8, 1, 9};
    cout << "4. Menor elemento da lista: " << min(lst2, lst2.begin()) << endl;

    vector<int> vec3 = {1, 2, 3, 4, 5};
    cout << "5. Elemento 3 encontrado: " << (find(vec3, vec3.size(), 3) ? "Sim" : "Não") << endl;
    cout << "5. Elemento 7 encontrado: " << (find(vec3, vec3.size(), 7) ? "Sim" : "Não") << endl;

    vector<int> vec4 = {1, 2, 3, 2, 2, 5};
    cout << "6. Ocorrências do número 2: " << count(vec4, vec4.size(), 2) << endl;

    vector<int> vec5 = {1, 2, 3, 4, 5};
    cout << "7. Vector original: ";
    for (int x : vec5)
        cout << x << " ";
    reverse(vec5, 0, vec5.size() - 1);
    cout << "\n   Vector invertido: ";
    for (int x : vec5)
        cout << x << " ";
    cout << endl;

    list<int> lst3 = {1, 2, 3, 4, 5};
    cout << "8. Lista original: ";
    for (int x : lst3)
        cout << x << " ";
    auto last_it = lst3.end();
    --last_it;
    reverse(lst3, lst3.begin(), last_it);
    cout << "\n   Lista invertida: ";
    for (int x : lst3)
        cout << x << " ";
    cout << endl;

    string str1 = "arara";
    string str2 = "hello";
    cout << "9. 'arara' é palíndromo: " << (palindrome(str1, 0, str1.length() - 1) ? "Sim" : "Não") << endl;
    cout << "9. 'hello' é palíndromo: " << (palindrome(str2, 0, str2.length() - 1) ? "Sim" : "Não") << endl;

    list<int> lst4 = {1, 2, 3, 2, 1};
    list<int> lst5 = {1, 2, 3, 4, 5};
    auto last4 = lst4.end();
    --last4;
    auto last5 = lst5.end();
    --last5;
    cout << "10. Lista {1,2,3,2,1} é palíndromo: " << (palindrome(lst4, lst4.begin(), last4) ? "Sim" : "Não") << endl;
    cout << "10. Lista {1,2,3,4,5} é palíndromo: " << (palindrome(lst5, lst5.begin(), last5) ? "Sim" : "Não") << endl;

    return 0;
}