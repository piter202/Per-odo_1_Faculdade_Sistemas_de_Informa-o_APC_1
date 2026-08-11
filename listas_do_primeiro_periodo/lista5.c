#include<stdio.h>

int main()
{
    printf("\n escreva o exercicio desejado: \n");
    printf("\n 1 - Exercicio 1: conta quantos numeros 5 aparecem nos numeros digitados pelo usuario \n 2 - exercicio 2: mostra as tabuadas referentes de um numero ha outro numero \n 3 - exercicio 3: quantos anos a cidade A demora para alcancar a cidade B em populacao \n 4 - exercicio 4: tranforma um numero dado pelo usuario em binario \n 5 - exercicio 5: cria uma piramide a partir de um numero \n 6 - exercicio 6: exercicio 1 da primeira prova -> leia 10 numero e mostre soma dos pares, a quantidade de impares e o maior e o menor numero. \n 7 - exercicio 7: exercicio 2 da primeira prova -> leia x numero e calcule a sequencia de Fibonacci \n 8 - exercicio 8: exercicio 3 da primeira prova -> mostre um menu repetitivo com opcoes de soma, subtracao e calculo do tipo de triangulo \n \n");

    int escolha;
    scanf("%d", &escolha);

    // essa é a quinta lista e além disso os exercicios 6,7 e 8 são da primeira prova da faculdade, primeiro periodo, ela contem codigos que utilizam do "for" e do "do while" para realizar as funções que aparecem no menu escrito acima.

    switch (escolha)
    {   
        case 1:
        {
            // esse exercicio conta quantos numeros 5 aparecem nos numeros digitados pelo usuário

            int numero, contagem = 0, auxiliar;

            do {
                printf("\n Digite um valor (0 para sair): \n");
                scanf("%d", &numero);
                if (numero == 0) {
                    break;
                }
                
                auxiliar = numero;
                if (auxiliar < 0) {
                    auxiliar = -auxiliar; // Resolve o problema de números negativos
                }
                
                while (auxiliar > 0) {
                    if (auxiliar % 10 == 5) {
                        contagem++;
                    }
                    auxiliar /= 10;
                }
            } while (numero != 0);
            
            printf("\n O numero 5 foi digitado %d vezes. \n", contagem);
            break;
        }
        case 2:
        {
            // esse exercicio mostra as tabuadas referentes de um numero há outro numero, escolhidos pelo usuário.

            int numero1, numero2, maior, menor, tabuada, resultado;

            printf("\n Digite dois valores: \n");
            scanf("%d %d", &numero1, &numero2);
            if(numero1 > numero2)
            {
                maior = numero1;
                menor = numero2;
            }
            else
            {
                maior = numero2;
                menor = numero1;
            }
            for( tabuada = menor; tabuada <= maior; tabuada++){
                printf("\n tabuada %d \n", tabuada);
                for(int i = 1; i <= 10; i++){
                    resultado = tabuada * i;
                    printf("\n %d x %d = %d \n", tabuada, i, resultado);
                }
            }

            break;
        }
        case 3:
        {
            // esse exercício calcula o tempo em anos que uma cidade A demora para alcançar a cidade B em população.

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
        case 4:
        {
        // esse exercício tranforma um numero dado pelo usuário em binário.

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
        case 5:
        {
        // esse exercicio cria uma piramide a partir de um numero.

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
        case 6:
        { 
        // esse exercicio é o primeiro da prova1 no qual deve, ler 10 numeros e somar os pares, contar quantos impares tem e mostrar o menor e o maior valor.

            int num, somapar = 0, contimpar = 0;
            int maior1, menor1;
            for(int p = 0; p < 10; p++){
                printf("\n Digite um numero: \n");
                scanf("%d", &num);
                if( p == 0){
                    maior1 = num;
                    menor1 = num;
                }
                if(num % 2 == 0){
                    somapar += num;
                }
                else{
                    contimpar++;
                }
                if(num > maior1){
                    maior1 = num;
                }
                if(num < menor1){
                    menor1 = num;
                }
            }
            printf("\n Soma dos pares: %d quantidade de impares: %d \n", somapar, contimpar);
            printf("\n maior numero: %d menor numero: %d \n", maior1, menor1);

            break;
        }
        case 7:
        { 
        // esse é o segundo exercicio da prova1 no qual deve, ler x numero e calcular a sequencia de Fibonacci utilizando laço de reperição, onde x é a quantidade de numeros da sequencia.

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

            break;
        }
        case 8:
        { 
        // esse é o terceiro exercicio da prova1 no qual deve,mostra um menu repetitivo que 1. soma, 2. subtrai, 3. calcular se o triangulo é equilatero, isosceles ou escaleno, onde o usuário digita os lados do triangulo e o programa mostra qual tipo de triangulo é, 0. sair.

            int opcao;
            // Adicionado o do-while para tornar o menu realmente repetitivo
            do {
                printf("\n --- MENU DA PROVA --- \n");
                printf(" 1. Soma \n 2. Subtrai \n 3. Calcular triangulo \n 0. Sair \n");
                printf(" Escolha uma opcao: ");
                scanf("%d", &opcao);
                
                switch (opcao) {
                    case 1:
                    {
                        int a, b;
                        printf("\n Digite dois numeros para somar: \n");
                        scanf("%d %d", &a, &b);
                        printf(" -> A soma e: %d \n", a + b);
                        break;
                    }
                    case 2:
                    {
                        int a, b;
                        printf("\n Digite dois numeros para subtrair: \n");
                        scanf("%d %d", &a, &b);
                        printf(" -> A subtracao e: %d \n", a - b);
                        break;
                    }
                    case 3:
                    {
                        int lado1, lado2, lado3;
                        printf("\n Digite os tres lados do triangulo: \n");
                        scanf("%d %d %d", &lado1, &lado2, &lado3);

                        if (lado1 == lado2 && lado2 == lado3) {
                            printf(" -> O triangulo e equilatero. \n");
                        }
                        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
                            printf(" -> O triangulo e isosceles. \n");
                        }
                        else {
                            printf(" -> O triangulo e escaleno. \n");
                        }
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
            default:
            {
            printf("\n Exercicio invalido \n");

            break;
            }
    }
}