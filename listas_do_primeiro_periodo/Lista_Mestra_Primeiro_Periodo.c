#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159

// ============================================================================
// FUNÇÕES E PROCEDIMENTOS (Listas 8 e 9)
// ============================================================================

// --- Funções da Lista 9 (Ponteiros) ---
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void somaReferencia(int a, int b, int *resultado) {
    *resultado = a + b;
}

// --- Funções da Lista 8 (Matemática, Vetores e Matrizes) ---
float calcVolumeEsfera(float raio) {
    return (4.0 / 3.0) * PI * pow(raio, 3);
}

void calcMediaAluno(float n1, float n2, float n3, char letra, float *resultado) {
    if (letra == 'A' || letra == 'a') {
        *resultado = (n1 + n2 + n3) / 3.0;
    } else if (letra == 'P' || letra == 'p') {
        *resultado = ((n1 * 5) + (n2 * 3) + (n3 * 2)) / 10.0;
    } else if (letra == 'H' || letra == 'h') {
        if(n1 == 0 || n2 == 0 || n3 == 0) *resultado = 0; 
        else *resultado = 3.0 / ((1.0/n1) + (1.0/n2) + (1.0/n3));
    } else {
        *resultado = -1;
    }
}

bool isPrimo(int valor) {
    if (valor <= 1) return false;
    for (int i = 2; i <= sqrt(valor); i++) {
        if (valor % i == 0) return false;
    }
    return true;
}

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

void converteTempo(int tempo_seg, int *h, int *m, int *s) {
    *h = tempo_seg / 3600;
    int resto = tempo_seg % 3600;
    *m = resto / 60;
    *s = resto % 60;
}

int idadeEmDias(int anos, int meses, int dias) {
    return (anos * 365) + (meses * 30) + dias;
}

bool isPerfeito(int valor) {
    int soma = 0;
    for (int i = 1; i < valor; i++) {
        if (valor % i == 0) soma += i;
    }
    return (soma == valor);
}

void categoriaNadador(int idade, char categoria[]) {
    if (idade >= 5 && idade <= 7) strcpy(categoria, "Infantil A");
    else if (idade >= 8 && idade <= 10) strcpy(categoria, "Infantil B");
    else if (idade >= 11 && idade <= 13) strcpy(categoria, "Juvenil A");
    else if (idade >= 14 && idade <= 17) strcpy(categoria, "Juvenil B");
    else if (idade >= 18) strcpy(categoria, "Adulto");
    else strcpy(categoria, "Sem Categoria");
}

long long calcFatorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fat = 1;
    for(int i = 2; i <= n; i++) fat *= i;
    return fat;
}

void fatoraVetor(int A[], int B[], int tam) {
    for(int i = 0; i < tam; i++) {
        B[i] = calcFatorial(A[i]);
    }
}

void uniaoVetores(int A[], int B[], int Uniao[], int *tamUniao, int tam) {
    *tamUniao = 0;
    for(int i = 0; i < tam; i++) {
        Uniao[*tamUniao] = A[i];
        (*tamUniao)++;
    }
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

int contaParesVetor(int X[], int tam) {
    int count = 0;
    for(int i = 0; i < tam; i++) {
        if(X[i] % 2 == 0) count++;
    }
    return count;
}

float somaVetorReais(float X[], int tam) {
    float soma = 0;
    for(int i = 0; i < tam; i++) soma += X[i];
    return soma;
}

void somaDoisVetores(int A[], int B[], int Soma[], int tam) {
    for(int i = 0; i < tam; i++) Soma[i] = A[i] + B[i];
}

void produtoDoisVetores(int A[], int B[], int Produto[], int tam) {
    for(int i = 0; i < tam; i++) Produto[i] = A[i] * B[i];
}

int somaMatriz5x5(int M[][5]) {
    int soma = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            soma += M[i][j];
    return soma;
}

int somaDiagonais6x6(int M[][6]) {
    int soma = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if (i == j) soma += M[i][j];               
            if (i + j == 5) soma += M[i][j];           
        }
    }
    return soma;
}

int somaLinha5Coluna3(int M[][6]) {
    int soma = 0;
    for(int j = 0; j < 6; j++) soma += M[4][j]; 
    for(int i = 0; i < 7; i++) soma += M[i][2]; 
    soma -= M[4][2]; 
    return soma;
}

int menorDiagSecundaria(int M[][6]) {
    int menor = M[0][5]; 
    for(int i = 0; i < 6; i++) {
        int j = 5 - i;
        if (M[i][j] < menor) {
            menor = M[i][j];
        }
    }
    return menor;
}

// ============================================================================
// FUNÇÃO PRINCIPAL (MENU MESTRE)
// ============================================================================

