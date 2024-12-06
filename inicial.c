#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/*
s1: primeira string
s2: segunda string
m: comprimento da primeira string
n: comprimento da segunda string
lcs_str: string que armazena a sequência comum mais longa
*/
void longest_common_sequence(char *s1, char *s2, int m, int n, char *lcs_str) {

/*
matriz: armazenar os comprimentos das substrings comuns
compr: inicializado como 0 e será usado para armazenar o comprimento da sequência comum mais longa encontrada
end_index: armazenar o índice final da sequência comum mais longa
*/
    int matriz[m + 1][n + 1];
    int compr = 0; 
    int end_index = 0; 

/*
Se s1[i-1] for igual a s2[j-1], matriz[i][j] é incrementado em 1 a partir de matriz[i-1][j-1]
i: índice da primeira string
j: índice da segunda string
*/
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                matriz[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                matriz[i][j] = matriz[i - 1][j - 1] + 1;
                if (matriz[i][j] > compr) {
                    compr = matriz[i][j];
                    end_index = i - 1;
                }
            } else {
                matriz[i][j] = 0;
            }
        }
    }
/*
Se compr for maior que 0, a sequência comum mais longa é copiada de s1 para lcs_str usando strncpy
*/
    if (compr > 0) {
        strncpy(lcs_str, s1 + end_index - compr + 1, compr);
    }
    lcs_str[compr] = '\0'; 
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

    char lcs_str[m + n + 1];

    clock_t start = clock();
    longest_common_sequence(s1, s2, m, n, lcs_str);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da sequência comum mais longa é %d\n", (int)strlen(lcs_str));
    printf("A sequência comum mais longa é %s\n", lcs_str);
    printf("Tempo de execução (programação dinâmica): %f segundos\n", time_taken);

    return 0;
}