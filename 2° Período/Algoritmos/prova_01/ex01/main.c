#include <stdio.h>
#include <string.h>

void remove_palindrome(char str[]){
    // testeetset
    int tamanhoString = strlen(str) - 1;

    for(int i = 0; str[i] != '\0'; i++){
        if((str[i] != str[tamanhoString - i]) || (i == tamanhoString/2)){
            printf("\nNão é palíndromo!\n");
            return;
        };
    }

    str[tamanhoString/2 + 1] = '\0';
}

int main(){
    char text[] = "testaaaeetest";
    remove_palindrome(text);
    printf("%s\n", text);

    return 0;
}