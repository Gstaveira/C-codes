#include <stdio.h>
#include <string.h>

//Sistema para cadastrar e gerenciar uma turma
typedef struct {
    int matricula;
    char nome[40];
    char datanasc[11];
    char tel[15];
    } Aluno;

typedef struct cx{
    Aluno item;
    struct cx *prox;

    } Caixa;

typedef caixa *ponteiro;

typedef struct {
    ponteiro, inicio, fim;
    char nome_turma[40];
    char objetivo[1000];
    } Turma;


void inicia_turma(Turma *T){
T->qtde-0;
T->inicio=(ponteiro)malloc(sizeof(Caixa));
T->fim=T->inicio;
T->incio->prox=NULL;
}

void insere_aluno_turma(Turma *T, Aluno A){
ponteiro aux, p;
aux=(ponteiro)malloc(sizeof(Caixa));
aux->item=A;
p=T->inicio;
while((p!=T->fim)&&(strcmp(A.nome,p->prox->item.nome)==1)){
        p=p->prox;
        if(p==T->fim){
            aux->prox=p->prox;
            p->prox=aux;
            T->fim=aux;
        }
        else{
            aux->prox=p->prox;
            p->prox=aux;
        }
    T->qtde++;
}
}

void menu(){
                printf("1- Inserir Pessoa\n");
             printf("2- Remover Pessoa\n");
             printf("3- Consultar Pessoa\n");
             printf("4- Exibir Agenda\n");
             printf("5- Imprimir Agenda\n");
             printf("6- Sair\n");
}



int main(){
Turma T;
Aluno A;
int op, i, j;
inicia_turma(&T);
do {
    menu();
    scanf("%d", &op);

}
