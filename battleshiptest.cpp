#include<iostream>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

struct board
{
    puzzle** tab;
}
struct puzzle
{
    bool avalability;
    char content;    

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
    
    

    for (int boards = 0; boards < numero_tabuleiros; boards++){
    puzzle** tabuleiro;
    tabuleiro = board_gen(tamanho_tabuleiro);

    for(int i=0; i < tamanho_tabuleiro; i++)
    {
        std::cout <<""<<std::endl;
        for(int j=0; j < tamanho_tabuleiro; j++ )
        {
           std::cout << tabuleiro[i][j].content ;
        }

    }

    /*for ( int b = 0; b < tamanho_tabuleiro; b++ )
        {
        delete [] tabuleiro[b];   
        }
        delete [] tabuleiro;
        tabuleiro = 0;
        

    /*std::cout << tamanho_tabuleiro << "\n";
    std::cout << numero_tabuleiros << "\n";
    std::cout << argc <<"\n";
    */

    return 0;
}

