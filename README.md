# CG-T1
Transformada Discreta do Cosseno

Descrição:
Desenvolva um programa em C++, utilizando a API SCV 4.2.2 ou Canvas 2D, que
aplique a Transformada Discreta do Cosseno (DCT) e sua Inversa (IDCT) em um sinal
amostrado unidimensional ou bidimensional (extra). No inicio do arquivo main.cpp
deve-se descrever tudo o que foi implementado no programa.

Requisitos Mínimos (Nota: 8):
• Ler um arquivo de entrada com a seguinte formatação: a primeira linha contém
um inteiro N (20<N<200) representando o número de amostras a serem lidas; a
linha seguinte contém as amostras. Cada amostra pode variar entre 0 e 2000. O
arquivo de entrada vai ser gerado pelo monitor para a correção.
• Plotar os gráficos: 1) Amostras lidas da entrada; 2) O sinal reconstruído. Os
gráficos podem ser implementados separadamente ou apenas um gráfico com
linhas de cores diferentes. A escala do gráfico deve se auto ajustar em função
dos valores das amostras e tamanho da tela.
• Permitir que o usuário escolha um threshold para truncamento dos valores da
DCT, por exemplo: if (saida_da_dct < threshold ) saida_da_dct = 0. Ou ainda,
aplicação da matriz de quantização às frequências antes da reconstituição do
sinal (http://www-usr.inf.ufsm.br/~pozzer/disciplinas/cg_3_imagem.pdf pg 10).
• Atenção: o console (cmd) será desconsiderado na correção do trabalho.
Portanto, todos os requisitos e extras devem ser implementados na interface
gráfica.

Extras:
• (+1) Usar matriz de quantização.
• (+1) Possibilitar que o usuário insira/altere amostras clicando no gráfico ou
através de campo de texto.
• (+3) Aplicar a transformada em arquivo wav. O arquivo deve ser lido, processado
(comprimido = quantizado ou truncado) e gravado novamente no arquivo de
saída. O arquivo de saída deve ser tocável em um player. Defina o número de
amostras a serem processadas a cada vez. Ex: no JPEG, usa-se blocos de 8x8
pixels.
• (+4) Aplicar a transformada sobre uma imagem (pode ser imagem em tons de
cinza). Para isso, você pode utilizar a classe de imagem do SCV ou outra classe
que permita manipulação de imagens. As imagens de entrada e saída devem
ser exibidas na interface.
• (+2) Permitir ao usuário clicar em uma saída específica da DCT e então mostrar
os termos do somatório que geraram essa saída:
