#include "recursividade.hpp";

int main()
{
    Recursividade *rec = new Recursividade();

    cout << "=== Teste 1: print_txt ===" << endl;
    char texto[] = "bora bill";
    rec->print_txt(texto, 10);

    cout << "\n=== Teste 2: count ===" << endl;
    rec->count(2);

    cout << "\n=== Teste 3: count_max ===" << endl;
    rec->count_max(2, 10);

    cout << "\n=== Teste 4: print_vec ===" << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    rec->print_vec(vec, 0);
    cout << endl;

    cout << "=== Teste 5: print_even (ordem inversa) ===" << endl;
    vector<int> vec_even = {1, 2, 3, 4, 5, 6, 7, 8};
    rec->print_even(vec_even, vec_even.size() - 1);
    cout << endl;

    cout << "=== Teste 6: print_list ===" << endl;
    list<int> lst = {10, 20, 30, 40};
    auto it = lst.begin();
    rec->print_list(lst, it);
    cout << endl;

    cout << "=== Teste 7: print_rev (forward_list) ===" << endl;
    forward_list<int> flst = {100, 200, 300, 400};
    auto fit = flst.begin();
    rec->print_rev(flst, fit);
    cout << endl;

    cout << "=== Teste 8: remove_all ===" << endl;
    vector<int> vec_remove = {1, 2, 3, 4, 5};
    cout << "Antes: tamanho = " << vec_remove.size() << endl;
    rec->remove_all(vec_remove);
    cout << "Depois: tamanho = " << vec_remove.size() << endl;

    cout << "=== Teste 9: print_stack ===" << endl;
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    cout << "Stack: ";
    rec->print_stack(stk);
    cout << endl;

    cout << "=== Teste 10: push_to ===" << endl;
    stack<int> stk1, stk2;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    cout << "Antes - stk1 tamanho: " << stk1.size() << ", stk2 tamanho: " << stk2.size() << endl;
    rec->push_to(stk1, stk2);
    cout << "Depois - stk1 tamanho: " << stk1.size() << ", stk2 tamanho: " << stk2.size() << endl;

    cout << "=== Teste 11: copy (vector) ===" << endl;
    vector<int> vec1 = {1, 2, 3, 4};
    vector<int> vec2;
    rec->copy(vec1, 0, vec2);
    cout << "vec2 copiado: ";
    for (int val : vec2)
        cout << val << " ";
    cout << endl;

    cout << "=== Teste 12: copy (list) ===" << endl;
    list<int> list1 = {10, 20, 30};
    list<int> list2;
    auto list_it = list1.begin();
    rec->copy(list1, list_it, list2);
    cout << "list2 copiada: ";
    for (int val : list2)
        cout << val << " ";
    cout << endl;

    return 0;
}