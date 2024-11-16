#include <stdio.h>
    // PI -- 180
    // Xrad -- valorGraus
    // valorGraus * PI = 180X -> (valorGraus * PI)/180 = X

int main(){
    float valorGraus;
    const float PI = 3.141593;

    printf("Digite um valor em graus: \n>");
    scanf(" %f", &valorGraus);

    float valorRadianos = (valorGraus*PI)/180;

    printf("O valor cru em radianos desse grau é: %f\nConvertendo para a notação Xπ rad é, aproximadamente: %.2fπ\n", valorRadianos, valorRadianos/PI);
    return 0;
}