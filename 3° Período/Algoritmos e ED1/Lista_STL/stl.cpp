#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "stl.hpp"

using namespace std;

ListaSTL::ListaSTL() {};

vector<int> ListaSTL::vet_to_vector(int *v, int n)
{
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        vec.push_back(v[i]);
    }

    return vec;
}

list<int> ListaSTL::vet_to_list(int *v, int n)
{
    list<int> ls;

    for (int i = 0; i < n; i++)
    {
        ls.push_back(v[i]);
    }

    return ls;
}

stack<int> ListaSTL::vet_to_stack(int *v, int n)
{
    stack<int> pilha;

    for (int i = 0; i < n; i++)
    {
        pilha.push(v[i]);
    }

    return pilha;
}

vector<int> ListaSTL::list_concat(list<int> &list1, list<int> &list2)
{
    vector<int> vec;

    for (int elem : list1)
    {
        vec.push_back(elem);
    }

    for (int elem : list2)
    {
        vec.push_back(elem);
    }

    return vec;
}

bool ListaSTL::check_brackets(string expression)
{
    stack<char> pilha;

    for (char c : expression)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            pilha.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (pilha.empty())
            {
                return false;
            }

            char topo = pilha.top();
            pilha.pop();

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{'))
            {
                return false;
            }
        }
    }

    return pilha.empty();
}

vector<string> ListaSTL::vectorize_expression(string expression)
{
    vector<string> result;
    string current_token;

    for (size_t i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];

        if (c == ' ')
        {
            if (!current_token.empty())
            {
                result.push_back(current_token);
                current_token.clear();
            }
        }
        else
        {
            current_token += c;
        }
    }

    if (!current_token.empty())
    {
        result.push_back(current_token);
    }

    return result;
}

float ListaSTL::calc_posfix(string expression)
{
    vector<string> tokens = vectorize_expression(expression);
    stack<float> operands;

    for (const string &token : tokens)
    {
        bool is_number = true;
        for (char c : token)
        {
            if (!isdigit(c))
            {
                is_number = false;
                break;
            }
        }

        if (is_number)
        {
            operands.push(stoi(token));
        }
        else
        {
            if (operands.size() < 2)
            {
                return -1;
            }

            float operand2 = operands.top();
            operands.pop();
            float operand1 = operands.top();
            operands.pop();

            float result;
            char op = token[0];

            switch (op)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    return -1;
                }
                result = operand1 / operand2;
                break;
            default:
                return -1;
            }

            operands.push(result);
        }
    }

    if (operands.size() != 1)
    {
        return -1;
    }

    return operands.top();
}

bool ListaSTL::check_posfix(string expression)
{
    vector<string> tokens = vectorize_expression(expression);
    stack<int> operands;

    for (const string &token : tokens)
    {
        bool is_number = true;
        for (char c : token)
        {
            if (!isdigit(c))
            {
                is_number = false;
                break;
            }
        }

        if (is_number)
        {
            operands.push(1);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (operands.size() < 2)
            {
                return false;
            }
            operands.pop();
        }
        else
        {
            return false;
        }
    }
    return operands.size() == 1;
}

// infelizmente feito com ajuda de IA
bool is_number(const string &token)
{
    if (token.empty())
        return false;
    for (char c : token)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool is_operator(const string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

string ListaSTL::posfix_to_infix(string expression)
{
    stack<string> s;
    string token;

    // Usando um stringstream-like loop para separar tokens por espaço
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == ' ')
            continue;

        token.clear();

        // Lê um número ou operador
        while (i < expression.length() && expression[i] != ' ')
        {
            token += expression[i];
            ++i;
        }

        if (is_number(token))
        {
            // Se é número, empilha
            s.push(token);
        }
        else if (is_operator(token))
        {
            // Se é operador, desempilha dois elementos
            if (s.size() < 2)
            {
                cerr << "Erro: expressão malformada." << endl;
                return "";
            }

            string right = s.top();
            s.pop();
            string left = s.top();
            s.pop();

            string expr = "( " + left + " " + token + " " + right + " )";
            s.push(expr);
        }
        else
        {
            cerr << "Erro: token inválido \"" << token << "\"." << endl;
            return "";
        }
    }

    // A pilha deve conter exatamente um elemento no final
    if (s.size() != 1)
    {
        cerr << "Erro: expressão malformada no final." << endl;
        return "";
    }

    return s.top();
}

void ListaSTL::print_vector(const vector<string> &vec)
{
    cout << "vector = {";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}