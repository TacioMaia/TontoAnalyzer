# Analisador Sintático para TONTO (Textual Ontology Language)

## Descrição

Este projeto implementa um analisador Sintático para a linguagem TONTO (Textual Ontology Language), conforme especificado na disciplina de Compiladores da UFERSA. O analisador utiliza a ferramenta Flex (na sua variante C++, `flex++`) para reconhecer os tokens da linguagem, incluindo palavras reservadas, estereótipos, símbolos especiais e convenções de nomes para classes, relações, instâncias e tipos de dados. E também a ferramente Bison, para utilizar os tokens da linguagem para garantir que estejam sendo utilizadas de forma correta na linguagem.

O programa lê um arquivo `.tonto` como entrada e produz duas saídas principais:
1.  **Relatório de erros:** Uma listagem de todos os erros encontramos juntamente com sugestões de tratamento.
2.  **Tabela de Síntese:** Resumo dos construtos encontrados, quantos e quais pacotes, quantas classes por pacote, externas, declarações de tipos).

O analisador também realiza tratamento de erros, identificando tokens inválidos e informando sua localização (linha e coluna) com uma sugestão de correção.
Tratamento de erro para sintaxe incorreta de classes e pacotes.

## Pré-requisitos

Para compilar e executar este projeto, você precisará ter os seguintes softwares instalados:

* **CMake:** (Versão 3.0 ou superior) - Gerenciador de compilação.
* **Flex:** (Versão `flex++` ou Flex configurado para C++) - Gerador de analisador léxico.
* **Bison:** (Versão mais recente, 3.0 ou superior) - Gerador de analisador sintático.
* **Compilador C++:** (Compatível com C++17, como g++) - Para compilar o código gerado e o parser.
* **Make:** (ou outra ferramenta de build compatível com o gerador do CMake, como Ninja) - Para executar os comandos de compilação definidos pelo CMake.

## Como Compilar o Programa

Siga estes passos para compilar o projeto usando CMake:

1.  **Clone o Repositório:** Se ainda não o fez, clone o repositório para a sua máquina local.
2.  **Navegue até o Diretório Raiz:** Abra um terminal e navegue até a pasta principal do projeto (`TontoAnalyzer`).
    ```bash
    cd caminho/para/TontoAnalyzer
    ```
3.  **Crie um Diretório de Build:** Crie uma pasta separada para os arquivos de compilação (é uma boa prática usar CMake fora da árvore de fontes).
    ```bash
    mkdir Build
    ```
4.  **Entre no Diretório de Build:**
    ```bash
    cd Build
    ```
5.  **Execute o CMake:** Rode o CMake para configurar o projeto e gerar os arquivos de build (Makefiles neste caso). O `..` indica que o `CMakeLists.txt` está no diretório pai.
    ```bash
    cmake ..
    ```
6.  **Compile com o Make:** Execute o comando `make` para compilar o código fonte e gerar o executável.
    ```bash
    make
    ```
    Se tudo correr bem, um executável chamado `tonto_parser` será criado dentro da pasta `Build`.

## Como Executar o Analisador

Após a compilação bem-sucedida:

1.  **Permaneça na pasta `Build`**.
2.  **Execute o programa `tonto_parser`**, redirecionando o arquivo `.tonto` desejado para a entrada padrão (`<`). Por exemplo, para analisar o arquivo `test.txt` que está no diretório pai:
    ```bash
    ./tonto_parser < ../test.txt
    ```
    Substitua `../test.txt` pelo caminho para qualquer outro arquivo `.tonto` que você queira analisar.
3.  **Observe a Saída:** O programa imprimirá no terminal:
    * As mensagens de erro léxico (se houver).
    * A tabela da Visão Analítica.
    * A Tabela de Síntese.
