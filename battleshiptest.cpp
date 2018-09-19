#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>


struct puzzle
{
    bool avalability;
    char content;    

};

struct board
{
    puzzle** tab;
};

void respostajogador (int solicita, board &grid, int tamanho)
{
    int a[solicita], b[solicita];
    bool correto = true;
    for (int i = 0; i<solicita; i++)
    {    std::cout << "Insira a sua " << i+1 << "coordenada";
        std::cin >> a[i];
        std::cin >> b[i];
        if (grid.tab[a[i]][b[i]].content == 'X')
        {
            correto = correto;
        }
        else
        {
            correto = false;
        }
        
    }

    if (correto)
    {
        std::cout << "Acertou miserávi" << std::endl;
    }

    else
    {
       std::cout << "ERROUUUUUUU" << std::endl; 
    }

    for(int i=0; i < tamanho; i++)
    {
    	std::cout <<"\n";
       	for(int j=0; j < tamanho; j++ )
       	{
     	std::cout << grid.tab[i][j].content ;
        }

	}

    std::cout << "suas coordenadas foram:" << std::endl;

    for (int i=0; i<solicita; i++)
    {
        std::cout << "horizontal: " << a[i] << " vertical: "<< b[i] << std::endl;
    }

    


}

void imprimeusr (board &grid, int tamanho, int &solicita)
{
    int contlinha[tamanho], contcoluna[tamanho];
    std::cout <<"Vamos jogar seu puzzle ja foi sorteado\n";
    std::cout <<"0 representa água \n\n\n";

    for(int i=0; i < tamanho; i++)
    {
        contcoluna[i] = 0;
        contlinha[i] = 0;
    }
    
    for(int i=0; i < tamanho; i++)
    	{
        	
        	for(int j=0; j < tamanho; j++ )
        	{
           		if (grid.tab[i][j].content == 'X')
                {
                    contlinha[i]++;
                }
        	}

		}

    for(int i=0; i < tamanho; i++)
    {
        
        for(int j=0; j < tamanho; j++ )
        {
            if (grid.tab[j][i].content == 'X')
            {
                contcoluna[i]++;
            }
        }

    }    

    std::cout << "    ";

    for(int i=0; i < tamanho; i++)
        {
        std::cout << i << " ";
        } 

    std::cout << "\n"; 


    for(int i=0; i < tamanho; i++)
    {
        std::cout <<"\n";
        std::cout << i << "   ";
        for(int j=0; j < tamanho; j++ )
            {   
                std::cout <<  "0 ";
            }
        std::cout << contlinha[i] << " ";
    }

    std::cout <<"\n";
    std::cout << "    ";

    for(int i=0; i < tamanho; i++)
    {
    std::cout << contcoluna[i] << " ";
    }  

    std::cout <<"\n";
    for (int i = 0; i < tamanho; i++)
        {
        solicita = solicita + contcoluna[i];
        }
}

void setboat(board &grid ,int tamanho, int boatsize)
{
    
    int posix, posiy, orient;
    posix = rand() % tamanho;
    posiy = rand() % tamanho;
    orient = rand() % 2;
    bool vert = false, horiz = false;

 



    if(orient == 0) //horizontal
    {
        for (int i = 0; i < boatsize; i++)
        {   
            if(posiy+i < tamanho)
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
            else
            {
                vert = false;
                break;
            }
        }
    }
    
    else
    {
        for (int i = 0; i < boatsize; i++)
        {
            if(posix+i < tamanho)
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
            else
            {
                vert = false;
                break;
            }
        }
    }

    if(horiz)
    {
        for (int i = 0; i < boatsize; i++)
        {
            grid.tab[posix][posiy+i].content = 'X';
        }

        for (int i = 0; i < 3; i++ )
        {
            for(int j = 0; j < boatsize+2; j++ )
            {   
                if(posiy-1+j < tamanho && posix-1+i < tamanho)
                {
                    if(posix-1+i >=0 && posiy-1+j >=0)
                    {
                        grid.tab[posix-1+i][posiy-1+j].avalability = false;    
                    }
                }
                    
                }
            }
    }            
    else if(vert)
    {
       for (int i = 0; i < boatsize; i++)
        {
            grid.tab[posix+i][posiy].content = 'X';
        }

        for (int i = 0; i < 3; i++ )
        {
            for(int j = 0; j < boatsize+2; j++ )
            {
                if(posiy-1+i < tamanho && posix-1+j < tamanho)
                {
                    if(posix-1+j >=0 && posiy-1+i >=0)
                    {
                    grid.tab[posix-1+j][posiy-1+i].avalability = false;
                    }
                }
            }
        } 

    }
    else
    {
        setboat(grid, tamanho, boatsize);
    }

}

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
    int bship = 4 , cruiser = 3, destroyer = 2, submarine = 1;
    tamanho_tabuleiro = strtol(argv[1], &p, 10);
    numero_tabuleiros = strtol(argv[2], &p, 10);
    board tabuleiro[numero_tabuleiros];
    std::ofstream printmatrix;

    printmatrix.open("tabuleirosprontos.txt");


    for (int conttabv = 0; conttabv < numero_tabuleiros; conttabv++)
	{
		tabuleiro[conttabv].tab = board_gen(tamanho_tabuleiro);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, bship);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, cruiser);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, cruiser);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, destroyer);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, submarine);
        setboat(tabuleiro[conttabv], tamanho_tabuleiro, submarine);

	}

    /*for(int counttab = 0 ; counttab < numero_tabuleiros; counttab++)
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

    } */
    
    printmatrix<< tamanho_tabuleiro << std::endl;
    printmatrix<< numero_tabuleiros << std::endl;

	for (int b = 0; b < numero_tabuleiros; b++)
	{
        printmatrix<< b <<"t" << std::endl;
		for(int i=0; i < tamanho_tabuleiro; i++)
    	{
        	printmatrix <<"\n";
        	for(int j=0; j < tamanho_tabuleiro; j++ )
        	{
           		printmatrix << tabuleiro[b].tab[i][j].content ;
        	}

		}
        printmatrix  << "\n\n\n\n"; 	
	}

        printmatrix.close();


    int randtabuleiro = rand () % numero_tabuleiros; 
    int numerodesolicitacoes = 0;
    imprimeusr (tabuleiro[randtabuleiro] , tamanho_tabuleiro, numerodesolicitacoes);
    respostajogador (numero_tabuleiros, tabuleiro[randtabuleiro], tamanho_tabuleiro);



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