int main() {
    int menu_mestre;

    do {
        printf("\n\n=======================================================\n");
        printf("               MENU MESTRE DE PROGRAMACAO              \n");
        printf("=======================================================\n");
        printf(" 1 - Lista 1: Operacoes Matematicas Basicas\n");
        printf(" 2 - Lista 2: Condicionais (if/else)\n");
        printf(" 3 - Lista 3: Menus de Opcoes (switch)\n");
        printf(" 4 - Lista 4: Lacos de Repeticao I (for/while)\n");
        printf(" 5 - Lista 5: Lacos de Repeticao II e Prova 1\n");
        printf(" 6 - Lista 6: Vetores e Strings\n");
        printf(" 7 - Lista 7: Matrizes e Prova Substitutiva\n");
        printf(" 8 - Lista 8: Funcoes, Procedimentos e Vetores/Matrizes\n");
        printf(" 9 - Lista 9: Ponteiros e Prova 2\n");
        printf(" 0 - Sair de todos os programas\n");
        printf("=======================================================\n");
        printf(" Escolha a lista que deseja acessar: ");
        scanf("%d", &menu_mestre);

        switch (menu_mestre) {
            case 1: {
                printf("\n --- ACESSANDO LISTA 1 --- \n");
                printf("\n escreva o exercicio desejado: \n");
                printf("\n 1 - Exercicio 1: calcular a media de 3 notas com pesos de 2, 3 e 5 \n 2 - Exercicio 2: converter segundos em horas, minutos e segundos \n 3 - Exercicio 3: calcular area e perimetro de um retangulo \n 4 - Exercicio 4: calcular volume de um paralelepipedo \n 5 - Exercicio 5: converter Celsius para Fahrenheit \n 6 - Exercicio 6: calcular salario de um funcionário \n 7 - Exercicio 7: calcular consumo medio de um carro \n \n");
                int exercicio;
                scanf("%d", &exercicio);

                if (exercicio == 1) {
                    float media, n1, n2, n3;
                    printf("\n Digite a nota 1: \n"); scanf("%f", &n1);
                    printf("\n Digite a nota 2: \n"); scanf("%f", &n2);
                    printf("\n Digite a nota 3: \n"); scanf("%f", &n3);
                    media = n1*0.2 + n2*0.3 + n3*0.5;
                    printf("A media e: %.2f \n", media);
                } else if (exercicio == 2) {
                    int segundostotais, horas, minutos, segundos, resto;
                    printf("\n Digite o numero de segundos: \n");
                    scanf("%d", &segundostotais);
                    horas = segundostotais / 3600;
                    resto = segundostotais % 3600;
                    minutos = resto / 60;
                    segundos = resto % 60;
                    printf("\n O tempo e: %d:%d:%d \n", horas, minutos, segundos);
                } else if (exercicio == 3) {
                    int base, altura, area, perimetro;
                    printf("\n Digite a base e a altura : \n");
                    scanf("%d %d", &base, &altura);
                    area = base * altura;
                    perimetro = 2 * (base + altura);
                    printf("\n A area e: %d \n O perimetro e: %d \n", area, perimetro);
                } else if (exercicio == 4) {
                    int comprimento, largura, altura, volume;
                    printf("\n Digite o comprimento, largura e altura: \n");
                    scanf("%d %d %d", &comprimento, &largura, &altura);
                    volume = comprimento * largura * altura;
                    printf("\n O volume e: %d \n", volume);
                } else if (exercicio == 5) {
                    float celsius, fahrenheit;
                    printf("\n Digite a temperatura em Celsius: \n");
                    scanf("%f", &celsius);
                    fahrenheit = (celsius * 9 / 5) + 32;
                    printf("\n A temperatura em Fahrenheit e: %.2f \n", fahrenheit);
                } else if (exercicio == 6) {
                    float valorhora, horasmes, salario;
                    printf("\n Digite o valor da hora e as horas trabalhadas no mes: \n");
                    scanf("%f %f", &valorhora, &horasmes);
                    salario = valorhora * horasmes;
                    printf("\n O salario e: %.2f \n", salario);
                } else if (exercicio == 7) {
                    float distancia, litros, consumo;
                    printf("\n Digite a distancia percorrida e os litros consumidos: \n");
                    scanf("%f %f", &distancia, &litros);
                    consumo = distancia / litros;
                    printf("\n O consumo medio e: %.2f km/l \n", consumo);
                } else {
                    printf("Exercicio invalido \n");
                }
                break;
            }
            
            case 2: {
                printf("\n --- ACESSANDO LISTA 2 --- \n");
                printf("\n escreva o exercicio desejado: \n");
                printf("\n 1 - Exercicio 1: descobre se e impar ou par \n 2 - exercicio 2: descobre qual o maior entre 2 numeros \n 3 - exercicio 3: descobre se o numero é positivo, negativo se é zero \n 4 - execicio 4: diz pela nota do aluno se ele foi aprovado ou reprovado \n 5 - exercicio 5: diz se o eleitor é facultativo, obrigatório ou não eleitor \n 6 - exercicio 6: diz qual o maior entre 3 numeros \n 7 - exercicio 7: diz se o triangulo é equilatero, isosceles ou escaleno \n 8 - execicio 8: calcula o IMC \n 9 - exercicio 9 : diz se a nota do aluno foi A, B, C, D ou invalida \n \n");
                int exercicio;
                scanf("%d", &exercicio);

                if (exercicio == 1) {
                    int numero;
                    printf("\n Digite um numero: \n"); scanf("%d", &numero);
                    if (numero % 2 == 0) printf("\n O numero e par \n");
                    else printf("\n O numero e impar \n");
                } else if (exercicio == 2) {
                    int n1, n2;
                    printf("\n Digite o numero 1 e o numero 2: \n");
                    scanf("%d %d", &n1, &n2);
                    if (n1 > n2) printf("\n o maior numero e %d \n", n1);
                    else if (n2 > n1) printf("\n o maior numero e %d \n", n2);
                    else printf("\n Os numeros sao iguais \n");
                } else if (exercicio == 3) {
                    int numero;
                    printf("\n Digite um numero: \n"); scanf("%d", &numero);
                    if (numero > 0) printf("\n O numero e positivo \n");
                    else if (numero < 0) printf("\n O numero e negativo \n");
                    else printf("\n O numero e zero \n");
                } else if (exercicio == 4) {
                    float nota;
                    printf("\n Digite a nota do aluno: \n"); scanf("%f", &nota);
                    if (nota >= 7 && nota <= 10) printf("\n O aluno foi aprovado \n");
                    else if (nota >= 0 && nota < 7) printf("\n O aluno foi reprovado \n");
                    else printf("\n Nota invalida \n");
                } else if (exercicio == 5) {
                    int idade;
                    printf("\n Digite a idade do eleitor: \n"); scanf("%d", &idade);
                    if (idade >= 18 && idade <= 70) printf("\n O eleitor e obrigatorio \n");
                    else if (idade >= 16 && idade < 18 || idade > 70) printf("\n O eleitor e facultativo \n");
                    else printf("\n O eleitor nao e permitido votar \n");
                } else if (exercicio == 6) {
                    int n1, n2, n3;
                    printf("\n Digite o numero 1, numero 2 e numero 3: \n");
                    scanf("%d %d %d", &n1, &n2, &n3);
                    if (n1 >= n2 && n1 >= n3) printf("\n O maior número e %d \n", n1);
                    else if (n2 >= n1 && n2 >= n3) printf("\n O maior número e %d \n", n2);
                    else printf("\n O maior número e %d \n", n3);
                } else if (exercicio == 7) {
                    int lado1, lado2, lado3;
                    printf("\n Digite os lados do triangulo: \n");
                    scanf("%d %d %d", &lado1, &lado2, &lado3);
                    if (lado1 == lado2 && lado2 == lado3) printf("\n O triangulo e equilatero \n");
                    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) printf("\n O triangulo e isosceles \n");
                    else printf("\n O triangulo e escaleno \n");
                } else if (exercicio == 8) {
                    float peso, altura, imc;
                    printf("\n Digite o peso em kg e a altura em metros: \n");
                    scanf("%f %f", &peso, &altura);
                    imc = peso / (altura * altura);
                    printf("\n O IMC e: %.2f \n", imc);
                    if (imc < 18.5) printf("\n Abaixo do peso \n");
                    else if (imc >= 18.5 && imc < 25) printf("\n Peso normal \n");
                    else if (imc >= 25 && imc < 30) printf("\n Sobrepeso \n");
                    else printf("\n Obesidade \n");
                } else if (exercicio == 9) {
                    float nota;
                    printf("\n Digite a nota do aluno: \n"); scanf("%f", &nota);
                    if (nota >= 9 && nota <= 10) printf("\n A nota do aluno e A \n");
                    else if (nota >= 7.5 && nota < 9) printf("\n A nota do aluno e B \n");
                    else if (nota >= 6 && nota < 7.5) printf("\n A nota do aluno e C \n");
                    else if (nota >= 0 && nota < 6) printf("\n A nota do aluno e D \n");
                    else printf("\n Nota invalida \n");
                } else {
                    printf("\n Exercicio invalido \n");
                }
                break;
            }

            case 3: {
                printf("\n --- ACESSANDO LISTA 3 --- \n");
                printf("\n escreva o exercicio desejado: \n");
                printf("\n 1 - Exercicio 1: menu de escolha entre operacoes \n 2 - exercicio 2: calcula o aumento do salario de um funcionario que recebe 500 ou menos \n 3 - exercicio 3: calcula o valor de um credito dependendo do valor \n 4 - exercicio 4: calcula o ganho de um investimento \n 5 - exercicio 5: verifica se a senha digitada e correta \n 6 - exercicio 6: verifica se a idade digitada e permitida para acesso\n \n");

                int escolha;
                scanf("%d", &escolha);

                switch (escolha) {   
                    case 1: {
                        float n1, n2, media, diferenca, produto, divisao;
                        printf("\n Digite o numero 1 e o numero 2: \n");
                        scanf("%f %f", &n1, &n2);
                        printf("\n Escolha a operacao desejada: \n 1 - Media \n 2 - Diferenca \n 3 - Produto \n 4 - Divisao \n");
                        int opcao;
                        scanf("%d", &opcao);
                        switch (opcao) {
                            case 1:
                                media = (n1 + n2) / 2;
                                printf("\n A media dos numeros e: %.2f \n", media);
                                break;
                            case 2:
                                diferenca = n1 - n2;
                                printf("\n A diferença entre os numeros e: %.2f \n", diferenca);
                                break;
                            case 3:
                                produto = n1 * n2;
                                printf("\n O produto dos numeros e: %.2f \n", produto);
                                break;
                            case 4:
                                if (n2 != 0) {
                                    divisao = n1 / n2;
                                    printf("\n A divisão dos numeros e: %.2f \n", divisao);
                                } else {
                                    printf("\n Divisão por zero nao é permitida \n");
                                }
                                break;
                            default:
                                printf("\n Opcao invalida \n");
                                break;
                        }
                        break;
                    }
                    case 2: {
                        float salario, aumento, novo_salario;
                        printf("\n Digite o salario do funcionario: \n");
                        scanf("%f", &salario);
                        if (salario <= 500) {
                            aumento = salario * 0.30;
                            novo_salario = salario + aumento;
                            printf("\n O novo salario do funcionario e: %.2f \n", novo_salario);
                        } else {
                            printf("\n O funcionario nao tem direito a aumento \n");
                        }
                        break;
                    }
                    case 3: {
                        float saldo, credito;
                        printf("\n Digite o saldo atual \n");
                        scanf("%f", &saldo);
                        if (saldo >= 400) credito = saldo * 0.3;
                        else if (saldo >= 300) credito = saldo * 0.25;
                        else if (saldo >= 200) credito = saldo * 0.2;
                        else credito = saldo * 0.1;   
                        printf("\n o valor do credito e: %.2f \n", credito);
                        break;
                    }
                    case 4: {
                        float investimento, poupanca, fundos_de_renda_fixa;
                        printf("\n Digite o valor do investimento: \n");
                        scanf("%f", &investimento);
                        printf("\n escolha a opcao de investimento: \n 1 - Poupanca \n 2 - Fundos de Renda Fixa \n");
                        int opcao_investimento;
                        scanf("%d", &opcao_investimento);
                        switch (opcao_investimento) {
                            case 1:
                                poupanca = investimento * 0.03;
                                printf("\n O rendimento da poupanca e: %.2f \n", poupanca);
                                break;
                            case 2:
                                fundos_de_renda_fixa = investimento * 0.05;
                                printf("\n O rendimento dos fundos de renda fixa e: %.2f \n", fundos_de_renda_fixa);
                                break;
                            default:
                                printf("\n Opcao invalida \n");
                                break;
                        }
                        break;
                    }
                    case 5: {
                        int senha;
                        printf("\n Digite a senha: \n");
                        scanf("%d", &senha);
                        if (senha == 4531) printf("\n Acesso permitido \n");
                        else printf("\n Acesso negado \n");
                        break;
                    }
                    case 6: {
                        int idade;
                        printf("\n Digite a idade: \n");
                        scanf("%d", &idade);
                        if (idade >= 18 && idade <=120) printf("\n acesso permitido \n");
                        else if (idade >= 0 && idade < 18) printf("\n idade não permitida \n");
                        else printf("\n idade invalida \n");
                        break;
                    }
                    default:
                        printf("\n Exercicio invalido \n");
                        break;
                }
                break;
            }

            case 4: {
                printf("\n --- ACESSANDO LISTA 4 --- \n");
                printf("\n escreva o exercicio desejado: \n");
                printf("\n 1 - Exercicio 1: determina o maior e o menor numero entre 10 numeros digitados pelo usuario \n 2 - Exercicio 2: calcula o resultado da soma 1/1 + 3/2 + 3/5 + 5/3 + 7/4 + ... + 99/50 \n 3 - Exercicio 3: calcula o produto dos numeros digitados pelo usuario \n 4 - Exercicio 4: exibe os numeros entre 1000 e 1999 que quando divididos por 11 tem resto igual a 5 \n 5 - Exercicio 5: exibe os numeros da sequencia de Fibonacci \n 6 - Exercicio 6: faz a soma dos numeros pares e impares \n 7 - Exercicio 7: mostra a quantidade de numeros primos que o usuario desejar \n 8 - Exercicio 8: calcula a soma de numeros primos em um intervalo \n 9 - Exercicio 9: mostra o numero que o usuario digitou invertido \n 10 - Exercicio 10: mostra a tabuada de 1 a 10 \n 11 - Exercicio 11: calcula a media dos numeros digitados pelo usuario e mostra a quantidade digitada \n \n");

                int escolha;
                scanf("%d", &escolha);

                switch (escolha) { 
                    case 1: {
                        int numero, maior1, menor1;
                        printf("\n Digite 10 numeros: \n");
                        for (int i = 0; i < 10; i++) {
                            scanf("%d", &numero);
                            if (i == 0) {
                                maior1 = numero;
                                menor1 = numero;
                            } else {
                                if (numero > maior1) maior1 = numero;
                                if (numero < menor1) menor1 = numero;
                            }
                        }
                        printf("\n O maior numero e: %d e o menor numero e: %d \n", maior1, menor1);
                        break;
                    }
                    case 2: {
                        float soma1 = 0, numerador = 1, denominador = 1;
                        printf("\n O resultado da seguinte soma: 1/1 + 3/2 + 3/5 + 5/3 + 7/4 + ... + 99/50 e: \n");
                        for (int i = 1; i <= 50; i++) {
                            denominador = i;
                            soma1 = soma1 + (numerador / denominador);
                            numerador = numerador + 2;
                        }
                        printf("\n O resultado da soma e: %.2f \n", soma1);
                        break;
                    }
                    case 3: {
                        float numero1 = 1, produto = 1;
                        printf("\n Digite quantos numeros desejar, para parar digite 0, o produto dos numeros digitados e: \n");
                        while ( numero1 != 0 ) {
                            scanf("%f", &numero1);
                            if(numero1 != 0) produto = produto * numero1;
                        } 
                        printf("\n O produto dos numeros digitados e: %f \n", produto);
                        break;
                    }
                    case 4: {
                        printf("\n numeros entre 1000 e 1999 que quando divididos por 11 tem resto igual a 5: \n");
                        for (int i = 1000; i <= 1999; i++) {
                            if (i % 11 == 5) printf("%d \n", i);
                        }
                        break;
                    }
                    case 5: {
                        int antecessor = 1, atual = 1, numero2, proximo;
                        printf("\n Digite o numero de numeros da sequencia de Fibonacci que deseja exibir: \n");
                        scanf("%d", &numero2);
                        printf("\n A sequencia de Fibonacci e: \n1 ");
                        for (int i = 1; i <= numero2; i++) {
                            proximo = antecessor + atual;
                            printf("%d ", proximo);
                            antecessor = atual;
                            atual = proximo;
                        }
                        printf("\n");
                        break;
                    }
                    case 6: { 
                        int numero3, par = 0, impar = 0;
                        printf("\n Digite quantos numeros desejar, para parar digite um numero maior que 1000, a soma dos numeros pares e impares sao: \n");
                        do {
                            scanf("%d", &numero3);
                            if (numero3 > 1000) break;
                            else if (numero3 % 2 == 0) par += numero3;
                            else impar += numero3;
                        } while (numero3 <= 1000);
                        printf("\n A soma dos numeros pares e: %d e a soma dos numeros impares e: %d \n", par, impar);
                        break;
                    }
                    case 7: { 
                        int numero4, contador = 0;
                        printf("\n Digite a quantidade de numeros primos que voce deseja que sejam exibidos: \n");
                        scanf("%d", &numero4);
                        for (int i = 2; contador < numero4; i++) {
                            int primo = 1;
                            for (int j = 2; j < i; j++) {
                                if (i % j == 0) {
                                    primo = 0; break;
                                }
                            }
                            if (primo) {
                                printf("%d ", i);
                                contador++;
                            }
                        }
                        printf("\n");
                        break;
                    }
                    case 8: { 
                        int n1 = 0, n2 = 0, soma2 = 0, maior, menor;
                        printf("\n Digite dois numeros, sera calculado a soma de todos os numeros primos nesse intervalo: \n");
                        scanf("%d %d", &n1, &n2);
                        if (n1 < n2) { maior = n2; menor = n1; }
                        else { maior = n1; menor = n2; }
                        for (int i = menor; i <= maior; i++) {
                            if (i < 2) continue;
                            int primo = 1;
                            for (int j = 2; j < i; j++) {
                                if (i % j == 0) {
                                    primo = 0; break;
                                }
                            }
                            if (primo) {
                                printf("%d ", i);
                                soma2 += i;
                            }
                        }
                        printf("\n O resuldado da soma e de: %d \n", soma2);
                        break;
                    }
                    case 9: { 
                        int numero6, invertido = 0;
                        printf("\n Digite um numero, sera exibido o numero invertido: \n");
                        scanf("%d", &numero6);
                        while (numero6 != 0) {
                            invertido = invertido * 10 + (numero6 % 10);
                            numero6 /= 10;
                        }
                        printf("\n O numero invertido e: %d \n", invertido);
                        break;
                    }
                    case 10: { 
                        int resultado;
                        for (int i = 1; i <= 10; i++) {
                            printf("\n Tabuada do %d: \n", i);
                            for (int j = 1; j <= 10; j++) {
                                resultado = i * j;
                                printf("%d x %d = %d \n", i, j, resultado);
                            }
                        }
                        break;
                    }
                    case 11: { 
                        float numero7, contagem = 0, media = 0, soma3 = 0;
                        printf("\n Digite numeros, para parar digite 0: \n");
                        scanf("%f", &numero7);
                        while (numero7 != 0) {
                            soma3 += numero7;
                            contagem++;
                            printf("\n Digite numeros, para parar digite 0: \n");
                            scanf("%f", &numero7);
                        }
                        if (contagem > 0) {
                            media = soma3 / contagem;
                            printf("\n A media dos numeros digitados e: %.2f \n", media);
                            printf("\n A quantidade de numeros digitados e: %.0f \n", contagem);
                        } else {
                            printf("\n Nenhum numero valido foi digitado \n");
                        }
                        break;
                    }
                    default: {
                        printf("\n Exercicio invalido \n");
                        break;
                    }
                }
                break;
            }

            case 5: {
                printf("\n --- ACESSANDO LISTA 5 --- \n");
                printf("\n escreva o exercicio desejado: \n");
                printf("\n 1 - Exercicio 1: conta quantos numeros 5 aparecem nos numeros digitados pelo usuario \n 2 - exercicio 2: mostra as tabuadas referentes de um numero ha outro numero \n 3 - exercicio 3: quantos anos a cidade A demora para alcancar a cidade B em populacao \n 4 - exercicio 4: tranforma um numero dado pelo usuario em binario \n 5 - exercicio 5: cria uma piramide a partir de um numero \n 6 - exercicio 6: exercicio 1 da primeira prova -> leia 10 numero e mostre soma dos pares, a quantidade de impares e o maior e o menor numero. \n 7 - exercicio 7: exercicio 2 da primeira prova -> leia x numero e calcule a sequencia de Fibonacci \n 8 - exercicio 8: exercicio 3 da primeira prova -> mostre um menu repetitivo com opcoes de soma, subtracao e calculo do tipo de triangulo \n \n");

                int escolha;
                scanf("%d", &escolha);

                switch (escolha) {   
                    case 1: {
                        int numero, contagem = 0, auxiliar;
                        do {
                            printf("\n Digite um valor (0 para sair): \n");
                            scanf("%d", &numero);
                            if (numero == 0) break;
                            auxiliar = numero;
                            if (auxiliar < 0) auxiliar = -auxiliar; 
                            while (auxiliar > 0) {
                                if (auxiliar % 10 == 5) contagem++;
                                auxiliar /= 10;
                            }
                        } while (numero != 0);
                        printf("\n O numero 5 foi digitado %d vezes. \n", contagem);
                        break;
                    }
                    case 2: {
                        int numero1, numero2, maior, menor, tabuada, resultado;
                        printf("\n Digite dois valores: \n");
                        scanf("%d %d", &numero1, &numero2);
                        if(numero1 > numero2) { maior = numero1; menor = numero2; }
                        else { maior = numero2; menor = numero1; }
                        for( tabuada = menor; tabuada <= maior; tabuada++){
                            printf("\n tabuada %d \n", tabuada);
                            for(int i = 1; i <= 10; i++){
                                resultado = tabuada * i;
                                printf("\n %d x %d = %d \n", tabuada, i, resultado);
                            }
                        }
                        break;
                    }
                    case 3: {
                        float cidadeA, cidadeB, anos;
                        printf("\n A cidade A cresce mais rapido que a cidade B por ano, em quantos anos a cidade A vai alcancar a B em populacao: \n");
                        printf("\n Digite a populacao da cidade A e da cidade B: \n");
                        scanf("%f %f", &cidadeA, &cidadeB );
                        anos = 0;
                        while(cidadeA < cidadeB){
                            cidadeA += cidadeA * 0.03;
                            cidadeB += cidadeB * 0.015;
                            anos++;
                        }
                        printf("\n A cidade A vai alcancar a cidade B em %.0f anos. \n", anos);
                        break;
                    }
                    case 4: {
                        int numero3, binario;
                        printf("\n Digite um numero inteiro: \n");
                        scanf("%d", &numero3);
                        binario = 0;
                        int p = 1, auxiliar1;
                        while(numero3 > 0){
                            auxiliar1 = numero3 % 2;
                            numero3 = numero3 / 2;
                            binario += (auxiliar1 * p);
                            p *= 10;
                        }
                        printf("\n O numero em binario e: %d\n", binario);
                        break;
                    }
                    case 5: {
                        int numero4;
                        printf("\n Digite o numero da piramide: \n");
                        scanf("%d", &numero4);
                        for(int e = 1; e <= numero4; e++){
                            printf(" \n");
                            for(int j = 1; j <= e; j++){
                                printf("%d", j);
                            }
                        }
                        printf(" \n");
                        break;
                    }
                    case 6: { 
                        int num, somapar = 0, contimpar = 0;
                        int maior1, menor1;
                        for(int p = 0; p < 10; p++){
                            printf("\n Digite um numero: \n");
                            scanf("%d", &num);
                            if( p == 0){
                                maior1 = num;
                                menor1 = num;
                            }
                            if(num % 2 == 0) somapar += num;
                            else contimpar++;
                            
                            if(num > maior1) maior1 = num;
                            if(num < menor1) menor1 = num;
                        }
                        printf("\n Soma dos pares: %d quantidade de impares: %d \n", somapar, contimpar);
                        printf("\n maior numero: %d menor numero: %d \n", maior1, menor1);
                        break;
                    }
                    case 7: { 
                        int numero5, antecessor = 1, atual = 1, proximo;
                        printf("\n Digite a quantidade de numeros da sequencia de Fibonacci que deseja exibir: \n");
                        scanf("%d", &numero5);
                        printf("\n A sequencia de Fibonacci e: \n1 ");
                        for(int i = 1; i < numero5; i++){
                            proximo = antecessor + atual;
                            printf("%d ", proximo);
                            antecessor = atual;
                            atual = proximo;
                        }
                        printf("\n");
                        break;
                    }
                    case 8: { 
                        int opcao;
                        do {
                            printf("\n --- MENU DA PROVA --- \n");
                            printf(" 1. Soma \n 2. Subtrai \n 3. Calcular triangulo \n 0. Sair \n");
                            printf(" Escolha uma opcao: ");
                            scanf("%d", &opcao);
                            
                            switch (opcao) {
                                case 1: {
                                    int a, b;
                                    printf("\n Digite dois numeros para somar: \n");
                                    scanf("%d %d", &a, &b);
                                    printf(" -> A soma e: %d \n", a + b);
                                    break;
                                }
                                case 2: {
                                    int a, b;
                                    printf("\n Digite dois numeros para subtrair: \n");
                                    scanf("%d %d", &a, &b);
                                    printf(" -> A subtracao e: %d \n", a - b);
                                    break;
                                }
                                case 3: {
                                    int lado1, lado2, lado3;
                                    printf("\n Digite os tres lados do triangulo: \n");
                                    scanf("%d %d %d", &lado1, &lado2, &lado3);
                                    if (lado1 == lado2 && lado2 == lado3) printf(" -> O triangulo e equilatero. \n");
                                    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) printf(" -> O triangulo e isosceles. \n");
                                    else printf(" -> O triangulo e escaleno. \n");
                                    break;
                                }
                                case 0:
                                    printf("\n Saindo do menu... \n");
                                    break;
                                default:
                                    printf("\n Opcao invalida. \n");
                                    break;
                            }
                        } while (opcao != 0);
                        break;
                    }
                    default: {
                        printf("\n Exercicio invalido \n");
                        break;
                    }
                }
                break;
            }

            case 6: {
                printf("\n --- ACESSANDO LISTA 6 --- \n");
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

                switch (escolha) {
                    case 1: {
                        int vet[12], pares = 0, impares = 0;
                        printf("\n Digite 12 numeros inteiros: \n");
                        for (int i = 0; i < 12; i++) {
                            scanf("%d", &vet[i]);
                            if (vet[i] % 2 == 0) pares++;
                            else impares++;
                        }
                        printf("\n Numeros pares: %d | Numeros impares: %d \n", pares, impares);
                        break;
                    }
                    case 2: {
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
                        for (int i = 0; i < contPos; i++) printf("%d ", positivos[i]);
                        printf("\n");
                        break;
                    }
                    case 3: {
                        int vet[20];
                        printf("\n Digite 20 numeros inteiros: \n");
                        for (int i = 0; i < 20; i++) scanf("%d", &vet[i]);
                        printf("\n Vetor na ordem inversa: \n");
                        for (int i = 19; i >= 0; i--) printf("%d ", vet[i]);
                        printf("\n");
                        break;
                    }
                    case 4: {
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
                    case 5: {
                        int vet[15];
                        printf("\n Digite 15 numeros: \n");
                        for (int i = 0; i < 15; i++) {
                            scanf("%d", &vet[i]);
                            if (vet[i] < 0) vet[i] = 0;
                        }
                        printf("\n Vetor atualizado (negativos trocados por 0): \n");
                        for (int i = 0; i < 15; i++) printf("%d ", vet[i]);
                        printf("\n");
                        break;
                    }
                    case 6: {
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
                        if (!achou) printf(" O numero %d nao existe no vetor.\n", busca);
                        break;
                    }
                    case 7: {
                        int vet[10], busca, cont = 0;
                        printf("\n Digite 10 valores do vetor: \n");
                        for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);
                        printf("\n Digite o numero para contar ocorrencias: \n");
                        scanf("%d", &busca);
                        for (int i = 0; i < 10; i++) {
                            if (vet[i] == busca) cont++;
                        }
                        printf("\n O numero %d aparece %d vez(es) no vetor.\n", busca, cont);
                        break;
                    }
                    case 8: {
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
                        for (int i = 0; i < 10; i++) printf("%d ", vet[i]);
                        printf("\n");
                        break;
                    }
                    case 9: {
                        int vet[20], unicos[20], qtdUnicos = 0;
                        printf("\n Digite 20 numeros inteiros: \n");
                        for (int i = 0; i < 20; i++) scanf("%d", &vet[i]);
                        for (int i = 0; i < 20; i++) {
                            int repetido = 0;
                            for (int j = 0; j < qtdUnicos; j++) {
                                if (vet[i] == unicos[j]) {
                                    repetido = 1; break;
                                }
                            }
                            if (!repetido) {
                                unicos[qtdUnicos] = vet[i];
                                qtdUnicos++;
                            }
                        }
                        printf("\n Vetor sem elementos repetidos: \n");
                        for (int i = 0; i < qtdUnicos; i++) printf("%d ", unicos[i]);
                        printf("\n");
                        break;
                    }
                    case 10:
                    case 11:
                    case 12: {
                        int vet[12], pares[12], impares[12], contP = 0, contI = 0;
                        printf("\n Digite 12 numeros inteiros: \n");
                        for (int i = 0; i < 12; i++) {
                            scanf("%d", &vet[i]);
                            if (vet[i] % 2 == 0) pares[contP++] = vet[i];
                            else impares[contI++] = vet[i];
                        }
                        printf("\n Vetor de Pares: ");
                        for (int i = 0; i < contP; i++) printf("%d ", pares[i]);
                        printf("\n Vetor de Impares: ");
                        for (int i = 0; i < contI; i++) printf("%d ", impares[i]);
                        printf("\n");
                        break;
                    }
                    case 13: {
                        int A[10], B[10], iguais = 1;
                        printf("\n Digite 10 elementos do Vetor A: \n");
                        for (int i = 0; i < 10; i++) scanf("%d", &A[i]);
                        printf("\n Digite 10 elementos do Vetor B: \n");
                        for (int i = 0; i < 10; i++) scanf("%d", &B[i]);
                        for (int i = 0; i < 10; i++) {
                            if (A[i] != B[i]) {
                                iguais = 0; break;
                            }
                        }
                        if (iguais) printf("\n Os dois vetores são EXATAMENTE iguais. \n");
                        else printf("\n Os dois vetores sao DIFERENTES. \n");
                        break;
                    }
                    case 14: {
                        int vet[10], aux;
                        printf("\n Digite 10 elementos para o vetor: \n");
                        for (int i = 0; i < 10; i++) scanf("%d", &vet[i]);
                        aux = vet[9]; 
                        for (int i = 9; i > 0; i--) vet[i] = vet[i - 1];
                        vet[0] = aux; 
                        printf("\n Vetor rotacionado para a direita: \n");
                        for (int i = 0; i < 10; i++) printf("%d ", vet[i]);
                        printf("\n");
                        break;
                    }
                    case 15: {
                        char frase[100];
                        printf("\n Digite uma frase: \n");
                        scanf(" %[^\n]", frase); 
                        int len = strlen(frase);
                        printf("\n Frase invertida: ");
                        for (int i = len - 1; i >= 0; i--) printf("%c", frase[i]);
                        printf("\n");
                        break;
                    }
                    case 16: {
                        char p1[50], p2[50];
                        printf("\n Digite a primeira palavra: \n"); scanf("%s", p1);
                        printf("\n Digite a segunda palavra: \n"); scanf("%s", p2);
                        if (strcmp(p1, p2) == 0) printf("\n As palavras sao iguais. \n");
                        else printf("\n As palavras sao diferentes. \n");
                        break;
                    }
                    case 17: {
                        char frase[100];
                        printf("\n Digite uma frase: \n");
                        scanf(" %[^\n]", frase);
                        for (int i = 0; frase[i] != '\0'; i++) {
                            if (frase[i] == 'a' || frase[i] == 'A') frase[i] = '@';
                        }
                        printf("\n Frase modificada: %s \n", frase);
                        break;
                    }
                    case 18: {
                        char palavra[50];
                        int ePalindromo = 1;
                        printf("\n Digite uma palavra: \n");
                        scanf("%s", palavra);
                        int len = strlen(palavra);
                        for (int i = 0; i < len / 2; i++) {
                            if (tolower(palavra[i]) != tolower(palavra[len - 1 - i])) {
                                ePalindromo = 0; break;
                            }
                        }
                        if (ePalindromo) printf("\n A palavra '%s' e um PALINDROMO! \n", palavra);
                        else printf("\n A palavra '%s' NAO e um palindromo. \n", palavra);
                        break;
                    }
                    case 19: {
                        char frase[100];
                        int vogais = 0, consoantes = 0, numeros = 0, especiais = 0;
                        printf("\n Digite uma frase: \n");
                        scanf(" %[^\n]", frase);
                        for (int i = 0; frase[i] != '\0'; i++) {
                            char c = tolower(frase[i]);
                            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vogais++;
                            else if (c >= 'a' && c <= 'z') consoantes++;
                            else if (isdigit(c)) numeros++;
                            else if (c != ' ') especiais++;
                        }
                        printf("\n Vogais: %d | Consoantes: %d | Numeros: %d | Especiais: %d \n", vogais, consoantes, numeros, especiais);
                        break;
                    }
                    case 20: {
                        char str[100], semEspaco[100];
                        int j = 0;
                        printf("\n Digite uma frase/string: \n");
                        scanf(" %[^\n]", str);
                        for (int i = 0; str[i] != '\0'; i++) {
                            if (str[i] != ' ') semEspaco[j++] = str[i];
                        }
                        semEspaco[j] = '\0';
                        printf("\n String sem espacos: %s \n", semEspaco);
                        break;
                    }
                    case 21: {
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
                break;
            }

            case 7: {
                printf("\n --- ACESSANDO LISTA 7 --- \n");
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
                    printf(" 0 - Sair deste submenu\n");
                    printf("========================================================================\n");
                    printf(" Escolha uma opcao: ");
                    scanf("%d", &escolha);

                    switch (escolha) {
                        case 1: {
                            int m, n;
                            printf("\n--- Matriz Transposta ---\n");
                            printf("Digite a quantidade de linhas (M) e colunas (N): ");
                            scanf("%d %d", &m, &n);
                            int matriz[m][n], transposta[n][m];
                            printf("Digite os elementos da matriz %dx%d:\n", m, n);
                            for (int i = 0; i < m; i++) {
                                for (int j = 0; j < n; j++) {
                                    scanf("%d", &matriz[i][j]);
                                    transposta[j][i] = matriz[i][j];
                                }
                            }
                            printf("\nMatriz Original:\n");
                            for (int i = 0; i < m; i++) {
                                for (int j = 0; j < n; j++) printf("%d ", matriz[i][j]);
                                printf("\n");
                            }
                            printf("\nMatriz Transposta:\n");
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) printf("%d ", transposta[i][j]);
                                printf("\n");
                            }
                            break;
                        }
                        case 2: {
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
                                    for (int j = 0; j < c1; j++) scanf("%d", &m1[i][j]);

                                printf("\nDigite os valores da Matriz 2:\n");
                                for (int i = 0; i < l2; i++)
                                    for (int j = 0; j < c2; j++) scanf("%d", &m2[i][j]);

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
                                    for (int j = 0; j < c2; j++) printf("%d ", m3[i][j]);
                                    printf("\n");
                                }
                            }
                            break;
                        }
                        case 3: {
                            int mat[2][3], num;
                            printf("\n--- Multiplicar Matriz 2x3 por Inteiro ---\n");
                            printf("Digite os 6 elementos da matriz 2x3:\n");
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 3; j++) scanf("%d", &mat[i][j]);
                            }
                            printf("Digite um numero inteiro para multiplicar a matriz: ");
                            scanf("%d", &num);
                            printf("\nNova Matriz Resultante:\n");
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 3; j++) printf("%d ", mat[i][j] * num);
                                printf("\n");
                            }
                            break;
                        }
                        case 4: {
                            int m1[3][3], m2[3][3], soma[3][3];
                            printf("\n--- Soma de Matrizes 3x3 ---\n");
                            printf("Digite os valores da Matriz 1:\n");
                            for (int i = 0; i < 3; i++)
                                for (int j = 0; j < 3; j++) scanf("%d", &m1[i][j]);
                            printf("\nDigite os valores da Matriz 2:\n");
                            for (int i = 0; i < 3; i++)
                                for (int j = 0; j < 3; j++) scanf("%d", &m2[i][j]);
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
                            int m, n, identidade = 1;
                            printf("\n--- Verificador de Matriz Identidade ---\n");
                            printf("Digite as dimensoes da matriz (MxN): ");
                            scanf("%d %d", &m, &n);
                            int mat[m][n];
                            printf("Digite os elementos da matriz:\n");
                            for (int i = 0; i < m; i++) {
                                for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
                            }
                            if (m != n) {
                                identidade = 0;
                            } else {
                                for (int i = 0; i < m; i++) {
                                    for (int j = 0; j < n; j++) {
                                        if (i == j && mat[i][j] != 1) identidade = 0;
                                        if (i != j && mat[i][j] != 0) identidade = 0;
                                    }
                                }
                            }
                            if (identidade == 1) printf("\nA matriz informada E uma Matriz Identidade!\n");
                            else printf("\nA matriz informada NAO E uma Matriz Identidade.\n");
                            break;
                        }
                        case 6: {
                            printf("\n--- PROVA SUBSTITUTIVA 1: Sub-vetor ---\n");
                            int vet1[3], vet2[20];
                            int i, j, encontrado = 0;
                            printf("Digite os 3 elementos do primeiro vetor:\n");
                            for (i = 0; i < 3; i++) scanf("%d", &vet1[i]);
                            printf("Digite os 20 elementos do segundo vetor:\n");
                            for (i = 0; i < 20; i++) scanf("%d", &vet2[i]);
                            for (i = 0; i <= 20 - 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (vet2[i + j] != vet1[j]) break; 
                                }
                                if (j == 3) {
                                    encontrado = 1; break; 
                                }
                            }
                            if (encontrado == 1) printf("\nO vetor 1 esta dentro do vetor 2!\n");
                            else printf("\nO vetor 1 nao esta contido no vetor 2.\n");
                            break;
                        }
                        case 7: {
                            printf("\n--- PROVA SUBSTITUTIVA 1: Quadrantes da Matriz 6x6 ---\n");
                            int matriz[6][6];
                            int i, j, A = 0, B = 0;
                            printf("Digite os 36 valores para a matriz 6x6:\n");
                            for (i = 0; i < 6; i++) {
                                for (j = 0; j < 6; j++) scanf("%d", &matriz[i][j]);
                            }
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) A += matriz[i][j];
                            }
                            for (i = 3; i < 6; i++) {
                                for (j = 3; j < 6; j++) B += matriz[i][j];
                            }
                            if (A > B) printf("\nA e maior que B\n");
                            else if (B > A) printf("\nB e maior que A\n");
                            else printf("\nA e B sao iguais\n");
                            break;
                        }
                        case 0:
                            printf("\nVoltando ao Menu Mestre...\n");
                            break;
                        default:
                            printf("\nOpcao invalida. Tente novamente.\n");
                            break;
                    }
                } while (escolha != 0);
                break;
            }

            case 8: {
                printf("\n --- ACESSANDO LISTA 8 --- \n");
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
                    printf(" 9  - Ex. 6: Fatorial de Vetor A para B\n");
                    printf(" 10 - Ex. 7: Uniao de 2 Vetores\n");
                    printf(" 11 - Ex. 8: Separar Pares e Impares de um Vetor\n");
                    printf(" 12 - Ex. 9: Quantidade de Pares no Vetor(15)\n");
                    printf(" 13 - Ex. 10: Soma de elementos Reais do Vetor(20)\n");
                    printf(" 14 - Ex. 18: Soma de dois Vetores(20)\n");
                    printf(" 15 - Ex. 19: Produto de dois Vetores(15)\n");
                    printf(" --- TERCEIRA PARTE (Matrizes) ---\n");
                    printf(" 16 - Ex. 24, 25, 26, 27: Operacoes em Matrizes (Demonstracao)\n");
                    printf(" 0  - Sair deste submenu\n");
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
                        case 9: { 
                            int A[5] = {4, 1, 0, 3, 5}; 
                            int B[5];
                            printf("\nCalculando fatorial de um vetor fixo A = {4, 1, 0, 3, 5}...\n");
                            fatoraVetor(A, B, 5);
                            printf("Vetor B gerado: ");
                            for(int i=0; i<5; i++) printf("%d ", B[i]);
                            printf("\n");
                            break;
                        }
                        case 10: { 
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
                        case 11: { 
                            int X[10] = {1,2,3,4,5,6,7,8,9,10};
                            int A[10], B[10], tA, tB;
                            printf("\nSeparando X={1 a 10} em Pares(A) e Impares(B)....\n");
                            separaParesImpares(X, A, B, &tA, &tB, 10);
                            printf("Vetor A (Pares): ");
                            for(int i=0; i<tA; i++) printf("%d ", A[i]);
                            printf("\nVetor B (Impares): ");
                            for(int i=0; i<tB; i++) printf("%d ", B[i]);
                            printf("\n");
                            break;
                        }
                        case 12: { 
                            int X[15] = {2,4,6,8,10,1,3,5,7,9,12,14,16,18,20};
                            printf("\nO vetor X possui %d valores pares.\n", contaParesVetor(X, 15));
                            break;
                        }
                        case 13: { 
                            float X[5] = {1.5, 2.5, 3.0, 4.0, 5.2}; 
                            printf("\nA soma do vetor real e: %.2f\n", somaVetorReais(X, 5));
                            break;
                        }
                        case 14: { 
                            int A[5] = {1,2,3,4,5}, B[5] = {5,4,3,2,1}, S[5];
                            somaDoisVetores(A, B, S, 5);
                            printf("\nSoma de Vetores: ");
                            for(int i=0; i<5; i++) printf("%d ", S[i]);
                            printf("\n");
                            break;
                        }
                        case 15: { 
                            int A[5] = {1,2,3,4,5}, B[5] = {2,2,2,2,2}, P[5];
                            produtoDoisVetores(A, B, P, 5);
                            printf("\nProduto de Vetores: ");
                            for(int i=0; i<5; i++) printf("%d ", P[i]);
                            printf("\n");
                            break;
                        }
                        case 16: { 
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
                            printf("\nVoltando ao Menu Mestre...\n");
                            break;
                        default:
                            printf("\nOpcao Invalida!\n");
                    }
                } while (escolha != 0);
                break;
            }

            case 9: {
                printf("\n --- ACESSANDO LISTA 9 --- \n");
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
                    printf(" 0  - Sair deste submenu\n");
                    printf(" =====================================================\n");
                    printf(" Escolha uma opcao: ");
                    scanf("%d", &escolha);

                    switch (escolha) {
                        case 1: {
                            int var = 10;
                            int *ptr = &var;
                            printf("\n--- Exercicio 1: Valor e Endereco ---\n");
                            printf("Valor da variavel: %d\n", var);
                            printf("Endereco da variavel: %p\n", (void*)&var);
                            printf("Conteudo do ponteiro: %p\n", (void*)ptr);
                            printf("Valor apontado: %d\n", *ptr);
                            break;
                        }
                        case 2: {
                            int var = 20;
                            int *ptr = &var;
                            *ptr = 50; 
                            printf("\n--- Exercicio 2: Alteracao por Ponteiro ---\n");
                            printf("Valor final da variavel: %d\n", var);
                            break;
                        }
                        case 3: {
                            int a = 5;
                            int b = 8;
                            printf("\n--- Exercicio 3: Troca de Valores ---\n");
                            printf("Antes: a = %d, b = %d\n", a, b);
                            troca(&a, &b); 
                            printf("Depois: a = %d, b = %d\n", a, b);
                            break;
                        }
                        case 4: {
                            int a = 15;
                            int b = 25;
                            int resultado;
                            printf("\n--- Exercicio 4: Soma por Referencia ---\n");
                            somaReferencia(a, b, &resultado); 
                            printf("Entrada: %d e %d -> Saida: Resultado = %d\n", a, b, resultado);
                            break;
                        }
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
                            int *p2 = p1; 
                            *p2 = 30;
                            printf("%d\n", a);
                            printf("%d\n", *p1);
                            break;
                        }
                        case 8: {
                            printf("\n--- Snippet 4: Incremento via Ponteiro ---\n");
                            int x = 7;
                            int *p = &x;
                            (*p)++; 
                            printf("%d\n", x);
                            break;
                        }
                        case 9: {
                            printf("\n--- Snippet 5: Vetor e Ponteiros ---\n");
                            int v[4] = {10, 20, 30, 40};
                            int *p = v; 
                            printf("%d\n", *p);       
                            printf("%d\n", *(p+1));   
                            printf("%d\n", *(p+2));   
                            break;
                        }
                        case 10: {
                            printf("\n--- Snippet 6: Aritmetica de Ponteiros ---\n");
                            int v[5] = {5, 10, 15, 20, 25};
                            int *p = v;
                            p = p + 3; 
                            printf("%d\n", *p);
                            break;
                        }
                        case 11: {
                            printf("\n--- Prova 2: Ex. 1 (Alteracao por ponteiro) ---\n");
                            int a = 10, b = 20, c = 30;
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
                            printf("Digite o tamanho N da matriz quadrada: ");
                            scanf("%d", &N);
                            if (N <= 0 || N > 50) {
                                printf("Tamanho invalido! Use um N entre 1 e 50.\n");
                                break;
                            }
                            int mat[50][50]; 
                            int somaPrin = 0, somaSec = 0, somaBorda = 0, somaInt = 0;
                            int maior, menor;

                            printf("Digite os %d elementos da matriz:\n", N * N);
                            for (int i = 0; i < N; i++) {
                                for (int j = 0; j < N; j++) {
                                    scanf("%d", &mat[i][j]);
                                    if (i == 0 && j == 0) {
                                        maior = mat[i][j];
                                        menor = mat[i][j];
                                    } else {
                                        if (mat[i][j] > maior) maior = mat[i][j];
                                        if (mat[i][j] < menor) menor = mat[i][j];
                                    }
                                    if (i == j) somaPrin += mat[i][j];
                                    if (i + j == N - 1) somaSec += mat[i][j];
                                    if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                                        somaBorda += mat[i][j];
                                    } else {
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
                            printf("\n Voltando ao Menu Mestre...\n");
                            break;
                        default:
                            printf("\n Opcao invalida. Tente novamente.\n");
                            break;
                    }
                } while (escolha != 0);
                break;
            }

            case 0:
                printf("\n Encerrando o Codigo Mestre. Ate mais!\n");
                break;

            default:
                printf("\n Opcao Invalida! Por favor, escolha uma lista de 1 a 9.\n");
                break;
        }

    } while (menu_mestre != 0);

    return 0;
}