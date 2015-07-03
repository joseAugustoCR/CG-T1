/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Implementacao das funcoes relativas aos componentes, principalmente a render() e clique do botao Ok.
*/


#include "widget.h"
#include "Dct.h"
#include <string>
#include <cmath>

float threshold_g = 0;
int numLinhas_g = 0;
int numColunas_g = 0;
int numAmostras_g = 0;
//int maiorAmostraSaida_g = 1;


Canvas0::Canvas0(scv::Point p1, scv::Point p2) : scv::Canvas(p1, p2) {
    // Cria matriz para entrada de amostras:
    matriz_entrada = new int*[numLinhas_g];
    for (int i = 0; i < numLinhas_g; i++)
    {
       matriz_entrada[i] = new int[numColunas_g];
    }

    // Cria matriz para o sinal reconstruido:
    matriz_reconstruida = new int*[numLinhas_g];
    for (int i = 0; i < numLinhas_g; i++)
    {
       matriz_reconstruida[i] = new int[numColunas_g];
    }

}
//Canvas0
void Canvas0::onMouseClick(const scv::MouseEvent &evt) {
}
void Canvas0::onMouseHold(const scv::MouseEvent &evt) {
}
void Canvas0::onMouseOver(const scv::MouseEvent &evt) {
}
void Canvas0::onMouseUp(const scv::MouseEvent &evt) {
}
void Canvas0::onMouseWheel(const scv::MouseEvent &evt) {
}
void Canvas0::onKeyPressed(const scv::KeyEvent &evt) {
}
void Canvas0::onKeyUp(const scv::KeyEvent &evt) {
}
void Canvas0::onSizeChange(void) {
}
void Canvas0::onPositionChange(void) {
}
void Canvas0::render() {

    if (numAmostras_g!=0)  // Sem tem um sinal de entrada
    {
        // Grafico se ajusta de acordo com amostras e tamanho da tela:
        float incrementoX = (float)getWidth()/numAmostras_g;
        float incrementoY = (float)getHeight()/maiorAmostraEntrada_g;
        float x0 = 0;
        float y0 = 0;
        float x1=0,y1=0;

        // Desenha grafico do sinal de entrada:
        clear(1,1,1);
        color(0,0,0);

        int** matriz_in = matriz_entrada;//{ {8,16,24,32,40,48,56,64,72,80,88,96} };
        y0 = getHeight()-(incrementoY*matriz_in[0][0]); // Primeira posicao = primeiro ponto
        for(int x=0; x<numLinhas_g; x++)
        {
           for(int y=0; y<numColunas_g; y++)
           {
                x1 = x0 + incrementoX;
                if (x==0 && y==0)
                {
                    y1 =  getHeight()-(incrementoY*matriz_in[0][1]);
                }
                else
                {
                     y1 =  getHeight()-(incrementoY*matriz_in[x][y]);
                }
                line ( (int) x0,(int) y0, (int) x1, (int)y1 );
                x0 = x1;
                y0 = y1;
           }
        }

        // Desenha grafico do sinal reconstruido:
        int** matriz_out = matriz_reconstruida;//{ {8,16,24,32,40,48,56,64,72,80,88,96} };
        color (0,1,0);
        // Configura dados iniciais:
        x0=0;
        y0=getHeight()-(incrementoY*matriz_out[0][0]);
        x1=0;
        y1=0;
        for(int x=0; x<numLinhas_g; x++)
        {
           for(int y=0; y<numColunas_g; y++)
           {
                x1 = x0 + incrementoX;
                if (x==0 && y==0)
                {
                    y1 =  getHeight()-(incrementoY*matriz_out[0][1]);
                }
                else
                {
                     y1 =  getHeight()-(incrementoY*matriz_out[x][y]);
                }
                line ( (int) x0,(int) y0, (int) x1, (int)y1 );
                std::cout << matriz_out[x][y]<<std::endl;
                x0 = x1;
                y0 = y1;
           }
        }
        //system("pause");
    }
}

