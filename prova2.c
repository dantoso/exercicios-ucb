#include<stdio.h>//biblioteca de input output padrao
#include<string.h>//biblioteca de funcao de string
#include<stdlib.h>//biblioteca de funcoes padrao
#include<locale.h>//biblioteca para linguagem
#include<ctype.h>//biblioteca pra mexer em char

int numAssentos = 0;
char destino[50], lugares[205];
float passagem = 0.0;

int reservar(char *ptr, int id), idadeCliente(void);
void defVoo(void), mapaAviao(void);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,id,idade;
    char opcaoMenu,entrarMenu = 's';

    defVoo();
    for(i=0;i<numAssentos;i++){
        lugares[i] = 'D';
    }
    system("cls");

    while(entrarMenu == toupper('s')){
        printf("\n\n");
        printf("\nMENU\n");
        printf("\nPRESSIONE M PARA VERIFICAR MAPA DE OCUPAÇÃO DO VOO\n");
        printf("\nPRESSIONE R PARA EFETUAR RESERVA\n");
        printf("\nPRESSIONE C PARA CANCELAR UMA RESERVA\n");
        printf("\nPRESSIONE T PARA CONSULTAR VALOR DE VENDAS E QUANTIDADE DE ASSENTOS\n");
        scanf("%c",&opcaoMenu);
        fflush(stdin);

        if(opcaoMenu == toupper('m')){
            system("cls");
            printf("---- MAPA DE OCUPAÇÃO DO VOO ----\n\n\n");
            mapaAviao();
            printf("-------------------------------\n\n\n");
            printf("DESEJA VOLTAR PARA O MENU?\n");
            printf("(NÃO VOLTAR PARA O MENU SIGNIFICA ENCERRAR O PROGRAMA)\n");
            scanf("%c",&opcaoMenu);
            fflush(stdin);
        }
        else if(opcaoMenu == toupper('r')){
            system("cls");
            idade = idadeCliente();
            printf("---- MAPA DE OCUPAÇÃO DO VOO ----\n\n\n");
            mapaAviao();
            printf("-------------------------------\n\n\n");
        }
        else if(opcaoMenu == toupper('c')){
            
        }
        else if(opcaoMenu == toupper('t')){
            
        }
    }
}

void defVoo(){//define quantos assentos o aviao possui, preco da passagem e o destino de voo
    while(numAssentos < 89 || numAssentos > 200){//definindo o numero de assentos
        printf("O AVIÃO DEVE POSSUIR DE 90 A 200 ASSENTOS\n");
        printf("QUANTOS ASSENTOS O AVIÃO POSSUI?\n");
        scanf("%d",&numAssentos);
        fflush(stdin);
    }
    while(destino[0] == '\0' ||destino[0] == '\n' || destino[0] == ' '){//definindo o destino
        printf("O VOO PRECISA DE UM DESTINO, INFORME-O: ");
        fgets(destino,50,stdin);
        fflush(stdin);
    }
    while(passagem == 0.0){//definindo o preco da passagem
        printf("A PASSAGEM PRECISA DE UM PREÇO VÁLIDO\n");
        printf("QUAL É O PREÇO DA PASSAGEM?\n");
        scanf("%f",&passagem);
        fflush(stdin);
    }
}

int reservar(char *ptr, int id){//reserva um lugar no voo, caso o lugar esteja ocupado retorna false, caso nao retorna true e reserva o lugar
    if(*(ptr+id) == 'D'){
        *(ptr+id) = 'R';
        printf("ASSENTO %d RESERVADO COM SUCESSO\n", id+1);
        return 1;//retorna true
    }
    printf("O ASSENTO REQUSITADO JÁ ESTÁ RESERVADO OU VENDIDO, POR FAVOR, ESCOLHA OUTRO LUGAR\n");
    return 0;//retorna false
}

void mapaAviao(){//mostra mapa do aviao com assentos reservados disponiveis e vendidos
    int i;
    for(i=0;i<numAssentos;i++){//para cada assento no aviao
        printf("%c ", i+1,lugares[i]);
        if((i+1)%3==0){//se o numero e divisivel por 3
            if((i+1)%2==0){//se o numero e divisivel por 6
                printf("\n");// acaba uma fileira
                continue;
            }
            printf("||   || ");//acaba o conjunto de cadeiras e comeca o corredor do aviao
        }
    }
}

int idadeCliente()//pega a idade de cada cliente e retorna o valor
{
    int idade;
    printf("INFORME IDADE DO CLIENTE: ");
    scanf("%d", &idade);
    fflush(stdin);
    while(idade<3 || idade>100)//loop pra corrigir input
    {
        printf("VALOR INVALIDO PARA IDADE, APENAS VALORES DE 0 A 110 SERAO ACEITOS\n");
        scanf("%d", &idade);
        fflush(stdin);
    }
    return idade;
}
