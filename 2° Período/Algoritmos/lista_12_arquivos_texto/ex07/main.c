#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    float price;
} Product;

Product *load_records(const char *filepath, int *n)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        *n = 0;
        return NULL;
    }

    int count = 0;
    fscanf(file, "%d", &count);
    if (count == 0)
    {
        *n = 0;
        fclose(file);
        return NULL;
    }

    Product *products = (Product *)malloc(count * sizeof(Product));
    if (!products)
    {
        *n = 0;
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d %s %f", &products[i].id, products[i].name, &products[i].price);
        for (int j = 0; j < strlen(products[i].name); j++)
        {
            if (products[i].name[j] == '@')
            {
                products[i].name[j] = ' ';
            }
        }
    }

    *n = count;
    fclose(file);
    return products;
}