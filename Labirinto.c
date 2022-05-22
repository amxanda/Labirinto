#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#include <locale.h>
#define MAX 20

void cria(char l[MAX][MAX])
{
	int i,j,x,y;
	srand(time(NULL));
	
	for(i=0;i<MAX;i++)  
	    for(j=0;j<MAX;j++)
		{
	        if((rand()%5)==1)
	            l[i][j]='|';
	        else
	            l[i][j]='.';
	    }
	    for(i=0;i<MAX;i++)
		{
	        l[0][i]='*';
	        l[MAX-1][i]='*';
	        l[i][0]='*';
	        l[i][MAX-1]='*';
	    }// fim for
	    
		x=  rand() % MAX-1;
	    y=  rand() % MAX-1;
	    l[x][y]='Q';
}// fim funcao cria
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int col)
{
    int i,j;
     for ( i = 0; i < linha; i++)
    {
     	printf("\n");
        for ( j = 0; j < col; j++)
			printf (" %c ",mat[i][j] );
    }
} // fim funcao
     
int funcaoSuperMouse(char lab[MAX][MAX],int i, int j)
{
     tpilha p1;
     inicializa (&p1);
     tdado pos;

	do
	{
		lab[i][j] = 'v'; 
        if(lab[i][j+1]=='.' || lab[i][j+1]=='Q') 
		{
             pos.i = i;
             pos.j = j;
             push(&p1,pos); //empilhar posição
             j++; //avançar a linha
        } 
        else
        if(lab[i+1][j]=='.' || lab[i+1][j]=='Q') {
             pos.i = i;
             pos.j = j;
             push(&p1,pos);
             i++; //avançar a coluna
        }
        else
        if(lab[i][j-1]=='.' || lab[i][j-1]=='Q') {
             pos.i = i;
             pos.j = j;
             push(&p1,pos);
             j--; //decrementar a linha
        }
        else
        if(lab[i-1][j]=='.' || lab[i-1][j]=='Q') {
             pos.i = i;
             pos.j = j;
             push(&p1,pos); 
             i--; //decrementar a coluna
        }
        else
		{
            if(!isEmpty(p1))
			{
                lab[i][j] = 'x'; //escrever 'x' nos lugares onde o rato ja passou
                pos = pop(&p1); //desempilhar 
                i = pos.i; //pega a posição do i e 
                j = pos.j;
            } else {
                printf(" Impossivel encontrar o queijo.");
                return 0;
            }
        }
        
        Sleep(300);
        system("cls");
		printf(" -------------------- L A B I R I N T O ------------------- \n");
        mostraLabirinto(lab, MAX,MAX);
        printf("\n ---------------------------------------------------------- \n");
	} while(lab[i][j] != 'Q');
	//enquanto a posição i,j for diferente de Q
    printf("\n Jerry encontrou o queijo na posicão [%d][%d]",i,j);
 }// fim funcao

int main()
{
	setlocale(LC_ALL,"");
	
    char labirinto[MAX][MAX];
    int x,y;
    
    printf(" -------------------- L A B I R I N T O ------------------- \n");

    
    cria(labirinto);
    mostraLabirinto(labirinto,MAX,MAX);
    printf("\n");
    printf("\n ---------------------------------------------------------- \n");
    
    printf("\n Digite a linha: ");
    scanf("%d",&x);
    printf(" Digite a coluna: ");
    scanf("%d",&y);
    
    funcaoSuperMouse(labirinto,x,y);
    
    getch();  
}
