/**
    JOSÉ AUGUSTO COMIOTTO ROTTINI - 201120279
    COMPUTAÇÃO GRÁFICA - ENGENHARIA DE COMPUTAÇÃO - UFSM

    Implementação da aplicacao e do layout da janela
*/

#include "Application.h"
#include "Dct.h"

Application::Application(void) : Kernel() {
	setWindowSize(1300,700);
	lockWindowSize(false);
	setFramesPerSecond(60);
	setWindowTitle("Discrete Cosine Transform");
}

Application::~Application(void) {
}

void Application::init(void) {
	Dct* dct = new Dct();

   _mainPanel = new scv::Panel(scv::Point(2, 2), scv::Point(2, 2));     // Painel Principal
   addComponent(_mainPanel);

    Canvas0 *canvas0 = new Canvas0(scv::Point(0,0), scv::Point(0, 0));  // Componente Canvas
    canvas0->setMinimumSize(scv::Point(1500,1000));
    _mainPanel->addChild(canvas0);

   Label0 *label0 = new Label0(scv::Point(0,0), scv::Point(0, 0), "Threshold:"); // Label Threshold
   label0->setMaximumSize(scv::Point(100,30));
   _mainPanel->addChild(label0);

   TextField0 *textField0 = new TextField0(scv::Point(0,0), 0, "");     // Textfield para receber o Threshold
   textField0->setMaximumSize(scv::Point(100,20));
   _mainPanel->addChild(textField0);

   TextField1 *textField1 = new TextField1(scv::Point(0,0), 0, "");     // Textfield de mensagens de funcionamento
   canvas0->setMinimumSize(scv::Point(1500,20));
   _mainPanel->addChild(textField1);

   CheckBox0 *checkBox0 = new CheckBox0(scv::Point(0,0), 0, "Usar matriz de quantizacao");  // Checkbox da matriz de quantizacao
   _mainPanel->addChild(checkBox0);

   Button0 *button0 = new Button0(scv::Point(0,0), scv::Point(0, 0), "Ok", textField0, canvas0, dct, textField1, checkBox0);    // Botao para realizar transformada
   button0->setMaximumSize(scv::Point(100,40));
   _mainPanel->addChild(button0);

   Label1 *label1 = new Label1(scv::Point(0,0), scv::Point(0, 0), "Sinal de entrada e Sinal Reconstruido:");
   label1->setMaximumSize(scv::Point(300,20));
   _mainPanel->addChild(label1);

   Label2 *label2 = new Label2(scv::Point(0,0), scv::Point(0, 0), "Sinal de entrada = Preto / Sinal Reconstruido = Verde");
   label2->setMaximumSize(scv::Point(300,20));
   _mainPanel->addChild(label2);

   GroupLayout0 *layout = new GroupLayout0(_mainPanel);
   _mainPanel->setLayout(layout);

    // Layout para que componentes se ajustem ao tamanho da tela:
   layout->setHorizontalGroup(
   	GroupLayout0::createParallelGroup()
   	->addGroup(GroupLayout0::createSequentialGroup()->setAutoCreateGaps(true)
   		->addComponent(label0)
   		->addGroup(GroupLayout0::createParallelGroup()
   			->addComponent(textField0)
   			->addComponent(label1)
   			->addComponent(canvas0)
   			->addComponent(label2)
   			->addComponent(textField1)
   			)
   		->addComponent(checkBox0)
   		->addComponent(button0)
   		)
   	);

   layout->setVerticalGroup(
   	GroupLayout0::createParallelGroup()
   	->addGroup(GroupLayout0::createSequentialGroup()->setAutoCreateGaps(true)
   		->addGroup(GroupLayout0::createParallelGroup()
   			->addComponent(label0)
   			->addComponent(textField0)
   			->addComponent(checkBox0)
   			->addComponent(button0)
   			)
   		->addComponent(label1)
   		-> addComponent(canvas0)
   		->addComponent(label2)
   		->addComponent(textField1)
   		)
   	);
}

void Application::onMouseClick(const scv::MouseEvent &evt) {
}
void Application::onMouseHold(const scv::MouseEvent &evt) {
}
void Application::onMouseOver(const scv::MouseEvent &evt) {
}
void Application::onMouseUp(const scv::MouseEvent &evt) {
}
void Application::onMouseWheel(const scv::MouseEvent &evt) {
}
void Application::onKeyPressed(const scv::KeyEvent &evt) {
}
void Application::onKeyUp(const scv::KeyEvent &evt) {
}
void Application::onSizeChange(void) { // Define tamanho minimo da janela para uma melhor visualizacao dos dados
	if (getWidth() < 700)
	{
		setWindowSize(700, getHeight());
	}
	else if(getHeight()<300)
	{
		setWindowSize(getWidth(), 300);
	}
	_mainPanel->setSize(getWidth()-4, getHeight()-4);
}
void Application::onPositionChange(void) {
}
