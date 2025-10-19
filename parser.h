#include <FlexLexer.h>
#include <vector>
#include <string>
#include <map> // Para mapear enums para nomes

using namespace std;

// Estrutura para armazenar informações de cada token
struct TokenInfo {
    int type;
    string text;
    int line;
    int column_start; 
};

class Parser
{
public:
	void Start();

private:
	yyFlexLexer scanner;
	int lookahead;
	
	// Armazenar todos os tokens para a visão analítica
    vector<TokenInfo> allTokens;

	// Contadores para a tabela de síntese
    int classCount = 0;
    int relationCount = 0;
    int keywordCount = 0;
    int instanceCount = 0;
    int reservedWordCount = 0;
    int metaAttributeCount = 0;

    // Mapa para nomes de tokens
    map<int, string> tokenNames;
    void initializeTokenNames();

    // Funções para gerar as saídas
    void printAnalyticalView();
    void printSynthesisTable();
};
