#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#define INSERIR 1
#define PESQUISAR 2
#define TOCAR 3
#define MOSTRAR 4
#define SAIR 9


typedef struct{
	
	int id;
	char nome[50];
	char endereco[200];
	
	
}musica;

typedef struct {

	int idmusicas;
	int anterior;
	int proximo;
	musica m[50];	

	
}playlist;

void iniPlaylist(playlist * l){
	l->idmusicas = 0;
	l->anterior = 0;
	l->proximo = 0;

}

int menu() {
    int option;
    printf("\n[1] INSERIR MUSICA");
    printf("\n[2] PESQUISAR");
    printf("\n[3] TOCAR");
    printf("\n[4] MOSTRAR");
    printf("\n[6] SAIR");
    printf("\n\n Informe o numero de sua opcao e tecle ENTER:  ");
    scanf("%d", &option);
    return option;
}

void inserir(playlist * l){
	musica * aux = malloc(sizeof(musica));
	printf("Entre com o nome da musica: ");
	scanf(" %[^\n]s", aux->nome);
	printf("Entre com o caminho da musica: ");
	scanf(" %[^\n]s", aux->endereco);
	if( l->idmusicas == 0){
		aux->id = 1;
	}
	else{
		aux->id = l->idmusicas + 1;
	}
	if (l->idmusicas == 0){
		l-> idmusicas = 1;
		l->anterior = 0;
		l->proximo = 0;
		l->m[l->idmusicas] = *aux;
	}
	else{
		l->idmusicas ++;
		l->anterior = l->idmusicas --;
		l->proximo = l->idmusicas ++;
		l->m[l->idmusicas] = *aux;
	}
	
}

void mostrar(playlist l) {
    int i;
    if (l.idmusicas == 0) {
        printf("Playlist vazia!\n");
    } else {
        printf("Lista de reproducao:\n");
        for (i = 1; i <= l.idmusicas; i++) {
            printf("ID da musica: %d\n", l.m[i].id);
            printf("Nome: %s\n", l.m[i].nome);
            printf("Caminho: %s\n", l.m[i].endereco);
            printf("\n");
        }
    }
}

void pesquisar(playlist l) {
    char nome[50];
    int i;
    int result = 1;

    printf("Entre com o nome da música que deseja pesquisar: ");
    scanf(" %[^\n]s", nome);

    for (i = 0; i <= l.idmusicas; i++) {
        result = strcmp(nome, l.m[i].nome);
        if (result == 0) {
        	break;        	
        }
	}
	if (result == 0){
		printf("\nMúsica encontrada!\n");
        printf("ID da música: %d\n", l.m[i].id);
        printf("Nome: %s\n", l.m[i].nome);
        printf("Caminho: %s\n", l.m[i].endereco);
        printf("\n");
	}
	else{
    	printf("Música não encontrada na playlist.\n");		
	}
}

void tocar(playlist l){	
    char nome[50];
    int i;
    int result = 1;

    printf("Entre com o nome da música que deseja tocar: ");
    scanf(" %[^\n]s", nome);

    for (i = 0; i <= l.idmusicas; i++) {
        result = strcmp(nome, l.m[i].nome);
        if (result == 0) {
        	break;        	
        }
	}
	if (result == 0){
		printf("\nMúsica encontrada!\n");
        printf("Nome: %s\n", l.m[i].nome);
        printf("TOCANDO MUSICA NO Caminho: %s\n", l.m[i].endereco);
        printf("\n");
	}
	else{
    	printf("Música não encontrada na playlist.\n");		
	}
}

void main(){
	setlocale(LC_ALL, "Portuguese");
	playlist l;
	iniPlaylist(&l);
	int opcao = 0;
	
	printf("Selecione a  opcao desejada" );
	
	while(opcao != SAIR){
		switch(menu()){
			case INSERIR : inserir(&l);
				break;
			case PESQUISAR : pesquisar(l);
				break;		
			case TOCAR : tocar(l);
				break;
			case MOSTRAR : mostrar(l);
				break;
			default : printf("Opcao invalida");
			break;
		}
	}
}
