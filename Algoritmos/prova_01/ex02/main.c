#include <stdio.h>

void vec_to_str(int n, int vec[], char str[]) {
    int index = 0;  
    
    for (int i = 0; i < n; i++) {
        if (vec[i] < 0) {
            str[index++] = '(';
            int num = -vec[i];  
            
            int digits[10], digit_count = 0;
            do {
                digits[digit_count++] = num % 10;
                num /= 10;
            } while (num > 0);
            
            for (int j = digit_count - 1; j >= 0; j--) {
                str[index++] = digits[j] + '0';
            }
            
            str[index++] = ')';
        } else {
            int num = vec[i];
            int digits[10], digit_count = 0;
            do {
                digits[digit_count++] = num % 10;
                num /= 10;
            } while (num > 0);
            
            for (int j = digit_count - 1; j >= 0; j--) {
                str[index++] = digits[j] + '0';
            }
        }
        if (i < n - 1) {
            str[index++] = ' ';
        }
    }
    str[index] = '\0';  
}

int main() {
    int v[] = {1, 2, -6, 7, 9, -1, 2};
    char st[50];
    vec_to_str(7, v, st);
    printf("%s\n", st);
    return 0;
}
