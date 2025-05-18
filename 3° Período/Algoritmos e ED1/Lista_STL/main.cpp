#include "stl.hpp"

int main()
{
    ListaSTL *listaSTL = new ListaSTL();

    // os testes foram gerados por IA com o prompt:"crie um main que teste o caso de sucesso de todos esses métodos"

    cout
        << "\n1. Teste de vectorize_expression:" << endl;

    string expr = "24 32 + 2 / 41 5 * +";
    vector<string> tokens = listaSTL->vectorize_expression(expr);

    cout << "Expressão: " << expr << endl;
    cout << "Resultado da vetorização: ";

    listaSTL->print_vector(tokens);

    // Teste de check_brackets
    cout << "\n2. Teste de check_brackets:" << endl;

    string balanced_expr = "[(x + 8) * (9-2)]";

    bool is_balanced = listaSTL->check_brackets(balanced_expr);

    cout << "Expressão: " << balanced_expr << endl;
    cout << "Resultado da verificação de parênteses: "
         << (is_balanced ? "Balanceada" : "Não balanceada") << endl;

    // Teste de calc_posfix
    cout << "\n3. Teste de calc_posfix:" << endl;

    string posfix_expr = "24 32 + 2 / 41 5 * +";

    try
    {
        float result = listaSTL->calc_posfix(posfix_expr);
        cout << "Expressão: " << posfix_expr << endl;
        cout << "Resultado do cálculo: " << result << endl;
    }
    catch (const exception &e)
    {
        cerr << "Erro: " << e.what() << endl;
    }

    // Teste de check_posfix
    cout << "\n4. Teste de check_posfix:" << endl;

    string valid_posfix = "24 32 + 2 / 41 5 * +";

    bool is_valid = listaSTL->check_posfix(valid_posfix);

    cout << "Expressão: " << valid_posfix << endl;
    cout << "Resultado da verificação da expressão posfix: "
         << (is_valid ? "Válida" : "Inválida") << endl;

    string result = listaSTL->posfix_to_infix("6 9 + 3 / 6 4 - *");
    cout << "Expressão infix: " << result << endl;
    return 0;
}