#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define PI 3.14159

// ============================================================================
// PROTÓTIPOS DAS FUNÇÕES E PROCEDIMENTOS
// ============================================================================

// Parte 1 (Funções e Procedimentos Básicos)
float calcVolumeEsfera(float raio);
void calcMediaAluno(float n1, float n2, float n3, char letra, float *resultado);
bool isPrimo(int valor);
void calcBhaskara(float a, float b, float c, float *r1, float *r2, int *possivel);
void converteTempo(int tempo_seg, int *h, int *m, int *s);
int idadeEmDias(int anos, int meses, int dias);
bool isPerfeito(int valor);
void categoriaNadador(int idade, char categoria[]);

// Parte 2 (Vetores)
long long calcFatorial(int n);
void fatoraVetor(int A[], int B[], int tam);
void uniaoVetores(int A[], int B[], int Uniao[], int *tamUniao, int tam);
void separaParesImpares(int X[], int A[], int B[], int *tamA, int *tamB, int tam);
int contaParesVetor(int X[], int tam);
float somaVetorReais(float X[], int tam);
void somaDoisVetores(int A[], int B[], int Soma[], int tam);
void produtoDoisVetores(int A[], int B[], int Produto[], int tam);

// Parte 3 (Matrizes)
int somaMatriz5x5(int M[][5]);
int somaDiagonais6x6(int M[][6]);
int somaLinha5Coluna3(int M[][6]);
int menorDiagSecundaria(int M[][6]);


// ============================================================================
// FUNÇÃO PRINCIPAL (MENU)
// ============================================================================

