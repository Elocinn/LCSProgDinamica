#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/*
max: retorna o maior valor entre x e y
*/
int max(int x, int y) {
    return x > y ? x : y;
}

/*
s1: primeira string
s2: segunda string
m: comprimento da primeira string
n: comprimento da segunda string
count: armazena a quantidade de caracteres da sequência comum mais longa
*/
int longest_common_sequence(char *s1, char *s2, int m, int n, int count) {
    if (m == 0 || n == 0) {
        return count;
    }
/*
sequência comum mais longa que termina em s1[m - 1] e s2[n - 1] 
é uma extensão da sequência comum mais longa que termina em s1[m - 2] e s2[n - 2].
Ignora o último caractere de s1 e tenta encontrar a sequência comum mais longa entre s1 sem o último caractere de s1 e s2.
*/
    if (s1[m - 1] == s2[n - 1]) {
        count = longest_common_sequence(s1, s2, m - 1, n - 1, count + 1);
    }

    count = max(count, max(longest_common_sequence(s1, s2, m, n - 1, 0),
                           longest_common_sequence(s1, s2, m - 1, n, 0)));

    return count;
}

int main() {
    setlocale(LC_ALL, ""); 

    char s1[100];
    char s2[100];

    printf("Digite a primeira string: ");
    scanf("%s", s1);

    printf("Digite a segunda string: ");
    scanf("%s", s2);

    int m = strlen(s1);
    int n = strlen(s2);

    clock_t start = clock();
    int compr = longest_common_sequence(s1, s2, m, n, 0);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da sequência comum mais longa é %d\n", compr);
    printf("A sequência comum mais longa é %s\n", compr);
    printf("Tempo de execução (recursivo): %f segundos\n", time_taken);

    return 0;
}