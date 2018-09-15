#include<iostream>

using namespace std;

struct board
{
	puzzle[tam][tam]
}

struct puzzle
{
	bool diponibilidade; // Variável que irá testar se espaço está disponível
	char conteudo; // Variável vai indicar o conteudo da posição  
}

void preenchematriz (tabuleiro[], q_tabuleiros)
{
	
}

puzzle geramatriz (int tamanho)
{// Função geradora da matriz
	short t2 = tamanho
	puzzle tabuleiro[t2][t2]; 
	

	if (t>7 && t<15)
	{
 		for(int i=0; i < t; i++)
 		{
			for(int j=0; j < t; i++)
  	 		{
 			tabuleiro[i][j].posicao="-"; // o hífen representa água 
			tabuleiro[i][j].disponibilidade = true; // espaço alocado como disponível
  	 		}	
 		}

 	return tabuleiro;
	}

	else 
	{	
	cout << "Tamanho inválido, insira outro tamanho para o tabuleiro" << endl; 
	cin >> t2;
	return gerametriz (t2);	
	}
}



int main()
{
	int tamanho; // Tamanho da matriz
	int q_tabuleiros // Quantidade de tabuleiros
	board tabs[q_tabuleiros];
	
	// apenas visual
	cout << "Insira o tamanho do tabuleiro" << endl;
	cin >> t;

	for(int i=0 ; i < q_tabuleiros; i++)
		tabs.puzzle[i] = geramatriz (tamanho);
		preenchematriz(tab.puzzle[i])
	
	// TEM QUE RECEBER A MATRIZ AINDA
}
