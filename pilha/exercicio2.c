#include <stdio.h>

//Definição do tamanho maximo da pilha
#define MAX 100

//Definição do tipo pilha
typedef struct pilha{
    int topo;//variavel para fazer controle do topo da pilha
    int vetor[MAX];//vetor que ira armazenar o conteudo da pilha
} Pilha;

void freestack(Pilha *p);
    //função que libera uma pilha qualquer

int stack(Pilha *p, int v);
    //função que recebe uma pilha qualquer e adiciona um inteiro nela

int desempilha(Pilha *p, int *v);
    //função que recebe uma pilhar qualquer e realiza a operação de desempilhar

int isEmpty(Pilha *p);
    //Recebe uma pilha qualquer e retorna 1 para uma pilha vazia ou 0 para uma pilha não vazia

int isFull(Pilha *p);
    //Recebe uma pilha qualquer e retorna 1 para uma pilha cheia ou 0 para uma pilha não cheia

int getGreatterNumber(Pilha *p);
    //Recebe uma pilha qualquer e retorna o maior numero achado

int getLowerNumber(Pilha *p);
    //Recebe uma pilha qualquer e retorna o menor numero achado

double average(Pilha *p);
    //Recebe uma pilha qualquer e retorna a media aritimetica da lista

void printStack(Pilha *p);
    //Recebe uma pilha qualquer e exibe no terminal a lista completa


void main() {
    Pilha p;//declaração da pilha que sera utilizada
    p.topo = -1;//normalização da varaivel de controle da pilha
    
    //declaração das variaveis de controle
    int loop = 1;//variavel de controle do loop do programa
    int escolha = 0;//variavel que armazena qual função o usuario escolheu
    int input = 0;//variavel para receber input do usuario
    int output = 0;//variavel para receber output de funções

    //inicio do loop do programa
    while(loop){
        //Menu para escolha de funções do programa
        printf("====MENU====\n");
        printf("1. liberar pilha\n");//Chama a função freestack que libera a pilha p
        printf("2. empilhar\n");//Chama o scanf para receber um int do usuario e usa a função stack para empilhar o valor fornecido na pilha p
        printf("3. desempilhar\n");//Chama a função desempilha passando a variavel output para ent mostrar na tela o valor recuperado da pilha
        printf("4. estahVazia\n");//verifica se a pilha p está vazia
        printf("5. EstahCheia\n");//verifica se a pilha p está cheia
        printf("6. Pegar maior numero\n");//Chama a função getGreatterNumber passando a pilha p e printa o resultado da chamada
        printf("7. Pegar menor numero\n");//Chama a função getLowerNumber passando a pilha p e printa o resultado da chamada
        printf("8. Pegar media aritmetica numero\n");//Chama a função average passando a pilha p e printa o resultado da chamada
        printf("9. Mostrar a pilha toda\n");//Chama a função printStack passando a pilha p
        printf("10. Sair\n");//setta o valor da variavel loop para 0, saindo loop do menu
        
        scanf("%d", &escolha);//recebe um numero que o usuario escrever

        //laço switch para contorle do menu
        switch(escolha){
            case 1:
                freestack(&p);
                break;

            case 2:
                scanf("%d", &input);
                stack(&p, input);
                break;

            case 3:
                if(desempilha(&p, &output))
                    printf("A pilha devolveu o valor: %d\n", output);
                else
                    printf("A pilha esta vazia\n");
                output = 0;
                break;

            case 4:
                if (isEmpty(&p))
                    printf("A pilha esta vazia\n");
                else
                    printf("A pilha nao esta vazia\n");
                break;

            case 5:
                if (isFull(&p))
                    printf("A pilha esta cheia\n");
                else
                    printf("A pilha nao esta cheia\n");
                break;

            case 6:
                printf("O maior numero eh: %d\n", getGreatterNumber(&p));
                break;

            case 7:
                printf("O menor numero eh: %d\n", getLowerNumber(&p));
                break;

            case 8:
                printf("A media eh: %.2lf\n", average(&p));
                break;

            case 9:
                printStack(&p);
                break;

            case 10:
                loop = 0;
                break;

            default:
                printf("numero invalido tente novamente\n");
        }
    }

}

void freestack(Pilha *p){
    //checa se a pilha está vazia
    if (isEmpty(p))
    {
        return;
    }
    //laço for para limpar toda a lista
    for (int i = p->topo; i > -1; i--)
    {
        p->vetor[i] = 0;
    }
    p->topo = -1;//realiza a normalização da variavel de controle da pilha
}

int stack(Pilha *p, int v){
    //verifica se a pilha está cheia
    if (isFull(p))
    {
        return 0;//retorna 0 para identificar fracasso
    }
    p->topo++;//atualiza o novo indexe do topo da pilha
    p->vetor[p->topo] = v;//copia o valor da variavel recebida para o topo dapilha
    return 1;//retorna 1 para identificar sucesso
}

int desempilha(Pilha *p, int *v){
    if (isEmpty(p))
    {
        return 0;
    }
    *v = p->vetor[p->topo];
    p->topo--;
    return 1;
}
int isEmpty(Pilha *p){
    if (p->topo == -1)//checa se a variavel topo esta no seu padrão normalizado
    {
        return 1;//caso a variavel estejá normalizada retorna 1 para endicar que a lista está vazia
    }
    return 0;//caso a variavel não estejá normalizada retorna 0 para indicar que a lista não está vazia
}

int isFull(Pilha *p){
    if (p->topo == MAX)//checa se o topo da pilha chegou ao maximo definido pelo programa
    {
        return 1;//caso o topo tenha chegado no maximo retorna 1 para indicar que a lista está cheia
    }
    return 0;//caso o topo não tenha chegado no maximo retorna 0 para indicar que a lista não está cheia
}

int getGreatterNumber(Pilha *p){
    int get_greatter_number = p->vetor[p->topo];//declaração de variavel para armarnezar o maior numero

    for (int i = p->topo; i > -1; i--)//laço for para percorrer toda a lista
    {

        if (p->vetor[i] > get_greatter_number)//compara se o numero no index atual é maior que o maior numero atual
        {
            get_greatter_number = p->vetor[i];//guarda o novo maior numero
        }
    }
    return get_greatter_number;//retorna o maior numero
}

int getLowerNumber(Pilha *p){
    int get_lower_number = p->vetor[p->topo];//declaração de variavel para armarnezar o menor numero
    for (int i = p->topo; i > -1; i--)//laço for para percorrer toda a lista
    {
        if (p->vetor[i] < get_lower_number)//compara se o numero no index atual é menor que o menor numero atual
        {
            get_lower_number = p->vetor[i];//guarda o novo menor numero
        }
    }
    return get_lower_number;//retorna o menor numero
}
double average(Pilha *p){
    double average = 0.0;//variavel para guadar a media
    int total = 0;//variavel para armazenar a soma de todos os numeros

    for (int i = p->topo; i > -1; i--)//laço for para percorrer toda a lista
    {

        total += p->vetor[i];//soma o valor do index atual na variavel total
    }
    average = (double)total/(double)(p->topo + 1);//realiza a operação de media aritimetica e armazenar o valo na variavel avarage
    return average;//retorna a media da pilha
}

void printStack(Pilha *p){
    for (int i = p->topo; i > -1; i--)
    {
        printf("%d\n", p->vetor[i]);
    }
}