int main() {
    int escolha;

    do {
        printf("\n=========================================================\n");
        printf("                 MENU DE EXERCICIOS\n");
        printf("=========================================================\n");
        printf(" --- PRIMEIRA PARTE (Basicos) ---\n");
        printf(" 1  - Ex. 1: Volume da Esfera\n");
        printf(" 2  - Ex. 2: Media do Aluno (A, P, H)\n");
        printf(" 3  - Ex. 3: Verificar Numero Primo\n");
        printf(" 4  - Ex. 4: Formula de Bhaskara\n");
        printf(" 5  - Ex. 5: Converter Segundos em H:M:S\n");
        printf(" 6  - Ex. 6: Idade em Dias\n");
        printf(" 7  - Ex. 7: Numero Perfeito\n");
        printf(" 8  - Ex. 8: Categoria de Nadador\n");
        printf(" --- SEGUNDA PARTE (Vetores) ---\n");
        printf(" 9  - Ex. 6 (Repetido): Fatorial de Vetor A para B\n");
        printf(" 10 - Ex. 7 (Repetido): Uniao de 2 Vetores\n");
        printf(" 11 - Ex. 8 (Repetido): Separar Pares e Impares de um Vetor\n");
        printf(" 12 - Ex. 9: Quantidade de Pares no Vetor(15)\n");
        printf(" 13 - Ex. 10: Soma de elementos Reais do Vetor(20)\n");
        printf(" 14 - Ex. 18: Soma de dois Vetores(20)\n");
        printf(" 15 - Ex. 19: Produto de dois Vetores(15)\n");
        printf(" --- TERCEIRA PARTE (Matrizes) ---\n");
        printf(" 16 - Ex. 24, 25, 26, 27: Operacoes em Matrizes (Demonstracao)\n");
        printf(" 0  - Sair\n");
        printf("=========================================================\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                float raio;
                printf("\nDigite o raio da esfera: ");
                scanf("%f", &raio);
                printf("Volume da esfera: %.2f\n", calcVolumeEsfera(raio));
                break;
            }
            case 2: {
                float n1, n2, n3, media = 0;
                char letra;
                printf("\nDigite as 3 notas: ");
                scanf("%f %f %f", &n1, &n2, &n3);
                printf("Digite a letra (A=Aritmetica, P=Ponderada, H=Harmonica): ");
                scanf(" %c", &letra);
                calcMediaAluno(n1, n2, n3, letra, &media);
                printf("A media calculada e: %.2f\n", media);
                break;
            }
            case 3: {
                int n;
                printf("\nDigite um valor inteiro e positivo: ");
                scanf("%d", &n);
                if (isPrimo(n)) printf("Verdadeiro (E primo)\n");
                else printf("Falso (Nao e primo)\n");
                break;
            }
            case 4: {
                float a, b, c, r1, r2;
                int possivel;
                printf("\nDigite os valores de a, b e c: ");
                scanf("%f %f %f", &a, &b, &c);
                calcBhaskara(a, b, c, &r1, &r2, &possivel);
                if (possivel) printf("Raizes: R1 = %.2f, R2 = %.2f\n", r1, r2);
                else printf("Nao e possivel calcular (Delta negativo ou a=0).\n");
                break;
            }
            case 5: {
                int seg_total, h, m, s;
                printf("\nDigite o tempo em segundos: ");
                scanf("%d", &seg_total);
                converteTempo(seg_total, &h, &m, &s);
                printf("Tempo convertido: %dh %dm %ds\n", h, m, s);
                break;
            }
            case 6: {
                int a, m, d;
                printf("\nDigite a idade em anos, meses e dias: ");
                scanf("%d %d %d", &a, &m, &d);
                printf("Idade expressa em dias: %d\n", idadeEmDias(a, m, d));
                break;
            }
            case 7: {
                int val;
                printf("\nDigite um numero para verificar se e perfeito: ");
                scanf("%d", &val);
                if (isPerfeito(val)) printf("O numero %d e perfeito!\n", val);
                else printf("O numero %d NAO e perfeito.\n", val);
                break;
            }
            case 8: {
                int idade;
                char cat[20];
                printf("\nDigite a idade do nadador: ");
                scanf("%d", &idade);
                categoriaNadador(idade, cat);
                printf("Categoria: %s\n", cat);
                break;
            }
            case 9: { // Fatorial de Vetores
                int A[5] = {4, 1, 0, 3, 5}; // Reduzido para 5 para teste rápido
                int B[5];
                printf("\nCalculando fatorial de um vetor fixo A = {4, 1, 0, 3, 5}...\n");
                fatoraVetor(A, B, 5);
                printf("Vetor B gerado: ");
                for(int i=0; i<5; i++) printf("%d ", B[i]);
                printf("\n");
                break;
            }
            case 10: { // União de Vetores
                int A[5] = {1, 2, 3, 4, 5};
                int B[5] = {4, 5, 6, 7, 8};
                int U[10], tamU = 0;
                printf("\nUnindo vetores fixos A={1,2,3,4,5} e B={4,5,6,7,8}...\n");
                uniaoVetores(A, B, U, &tamU, 5);
                printf("Vetor Uniao: ");
                for(int i=0; i<tamU; i++) printf("%d ", U[i]);
                printf("\n");
                break;
            }
            case 11: { // Separa Pares e Impares
                int X[10] = {1,2,3,4,5,6,7,8,9,10};
                int A[10], B[10], tA, tB;
                printf("\nSeparando X={1 a 10} em Pares(A) e Impares(B)...\n");
                separaParesImpares(X, A, B, &tA, &tB, 10);
                printf("Vetor A (Pares): ");
                for(int i=0; i<tA; i++) printf("%d ", A[i]);
                printf("\nVetor B (Impares): ");
                for(int i=0; i<tB; i++) printf("%d ", B[i]);
                printf("\n");
                break;
            }
            case 12: { // Ex 9
                int X[15] = {2,4,6,8,10,1,3,5,7,9,12,14,16,18,20};
                printf("\nO vetor X possui %d valores pares.\n", contaParesVetor(X, 15));
                break;
            }
            case 13: { // Ex 10
                float X[5] = {1.5, 2.5, 3.0, 4.0, 5.2}; // Exemplo reduzido
                printf("\nA soma do vetor real e: %.2f\n", somaVetorReais(X, 5));
                break;
            }
            case 14: { // Ex 18
                int A[5] = {1,2,3,4,5}, B[5] = {5,4,3,2,1}, S[5];
                somaDoisVetores(A, B, S, 5);
                printf("\nSoma de Vetores: ");
                for(int i=0; i<5; i++) printf("%d ", S[i]);
                printf("\n");
                break;
            }
            case 15: { // Ex 19
                int A[5] = {1,2,3,4,5}, B[5] = {2,2,2,2,2}, P[5];
                produtoDoisVetores(A, B, P, 5);
                printf("\nProduto de Vetores: ");
                for(int i=0; i<5; i++) printf("%d ", P[i]);
                printf("\n");
                break;
            }
            case 16: { // Agrupado os exercícios de matriz (24 a 27) para facilitar o teste
                printf("\nPara nao digitar dezenas de numeros manualmente, as matrizes de teste serao preenchidas com o numero 1.\n");
                
                int M5[5][5], M6[6][6], M7[7][6];
                for(int i=0; i<7; i++){
                    for(int j=0; j<6; j++){
                        if(i<5 && j<5) M5[i][j] = 1;
                        if(i<6 && j<6) M6[i][j] = 1;
                        M7[i][j] = 1;
                    }
                }
                
                printf("Ex 24 - Soma Matriz 5x5 (todas posicoes = 1): %d\n", somaMatriz5x5(M5));
                printf("Ex 25 - Soma Diagonais Matriz 6x6: %d\n", somaDiagonais6x6(M6));
                printf("Ex 26 - Soma Linha 5 e Coluna 3 Matriz 7x6: %d\n", somaLinha5Coluna3(M7));
                printf("Ex 27 - Menor da Diag Secundaria 6x6: %d\n", menorDiagSecundaria(M6));
                break;
            }
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao Invalida!\n");
        }
    } while (escolha != 0);

    return 0;
}

