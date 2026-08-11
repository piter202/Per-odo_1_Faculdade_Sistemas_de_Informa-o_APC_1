#include <stdio.h>

int main() {
    int escolha;

    do {
        printf("\n========================================================================\n");
        printf("                          MENU DE EXERCICIOS\n");
        printf("========================================================================\n");
        printf(" --- LISTA DE MATRIZES ---\n");
        printf(" 1 - Exercicio 1: Matriz Transposta (MxN)\n");
        printf(" 2 - Exercicio 2: Multiplicacao de duas matrizes\n");
        printf(" 3 - Exercicio 3: Multiplicar matriz 2x3 por um numero inteiro\n");
        printf(" 4 - Exercicio 4: Soma de duas matrizes 3x3\n");
        printf(" 5 - Exercicio 5: Verificar se matriz MxN e identidade\n");
        printf(" --- PROVA SUBSTITUTIVA 1 (Exercicios a mao) ---\n");
        printf(" 6 - Exercicio 6 (Prova Sub 1): Verificar se vetor de 3 esta contido no de 20\n");
        printf(" 7 - Exercicio 7 (Prova Sub 1): Comparar somas de quadrantes em matriz 6x6\n");
        printf(" 0 - Sair do programa\n");
        printf("========================================================================\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                // Desenvolva um programa que dada uma matriz MxN descreva sua forma transposta.
                int m, n;
                printf("\n--- Matriz Transposta ---\n");
                printf("Digite a quantidade de linhas (M) e colunas (N): ");
                scanf("%d %d", &m, &n);

                int matriz[m][n], transposta[n][m];

                printf("Digite os elementos da matriz %dx%d:\n", m, n);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%d", &matriz[i][j]);
                        transposta[j][i] = matriz[i][j]; // Já vai construindo a transposta
                    }
                }

                printf("\nMatriz Original:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", matriz[i][j]);
                    }
                    printf("\n");
                }

                printf("\nMatriz Transposta:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", transposta[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 2: {
                // Verifique se duas matrizes podem ser multiplicadas, caso for, realize a multiplicação.
                int l1, c1, l2, c2;
                printf("\n--- Multiplicacao de Matrizes ---\n");
                printf("Digite as dimensoes (linhas e colunas) da Matriz 1: ");
                scanf("%d %d", &l1, &c1);
                printf("Digite as dimensoes (linhas e colunas) da Matriz 2: ");
                scanf("%d %d", &l2, &c2);

                if (c1 != l2) {
                    printf("\nErro: Nao e possivel multiplicar as matrizes! O numero de colunas da M1 (%d) deve ser igual ao numero de linhas da M2 (%d).\n", c1, l2);
                } else {
                    int m1[l1][c1], m2[l2][c2], m3[l1][c2];

                    printf("\nDigite os valores da Matriz 1:\n");
                    for (int i = 0; i < l1; i++)
                        for (int j = 0; j < c1; j++)
                            scanf("%d", &m1[i][j]);

                    printf("\nDigite os valores da Matriz 2:\n");
                    for (int i = 0; i < l2; i++)
                        for (int j = 0; j < c2; j++)
                            scanf("%d", &m2[i][j]);

                    // Zerando e calculando a matriz resultante (Matriz 3)
                    for (int i = 0; i < l1; i++) {
                        for (int j = 0; j < c2; j++) {
                            m3[i][j] = 0;
                            for (int k = 0; k < c1; k++) {
                                m3[i][j] += m1[i][k] * m2[k][j];
                            }
                        }
                    }

                    printf("\nMatriz Resultante da Multiplicacao:\n");
                    for (int i = 0; i < l1; i++) {
                        for (int j = 0; j < c2; j++) {
                            printf("%d ", m3[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;
            }

            case 3: {
                // Leia uma matriz 2x3 e um numero; multiplique a matriz pelo numero.
                int mat[2][3], num;
                
                printf("\n--- Multiplicar Matriz 2x3 por Inteiro ---\n");
                printf("Digite os 6 elementos da matriz 2x3:\n");
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        scanf("%d", &mat[i][j]);
                    }
                }

                printf("Digite um numero inteiro para multiplicar a matriz: ");
                scanf("%d", &num);

                printf("\nNova Matriz Resultante:\n");
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        printf("%d ", mat[i][j] * num);
                    }
                    printf("\n");
                }
                break;
            }

            case 4: {
                // Crie um programa que leia duas matrizes 3x3 e realize a soma entre elas.
                int m1[3][3], m2[3][3], soma[3][3];

                printf("\n--- Soma de Matrizes 3x3 ---\n");
                printf("Digite os valores da Matriz 1:\n");
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        scanf("%d", &m1[i][j]);

                printf("\nDigite os valores da Matriz 2:\n");
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        scanf("%d", &m2[i][j]);

                printf("\nMatriz Resultante da Soma:\n");
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        soma[i][j] = m1[i][j] + m2[i][j];
                        printf("%d ", soma[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 5: {
                // Leia uma matriz MxN e verifique se ela e identidade.
                int m, n, identidade = 1;

                printf("\n--- Verificador de Matriz Identidade ---\n");
                printf("Digite as dimensoes da matriz (MxN): ");
                scanf("%d %d", &m, &n);

                int mat[m][n];
                printf("Digite os elementos da matriz:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%d", &mat[i][j]);
                    }
                }

                // Condição 1: Para ser identidade precisa ser quadrada
                if (m != n) {
                    identidade = 0;
                } else {
                    // Condição 2: Diagonal principal deve ser 1, o resto 0
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                            if (i == j && mat[i][j] != 1) {
                                identidade = 0;
                            }
                            if (i != j && mat[i][j] != 0) {
                                identidade = 0;
                            }
                        }
                    }
                }

                if (identidade == 1) {
                    printf("\nA matriz informada E uma Matriz Identidade!\n");
                } else {
                    printf("\nA matriz informada NAO E uma Matriz Identidade.\n");
                }
                break;
            }

            case 6: {
                // PROVA SUBSTITUTIVA 1 
                // Verifica se um vetor de 3 posições está contido dentro de um vetor de 20 posições.
                printf("\n--- PROVA SUBSTITUTIVA 1: Sub-vetor ---\n");
                int vet1[3], vet2[20];
                int i, j, encontrado = 0;

                printf("Digite os 3 elementos do primeiro vetor:\n");
                for (i = 0; i < 3; i++) {
                    scanf("%d", &vet1[i]);
                }

                printf("Digite os 20 elementos do segundo vetor:\n");
                for (i = 0; i < 20; i++) {
                    scanf("%d", &vet2[i]);
                }

                // procura o padrão do vetor 1 dentro do vetor 2
                for (i = 0; i <= 20 - 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (vet2[i + j] != vet1[j]) {
                            break; // Se um elemento nao bater, quebra o laco interno
                        }
                    }
                    if (j == 3) {
                        encontrado = 1;
                        break; // Encontrou o padrao todo, quebra o laco externo
                    }
                }

                if (encontrado == 1) {
                    printf("\nO vetor 1 esta dentro do vetor 2!\n");
                } else {
                    printf("\nO vetor 1 nao esta contido no vetor 2.\n");
                }
                break;
            }

            case 7: {
                // PROVA SUBSTITUTIVA 1 
                // Lê matriz 6x6, compara soma do quadrante superior esquerdo (A) com inferior direito (B)
                printf("\n--- PROVA SUBSTITUTIVA 1: Quadrantes da Matriz 6x6 ---\n");
                int matriz[6][6];
                int i, j, A = 0, B = 0;

                printf("Digite os 36 valores para a matriz 6x6:\n");
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 6; j++) {
                        scanf("%d", &matriz[i][j]);
                    }
                }

                // Soma do Quadrante Superior Esquerdo (3x3 inicial)
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        A += matriz[i][j];
                    }
                }

                // Soma do Quadrante Inferior Direito (3x3 final)
                for (i = 3; i < 6; i++) {
                    for (j = 3; j < 6; j++) {
                        B += matriz[i][j];
                    }
                }

                // Comparacao e exibicao 
                if (A > B) {
                    printf("\nA e maior que B\n");
                } else if (B > A) {
                    printf("\nB e maior que A\n");
                } else {
                    printf("\nA e B sao iguais\n");
                }
                break;
            }

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (escolha != 0);

    return 0;
}