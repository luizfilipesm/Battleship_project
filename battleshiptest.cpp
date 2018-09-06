#include<iostream>

using namespace std;

struct puzzle
{
bool revelado; // Variável que irá testar se o usuário já viu o espaço
char posicao; // Variável vai indicar o conteudo da posição  
}

puzzle geramatriz (int tamanho)
{// Função geradora da matriz
puzzle tabuleiro[][]; int t2;

if (t>10 && t<15)
{
 	for(int i=0; i < t; i++)
 	{
  	 for(int j=0; j < t; i++)
  	 {
 	   tabuleiro[i][j]="-"; // o hífen representa água 
  	 }	
 	}
 return tabuleiro [t][t];
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
