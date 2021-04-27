// matheus dantas vilela - UC21100594 - bacharelado ciencias da computaçao

#include<stdio.h>//biblioteca de input output padrao
#include<string.h>//biblioteca de funcao de string
#include<stdlib.h>//biblioteca de funcoes padrao

//declarando variaveis globais
typedef struct{//struct para as dados de cada pessoa
//    to usando um struct pra fins de uma suposta manutencao no codigo, ja que se o pro
    char sex; //guarda o sexo do cliente
    int age; //guarda a idade do cliente
}pessoa;
//numeros de sessoes, crianças, adloescentes, adultos e idosos que assistiram as sessoes, respectivamente:
int num_sessoes,num_crianca,num_adolescente,num_adulto,num_idoso;//nomes de variaveis gigantescos, mas explicitos, pro CODIGO ficar LIMPO (do livro codigo limpo, ele mesmo)
int pessoas;//numero de pessoas que assistiram o filme

//guarada o numero de pessoas do sexo masculino maiores de 18 e guarda o numero de maiores do sexo feminino, respectivamente
int num_M_maior, num_F_maior;
int num_M,num_F;// numero de pessoas do sexo masculino e numero de pessoas do sexo feminino
char filme[105];//string pro nome do filme transmitido

//declarando funcoes (me recuso a encher com mais comentario aqui)
int getsAge(void);
char getsSex(void);
void getsPessoas(void),getsFilme(void),getsSessoes(void);

int main()//funcao main (por incrivel que pareca)
{
    //funcao da stdlib pra limpar o terminal
    system("cls");//limpando o terminal
    printf("Bem-vindo, preencha as informacoes pedidas abaixo:\n");//interagindo com o usuario
    //usando as minhas funcoes
    getsFilme();//funcao que pega o filme
    getsPessoas();//funcao que pega o numero de pessoas
    pessoa cliente[pessoas]; //definindo o array de clientes

    for(int i=0;i<pessoas;i++)// loop para guardar informaçao de cada cliente (idade e sexo) e informacoes relevantes
    {
        cliente[i].age = getsAge();//guardando idade do cliente i
        cliente[i].sex = getsSex();//guardando sexo do cliente i

        //transformando dados coletados acima em informacoes relevantes
        if(cliente[i].sex == 'M')//verifica se eh masculino
        {
            num_M++;//computando pessoas do sexo masculino
            if(cliente[i].age > 17) num_M_maior++;//computando pessoas do sexo masculino maiores de 18
        }
        if(cliente[i].sex == 'F')//verifica se eh feminino
        {
            num_F++;//computando pessoas do sexo feminino
            if(cliente[i].age > 17) num_F_maior++;//computando pessoas do sexo feminino maiores de 18
        }
        if(cliente[i].age < 14) num_crianca++;//computando se eh crianca
        else if(cliente[i].age < 18) num_adolescente++;//computando se eh adolescente
        else if(cliente[i].age < 65) num_adulto++;//computando se eh adulto
        else num_idoso++;//computando se eh idoso
    }
    system("cls");//limpando o terminal
    printf("\nO filme transmitido foi %s", filme);//interagindo com o usuario
    printf("\nEsse filme foi assistido por um total de %d pessoas, sendo elas:\n", pessoas);//interagindo com o usuario
    printf("\n %d pessoas do sexo masculino e %d pessoas do sexo feminino\n",num_M,num_F);//interagindo com usuario
    printf("\n%d Criancas\n%d Adolescentes\n%d Adultos\n%d Idosos\n", num_crianca,num_adolescente,num_adulto,num_idoso);//interagindo com o usuario
    printf("\nATENCAO professora Joyce, a implementacao bonus eh essa:\n");//interagindo com a usuaria Joyce
    
    for(int i=0;i<pessoas;i++)//loop pra printar as informacoes
    {
        //printa o sexo e a idade de cada cliente
        //o objetivo dessa implementacao e printar informacoes mais detalhadas
        //pros donos do cinema terem informacoes mais especificas pra trabalhar
        if(cliente[i].sex == 'F') printf("\nCliente %d do sexo biologico MASCULINO tem %d anos de idade.\n",i+1,cliente[i].age);//printa se for feminino
        else printf("\nCliente %d do sexo biologico FEMININO tem %d anos de idade.\n",i+1,cliente[i].age);//printa se for masculino
    }
    
    getsSessoes();//funcao pra pegar o numero de sessoes
    //essa funcao esta sendo usada agora para que o output aconteca de acordo com o pdf de instrucoes enviado pela professora
    system("cls");//limpando o terminal
    printf("\nMaiores do sexo masculino: %d\n",num_M_maior);//interagindo com o usuario
    printf("\nMaiores do sexo feminino: %d\n",num_F_maior);//interagindo com o usuario
    printf("\nfim");//interagindo com o usuario
    
    return 0;//retorna 0 (grande plot twist)
}

