#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>


struct puzzle
{// Estrutura do conteúdo da matriz
    bool avalability; // Variável que denota a disponibilidade da célula
    char content; // Variável que denota o conteúdo da célula
}; 

struct board
{// Estturtura do tabuleiro
    puzzle** tab;
};

void setboat(board &grid ,int tamanho, int boatsize)
{
    
    std::cout <<"oremos";
    board abacaxi = grid;
    int posix, posiy, orient;
    posix = rand() % tamanho;
    posiy = rand() % tamanho;
    orient = rand() % 3;
    bool vert = false, horiz = false;

    std::cout << posix << std::endl;
    std::cout << posiy << std::endl;
    std::cout << orient << std::endl;

    if(orient = 0) //horizontal
    {
        std::cout <<"oremoshorizon" << std::endl;
        for (int i = 0; i < boatsize; i++)
        {
            if (grid.tab[posix][posiy+i].avalability)
            {
                horiz = true;
            }
            else
            {
                horiz = false;
                break;
            }
        }
    }
    
    else
    {
        std::cout <<"oremosvert"<< std::endl;
        for (int i = 0; i < boatsize; i++)
        {
            if (grid.tab[posix+i][posiy].avalability)
            {
                vert = true;
            }
            else
            {
                vert = false;
                break;
            }
        }
    }

    if(horiz)
    {
        std::cout <<"oremos horizn2"<< std::endl;
        for (int i = 0; i < boatsize; i++)
        {
            grid.tab[posix][posiy+i].content = 'X';
        }

        for (int i = 0; i < 3; i++ )
        {
            for(int j = 0; j < boatsize+2; j++ )
            {
                grid.tab[posix-1+i][posiy-1+j].avalability = false;
            }
        }
    }            
    else if(vert)
    {
        std::cout <<"oremosvert2"<< std::endl;
       for (int i = 0; i < boatsize; i++)
        {
            grid.tab[posix+i][posiy].content = 'X';
        }

        for (int i = 0; i < 3; i++ )
        {
            for(int j = 0; j < boatsize+2; j++ )
            {
                grid.tab[posix-1+j][posiy-1+i].avalability = false;
            }
        } 

    }
    else
    {
        setboat(abacaxi, tamanho, boatsize);
    }

}

puzzle** board_gen(int tam)
{
    puzzle** tab_aqua = 0; // Matriz receberá '0' inicializando o tabuleiro
    tab_aqua = new puzzle *[tam]; //
    
    for(int h = 0; h < tam; h++)
        {
            tab_aqua[h] = new puzzle [tam]; // 
        }
    
    for(int i=0; i < tam; i++)
    {
        for(int j=0; j < tam; j++ )
        {
            tab_aqua[i][j].avalability = true;// Preenchendo a tabela de disponibilidade, deixando todos os espaços disponíveis
            tab_aqua[i][j].content = '-'; // Preenchendo todos os espaços com "-" que representa água 
        }

    }

    return tab_aqua; // Retorna a tabela inicializada e preenchida 
}


int main(int argc, char const *argv[])
{
    char *p; 
    int tamanho_tabuleiro, numero_tabuleiros;
    int bship = 4 , cruiser = 3, destroyer = 2, submarine = 1;
    tamanho_tabuleiro = strtol(argv[1], &p, 10);
    numero_tabuleiros = strtol(argv[2], &p, 10);
    
    board tabuleiro[numero_tabuleiros];todo


    for (int conttabv = 0; conttabv < numero_tabuleiros; conttabv++)
	{
		tabuleiro[conttabv].tab = board_gen(tamanho_tabuleiro);
	}

    for(int counttab = 0 ; counttab < numero_tabuleiros; counttab++)
    {
        std::cout <<"agrvai" << std::endl;
        setboat(tabuleiro[counttab], tamanho_tabuleiro, bship);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, cruiser);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, cruiser);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[counttab], tamanho_tabuleiro, submarine);

    } 
    
	for (int b = 0; b < numero_tabuleiros; b++)
	{
        std::cout<< std::endl;
		for(int i=0; i < tamanho_tabuleiro; i++)
    	{
        	std::cout <<"\n";
        	for(int j=0; j < tamanho_tabuleiro; j++ )
        	{
           		std::cout << tabuleiro[b].tab[i][j].content ;
        	}

		}
        std::cout << b <<"\n"; 	
	}

    ; 


    /*for (int e = 0; e < tamanho_tabuleiro; e++ )
    {   
        for ( int d = 0; d < tamanho_tabuleiro; d++ )
        {
        delete [] tabuleiro[e].tab[d];   
        }
        delete [] tabuleiro[e].tab;
        tabuleiro[e].tab = 0;
    }*/
    
        

    /*std::cout << tamanho_tabuleiro << "\n";
    std::cout << numero_tabuleiros << "\n";
    std::cout << argc <<"\n";
    */

    return 0;
}

