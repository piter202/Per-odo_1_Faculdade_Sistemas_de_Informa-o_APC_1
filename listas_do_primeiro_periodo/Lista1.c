#include<stdio.h>

int main()
{
    printf("\n escreva o exercicio desejado: \n");
    printf("\n 1 - Exercicio 1: calcular a media de 3 notas com pesos de 2, 3 e 5 \n 2 - Exercicio 2: converter segundos em horas, minutos e segundos \n 3 - Exercicio 3: calcular area e perimetro de um retangulo \n 4 - Exercicio 4: calcular volume de um paralelepipedo \n 5 - Exercicio 5: converter Celsius para Fahrenheit \n 6 - Exercicio 6: calcular salario de um funcionário \n 7 - Exercicio 7: calcular consumo medio de um carro \n \n");
    int exercicio;
    scanf("%d", &exercicio);

    // essa lista de exercícios é a primeira lista de programação em c que fiz na faculdade, contem codigos simples e básicos, muitos com a mesma lógica.
    
    if (exercicio == 1)
    {
        // esse exercício calcula a média ponderada de 3 notas, onde a primeira nota tem peso 2, a segunda nota tem peso 3 e a terceira nota tem peso 5.
        float media, n1, n2, n3;
        printf("\n Digite a nota 1: \n");
        scanf("%f", &n1);
        printf("\n Digite a nota 2: \n");
        scanf("%f", &n2);
        printf("\n Digite a nota 3: \n");
        scanf("%f", &n3);
        media = n1*0.2 + n2*0.3 + n3*0.5;
        printf("A media e: %.2f \n", media);

    }
    else if (exercicio == 2)
    {
        // esse exercício converte um número de segundos em horas, minutos e segundos.
        int segundostotais, horas, minutos, segundos, resto;
        printf("\n Digite o numero de segundos: \n");
        scanf("%d", &segundostotais);
        horas = segundostotais / 3600;
        resto = segundostotais % 3600;
        minutos = resto / 60;
        segundos = resto % 60;
        printf("\n O tempo e: %d:%d:%d \n", horas, minutos, segundos);
    }
    else if (exercicio == 3)
    {
        // esse exercício calcula a área e o perímetro de um retângulo, onde a base e a altura são fornecidas pelo usuário.
        int base, altura, area, perimetro;
        printf("\n Digite a base e a altura : \n");
        scanf("%d %d", &base, &altura);
        area = base * altura;
        perimetro = 2 * (base + altura);
        printf("\n A area e: %d \n O perimetro e: %d \n", area, perimetro);
    }
    else if (exercicio == 4)
    {
        // esse exercício calcula o volume de um paralelepípedo, onde o comprimento, a largura e a altura são fornecidos pelo usuário.
        int comprimento, largura, altura, volume;
        printf("\n Digite o comprimento, largura e altura: \n");
        scanf("%d %d %d", &comprimento, &largura, &altura);
        volume = comprimento * largura * altura;
        printf("\n O volume e: %d \n", volume);
    }
    else if (exercicio == 5)
    {
        // esse exercício converte uma temperatura de Celsius para Fahrenheit, onde a temperatura em Celsius é fornecida pelo usuário.
        float celsius, fahrenheit;
        printf("\n Digite a temperatura em Celsius: \n");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("\n A temperatura em Fahrenheit e: %.2f \n", fahrenheit);
    }
    else if (exercicio == 6)
    {
        // esse exercício calcula o salário de um funcionário, onde o valor da hora e as horas trabalhadas no mês são fornecidos pelo usuário.
        float valorhora, horasmes, salario;
        printf("\n Digite o valor da hora e as horas trabalhadas no mes: \n");
        scanf("%f %f", &valorhora, &horasmes);
        salario = valorhora * horasmes;
        printf("\n O salario e: %.2f \n", salario);
    }
    else if (exercicio == 7)
    {
        // esse exercício calcula o consumo médio de um carro, onde a distância percorrida e os litros consumidos são fornecidos pelo usuário.
        float distancia, litros, consumo;
        printf("\n Digite a distancia percorrida e os litros consumidos: \n");
        scanf("%f %f", &distancia, &litros);
        consumo = distancia / litros;
        printf("\n O consumo medio e: %.2f km/l \n", consumo);
    }
    else
    {
        printf("Exercicio invalido \n");
    }
    return 0;
}