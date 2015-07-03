/**
    JOS� AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTA��O GR�FICA - ENGENHARIA DE COMPUTA��O - UFSM

    Cria e roda a aplicacao


    REQUISITOS M�NIMOS: TODOS
	- Leitura do arquivo
	- Gr�ficos da amostra lida e sinal reconstru�do, com escala que se ajusta aos valores das amostras e tamanho de tela
	- Threshold para truncamento

    EXTRAS:
	- Entrada Bidimensional
	- Matriz de Quantiza��o

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
