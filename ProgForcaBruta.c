#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/*
s1: primeira string
s2: segunda string
m: comprimento da primeira string
n: comprimento da segunda string
verifica se a string s1 é uma sequência da string s2
*/

int longest_common_sequence(char *s1, char *s2, int m, int n, char *lcs_str) {
    int max_len = 0;
    int end_pos = 0; 
    lcs_str[0] = '\0';
/*
abordagem de força bruta
Ela gera todas as possíveis sequências de s1 e verifica se cada uma delas é umasequência de s2, armazenando em lcs_str
max_len para armazenar o comprimento
*/

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int len = 0;
            while (i + len < m && j + len < n && s1[i + len] == s2[j + len]) {
                len++;
            }

            if (len > max_len) {
                max_len = len;
                end_pos = i + len - 1;  
            }
        }
    }

    if (max_len > 0) {
        strncpy(lcs_str, s1 + end_pos - max_len + 1, max_len);
        lcs_str[max_len] = '\0'; 
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

    char lcs_str[m + 1];

    clock_t start = clock();
    int compr = longest_common_sequence(s1, s2, m, n, lcs_str);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da sequencia comum mais longa e '%d'\n", (int)strlen(lcs_str));
    printf("A sequencia comum mais longa e '%s'\n", lcs_str);
    printf("Tempo de execucao (forca bruta): %0.10f segundos\n", time_taken);
    }
}
