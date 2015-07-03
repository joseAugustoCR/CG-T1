/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Classe dos componentes gráficos
*/

#ifndef __WIDGET_H__
#define __WIDGET_H__
#include <SCV/SCV.h>
#include "Dct.h"

extern float threshold_g;           // Threshold para truncamento
extern int numLinhas_g;             // Numero de linhas da matriz de entrada
extern int numColunas_g;            // Numero de colunas da matriz de entrada
extern int maiorAmostraEntrada_g;   // Maior amostra de entrada
extern int maiorAmostraSaida_g;     // Maior amostra de saida

class Canvas0 : public scv::Canvas {
public:
	int** matriz_entrada;       // Matriz para receber o sinal de entrada
	int** matriz_reconstruida;  // Matriz para salvar o sinal reconstruido
	Canvas0(scv::Point p1, scv::Point p2);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);
	void render();  // Funcao render desenha os graficos no canvas

};

class GroupLayout0 : public scv::GroupLayout {
public:
	GroupLayout0(scv::Panel *host);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class Button0 : public scv::Button {
private:
	Dct* dctf;              // Objeto tipo dct para realizar as operacoes
	scv::TextField *tf;     // textfield recebera threshold
	scv::TextField *tf2;    // textfield de informacoes de funcionamento
	Canvas0* canvasf;       // canvas para desenhar graficos
	scv::CheckBox* cbf;     // checkbox da matriz de quantizacao

public:
	Button0(scv::Point p1, scv::Point p2, std::string str, scv::TextField* tt, Canvas0* canvast, Dct* dctt, scv::TextField* tt2, scv::CheckBox* cbt);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class Label0 : public scv::Label {
public:
	Label0(scv::Point p1, scv::Point p2, std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class Canvas1 : public scv::Canvas {
public:
	Canvas1(scv::Point p1, scv::Point p2);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class TextField0 : public scv::TextField {
public:
	TextField0(scv::Point p, unsigned int width, std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

	virtual void onStringChange(void);

};

class TextField1 : public scv::TextField {
public:
	TextField1(scv::Point p, unsigned int width, std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

	virtual void onStringChange(void);

};

class Label1 : public scv::Label {
public:
	Label1(scv::Point p1, scv::Point p2, std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class Label2 : public scv::Label {
public:
	Label2(scv::Point p1, scv::Point p2, std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

};

class CheckBox0 : public scv::CheckBox {
public:
	CheckBox0(scv::Point p, bool state, const std::string str);

	virtual void onMouseClick(const scv::MouseEvent &evt);
	virtual void onMouseHold (const scv::MouseEvent &evt);
	virtual void onMouseOver (const scv::MouseEvent &evt);
	virtual void onMouseUp   (const scv::MouseEvent &evt);
	virtual void onMouseWheel(const scv::MouseEvent &evt);

	virtual void onKeyPressed(const scv::KeyEvent &evt);
	virtual void onKeyUp     (const scv::KeyEvent &evt);

	virtual void onSizeChange(void);
	virtual void onPositionChange(void);

	virtual void onValueChange(void);

};

#endif
