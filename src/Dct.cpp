/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Implementaçao das funcoes referentes as transformadas e criacao de matrizes a partir dos arquivos de entrada

*/


#include "Dct.h"
#include "widget.h"
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


const double M_PI = 3.141592653589;
int N_g = 0;                        // Dimensao N do sinal
int M_g = 0;                        // Dimensao M do sinal
bool matrizInvalida_g = false;      // Flag de matriz invalida
bool problemaArquivo_g = false;     // Flag de problema com o arquivo lido
int maiorAmostraEntrada_g = 1;


Dct::Dct()
{
    //ctor
}

/* Conta o numero de linhas no arquivo txt
*/
int Dct::contaLinhas(std::string nomeDoArquivo)
{
   std::ifstream file;
   std::string str = "";
   numLinhas_g=0;

   file.open (nomeDoArquivo.c_str());
    if (file.is_open())
    {
        std::getline(file, str);        //pula primeira linha
        while (std::getline(file, str) ) // conta as linhas
        {
           numLinhas_g++;
        }
        file.close();
        N_g = numLinhas_g;
        return numLinhas_g;
    }
    else
    {
        problemaArquivo_g = true;
    }
}


/* Conta o numero de colunas no arquivo txt
*/
int Dct::contaColunas(std::string nomeDoArquivo)
{
    std::ifstream file;
    std::string linha = "";
    float amostra;
    numColunas_g=0;

    file.open (nomeDoArquivo.c_str());
    if (file.is_open())
    {
        std::getline(file, linha);    //pula primeira linha
        std::getline(file, linha);    //pega a segunda linha

        std::stringstream stream (linha);   // conta as colunas
        while (stream >> amostra)
        {
            numColunas_g++;
        }
        file.close();
        M_g = numColunas_g;
        return numColunas_g;
    }
    else
    {
        problemaArquivo_g = true;
    }
}


/*  Funcao C utilizada na DCT
*/
float Dct::functionC (int arg)
{
   if (arg==0)
   {
       return (pow(0.5,0.5));
   }
   else
   {
       return 1;
   }
}


/* Faz a FDCT de uma matriz de entrada e retorna a matriz resultante
*/
float** Dct::fdct_bidimensional(int** i )
{
    int u, v, x, y;
    double pix, pi = M_PI;

    // Cria uma matriz:
    float** m = new float*[numLinhas_g];
    for (int p = 0; p < numLinhas_g; p++)
    {
        m[p] = new float[numColunas_g];
    }

    // Implementa FDCT:
    for(u=0; u<N_g; u++)
    {
        for(v=0; v<M_g; v++)
        {
            pix = 0.0;
            for(x=0; x<N_g; x++)
            {
               for(y=0; y<M_g; y++)
               {
                  pix += i[x][y] * cos(((2.0*x+1.0)*pi*u)/(2*N_g)) * cos(((2.0*y+1.0)*pi*v)/(2*M_g) ) ;
               }
            }
            m[u][v] =  pix*( pow((float)2/N_g, 0.5) )*( pow((float)2/M_g,0.5) )  *functionC(u)*functionC(v);
            if (m[u][v] < threshold_g && m[u][v]> (threshold_g*(-1)) ) // Threshold
            {
                m[u][v]=0;
            }

        }
    }
    return m;
}


/* Faz a IDCT de uma matriz de entrada e retorna a matriz resultante
*/
int** Dct::idct_bidimensional(float** i )
{
    int u, v, x, y;
    double pix, pi = M_PI;
    // Cria uma matriz:
    int** m = new int*[numLinhas_g];
    for (int p = 0; p < numLinhas_g; p++)
    {
       m[p] = new int[numColunas_g];
    }

    // Implementa a IDCT:
    for(x=0; x<N_g; x++)
    {
        for(y=0; y<M_g; y++)
        {
            pix = 0.0;
            for(u=0; u<N_g; u++)
            {
               for(v=0; v<M_g; v++)
               {
                  pix += functionC(u)*functionC(v)* i[u][v] * cos(((2.0*x+1.0)*pi*u)/(2*N_g)) * cos(((2.0*y+1.0)*pi*v)/(2*M_g) ) ;
               }
            }
            m[x][y] =  ceil (pix*( pow((float)2/N_g, 0.5) )*( pow((float)2/M_g,0.5) ) ) ;

        }
    }
    return m;
}


