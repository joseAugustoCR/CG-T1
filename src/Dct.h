/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Classe da Dct
*/

#ifndef DCT_H
#define DCT_H
#include <string>

extern int numAmostras_g;       // numero de Amostras do arquivo
extern int M_g;                 // Dimensao M do sinal
extern int N_g;                 // Dimensao N do sinal
extern bool matrizInvalida_g;   // flag de matriz invalida
extern bool problemaArquivo_g;  // flag de problema com arquivo txt

class Dct
{
    public:
        Dct();
		int contaLinhas(std::string nomeDoArquivo);        // Conta linhas do arquivo
		int contaColunas(std::string nomeDoArquivo);       // Conta colunas do arquivo
		int** readFile_generateMatriz (std::string nomeDoArquivo); // Le arquivo e retorna matriz de dados
		void maiorAmostra(int** matriz_entrada);            // Encontra a maior amostra de entrada
		float functionC (int arg);                         // Funcao C utilizada na transformada
		float** fdct_bidimensional(int** i);   //forward discrete cosine transform
		int** idct_bidimensional(float** i);   //inverse discrete cosine transform
		float** quantizacao_direta(int** matriz_quantizacao, float** matriz_fdct); // Realiza a quantizacao direta
		float** quantizacao_inversa(int** matriz_quantizacao, float** matriz_fdct);// Realiza a quantizacao inversa
    protected:
    private:
};

#endif // DCT_H