// ============================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES (PARTE 1)
// ============================================================================

// Ex 1
float calcVolumeEsfera(float raio) {
    return (4.0 / 3.0) * PI * pow(raio, 3);
}

// Ex 2 (Procedimento)
void calcMediaAluno(float n1, float n2, float n3, char letra, float *resultado) {
    if (letra == 'A' || letra == 'a') {
        *resultado = (n1 + n2 + n3) / 3.0;
    } else if (letra == 'P' || letra == 'p') {
        *resultado = ((n1 * 5) + (n2 * 3) + (n3 * 2)) / 10.0;
    } else if (letra == 'H' || letra == 'h') {
        if(n1 == 0 || n2 == 0 || n3 == 0) *resultado = 0; // Evita divisao por zero
        else *resultado = 3.0 / ((1.0/n1) + (1.0/n2) + (1.0/n3));
    } else {
        *resultado = -1; // Erro
    }
}

// Ex 3
bool isPrimo(int valor) {
    if (valor <= 1) return false;
    for (int i = 2; i <= sqrt(valor); i++) {
        if (valor % i == 0) return false;
    }
    return true;
}

// Ex 4 (Procedimento)
void calcBhaskara(float a, float b, float c, float *r1, float *r2, int *possivel) {
    if (a == 0) {
        *possivel = 0;
        return;
    }
    float delta = (b * b) - (4 * a * c);
    if (delta < 0) {
        *possivel = 0;
    } else {
        *possivel = 1;
        *r1 = (-b + sqrt(delta)) / (2 * a);
        *r2 = (-b - sqrt(delta)) / (2 * a);
    }
}

// Ex 5 (Procedimento)
void converteTempo(int tempo_seg, int *h, int *m, int *s) {
    *h = tempo_seg / 3600;
    int resto = tempo_seg % 3600;
    *m = resto / 60;
    *s = resto % 60;
}

// Ex 6a
int idadeEmDias(int anos, int meses, int dias) {
    return (anos * 365) + (meses * 30) + dias;
}

// Ex 7a
bool isPerfeito(int valor) {
    int soma = 0;
    for (int i = 1; i < valor; i++) {
        if (valor % i == 0) soma += i;
    }
    return (soma == valor);
}

