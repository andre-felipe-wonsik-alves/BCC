#include "stl.hpp"

int main()
{
    ListaSTL *elem = new ListaSTL();
    int checkBrackets = elem->check_brackets("[11+23]");
    vector<string> vectorizedExpression = elem->vectorize_expression("24 32 + 2 / 41 5 * +");
    elem->print_vector(vectorizedExpression);

    if (checkBrackets)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}