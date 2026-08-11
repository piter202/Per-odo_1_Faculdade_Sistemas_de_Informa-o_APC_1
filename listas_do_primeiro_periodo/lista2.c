#include<stdio.h>

int main()
{
    printf("\n escreva o exercicio desejado: \n");
    printf("\n 1 - Exercicio 1: descobre se e impar ou par \n 2 - exercicio 2: descobre qual o maior entre 2 numeros \n 3 - exercicio 3: descobre se o numero é positivo, negativo se é zero \n 4 - execicio 4: diz pela nota do aluno se ele foi aprovado ou reprovado \n 5 - exercicio 5: diz se o eleitor é facultativo, obrigatório ou não eleitor \n 6 - exercicio 6: diz qual o maior entre 3 numeros \n 7 - exercicio 7: diz se o triangulo é equilatero, isosceles ou escaleno \n 8 - execicio 8: calcula o IMC \n 9 - exercicio 9 : diz se a nota do aluno foi A, B, C, D ou invalida \n \n");
    int exercicio;
    scanf("%d", &exercicio);

    // essa é a segunda lista, primeiro periodo, ela contem codigos que utilizam a ferramente "if" e "else if" para exercutar multiplas funcões caso aconteça algum evento específivo

    if (exercicio == 1)
    {
        // esse exercício descobre se um número é par ou ímpar, onde o número é fornecido pelo usuário.
        int numero;
        printf("\n Digite um numero: \n");
        scanf("%d", &numero);
        if (numero % 2 == 0)
        {
            printf("\n O numero e par \n");
        }
        else
        {
            printf("\n O numero e impar \n");
        }
    }
    else if (exercicio == 2)
    {
        // esse exercício descobre qual o maior entre 2 números, onde os números são fornecidos pelo usuário.
        int n1, n2;
        printf("\n Digite o numero 1 e o numero 2: \n");
        scanf("%d %d", &n1, &n2);
        if (n1 > n2)
        {
            printf("\n o maior numero e %d \n", n1);
        }
        else if (n2 > n1)
        {
            printf("\n o maior numero e %d \n", n2);
        }
        else
        {
            printf("\n Os numeros sao iguais \n");
        }
    }
    else if (exercicio == 3)
    {
        // esse exercício descobre se um número é positivo, negativo ou zero, onde o número é fornecido pelo usuário.
        int numero;
        printf("\n Digite um numero: \n");
        scanf("%d", &numero);
        if (numero > 0)
        {
            printf("\n O numero e positivo \n");
        }
        else if (numero < 0)
        {
            printf("\n O numero e negativo \n");
        }
        else
        {
            printf("\n O numero e zero \n");
        }
    }
    else if (exercicio == 4)
    {
        // esse exercício diz pela nota do aluno se ele foi aprovado ou reprovado, onde a nota é fornecida pelo usuário.
        float nota;
        printf("\n Digite a nota do aluno: \n");
        scanf("%f", &nota);
        if (nota >= 7 && nota <= 10)
        {
            printf("\n O aluno foi aprovado \n");
        }
        else if (nota >= 0 && nota < 7)
        {
            printf("\n O aluno foi reprovado \n");
        }
        else
        {
            printf("\n Nota invalida \n");
        }
    }
    else if (exercicio == 5)
    {
        // esse exercício diz se o eleitor é facultativo, obrigatório ou não eleitor, onde a idade do eleitor é fornecida pelo usuário.
        int idade;
        printf("\n Digite a idade do eleitor: \n");
        scanf("%d", &idade);
        if (idade >= 18 && idade <= 70)
        {
            printf("\n O eleitor e obrigatorio \n");
        }
        else if (idade >= 16 && idade < 18 || idade > 70)
        {
            printf("\n O eleitor e facultativo \n");
        }
        else
        {
            printf("\n O eleitor nao e permitido votar \n");
        }
    }
    else if (exercicio == 6)
    {
        // esse exercício diz qual o maior entre 3 números, onde os números são fornecidos pelo usuário.
        int n1, n2, n3;
        printf("\n Digite o numero 1, numero 2 e numero 3: \n");
        scanf("%d %d %d", &n1, &n2, &n3);
        if (n1 >= n2 && n1 >= n3)
        {
            printf("\n O maior número e %d \n", n1);
        }
        else if (n2 >= n1 && n2 >= n3)
        {
            printf("\n O maior número e %d \n", n2);
        }
        else
        {
            printf("\n O maior número e %d \n", n3);
        }
    }
    else if (exercicio == 7)
    {
        // esse exercício diz se um triângulo é equilátero, isósceles ou escaleno, onde os lados do triângulo são fornecidos pelo usuário.
        int lado1, lado2, lado3;
        printf("\n Digite os lados do triangulo: \n");
        scanf("%d %d %d", &lado1, &lado2, &lado3);
        if (lado1 == lado2 && lado2 == lado3)
        {
            printf("\n O triangulo e equilatero \n");
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
        {
            printf("\n O triangulo e isosceles \n");
        }
        else
        {
            printf("\n O triangulo e escaleno \n");
        }
    }
    else if (exercicio == 8)
    {
        // esse exercício calcula o IMC (Índice de Massa Corporal), onde o peso e a altura são fornecidos pelo usuário.
        float peso, altura, imc;
        printf("\n Digite o peso em kg e a altura em metros: \n");
        scanf("%f %f", &peso, &altura);
        imc = peso / (altura * altura);
        printf("\n O IMC e: %.2f \n", imc);
        if (imc < 18.5)
        {
            printf("\n Abaixo do peso \n");
        }
        else if (imc >= 18.5 && imc < 25)
        {
            printf("\n Peso normal \n");
        }
        else if (imc >= 25 && imc < 30)
        {
            printf("\n Sobrepeso \n");
        }
        else
        {
            printf("\n Obesidade \n");
        }
    }
    else if (exercicio == 9)
    {
        // esse exercício diz se a nota do aluno foi A, B, C, D ou inválida, onde a nota é fornecida pelo usuário.
        float nota;
        printf("\n Digite a nota do aluno: \n");
        scanf("%f", &nota);
        if (nota >= 9 && nota <= 10)
        {
            printf("\n A nota do aluno e A \n");
        }
        else if (nota >= 7.5 && nota < 9)
        {
            printf("\n A nota do aluno e B \n");
        }
        else if (nota >= 6 && nota < 7.5)
        {
            printf("\n A nota do aluno e C \n");
        }
        else if (nota >= 0 && nota < 6)
        {
            printf("\n A nota do aluno e D \n");
        }
        else
        {
            printf("\n Nota invalida \n");
        }
    }
    else
    {
        printf("\n Exercicio invalido \n");
    }
    return 0;
}