// Ex 8a (Procedimento que retorna String)
void categoriaNadador(int idade, char categoria[]) {
    if (idade >= 5 && idade <= 7) strcpy(categoria, "Infantil A");
    else if (idade >= 8 && idade <= 10) strcpy(categoria, "Infantil B");
    else if (idade >= 11 && idade <= 13) strcpy(categoria, "Juvenil A");
    else if (idade >= 14 && idade <= 17) strcpy(categoria, "Juvenil B");
    else if (idade >= 18) strcpy(categoria, "Adulto");
    else strcpy(categoria, "Sem Categoria");
}

// ============================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES (PARTE 2 - VETORES)
// ============================================================================

// Funcao auxiliar para o Ex 6b
long long calcFatorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fat = 1;
    for(int i = 2; i <= n; i++) fat *= i;
    return fat;
}

// Ex 6b (Procedimento altera o vetor B)
void fatoraVetor(int A[], int B[], int tam) {
    for(int i = 0; i < tam; i++) {
        B[i] = calcFatorial(A[i]);
    }
}

// Ex 7b (Procedimento)
void uniaoVetores(int A[], int B[], int Uniao[], int *tamUniao, int tam) {
    *tamUniao = 0;
    // Adiciona elementos de A
    for(int i = 0; i < tam; i++) {
        Uniao[*tamUniao] = A[i];
        (*tamUniao)++;
    }
    // Adiciona elementos de B, se nao existirem em Uniao
    for(int i = 0; i < tam; i++) {
        bool existe = false;
        for(int j = 0; j < *tamUniao; j++) {
            if(B[i] == Uniao[j]) {
                existe = true; break;
            }
        }
        if(!existe) {
            Uniao[*tamUniao] = B[i];
            (*tamUniao)++;
        }
    }
}

// Ex 8b (Procedimento)
void separaParesImpares(int X[], int A[], int B[], int *tamA, int *tamB, int tam) {
    *tamA = 0;
    *tamB = 0;
    for(int i = 0; i < tam; i++) {
        if(X[i] % 2 == 0) {
            A[*tamA] = X[i];
            (*tamA)++;
        } else {
            B[*tamB] = X[i];
            (*tamB)++;
        }
    }
}

// Ex 9 
int contaParesVetor(int X[], int tam) {
    int count = 0;
    for(int i = 0; i < tam; i++) {
        if(X[i] % 2 == 0) count++;
    }
    return count;
}

// Ex 10
float somaVetorReais(float X[], int tam) {
    float soma = 0;
    for(int i = 0; i < tam; i++) soma += X[i];
    return soma;
}

// Ex 18
void somaDoisVetores(int A[], int B[], int Soma[], int tam) {
    for(int i = 0; i < tam; i++) Soma[i] = A[i] + B[i];
}

// Ex 19
void produtoDoisVetores(int A[], int B[], int Produto[], int tam) {
    for(int i = 0; i < tam; i++) Produto[i] = A[i] * B[i];
}


// ============================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES (PARTE 3 - MATRIZES)
// ============================================================================

// Ex 24
int somaMatriz5x5(int M[][5]) {
    int soma = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            soma += M[i][j];
    return soma;
}

// Ex 25
int somaDiagonais6x6(int M[][6]) {
    int soma = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if (i == j) soma += M[i][j];               // Diagonal Principal
            if (i + j == 5) soma += M[i][j];           // Diagonal Secundaria
        }
    }
    return soma;
}

// Ex 26
int somaLinha5Coluna3(int M[][6]) {
    int soma = 0;
    // Considerando indice 4 como Linha 5 e indice 2 como Coluna 3 (0-indexed)
    for(int j = 0; j < 6; j++) soma += M[4][j]; // Soma linha
    for(int i = 0; i < 7; i++) soma += M[i][2]; // Soma coluna
    
    soma -= M[4][2]; // Remove a intersecao para nao somar duas vezes
    return soma;
}

// Ex 27
int menorDiagSecundaria(int M[][6]) {
    int menor = M[0][5]; // Primeiro elemento da diagonal secundaria
    for(int i = 0; i < 6; i++) {
        int j = 5 - i;
        if (M[i][j] < menor) {
            menor = M[i][j];
        }
    }
    return menor;
}