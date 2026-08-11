#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("\n Escolha o exercicio desejado: \n");
    printf(" 1  - Contar pares e impares (12 posicoes)\n");
    printf(" 2  - Copiar apenas numeros positivos para outro vetor (10 posicoes)\n");
    printf(" 3  - Mostrar vetor de 20 elementos na ordem inversa\n");
    printf(" 4  - Somar elementos correspondentes dos vetores A e B (10 posicoes)\n");
    printf(" 5  - Substituir numeros negativos por 0 (15 posicoes)\n");
    printf(" 6  - Buscar um numero no vetor e indicar a posicao (10 posicoes)\n");
    printf(" 7  - Contar quantes vezes um numero aparece no vetor\n");
    printf(" 8  - Ordenar 10 numeros em ordem crescente\n");
    printf(" 9  - Remover elementos repetidos de um vetor (20 posicoes)\n");
    printf(" 10 - Dividir 12 numeros em dois vetores (pares e impares)\n");
    printf(" 13 - Verificar se dois vetores de 10 posicoes sao iguais\n");
    printf(" 14 - Rotacionar elementos do vetor uma posicao para a direita\n");
    printf(" 15 - Inverter uma frase/string\n");
    printf(" 16 - Verificar se duas palavras sao iguais\n");
    printf(" 17 - Substituir todas as letras 'a' por '@' em uma frase\n");
    printf(" 18 - Verificar se uma palavra e um palindromo\n");
    printf(" 19 - Contar vogais, consoantes, numeros e caracteres especiais em uma frase\n");
    printf(" 20 - Remover todos os espacos em branco de uma string\n");
    printf(" 21 - Mostrar apenas o primeiro nome de um nome completo\n\n");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha)
    {
        case 1:
        {
            // Lê um vetor com 12 posições e conta quantos são pares e ímpares
            int vet[12], pares = 0, impares = 0;

            printf("\n Digite 12 numeros inteiros: \n");
            for (int i = 0; i < 12; i++) {
                scanf("%d", &vet[i]);
                if (vet[i] % 2 == 0) {
                    pares++;
                } else {
                    impares++;
                }
            }
            printf("\n Numeros pares: %d | Numeros impares: %d \n", pares, impares);
            break;
        }

        case 2:
        {
            // Lê 10 números e copia apenas os positivos para outro vetor
            int vet[10], positivos[10], contPos = 0;

            printf("\n Digite 10 numeros: \n");
            for (int i = 0; i < 10; i++) {
                scanf("%d", &vet[i]);
                if (vet[i] > 0) {
                    positivos[contPos] = vet[i];
                    contPos++;
                }
            }

            printf("\n Vetor de numeros positivos: ");
            for (int i = 0; i < contPos; i++) {
                printf("%d ", positivos[i]);
            }
            printf("\n");
            break;
        }

        case 3:
        {
            // Lê 20 elementos inteiros e exibe na ordem inversa
            int vet[20];

            printf("\n Digite 20 numeros inteiros: \n");
            for (int i = 0; i < 20; i++) {
                scanf("%d", &vet[i]);
            }

            printf("\n Vetor na ordem inversa: \n");
            for (int i = 19; i >= 0; i--) {
                printf("%d ", vet[i]);
            }
            printf("\n");
            break;
        }

        case 4:
        {
            // Lê vetores A e B de 10 posições e gera C = A + B
            int A[10], B[10], C[10];

            printf("\n Digite 10 elementos do Vetor A: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &A[i]);

            printf("\n Digite 10 elementos do Vetor B: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &B[i]);

            printf("\n Vetor C (Soma de A + B): \n");
            for (int i = 0; i < 10; i++) {
                C[i] = A[i] + B[i];
                printf("%d ", C[i]);
            }
            printf("\n");
            break;
        }

        case 5:
        {
            // Substitui números negativos por 0 em um vetor de 15 posições
            int vet[15];

            printf("\n Digite 15 numeros: \n");
            for (int i = 0; i < 15; i++) {
                scanf("%d", &vet[i]);
                if (vet[i] < 0) {
                    vet[i] = 0;
                }
            }

            printf("\n Vetor atualizado (negativos trocados por 0): \n");
            for (int i = 0; i < 15; i++) {
                printf("%d ", vet[i]);
            }
            printf("\n");
            break;
        }

        case 6:
        {
            // Verifica se um número existe no vetor de 10 posições e mostra sua posição
            int vet[10], busca, achou = 0;

            printf("\n Digite 10 valores para o vetor: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);

            printf("\n Digite o numero que deseja buscar: \n");
            scanf("%d", &busca);

            for (int i = 0; i < 10; i++) {
                if (vet[i] == busca) {
                    printf(" O numero %d foi encontrado na posicao %d (indice %d)\n", busca, i + 1, i);
                    achou = 1;
                }
            }
            if (!achou) {
                printf(" O numero %d nao existe no vetor.\n", busca);
            }
            break;
        }

        case 7:
        {
            // Informa quantas vezes um determinado número aparece no vetor
            int vet[10], busca, cont = 0;

            printf("\n Digite 10 valores do vetor: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);

            printf("\n Digite o numero para contar ocorrencias: \n");
            scanf("%d", &busca);

            for (int i = 0; i < 10; i++) {
                if (vet[i] == busca) {
                    cont++;
                }
            }
            printf("\n O numero %d aparece %d vez(es) no vetor.\n", busca, cont);
            break;
        }

        case 8:
        {
            // Ordena um vetor de 10 números em ordem crescente (Bubble Sort)
            int vet[10], aux;

            printf("\n Digite 10 numeros inteiros: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);

            for (int i = 0; i < 10 - 1; i++) {
                for (int j = 0; j < 10 - i - 1; j++) {
                    if (vet[j] > vet[j + 1]) {
                        aux = vet[j];
                        vet[j] = vet[j + 1];
                        vet[j + 1] = aux;
                    }
                }
            }

            printf("\n Vetor em ordem crescente: \n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", vet[i]);
            }
            printf("\n");
            break;
        }

        case 9:
        {
            // Remove elementos repetidos de um vetor de 20 posições
            int vet[20], unicos[20], qtdUnicos = 0;

            printf("\n Digite 20 numeros inteiros: \n");
            for (int i = 0; i < 20; i++) scanf("%d", &vet[i]);

            for (int i = 0; i < 20; i++) {
                int repetido = 0;
                for (int j = 0; j < qtdUnicos; j++) {
                    if (vet[i] == unicos[j]) {
                        repetido = 1;
                        break;
                    }
                }
                if (!repetido) {
                    unicos[qtdUnicos] = vet[i];
                    qtdUnicos++;
                }
            }

            printf("\n Vetor sem elementos repetidos: \n");
            for (int i = 0; i < qtdUnicos; i++) {
                printf("%d ", unicos[i]);
            }
            printf("\n");
            break;
        }

        case 10:
        case 11:
        case 12:
        {
            // Exercícios 10, 11 e 12 da lista:
            // Lê 12 números e separa em dois vetores (um de pares e outro de ímpares)
            int vet[12], pares[12], impares[12], contP = 0, contI = 0;

            printf("\n Digite 12 numeros inteiros: \n");
            for (int i = 0; i < 12; i++) {
                scanf("%d", &vet[i]);
                if (vet[i] % 2 == 0) {
                    pares[contP++] = vet[i];
                } else {
                    impares[contI++] = vet[i];
                }
            }

            printf("\n Vetor de Pares: ");
            for (int i = 0; i < contP; i++) printf("%d ", pares[i]);

            printf("\n Vetor de Impares: ");
            for (int i = 0; i < contI; i++) printf("%d ", impares[i]);
            printf("\n");
            break;
        }

        case 13:
        {
            // Verifica se dois vetores de 10 posições são iguais
            int A[10], B[10], iguais = 1;

            printf("\n Digite 10 elementos do Vetor A: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &A[i]);

            printf("\n Digite 10 elementos do Vetor B: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &B[i]);

            for (int i = 0; i < 10; i++) {
                if (A[i] != B[i]) {
                    iguais = 0;
                    break;
                }
            }

            if (iguais) {
                printf("\n Os dois vetores são EXATAMENTE iguais. \n");
            } else {
                printf("\n Os dois vetores sao DIFERENTES. \n");
            }
            break;
        }

        case 14:
        {
            // Rotaciona os elementos de um vetor uma posição para a direita
            int vet[10], aux;

            printf("\n Digite 10 elementos para o vetor: \n");
            for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);

            aux = vet[9]; // guarda o último elemento
            for (int i = 9; i > 0; i--) {
                vet[i] = vet[i - 1];
            }
            vet[0] = aux; // o último vira o primeiro

            printf("\n Vetor rotacionado para a direita: \n");
            for (int i = 0; i < 10; i++) {
                printf("%d ", vet[i]);
            }
            printf("\n");
            break;
        }

        case 15:
        {
            // Lê uma string e exibe a frase invertida
            char frase[100];

            printf("\n Digite uma frase: \n");
            scanf(" %[^\n]", frase); // lê a frase com espaços

            int len = strlen(frase);
            printf("\n Frase invertida: ");
            for (int i = len - 1; i >= 0; i--) {
                printf("%c", frase[i]);
            }
            printf("\n");
            break;
        }

        case 16:
        {
            // Lê duas palavras e verifica se são iguais
            char p1[50], p2[50];

            printf("\n Digite a primeira palavra: \n");
            scanf("%s", p1);
            printf("\n Digite a segunda palavra: \n");
            scanf("%s", p2);

            if (strcmp(p1, p2) == 0) {
                printf("\n As palavras sao iguais. \n");
            } else {
                printf("\n As palavras sao diferentes. \n");
            }
            break;
        }

        case 17:
        {
            // Substitui todas as letras 'a' ou 'A' por '@'
            char frase[100];

            printf("\n Digite uma frase: \n");
            scanf(" %[^\n]", frase);

            for (int i = 0; frase[i] != '\0'; i++) {
                if (frase[i] == 'a' || frase[i] == 'A') {
                    frase[i] = '@';
                }
            }

            printf("\n Frase modificada: %s \n", frase);
            break;
        }

        case 18:
        {
            // Verifica se uma palavra é um palíndromo (ex: arara, ovo)
            char palavra[50];
            int ePalindromo = 1;

            printf("\n Digite uma palavra: \n");
            scanf("%s", palavra);

            int len = strlen(palavra);
            for (int i = 0; i < len / 2; i++) {
                if (tolower(palavra[i]) != tolower(palavra[len - 1 - i])) {
                    ePalindromo = 0;
                    break;
                }
            }

            if (ePalindromo) {
                printf("\n A palavra '%s' e um PALINDROMO! \n", palavra);
            } else {
                printf("\n A palavra '%s' NAO e um palindromo. \n", palavra);
            }
            break;
        }

        case 19:
        {
            // Conta vogais, consoantes, números e caracteres especiais em uma frase
            char frase[100];
            int vogais = 0, consoantes = 0, numeros = 0, especiais = 0;

            printf("\n Digite uma frase: \n");
            scanf(" %[^\n]", frase);

            for (int i = 0; frase[i] != '\0'; i++) {
                char c = tolower(frase[i]);

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vogais++;
                } else if (c >= 'a' && c <= 'z') {
                    consoantes++;
                } else if (isdigit(c)) {
                    numeros++;
                } else if (c != ' ') {
                    especiais++;
                }
            }

            printf("\n Vogais: %d | Consoantes: %d | Numeros: %d | Especiais: %d \n", 
                   vogais, consoantes, numeros, especiais);
            break;
        }

        case 20:
        {
            // Remove todos os espaços em branco de uma string
            char str[100], semEspaco[100];
            int j = 0;

            printf("\n Digite uma frase/string: \n");
            scanf(" %[^\n]", str);

            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] != ' ') {
                    semEspaco[j++] = str[i];
                }
            }
            semEspaco[j] = '\0';

            printf("\n String sem espacos: %s \n", semEspaco);
            break;
        }

        case 21:
        {
            // Mostra apenas o primeiro nome de um nome completo
            char nomeCompleto[100], primeiroNome[50];

            printf("\n Digite seu nome completo: \n");
            scanf(" %[^\n]", nomeCompleto);

            int i = 0;
            while (nomeCompleto[i] != ' ' && nomeCompleto[i] != '\0') {
                primeiroNome[i] = nomeCompleto[i];
                i++;
            }
            primeiroNome[i] = '\0';

            printf("\n Primeiro nome: %s \n", primeiroNome);
            break;
        }

        default:
            printf("\n Exercicio invalido \n");
            break;
    }

    return 0;
}