#include <iostream>

// Declarações vindas do parser.y
extern int yyparse();
extern void print_synthesis_table();

int main() {
    std::cout << ">>> Iniciando Analisador Sintático TONTO <<<\n";
    
    // yyparse executa a análise. Retorna 0 se sucesso, 1 se erro.
    int result = yyparse();

    if (result == 0) {
        std::cout << "\n>>> Análise Sintática concluída com SUCESSO! <<<\n";
        print_synthesis_table();
    } else {
        std::cout << "\n>>> Análise Sintática FALHOU devido a erros. <<<\n";
        // Tenta imprimir o que foi achado mesmo com erro
        print_synthesis_table(); 
    }
    
    return result;
}