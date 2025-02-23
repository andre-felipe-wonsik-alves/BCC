#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[51];
    float price;
} Product;

int saveProductsToFile(Product products[], int size, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        char modifiedName[51];
        strcpy(modifiedName, products[i].name);
        for (int j = 0; j < strlen(modifiedName); j++)
        {
            if (modifiedName[j] == ' ')
            {
                modifiedName[j] = '@';
            }
        }

        fprintf(file, "%d %s %.2f\n", products[i].id, modifiedName, products[i].price);
    }

    fclose(file);
    return 1;
}

int main()
{
    Product products[] = {
        {1, "Product One", 10.99},
        {2, "Product Two", 20.99},
        {3, "Product Three", 30.99}};
    int size = sizeof(products) / sizeof(products[0]);

    if (saveProductsToFile(products, size, "products.txt"))
    {
        printf("Products saved successfully.\n");
    }
    else
    {
        printf("Failed to save products.\n");
    }

    return 0;
}