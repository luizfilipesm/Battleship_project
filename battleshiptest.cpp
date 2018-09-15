#include<iostream>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>



struct puzzle
{
    bool avalability;
    char content;    

};

struct board
{
    puzzle** tab;
};

puzzle** board_gen(int tam)
{
    puzzle** tab_aqua = 0;
    tab_aqua = new puzzle *[tam];
    
    for(int h = 0; h < tam; h++)
        {
            tab_aqua[h] = new puzzle [tam];
        }
    
    for(int i=0; i < tam; i++)
    {
        for(int j=0; j < tam; j++ )
        {
            tab_aqua[i][j].avalability = true;
            tab_aqua[i][j].content = '-';
        }

    }

    return tab_aqua;
}


int main(int argc, char const *argv[])
{
    char *p;
    int tamanho_tabuleiro, numero_tabuleiros;
    tamanho_tabuleiro = strtol(argv[1], &p, 10);
    numero_tabuleiros = strtol(argv[2], &p, 10);
    
     board tabuleiro[numero_tabuleiros];

    for (int b = 0; b < numero_tabuleiros; b++)
	{
			tabuleiro[b].tab = board_gen(tamanho_tabuleiro);
	}
    
	for (int b = 0; b < numero_tabuleiros; b++)
	{
        std::cout << "mama eu \n";
		for(int i=0; i < tamanho_tabuleiro; i++)
    	{
        	std::cout <<"\n";
        	for(int j=0; j < tamanho_tabuleiro; j++ )
        	{
           		std::cout << tabuleiro[b].tab[i][j].content ;
        	}

		}
        std::cout <<"\n"; 	
	}

    

    /*for ( int c = 0; c < tamanho_tabuleiro; c++ )
        {
        delete [] tabuleiro[c];   
        }
        delete [] tabuleiro;
        tabuleiro = 0;
        

    /*std::cout << tamanho_tabuleiro << "\n";
    std::cout << numero_tabuleiros << "\n";
    std::cout << argc <<"\n";
    */

    return 0;
}

