#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/*
s1: primeira string
s2: segunda string
m: comprimento da primeira string
n: comprimento da segunda string
verifica se a string s1 é uma subsequência da string s2
*/
int is_subsequence(char *s1, char *s2, int m, int n) {
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (s1[j] == s2[i]) {
            j++;
        }
    }
    return j == m;
}

/*
abordagem de força bruta
Ela gera todas as possíveis subsequências de s1 e verifica se cada uma delas é uma subsequência de s2, armazenando em lcs_str
max_len para armazenar o comprimento
*/
int longest_common_sequence(char *s1, char *s2, int m, int n, char *lcs_str) {
    int max_len = 0;

    for (int i = 0; i < (1 << m); i++) {
        char subseq[m + 1];
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                subseq[k++] = s1[j];
            }
        }
        subseq[k] = '\0';

        if (is_subsequence(subseq, s2, k, n) && k > max_len) {
            max_len = k;
            strcpy(lcs_str, subseq);
        }
    }

    return max_len;
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
            line[strcspn(line, "\n")] = '\0';
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
        printf("Menu:\n");
        printf("1. Comparar sequências de DNA pré-registradas\n");
        printf("2. Inserir suas próprias sequências de DNA\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_fasta_sequence("sequence1.fasta", s1, 500);
                read_fasta_sequence("sequence2.fasta", s2, 500);
                break;
            case 2:
                printf("Digite a primeira sequência de DNA: ");
                scanf("%s", s1);
                printf("Digite a segunda sequência de DNA: ");
                scanf("%s", s2);
                break;
            case 3:
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

    int m = strlen(s1);
    int n = strlen(s2);

    char lcs_str[m + 1];

    clock_t start = clock();
    int compr = longest_common_sequence(s1, s2, m, n, lcs_str);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da subsequência comum mais longa é %d\n", compr);
    printf("A subsequência comum mais longa é %s\n", lcs_str);
    printf("Tempo de execução (força bruta): %0.10f segundos\n", time_taken);
    }
}