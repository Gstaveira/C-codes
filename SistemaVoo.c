//Gabriel Silva Taveira 201800085

//Sistema que permite a compra e o gerenciamento de passagens aéreas de um voo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 32
#define M 4

typedef struct {
char nome[40];
char rg[12];
char codmilhas[8];
char email[40];
char tel[12];
char nomecont[40];
char telc[12];
char relacao[40];
int fileira;
int coluna;
int status;
} PESSOA;


typedef struct {
PESSOA lugares[32][4];
char data_voo[11];
char horario[5];
char codvoo[6];
char origem[40];
char destino[40];
char comandante[40];
int qtde;
} VOOS;

void Gravar (VOOS A) {
   FILE *fp;
   fp = fopen ("Binario.dat", "wb"); //arquivo para escrita binária
   if (fp == NULL) {
      printf ("Erro ao abrir o arquivo.\n");
      exit(1);
   }
   else {
        printf ("Arquivo Binario criado com sucesso.\n");
        fwrite(&A, sizeof(VOOS), 1, fp);
        fclose (fp);
   }
}/*Função reponsavel por exibir o conteudo do arquivo Binario.dat*/
void Carregar_Voo(VOOS *A){
     FILE *fp;
     fp = fopen ("Binario.dat", "rb");
      if (fp == NULL) {
		return;
}  else {
          fread(&(*A),sizeof(VOOS),1,fp);
          fclose(fp);
       }
}

void Ler_Voo(VOOS *x)
{ int i, j;
printf("\nEntre com a data do voo: ");
fgets(x->data_voo,11,stdin);
getchar();
printf("\nEntre com o horario do voo: ");
fgets(x->horario,5,stdin);
getchar();
printf("\nEntre com o codigo do voo: ");
fgets(x->codvoo,6,stdin);
getchar();
printf("\nEntre com a origem do voo: ");
fgets(x->origem,40,stdin);
getchar();
printf("\nEntre com o destino do voo: ");
fgets(x->destino,40,stdin);
getchar();
printf("\nEntre com o nome do comandante do voo: ");
fgets(x->comandante,40,stdin);
getchar();
for (i=0; i<N; i++){
for (j=0; j<M; j++){
x->lugares[i][j].status=1;
}
}
printf("\nVoo criado com sucesso!\n");
}


void Ler_Pessoa(PESSOA *x)
{ printf("\nEntre com o nome: ");
fgets(x->nome,40,stdin);
getchar();
printf("\nEntre com o RG: ");
fgets(x->rg,12,stdin);
printf("\nEntre com o codigo de milhas: ");
fgets(x->codmilhas,8,stdin);
printf("\nEntre com o email: ");
fgets(x->email,40,stdin);
getchar();
printf("\nEntre com o telefone: ");
fgets(x->tel,12,stdin);
getchar();
printf("\nEntre com o nome de um contato: ");
fgets(x->nomecont,40,stdin);
getchar();
printf("\nEntre com o telefone do contato: ");
fgets(x->telc,12,stdin);
getchar();
printf("\nEntre com a relacao com o contato: ");
fgets(x->relacao,40,stdin);
getchar();
}

void exibir_lugar(VOOS V){
int i, j;
printf("   1 2 3 4\n");
for (i=0; i<N; i++){
printf("%2.d ", i+1);
for (j=0; j<M; j++){
if(V.lugares[i][j].status==1){
printf("D ");
}
else {
printf("X ");
}
}
printf("\n");
}
printf("LEGENDA:\nD-DISPONIVEL \nX-OCUPADO\n");
}


void Exibir_Pessoa(PESSOA x)
{
printf("*** Nome: %s\n",x.nome);
printf("*** RG: %d\n",x.rg);
printf("*** Email: %d\n",x.email);
printf("*** Telefone: %s\n",x.tel);
printf("*** Nome do contato: %s\n",x.nomecont);
printf("*** Telefone do contato: %s\n",x.telc);
printf("*** Relacao com o passageiro: %s\n",x.relacao);
printf("*** Assento: %d-%d(fileira-coluna)\n",x.fileira, x.coluna);
printf("\n*******************************\n");
}

void Exibir_Voo(VOOS V)
{ int i, j;
printf("***********VOO***********\n");
printf("*** Data do Voo: %s\n", V.data_voo);
printf("*** Horario do Voo: %s\n", V.horario);
printf("*** Codigo do Voo: %s\n", V.codvoo);
printf("*** Origem do Voo: %s\n", V.origem);
printf("*** Destino do Voo: %s\n",V.destino);
printf("*** Comandante: %s\n",V.comandante);
printf("*******PASSAGEIROS********\n");
for(i=0;i<N;i++){
for(j=0; j<M; j++){
if(V.lugares[i][j].status==2){
Exibir_Pessoa(V.lugares[i][j]);
}


}
}
printf("\n*****FINAL VOO*****\n");
}





int main() {
int codigo,f, c, opcao;
int op;
PESSOA x;
VOOS V;
do {
printf("Digite 1 para carregar o voo ou digite 2 para iniciar um voo: ");
scanf("%d", &op);
getchar();
if (op==1){
Carregar_Voo(&V);
}
if (op==2){
Ler_Voo(&V);
}
}while(op!=1&&op!=2);





do {

printf("1- Comprar passagem\n");
printf("2- Exibir lugares do voo\n");
printf("3- Exibir detalhes do voo\n");
printf("4- Consultar passageiro\n");
printf("5- Remover passageiro\n");
printf("6- Sair\n");
scanf("%d",&opcao);
getchar();
switch(opcao)
{
case 1:{
Ler_Pessoa(&x);
exibir_lugar(V);
printf("\nEscolha a fileira: ");
scanf("%d", &f);
getchar();
printf("\nEscolha a coluna: ");
scanf("%d", &c);
while(V.lugares[f-1][c-1].status==2){
printf("Lugar ocupado, escolha outro");
printf("\nEscolha a fileira: ");
scanf("%d", &f);
printf("\nEscolha a coluna: ");
scanf("%d", &c);
getchar();
}
getchar();
x.fileira=f;
x.coluna=c;
x.status=2;
V.lugares[f-1][c-1]=x;
printf("\nLugar comprado com sucesso!\n");
break;
}




case 2: {
exibir_lugar(V);
break;
}

case 3: {
Exibir_Voo(V);
break;
}

case 4: {
printf("\nDigite o numero da fileira: ");
scanf("%d", &f);
printf("\nDigite o numero da coluna: ");
scanf("%d", &c);
getchar();
if(V.lugares[f-1][c-1].status==1){
printf("\nPessoa nao encontrada!\n");
}
else {
Exibir_Pessoa(V.lugares[f-1][c-1]);
}
break;
}

case 5:{
printf("\nDigite o numero da fileira: ");
scanf("%d", &f);
printf("\nDigite o numero da coluna\n: ");
scanf("%d", &c);
getchar();
if(V.lugares[f-1][c-1].status==1){
printf("\nNao ha ninguem neste assento\n");
}
else {
Exibir_Pessoa(V.lugares[f-1][c-1]);
printf("Este passageiro foi removido!\n\n\n");
V.lugares[f-1][c-1].status=1;
}
break;
}




case 6:{ printf("Obrigado por usar nosso Software\n");
Gravar(V);
break;
}
}



}while(opcao!=6);

return 0;
}


