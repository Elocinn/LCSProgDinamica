# Longest Common Subsequence (LCS)  

Este projeto implementa o problema da **Subsequência Comum Mais Longa (LCS)** de duas formas diferentes:  
**Programação Dinâmica**: Uma abordagem eficiente, utilizando uma tabela para armazenar subproblemas resolvidos.  
**Recursiva**: Uma abordagem direta e intuitiva, porém extremamente ineficiente para entradas grandes.  

O objetivo é demonstrar a diferença de desempenho entre as duas estratégias.

---

**Descrição do Problema**  

Dadas duas sequências de caracteres, o problema é determinar:  
1. O comprimento da subsequência comum mais longa.  
2. Os próprios caracteres desta subsequência comum.  

### **Exemplo**  
**Entrada**:  
Digite a primeira string: `aegvaweifj`  
Digite a segunda string: `aenoerihao`  

**Saída**:  
Comprimento da sequência comum mais longa é  `2`  
A sequência comum mais longa é `ae`  
Tempo de execução (recursivo): `0.003000 segundos`

---
As cadeias de DNA são compostas por uma sequência de nucleotídeos representados pelas letras A (adenina), T (timina), G (guanina) e C (citosina). O comprimento de uma cadeia de DNA pode variar bastante, dependendo do organismo. Por exemplo:

Células humanas: O DNA humano tem aproximadamente 3 bilhões de pares de bases (cerca de 3 gigabases, ou 3 Gb).
Bactérias: O DNA de uma bactéria pode ter cerca de 1 a 5 milhões de pares de bases.

Diante os arquivos FASTA utilizado no teste estão disponíveis no repositório GenBank da National Center for Biotechnology Information (NCBI), acessível através de https://www.ncbi.nlm.nih.gov/nucleotide/."

### **Entradas Teste**  

- **50 caracteres**:  
  ```
  aegvaweifjoawsoledfjaweoifkmjsdwealoifkawjsmdefoaw  
  aenoerihaolfwaedishfpawiosewagorifaydswazeytgrfuwa  
  ```  
  (O recursivo pode levar questão de anos para finalizar)
- **20 caracteres**:  
  ```
  aegvaweifjoawsoledfj  
  aenoerihaolfwaedishf  
  ```  
- **10 caracteres**:  
  ```
  aegvaweifj  
  aenoerihao  
  ```  

---

## **Comparação entre as Abordagens**  

### **Programação Dinâmica**  
- **Desempenho**: Rápido, mesmo para entradas grandes.  
- **Complexidade**: O(m * n), onde m e n são os tamanhos das sequências.  
- **Armazena resultados intermediários** em uma tabela para evitar cálculos repetidos.  

### **Recursiva**  
- **Desempenho**: Extremamente lento para entradas grandes. Pode levar horas (ou mais) para entradas com centenas de caracteres.  
- **Complexidade**: Exponencial, O(2^(min(m, n))).  
- **Propósito**: Mostrar como a abordagem recursiva direta é inadequada para problemas como LCS.  

---

## **Observações**  

- **Recomendações**: Use as mesmas entradas em ambos os códigos para comparar os resultados.  
- **Atenção com a abordagem recursiva**: Pode demorar ***muito*** tempo para entradas grandes, mas isso faz parte do objetivo deste projeto.  

05/12/2024

