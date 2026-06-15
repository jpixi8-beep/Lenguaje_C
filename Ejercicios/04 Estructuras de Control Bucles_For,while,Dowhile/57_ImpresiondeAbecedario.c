#include <stdio.h>  
int main() {
    char letra = 'a';
    do {
        printf("%c ", letra);
        letra++;
    } while (letra <= 'z');
    return 0;
}