#include<stdio.h>

int main()
{
    printf("\n escreva o exercicio desejado: \n");
    printf("\n 1 - Exercicio 1: menu de escolha entre operacoes \n 2 - exercicio 2: calcula o aumento do salario de um funcionario que recebe 500 ou menos \n 3 - exercicio 3: calcula o valor de um credito dependendo do valor \n 4 - exercicio 4: calcula o ganho de um investimento \n 5 - exercicio 5: verifica se a senha digitada e correta \n 6 - exercicio 6: verifica se a idade digitada e permitida para acesso\n \n");

    int escolha;
    scanf("%d", &escolha);

    // essa é a terceira lista, primeiro periodo, ela contem codigos que rodam a partir ferramenta "switch" para exercutar multiplas funcões que aparecem no menu escrito acima.

    switch (escolha)
    {   case 1:
            // esse exercício apresenta um menu de escolha entre operações matemáticas (média, diferença, produto e divisão) para dois números fornecidos pelo usuário.

            float n1, n2, media, diferenca, produto, divisao;

            printf("\n Digite o numero 1 e o numero 2: \n");
            scanf("%f %f", &n1, &n2);
            
            printf("\n Escolha a operacao desejada: \n 1 - Media \n 2 - Diferenca \n 3 - Produto \n 4 - Divisao \n");

            int opção;
            scanf("%d", &opção);
            switch (opção)
            {
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
                    if (n2 != 0)
                    {
                        divisao = n1 / n2;
                        printf("\n A divisão dos numeros e: %.2f \n", divisao);
                    }
                    else
                    {
                        printf("\n Divisão por zero nao é permitida \n");
                    }
                    break;
                default:
                    printf("\n Opcao invalida \n");
                    break;
            }
            break;
        case 2:
            // esse exercício calcula o aumento do salário de um funcionario no qual o salario é menor ou igual a 500.

            float salario, aumento, novo_salario;

            printf("\n Digite o salario do funcionario: \n");
            scanf("%f", &salario);
            
            if (salario <= 500)
            {
                aumento = salario * 0.30;
                novo_salario = salario + aumento;
                printf("\n O novo salario do funcionario e: %.2f \n", novo_salario);
            }
            else
            {
                printf("\n O funcionario nao tem direito a aumento \n");
            }

            break;
        case 3:
            // esse execício calcula o valor de um credito em diferentes graus, dependendo do saldo atual.
        
            float saldo, credito;

            printf("\n Digite o saldo atual \n");
            scanf("%f", &saldo);
        
            if (saldo >= 400)
            {
                credito = saldo * 0.3;
            }
            else if (saldo >= 300)
            {
                credito = saldo * 0.25;
            }
            else if (saldo >= 200)
            {
                credito = saldo * 0.2;
            }
            else
            {
                credito = saldo * 0.1;
            }   

            printf("\n o valor do credito e: %.2f \n", credito);
            
            break;
        case 4:
            // esse exercício calcula o rendimento de um investimento, onde o valor do investimento e a opção de investimento são fornecidos pelo usuário.
        
            float investimento, poupança, fundos_de_renda_fixa;
            
            printf("\n Digite o valor do investimento: \n");
            scanf("%f", &investimento);
            printf("\n escolha a opcao de investimento: \n 1 - Poupanca \n 2 - Fundos de Renda Fixa \n");
            int opcao_investimento;
            scanf("%d", &opcao_investimento);

            switch (opcao_investimento)
            {
                case 1:
                    poupança = investimento * 0.03;
                    printf("\n O rendimento da poupanca e: %.2f \n", poupança);
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
        case 5:
            // esse exercício verifica se a senha digitada pelo usuário é correta, na qual a senha correta é 4531.

            int senha;

            printf("\n Digite a senha: \n");
            scanf("%d", &senha);
            if (senha == 4531)
            {
                printf("\n Acesso permitido \n");
            }
            else
            {
                printf("\n Acesso negado \n");
            }
            
            break;
        case 6:
            // esse exercício verifica se a idade digitada pelo usuário é permitida para acesso, onde a idade permitida é acima dos 18 anos.

            int idade;

            printf("\n Digite a idade: \n");
            scanf("%d", &idade);

            if (idade >= 18 && idade <=120)
            {
                printf("\n acesso permitido \n");
            }
            else if (idade >= 0 && idade < 18)
            {
                printf("\n idade não permitida \n");
            }
            else
            {
                printf("\n idade invalida \n");
            }

            break;
        default:

            printf("\n Exercicio invalido \n");

            break;
    }
    return 0;
}