#include <stdio.h>

int main(){
    float raio;
    const float PI = 3.141593;

    printf("Digite o raio:\n> ");
    scanf(" %f", &raio);

    printf("Diâmetro: %f\nCircunferencia: %f\nArea: %f\n", 2*raio, 2*PI*raio, PI*(raio*raio));

    return 0;
}