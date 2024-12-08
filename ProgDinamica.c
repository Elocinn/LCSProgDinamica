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
matriz: armazenar os comprimentos das strings comuns
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

void read_fasta_sequence(const char *filename, char *sequence, int max_length) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char line[1000];
    int length = 0;
    while (fgets(line, sizeof(line), file) && length < max_length) {
        if (line[0] != '>') {
            line[strcspn(line, "\n")] = '\0'; // Remove o caractere de nova linha
            strncat(sequence, line, max_length - length);
            length += strlen(line);
        }
    }

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "");
    char s1[1000] = "";
    char s2[1000] = "";
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Comparar sequencias de DNA pre-registradas\n");
        printf("2. Inserir suas proprias sequencias de DNA\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

     switch (choice) {
        case 1:
            read_fasta_sequence("sequence1.fasta", s1, 500);
            read_fasta_sequence("sequence2.fasta", s2, 500);
            break;
        case 2:
            printf("Digite a primeira sequencia de DNA: ");
            scanf("%s", s1);
            printf("Digite a segunda sequencia de DNA: ");
            scanf("%s", s2);
            break;
        case 3:
            return 0;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            continue;
    }  

    int m = strlen(s1);
    int n = strlen(s2);

    char lcs_str[m + n + 1];

    clock_t start = clock();
    longest_common_sequence(s1, s2, m, n, lcs_str);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da sequencia comum mais longa e '%d'\n", (int)strlen(lcs_str));
    printf("A sequencia comum mais longa e '%s'\n", lcs_str);
    printf("Tempo de execucao (programacao dinamica): %f segundos\n", time_taken);
    }
}