//Button0 (Ok)
Button0::Button0(scv::Point p1, scv::Point p2, std::string str, scv::TextField* tt, Canvas0* canvast, Dct* dctt, scv::TextField* tt2, scv::CheckBox* cbt) : scv::Button(p1, p2, str) {
    tf = tt;
    tf2 = tt2;
    canvasf = canvast;
    dctf = dctt;
    cbf = cbt;
}
void Button0::onMouseClick(const scv::MouseEvent &evt) {

   // Recebe o threshold informado pelo usuario:
    threshold_g =  std::atof( ((tf->getString()).c_str()) );
    if (threshold_g<0 || threshold_g>2000)
    {
        threshold_g = 0;
        tf2->setString("Threshold invalido! Redefinido para 0");
    }

    dctf->contaColunas("in.txt");
    dctf->contaLinhas("in.txt");

    int** matriz_entrada; // Cria matriz de entrada

     if (problemaArquivo_g == true) // Problema com arquivo txt
     {
         numAmostras_g = 0;
         matrizInvalida_g = true;
         problemaArquivo_g = false;
     }
     else
     {
       matriz_entrada = dctf->readFile_generateMatriz("in.txt");
     }

     if (matrizInvalida_g == true)  // Formato de dados invalido
     {
         tf2->setString("Entrada Invalida! Deve haver entre 20 e 200 amostras, variando de 0 a 2000, no arquivo nomeado in.txt");
         matrizInvalida_g = false;
     }
     else
     {
        dctf->maiorAmostra(matriz_entrada); // Encontra maior amostra de entrada para ajustar grafico
        float** matriz_fdct = dctf->fdct_bidimensional(matriz_entrada); // Faz a FDCT



        float** matriz_resultante;

		if (cbf->getState())  // Matriz de quantizacao habilitada
		{
		   // Verifica se a matriz de quantizacao esta no formato correto:
		   int numColunasEntrada = numColunas_g;
		   int numLinhasEntrada = numLinhas_g;

		   dctf->contaColunas("matrizDeQuantizacao.txt");
		   dctf->contaLinhas("matrizDeQuantizacao.txt");

		   if ((numColunasEntrada != numColunas_g) || (numLinhasEntrada != numLinhas_g) )    // Formato invalido da matriz de quantizacao
		   {
		       tf2->setString("Matriz de Quantizacao Invalida !");
		       numColunas_g = numColunasEntrada;
		       numLinhas_g = numLinhasEntrada;
		       N_g = numLinhas_g;
		       M_g = numColunas_g;
		       matriz_resultante = matriz_fdct;
		   }
		   else
		   {
		       int** matriz_quantizacao = dctf->readFile_generateMatriz("matrizDeQuantizacao.txt");       // Cria matriz de quantizacao
		       float** matriz_quantizada = (dctf->quantizacao_direta (matriz_quantizacao, matriz_fdct));  // Realiza a quantizacao direta
		       matriz_resultante = dctf->quantizacao_inversa(matriz_quantizacao, matriz_quantizada);      // Realiza a quantizacao inversa

		       tf2->setString("Reconstrucao realizada com sucesso! - Com quantizacao");
		    }
		}
		else    // Matriz de quantizacao desabilitada
		{
		    matriz_resultante = matriz_fdct;
		    tf2->setString("Reconstrucao realizada com sucesso! - Sem quantizacao");
		}


		int** matriz_reconstruida = dctf->idct_bidimensional(matriz_resultante); // Faz a IDCT

		// Passa as matrizes de entrada e reconstruida para o canvas:
		canvasf->matriz_entrada = matriz_entrada;
		canvasf->matriz_reconstruida = matriz_reconstruida;
    }
}
void Button0::onMouseHold(const scv::MouseEvent &evt) {
}
void Button0::onMouseOver(const scv::MouseEvent &evt) {
}
void Button0::onMouseUp(const scv::MouseEvent &evt) {
}
void Button0::onMouseWheel(const scv::MouseEvent &evt) {
}
void Button0::onKeyPressed(const scv::KeyEvent &evt) {
}
void Button0::onKeyUp(const scv::KeyEvent &evt) {
}
void Button0::onSizeChange(void) {
}
void Button0::onPositionChange(void) {
}

//Label0
Label0::Label0(scv::Point p1, scv::Point p2, std::string str) : scv::Label(p1, p2, str) {
}
void Label0::onMouseClick(const scv::MouseEvent &evt) {
}
void Label0::onMouseHold(const scv::MouseEvent &evt) {
}
void Label0::onMouseOver(const scv::MouseEvent &evt) {
}
void Label0::onMouseUp(const scv::MouseEvent &evt) {
}
void Label0::onMouseWheel(const scv::MouseEvent &evt) {
}
void Label0::onKeyPressed(const scv::KeyEvent &evt) {
}
void Label0::onKeyUp(const scv::KeyEvent &evt) {
}
void Label0::onSizeChange(void) {
}
void Label0::onPositionChange(void) {
}

//GroupLayout0
GroupLayout0::GroupLayout0(scv::Panel *host) : scv::GroupLayout(host) {
}
void GroupLayout0::onMouseClick(const scv::MouseEvent &evt) {
}
void GroupLayout0::onMouseHold(const scv::MouseEvent &evt) {
}
void GroupLayout0::onMouseOver(const scv::MouseEvent &evt) {
}
void GroupLayout0::onMouseUp(const scv::MouseEvent &evt) {
}
void GroupLayout0::onMouseWheel(const scv::MouseEvent &evt) {
}
void GroupLayout0::onKeyPressed(const scv::KeyEvent &evt) {
}
void GroupLayout0::onKeyUp(const scv::KeyEvent &evt) {
}
void GroupLayout0::onSizeChange(void) {
}
void GroupLayout0::onPositionChange(void) {
}

