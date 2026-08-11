#include <stdio.h>

// ============================================================
// FUNÇÕES DOS EXERCÍCIOS 3 E 4 (Devem ficar antes do main)
// ============================================================

// Função do Exercício 3 - Troca de Valores
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Função do Exercício 4 - Soma por Referência
void soma(int a, int b, int *resultado) {
    *resultado = a + b;
}

// ============================================================
// FUNÇÃO PRINCIPAL
// ============================================================

int main() {
    int escolha;

    do {
        printf("\n\n ================= MENU DE PONTEIROS =================\n");
        printf(" --- PARTE 1: Exercicios Descritivos ---\n");
        printf(" 1  - Exercicio 1: Valor e Endereco\n");
        printf(" 2  - Exercicio 2: Alteracao por Ponteiro\n");
        printf(" 3  - Exercicio 3: Troca de Valores (funcao)\n");
        printf(" 4  - Exercicio 4: Soma por Referencia (funcao)\n");
        printf(" --- PARTE 2: Testes de Codigo (Snippets) ---\n");
        printf(" 5  - Exercicio 1: Valor e Ponteiro\n");
        printf(" 6  - Exercicio 2: Alteracao por Ponteiro\n");
        printf(" 7  - Exercicio 3: Dois Ponteiros\n");
        printf(" 8  - Exercicio 4: Incremento via Ponteiro\n");
        printf(" 9  - Exercicio 5: Vetor e Ponteiros\n");
        printf(" 10 - Exercicio 6: Aritmetica de Ponteiros\n");
        printf(" --- PARTE 3: Prova 2 (UFCAT) ---\n");
        printf(" 11 - Prova 2 (Ex 1 e 2): Rastreio e Aritmetica de Ponteiros\n");
        printf(" 12 - Prova 2 (Ex 3): Matriz NxN (Diagonais, Bordas, Maior/Menor)\n");
        printf(" 0  - Sair do programa\n");
        printf(" =====================================================\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            
            // ------------------------------------------------
            // PARTE 1: EXERCÍCIOS DESCRITIVOS
            // ------------------------------------------------
            case 1: {
                int var = 10;
                int *ptr = &var;
                
                printf("\n--- Exercicio 1: Valor e Endereco ---\n");
                printf("Valor da variavel: %d\n", var);
                // Usamos (void*) e %p para imprimir endereços de memória corretamente
                printf("Endereco da variavel: %p\n", (void*)&var);
                printf("Conteudo do ponteiro: %p\n", (void*)ptr);
                printf("Valor apontado: %d\n", *ptr);
                break;
            }
            case 2: {
                int var = 20;
                int *ptr = &var;
                
                // Alterando o valor utilizando apenas o ponteiro
                *ptr = 50; 
                
                printf("\n--- Exercicio 2: Alteracao por Ponteiro ---\n");
                printf("Valor final da variavel: %d\n", var);
                printf("Pergunta: O valor da variavel mudou sem ser acessado diretamente?\n");
                printf("Resposta: Sim, pois o ponteiro modificou o valor direto no endereco de memoria.\n");
                break;
            }
            case 3: {
                int a = 5;
                int b = 8;
                
                printf("\n--- Exercicio 3: Troca de Valores ---\n");
                printf("Antes: a = %d, b = %d\n", a, b);
                
                // Chamando a função e passando os endereços de 'a' e 'b'
                troca(&a, &b); 
                
                printf("Depois: a = %d, b = %d\n", a, b);
                break;
            }
            case 4: {
                int a = 15;
                int b = 25;
                int resultado;
                
                printf("\n--- Exercicio 4: Soma por Referencia ---\n");
                // Passa 'a' e 'b' por valor, mas 'resultado' por referência (endereço)
                soma(a, b, &resultado); 
                
                printf("Entrada: %d e %d -> Saida: Resultado = %d\n", a, b, resultado);
                break;
            }

            // ------------------------------------------------
            // PARTE 2: TESTES DE CÓDIGO (SNIPPETS)
            // ------------------------------------------------
            case 5: {
                printf("\n--- Snippet 1: Valor e Ponteiro ---\n");
                int x = 10;
                int *p = &x;
                printf("%d\n", x);
                printf("%d\n", *p);
                break;
            }
            case 6: {
                printf("\n--- Snippet 2: Alteracao por Ponteiro ---\n");
                int x = 5;
                int *p = &x;
                *p = 20;
                printf("%d\n", x);
                break;
            }
            case 7: {
                printf("\n--- Snippet 3: Dois Ponteiros ---\n");
                int a = 10;
                int *p1 = &a;
                int *p2 = p1; // p2 aponta para o mesmo lugar que p1
                *p2 = 30;
                printf("%d\n", a);
                printf("%d\n", *p1);
                break;
            }
            case 8: {
                printf("\n--- Snippet 4: Incremento via Ponteiro ---\n");
                int x = 7;
                int *p = &x;
                (*p)++; // Incrementa o valor de x em 1
                printf("%d\n", x);
                break;
            }
            case 9: {
                printf("\n--- Snippet 5: Vetor e Ponteiros ---\n");
                int v[4] = {10, 20, 30, 40};
                int *p = v; // Ponteiro aponta para a base do vetor (índice 0)
                printf("%d\n", *p);       // v[0]
                printf("%d\n", *(p+1));   // v[1]
                printf("%d\n", *(p+2));   // v[2]
                break;
            }
            case 10: {
                printf("\n--- Snippet 6: Aritmetica de Ponteiros ---\n");
                int v[5] = {5, 10, 15, 20, 25};
                int *p = v;
                p = p + 3; // O ponteiro avança 3 posições na memória (vai para v[3])
                printf("%d\n", *p);
                break;
            }

            // ------------------------------------------------
            // PARTE 3: EXERCÍCIOS DA PROVA 2 (UFCAT)
            // ------------------------------------------------
            case 11: {
                printf("\n--- Prova 2: Ex. 1 (Alteracao por ponteiro) ---\n");
                int a = 10;
                int b = 20;
                int c = 30;
                int *p = &a;
                int *q = &b;
                
                *p = *p + 5;
                *q = *q + *p;
                p = &c;
                *p = *q - a;
                q = &a;
                *q = *p + b;
                
                printf("Saida (a, b, c): \n%d %d %d\n", a, b, c);
                printf("Saida (*p, *q): \n%d %d\n", *p, *q);

                printf("\n--- Prova 2: Ex. 2 (Aritmetica de ponteiros) ---\n");
                int v[6] = {2, 4, 6, 8, 10, 12};
                int *p2 = v + 2;
                
                printf("Saida:\n");
                printf("%d\n", *p2);
                p2--;
                printf("%d\n", *p2);
                p2 = p2 + 3;
                printf("%d\n", *p2);
                *(p2 - 2) = 100;
                printf("%d\n", v[2]);
                printf("%d\n", *(v + 2));
                break;
            }
            case 12: {
                printf("\n--- Prova 2: Ex. 3 (Soma das Diagonais e Bordas) ---\n");
                int N;
                
                printf("Digite o tamanho N da matriz quadrada (Ex: 4 para 4x4): ");
                scanf("%d", &N);
                
                // Limitador de segurança para não explodir a memória do VS Code
                if (N <= 0 || N > 50) {
                    printf("Tamanho invalido! Por favor, use um N entre 1 e 50.\n");
                    break;
                }

                int mat[50][50]; // Tamanho máximo fixo para evitar erros de compilação (VLA)
                int somaPrin = 0, somaSec = 0, somaBorda = 0, somaInt = 0;
                int maior, menor;

                printf("Digite os %d elementos da matriz:\n", N * N);
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        scanf("%d", &mat[i][j]);
                        
                        // Inicializa o maior e menor com o primeiríssimo elemento lido
                        if (i == 0 && j == 0) {
                            maior = mat[i][j];
                            menor = mat[i][j];
                        } else {
                            if (mat[i][j] > maior) maior = mat[i][j];
                            if (mat[i][j] < menor) menor = mat[i][j];
                        }

                        // Verifica Diagonal principal
                        if (i == j) somaPrin += mat[i][j];

                        // Verifica Diagonal secundária
                        if (i + j == N - 1) somaSec += mat[i][j];

                        // Verifica se é Borda (primeira/última linha OU primeira/última coluna)
                        if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                            somaBorda += mat[i][j];
                        } else {
                            // Se não é borda, com certeza é interno
                            somaInt += mat[i][j];
                        }
                    }
                }

                printf("\n--- RESULTADOS DA MATRIZ ---\n");
                printf("Soma da diagonal principal: %d\n", somaPrin);
                printf("Soma da diagonal secundaria: %d\n", somaSec);
                printf("Soma dos elementos da borda: %d\n", somaBorda);
                printf("Soma dos elementos internos: %d\n", somaInt);
                printf("Maior valor da matriz: %d\n", maior);
                printf("Menor valor da matriz: %d\n", menor);
                break;
            }

            case 0:
                printf("\n Encerrando o programa...\n");
                break;
            default:
                printf("\n Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (escolha != 0);

    return 0;
}