//nomes das funçoes explicitos pro CODIGO ficar LIMPO
//funcoes curtas e diretas, por motivos de livro ^^^^
//usando funcoes pra operacoes, deixando a funcao main LIMPA
void getsFilme()//pega o nome do filme e guarda em uma variavel global
{
    printf("----------------------------------------------------------------------------\n");//linha pra dividir as telas
    printf("Qual o nome do filme?\n");//interagindo com o usuario
    fgets(filme, 105, stdin);//le a variavel filme
    fflush(stdin);//limpar buffer
    while(strcmp(filme,"\n")==0 || strcmp(filme,"vazio\n")==0 || filme[0] == ' ')//loop pra corrigir input
    {
        printf("o filme precisa de nome e precisa ser diferente de vazio\n");// feedback pro usuario
        printf("o nome tambem nao pode comecar com barra de espaco\n");// feedback pro usuario
        fgets(filme, 105, stdin);//le a variavel filme
        fflush(stdin);//limpar buffer
    }
    printf("Sucesso!\n");//mais feedback
    printf("\n----------------------------------------------------------------------------");//linha pra dividir as telas
}

void getsSessoes()//pega o numero de sessoes e guarda em uma variavel global
{
    printf("----------------------------------------------------------------------------\n");//linha pra dividir as telas
    printf("Quantas vezes o filme foi transmitido?\n");//interagindo com o usuario
    scanf("%d", &num_sessoes);//le o numero de sessoes
    fflush(stdin);//limpar buffer
    while(num_sessoes!=2)//loop pra corrigir input
    {
        printf("O numero de sessoes precisa ser exatamente 2 para ser valido (nao me pergunte porque)\n");//interagindo com o usuario
        scanf("%d", &num_sessoes);//le o numero de sessoes
        fflush(stdin);//limpar buffer
    }
    printf("Sucesso!\n");//interagindo com o usuario
    printf("\n----------------------------------------------------------------------------");//linha pra dividir as telas
}

void getsPessoas()//pega a quantidade de pessoas que assistiram ao filme e guarda em uma variavel global
{
    printf("----------------------------------------------------------------------------\n");//linha pra dividir as telas
    printf("Quantas pessoas assistiram ao filme?\n");//interagindo com o usuario
    scanf("%d", &pessoas);//guarda o input em pessoes
    fflush(stdin);//limpar buffer
    while(pessoas<10)//loop pra corrigir input
    {
        printf("Quantidade invalida, insira um numero maior que 9\n");//interagindo com o usuario
        scanf("%d", &pessoas);//guarda o input em pessoas
        fflush(stdin);//limpar buffer
    }
    printf("Sucesso!\n");//interagindo com o usuario
    printf("\n----------------------------------------------------------------------------");//linha pra dividir as telas
}

int getsAge()//pega a idade de cada cliente e retorna o valor
{
    int idade;//variavel local para ser usada no loop
    printf("----------------------------------------------------------------------------\n");//linha pra dividir as telas
    printf("Por favor informe sua idade:\n");//interagindo com o usuario
    scanf("%d", &idade);//le idade
    fflush(stdin);//limpar buffer
    while(idade<3 || idade>100)//loop pra corrigir input
    {
        printf("Valor invalido para idade, apenas valores de 3 a 100 serao aceitos\n");//interagindo com o usuario
        scanf("%d", &idade);//le idade
        fflush(stdin);//limpar buffer
    }

    printf("Sucesso!\n");//interagindo com o usuario
    return idade;//retorna idade (nao se assuste, eu sei que eh muita informacao em um unico comentario)
}

char getsSex()//pega o sexo biologico de cada cliente e retorna o valor
{
    char sexo;//variavel local pra ser usada no loop
    printf("\nPor favor informe seu sexo biologico (M / F):\nDigite M se for masculino, F se for feminino:\n");//interagindo com o usuario
    printf("\n(Letra MAIUSCULA)\n");//especificando pro usuario
    scanf("%c", &sexo);//le o sexo
    fflush(stdin);//limpar buffer
    while(sexo!='M' && sexo!='F')//loop pro usuario otario
    {
        printf("\nINPUT INVALIDO:\n\nDigite M se for masculino, F se for feminino\n");//interagindo com o usuario
        printf("Lembre-se, os caracteres precisam ser MAIUSCULOS (CAPS LOCK ON):\n");//interagindo ainda mais com o usuario (vai que)
        scanf("%c", &sexo);//le o sexo
        fflush(stdin);//limpar buffer
    }

    printf("Sucesso!\n");//interagindo com o usuario
    printf("\n----------------------------------------------------------------------------");//linha pra dividir as telas
    return sexo;//retorna sexo (calma, respira)
}