Canvas1::Canvas1(scv::Point p1, scv::Point p2) : scv::Canvas(p1, p2) {
}
//Canvas1
void Canvas1::onMouseClick(const scv::MouseEvent &evt) {
}
void Canvas1::onMouseHold(const scv::MouseEvent &evt) {
}
void Canvas1::onMouseOver(const scv::MouseEvent &evt) {
}
void Canvas1::onMouseUp(const scv::MouseEvent &evt) {
}
void Canvas1::onMouseWheel(const scv::MouseEvent &evt) {
}
void Canvas1::onKeyPressed(const scv::KeyEvent &evt) {
}
void Canvas1::onKeyUp(const scv::KeyEvent &evt) {
}
void Canvas1::onSizeChange(void) {
}
void Canvas1::onPositionChange(void) {
}

//TextField0
TextField0::TextField0(scv::Point p, unsigned int width, std::string str) : scv::TextField(p, width, str) {
}
void TextField0::onMouseClick(const scv::MouseEvent &evt) {
}
void TextField0::onMouseHold(const scv::MouseEvent &evt) {
}
void TextField0::onMouseOver(const scv::MouseEvent &evt) {
}
void TextField0::onMouseUp(const scv::MouseEvent &evt) {
}
void TextField0::onMouseWheel(const scv::MouseEvent &evt) {
}
void TextField0::onKeyPressed(const scv::KeyEvent &evt) {
}
void TextField0::onKeyUp(const scv::KeyEvent &evt) {
}
void TextField0::onSizeChange(void) {
}
void TextField0::onPositionChange(void) {
}
void TextField0::onStringChange(void) {
}

//TextField1
TextField1::TextField1(scv::Point p, unsigned int width, std::string str) : scv::TextField(p, width, str) {
}
void TextField1::onMouseClick(const scv::MouseEvent &evt) {
}
void TextField1::onMouseHold(const scv::MouseEvent &evt) {
}
void TextField1::onMouseOver(const scv::MouseEvent &evt) {
}
void TextField1::onMouseUp(const scv::MouseEvent &evt) {
}
void TextField1::onMouseWheel(const scv::MouseEvent &evt) {
}
void TextField1::onKeyPressed(const scv::KeyEvent &evt) {
}
void TextField1::onKeyUp(const scv::KeyEvent &evt) {
}
void TextField1::onSizeChange(void) {
}
void TextField1::onPositionChange(void) {
}
void TextField1::onStringChange(void) {
}

//Label1
Label1::Label1(scv::Point p1, scv::Point p2, std::string str) : scv::Label(p1, p2, str) {
}
void Label1::onMouseClick(const scv::MouseEvent &evt) {
}
void Label1::onMouseHold(const scv::MouseEvent &evt) {
}
void Label1::onMouseOver(const scv::MouseEvent &evt) {
}
void Label1::onMouseUp(const scv::MouseEvent &evt) {
}
void Label1::onMouseWheel(const scv::MouseEvent &evt) {
}
void Label1::onKeyPressed(const scv::KeyEvent &evt) {
}
void Label1::onKeyUp(const scv::KeyEvent &evt) {
}
void Label1::onSizeChange(void) {
}
void Label1::onPositionChange(void) {
}

//Label2
Label2::Label2(scv::Point p1, scv::Point p2, std::string str) : scv::Label(p1, p2, str) {
}
void Label2::onMouseClick(const scv::MouseEvent &evt) {
}
void Label2::onMouseHold(const scv::MouseEvent &evt) {
}
void Label2::onMouseOver(const scv::MouseEvent &evt) {
}
void Label2::onMouseUp(const scv::MouseEvent &evt) {
}
void Label2::onMouseWheel(const scv::MouseEvent &evt) {
}
void Label2::onKeyPressed(const scv::KeyEvent &evt) {
}
void Label2::onKeyUp(const scv::KeyEvent &evt) {
}
void Label2::onSizeChange(void) {
}
void Label2::onPositionChange(void) {
}

//CheckBox0
CheckBox0::CheckBox0(scv::Point p, bool state, const std::string str) : scv::CheckBox(p, state, str) {
}
void CheckBox0::onMouseClick(const scv::MouseEvent &evt) {
}
void CheckBox0::onMouseHold(const scv::MouseEvent &evt) {
}
void CheckBox0::onMouseOver(const scv::MouseEvent &evt) {
}
void CheckBox0::onMouseUp(const scv::MouseEvent &evt) {
}
void CheckBox0::onMouseWheel(const scv::MouseEvent &evt) {
}
void CheckBox0::onKeyPressed(const scv::KeyEvent &evt) {
}
void CheckBox0::onKeyUp(const scv::KeyEvent &evt) {
}
void CheckBox0::onSizeChange(void) {
}
void CheckBox0::onPositionChange(void) {
}
void CheckBox0::onValueChange(void) {
}
