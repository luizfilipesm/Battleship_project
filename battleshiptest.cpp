#include<iostream>

using namespace std;

struct puzzle
{
	bool diponibilidade; // Variável que irá testar se espaço está disponível
	char posicao; // Variável vai indicar o conteudo da posição  
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
	int t; // Tamanho da matriz
	cout << "Insira o tamanho do tabuleiro" << endl;
	cin >> t; 
	geramatriz (t);
	// TEM QUE RECEBER A MATRIZ AINDA
}
