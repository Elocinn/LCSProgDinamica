# Longest Common Subsequence (LCS)  

Este projeto implementa o problema da **Subsequência Comum Mais Longa (LCS)** de duas formas diferentes:  
**Programação Dinâmica**: Uma abordagem eficiente, utilizando uma tabela para armazenar subproblemas resolvidos.  
**Recursiva**: Uma abordagem direta e intuitiva, porém extremamente ineficiente para entradas grandes.  
**Força Bruta**: Uma abordagem exaustiva que tenta todas as combinações possíveis para encontrar a solução.

O objetivo é demonstrar a diferença de desempenho entre as três estratégias.


## **O que faz?**

- São três códigos que implementam o algoritmo de LCS (Longest Common Subsequence) usando abordagens diferentes: Programação Dinâmica, Recursiva e Força Bruta.
- O usuário tem duas opções de entrada: utilizar sequências de DNA pré-definidas em arquivos FASTA ou inserir suas próprias sequências manualmente.
- Utilize este projeto para analisar e comparar o desempenho e o tempo de execução de cada abordagem.
---
**Descrição do Problema**  

Dadas duas sequências de caracteres, o problema é determinar:  
1. O comprimento da subsequência comum mais longa.  
2. Os próprios caracteres desta subsequência comum.  

### **Exemplo**  
**Entrada**:  
Digite a primeira string: `aegvaweifj`  
Digite a segunda string: `aenoerihao`  

**Saída (recursivo)**:  
Comprimento da sequência comum mais longa é  `2`  
A sequência comum mais longa é `ae`  
Tempo de execução: `0.003000 segundos`

---

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

### **Força Bruta**  
- **Desempenho**: Muito lento para entradas grandes.  
- **Complexidade**: Exponencial, O(2^m * n), onde m é o tamanho da primeira sequência e n é o tamanho da segunda sequência.  
- **Propósito**: Demonstrar a abordagem mais simples e direta, mas ineficiente, para resolver o problema de LCS.
---

## **Observações**  

- **Recomendações**: Use as mesmas entradas em ambos os códigos para comparar os resultados.  
- **Atenção com a abordagem recursiva**: Pode demorar ***muito*** tempo para entradas grandes, mas isso faz parte do objetivo deste projeto.  

05/12/2024
