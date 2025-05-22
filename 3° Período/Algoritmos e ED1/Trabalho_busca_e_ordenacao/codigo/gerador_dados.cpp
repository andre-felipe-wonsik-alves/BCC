#include <iostream>
#include <string>
#include <vector>
#include <list>

void create_file(const char *filepath, int size)
{
    FILE *file = fopen(filepath, "w");
    std::cout << "teste";
    fwrite("asd", sizeof(char), size, file);
}

int main()
{
    create_file("./", 30);
}