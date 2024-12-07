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

    clock_t start = clock();
    int compr = longest_common_sequence(s1, s2, m, n, 0);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Comprimento da sequência comum mais longa é %d\n", compr);
    printf("A sequência comum mais longa é %s\n", compr);
    printf("Tempo de execução (recursivo): %0.10f segundos\n", time_taken);
    }
}
