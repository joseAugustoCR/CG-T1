/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Cria e roda a aplicacao


    REQUISITOS MÍNIMOS: TODOS
	- Leitura do arquivo
	- Gráficos da amostra lida e sinal reconstruído, com escala que se ajusta aos valores das amostras e tamanho de tela
	- Threshold para truncamento

    EXTRAS:
	- Entrada Bidimensional
	- Matriz de Quantização

	SCV 4.2.2 - CodeBlocks 13.12

*/

#include <SCV/SCV.h>
#include "Application.h"


int main(int argc, char* argv[]) {
   Application *kernel = new Application();
   scv::Kernel::setInstance(kernel);

   kernel->init();
   kernel->run();

  return 0;
}
