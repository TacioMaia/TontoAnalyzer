cmake_minimum_required(VERSION 3.10)
project(TontoAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# 1. Encontrar pacotes Flex e Bison
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# 2. Configurar o Parser (Bison)
# Gera parser.tab.cpp e parser.tab.h
BISON_TARGET(MyParser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.h)

# 3. Configurar o Scanner (Flex)
# --- MUDANÇA AQUI: Mudamos de lex.yy.c para lex.yy.cpp ---
FLEX_TARGET(MyScanner lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)

# 4. Definir Dependência
# O scanner precisa do header gerado pelo parser
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

# 5. Incluir diretórios de build
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR})

# 6. Criar o executável
add_executable(tonto_parser
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    main.cpp
)