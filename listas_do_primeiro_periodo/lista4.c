#include<stdio.h>

int main()
{
    printf("\n escreva o exercicio desejado: \n");
    printf("\n 1 - Exercicio 1: determina o maior e o menor numero entre 10 numeros digitados pelo usuario \n 2 - Exercicio 2: calcula o resultado da soma 1/1 + 3/2 + 3/5 + 5/3 + 7/4 + ... + 99/50 \n 3 - Exercicio 3: calcula o produto dos numeros digitados pelo usuario \n 4 - Exercicio 4: exibe os numeros entre 1000 e 1999 que quando divididos por 11 tem resto igual a 5 \n 5 - Exercicio 5: exibe os numeros da sequencia de Fibonacci \n 6 - Exercicio 6: faz a soma dos numeros pares e impares \n 7 - Exercicio 7: mostra a quantidade de numeros primos que o usuario desejar \n 8 - Exercicio 8: calcula a soma de numeros primos em um intervalo \n 9 - Exercicio 9: mostra o numero que o usuario digitou invertido \n 10 - Exercicio 10: mostra a tabuada de 1 a 10 \n 11 - Exercicio 11: calcula a media dos numeros digitados pelo usuario e mostra a quantidade digitada \n \n");

    int escolha;
    scanf("%d", &escolha);

    // essa é a quarta lista, primeiro periodo, ela contem codigos que utilizam do "for" e do "do while" para realizar as funções que aparecem no menu escrito acima.

    switch (escolha)
    { 
        case 1:
        {
            // esse exercício observa 10 números digitados pelo usuário e determina qual é o maior e qual é o menor número entre eles.

            int numero, maior1, menor1;

            printf("\n Digite 10 numeros: \n");
            for (int i = 0; i < 10; i++)
            {
                scanf("%d", &numero);
                if (i == 0)
                {
                    maior1 = numero;
                    menor1 = numero;
                }
                else
                {
                    if (numero > maior1)
                    {
                        maior1 = numero;
                    }
                    if (numero < menor1)
                    {
                        menor1 = numero;
                    }
                }
            }
            printf("\n O maior numero e: %d e o menor numero e: %d \n", maior1, menor1);

            break;
        }
        case 2:
        {
            // esse exercício calcula o resultado da soma 1/1 + 3/2 + 3/5 + 5/3 + 7/4 + ... + 99/50.
            
            float soma1 = 0, numerador = 1, denominador = 1;

            printf("\n O resultado da seguinte soma: 1/1 + 3/2 + 3/5 + 5/3 + 7/4 + ... + 99/50 e: \n");
            for (int i = 1; i <= 50; i++)
            {
                denominador = i;
                soma1 = soma1 + (numerador / denominador);
                numerador = numerador + 2;
            }

            printf("\n O resultado da soma e: %.2f \n", soma1);

            break;
        }
        case 3:
        {
            // esse exercício calcula o produto dos números digitados pelo usuário, onde o usuário pode digitar quantos números desejar, para parar de digitar números o usuário deve digitar 0.
            
            float numero1 = 1, produto = 1;

            printf("\n Digite quantos numeros desejar, para parar digite 0, o produto dos numeros digitados e: \n");
            while ( numero1 != 0 )
            {
                produto = produto * numero1;
                scanf("%f", &numero1);
            } 

            printf("\n O produto dos numeros digitados e: %f \n", produto);

            break;
        }
        case 4:
        {
            // esse exercício exibe os números entre 1000 e 1999 que quando divididos por 11 tem resto igual a 5.
            
            printf("\n numeros entre 1000 e 1999 que quando divididos por 11 tem resto igual a 5: \n");
            for (int i = 1000; i <= 1999; i++)
            {
                if (i % 11 == 5)
                {
                    printf("%d \n", i);
                }
            }

            break;
        }
        case 5:
        {
            // esse exercício exibe os números da sequência de Fibonacci, onde o usuário pode escolher quantos números da sequência deseja exibir.
            
            int antecessor = 1, atual = 1, numero2, proximo;

            printf("\n Digite o numero de numeros da sequencia de Fibonacci que deseja exibir: \n");
            scanf("%d", &numero2);
            printf("\n A sequencia de Fibonacci e: \n1 ");
            for (int i = 1; i <= numero2; i++)
            {
                proximo = antecessor + atual;
                printf("%d ", proximo);
                antecessor = atual;
                atual = proximo;
            }

            break;
        }
        case 6:
        { 
        // esse exercício calcula a soma dos números pares e a soma dos números ímpares, onde o usuário pode digitar quantos números desejar, para parar de digitar números o usuário deve digitar um número maior que 1000.
            
            int numero3, par = 0, impar = 0;

            printf("\n Digite quantos numeros desejar, para parar digite um numero maior que 1000, a soma dos numeros pares e impares sao: \n");
            do
            {
                scanf("%d", &numero3);
                if (numero3 > 1000)
                {
                    break;
                }
                else if (numero3 % 2 == 0)
                {
                    par += numero3;
                }
                else
                {
                    impar += numero3;
                }
            } while (numero3 <= 1000);
            printf("\n A soma dos numeros pares e: %d e a soma dos numeros impares e: %d \n", par, impar);

            break;
        }
        case 7:
        { 
        // esse exercício exibe os números primos, onde o usuário pode escolher quantos números primos deseja que sejam exibidos.

            int numero4, contador = 0;

            printf("\n Digite a quantidade de numeros primos que voce deseja que sejam exibidos: \n");
            scanf("%d", &numero4);
            for (int i = 2; contador < numero4; i++)
            {
                int primo = 1;
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        primo = 0;
                        break;
                    }
                }
                if (primo)
                {
                    printf("%d ", i);
                    contador++;
                }
            }

            break;
        }
        case 8:
        { 
        // esse exercício calcula a soma de todos os números primos entre dois números digitados pelo usuário, onde o usuário pode digitar os números em qualquer ordem.
            
            int n1 = 0, n2 = 0, soma2 = 0, maior, menor;

            printf("\n Digite dois numeros, sera calculado a soma de todos os numeros primos nesse intervalo: \n");
            scanf("%d %d", &n1, &n2);
            if (n1 < n2)
            {
                maior = n2;
                menor = n1;
            }
            else
            {
                maior = n1;
                menor = n2;
            }
            for (int i = menor; i <= maior; i++)
            {
                if (i < 2)
                {
                    continue;
                }

                int primo = 1;
                for (int j = 2; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        primo = 0;
                        break;
                    }
                }
                if (primo)
                {
                    printf("%d ", i);
                    soma2 += i;
                }
                
            }
                printf("\n O resuldado da soma e de: %d \n", soma2);

            break;
        }
        case 9:
        { 
        // esse exercício inverte um número inteiro, onde o usuário digita um número inteiro e o programa exibe o número invertido.

            int numero6, invertido = 0;

            printf("\n Digite um numero, sera exibido o numero invertido: \n");
            scanf("%d", &numero6);
            while (numero6 != 0)
            {
                invertido = invertido * 10 + (numero6 % 10);
                numero6 /= 10;
            }
            printf("\n O numero invertido e: %d \n", invertido);

            break;
        }
        case 10:
        { 
        // esse exercício exibe a tabuada de multiplicação de 1 a 10, onde o programa exibe a tabuada do 1, depois a tabuada do 2, e assim por diante até a tabuada do 10.
            
            int resultado;

            for (int i = 1; i <= 10; i++)
            {
                printf("\n Tabuada do %d: \n", i);
                for (int j = 1; j <= 10; j++)
                {
                    resultado = i * j;
                    printf("%d x %d = %d \n", i, j, resultado);
                }
            }

            break;
        }
        case 11:
        { 
    
        // esse exercício calcula a média dos números digitados pelo usuário, onde o usuário pode digitar quantos números desejar e será contado quantos números foram digitados, para parar de digitar números o usuário deve digitar 0.
            float numero7, contagem = 0, media = 0, soma3 = 0;

            printf("\n Digite numeros, para parar digite 0: \n");
            scanf("%f", &numero7);
            while (numero7 != 0)
            {
                soma3 += numero7;
                contagem++;
                printf("\n Digite numeros, para parar digite 0: \n");
                scanf("%f", &numero7);
            }

            if (contagem > 0)
            {
                media = soma3 / contagem;
                printf("\n A media dos numeros digitados e: %.2f \n", media);
                printf("\n A quantidade de numeros digitados e: %.0f \n", contagem);
            }
            else
            {
                printf("\n Nenhum numero valido foi digitado \n");
            }
            
            break;
        }
        default:
        {
            printf("\n Exercicio invalido \n");

            break;
        }
    }
    return 0;
}