/* Le um arquivo txt e extrai as informaçoes do mesmo, retornando uma matriz de valores
*/
int** Dct::readFile_generateMatriz (std::string nomeDoArquivo)
{
    std::ifstream file;
    std::string str_numAmostras = "";
    std::string linha = "";

    float amostra;
    int i=0, j=0;

    contaColunas(nomeDoArquivo.c_str());
    contaLinhas(nomeDoArquivo.c_str());

    file.open (nomeDoArquivo.c_str());
    if (file.is_open())
    {
        // Le o numero de amostras (primeira linha) :
        std::getline(file, str_numAmostras);
        numAmostras_g = std::atoi (str_numAmostras.c_str());

        // Verifica formato dos dados:
        if (numAmostras_g<20 || numAmostras_g>200 || numAmostras_g != (numColunas_g*numLinhas_g))
        {
            matrizInvalida_g = true;
            numAmostras_g =0;
        }

        // Cria matriz para salvar as amostras do arquivo:
        int** matriz = new int*[numLinhas_g];
        for (int p = 0; p < numLinhas_g; p++)
        {
            matriz[p] = new int[numColunas_g];
        }

        file.clear();           // Retorna para o inicio do arquivo
        file.seekg(0,std::ios::beg);

        std::getline(file, linha); // pula a primeira linha (num de amostras)
        std::cout <<"\nSalvando matriz! " << std::endl;

        // Percorre o arquivo salvando a matriz:
        i=0;j=0;
        while (std::getline(file, linha) )
        {
            std::stringstream stream (linha);

            std::cout << "\n";
            while (stream >> amostra)
            {
                if (amostra < 0 || amostra > 2000)
                {
                    matrizInvalida_g = true;
                    numAmostras_g = 0;
                }
                matriz[i][j] = amostra;
                std::cout << matriz[i][j] << " ";
                j++;
            }
            i++;
            j=0;
        }
        return matriz;
    }
    else
    {
        problemaArquivo_g = true;
    }
}


/* Encontra a maior amostra de entrada
*/
void Dct::maiorAmostra(int** matriz_entrada)
{
   for(int x=0; x<numLinhas_g; x++)
   {
       for(int y=0; y<numColunas_g; y++)
       {
           if (matriz_entrada[x][y]> maiorAmostraEntrada_g)   // Encontra maior valor
           {
                maiorAmostraEntrada_g = matriz_entrada[x][y];
           }
       }
   }
}


/* Quantizacao direta
*/
float** Dct::quantizacao_direta(int** matriz_quantizacao, float** matriz_fdct)
{
    // Cria matriz para salvar resultado:
    float** matriz_resultante = new float*[numLinhas_g];
    for (int p = 0; p < numLinhas_g; p++)
    {
        matriz_resultante[p] = new float[numColunas_g];
    }

   for(int x=0; x<numLinhas_g; x++)
   {
        for(int y=0; y<numColunas_g; y++)
        {
            matriz_resultante[x][y] =  (int)(matriz_fdct[x][y]/matriz_quantizacao[x][y]);    // Arredonda para inteiro
        }
    }
    return matriz_resultante;
}


/* Quantizacao inversa
*/
float** Dct::quantizacao_inversa(int** matriz_quantizacao, float** matriz_quantizada)
{
    // Cria matriz para salvar resultado:
    float** matriz_resultante = new float*[numLinhas_g];
    for (int p = 0; p < numLinhas_g; p++)
    {
        matriz_resultante[p] = new float[numColunas_g];
    }

   for(int x=0; x<numLinhas_g; x++)
   {
        for(int y=0; y<numColunas_g; y++)
        {
            matriz_resultante[x][y] =  (int)(matriz_quantizada[x][y]*matriz_quantizacao[x][y]);    // Arredonda para inteiro
        }
    }
    return matriz_resultante;
}



