// Enumeração dos tokens da linguagem TONTO

enum TokenType{
    // Palavras Reservadas
    T_PACKAGE = 1,
    T_IMPORT,
    T_GENSET,
    T_DISJOINT,
    T_COMPLETE,
    T_GENERAL,
    T_SPECIFICS,
    T_WHERE,
    T_FUNCTIONAL_COMPLEXES,

    // Esteriotipos de Classe
    T_EVENT, T_SITUATION, T_PROCESS, T_CATEGORY, T_MIXIN,
    T_PHASEMIXIN, T_ROLEMIXIN, T_HISTORICALROLEMIXIN, T_KIND,
    T_COLLECTIVE, T_QUANTITY, T_QUALITY, T_MODE, T_INTRINSICMODE,
    T_EXTRINSICMODE, T_SUBKIND, T_PHASE, T_ROLE, T_HISTORICALROLE,

    // Esteriotipos de Relação
    T_MATERIAL, T_DERIVATION, T_COMPARATIVE, T_MEDIATION,
    T_CHARACTERIZATION, T_SUBCOLLECTIONOF, T_SUBQUALITYOF,
    T_INSTANTIATION, T_EXTERNALDEPENDENCE, T_COMPONENTOF, T_MEMBEROF,
    T_TERMINATION, T_PARTICIPATIONAL, T_PARTICIPATION,
    T_HISTORICALDEPENDENCE, T_CREATION, T_MANIFESTATION,
    T_BRINGSABOUT, T_TRIGGERS, T_COMPOSITION, T_AGGREGATION,
    T_INHERENCE, T_VALUE, T_FORMAL, T_CONSTITUTION,

    // Tipos de Dados Nativos
    T_NUMBER_TYPE, T_STRING_TYPE, T_BOOLEAN_TYPE, T_DATE_TYPE,
    T_TIME_TYPE, T_DATETIME_TYPE,

    // Meta-atributos
    T_ORDERED, T_CONST, T_DERIVED, T_SUBSETS, T_REDEFINES,

    // Símbolos Especiais
    T_LBRACE,            // {
    T_RBRACE,            // }
    T_LPAREN,            // (
    T_RPAREN,            // )
    T_LBRACK,            // [
    T_RBRACK,            // ]
    T_DOTDOT,            // ..
    T_DIAMOND_ARROW,     // <>--
    T_ARROW_DIAMOND,     // --<>
    T_ASTERISK,          // *
    T_AT,                // @
    T_DOT,               // .

    // Literais e Identificadores
    T_CLASS_NAME,    
    T_RELATION_NAME,    
    T_INSTANCE_NAME,   
    T_NEW_DATA_TYPE,   
    T_NUMBER,           
    T_STRING,       
    
    // Controle e Erro
    T_INVALID,          // Token inválido
    T_EOF               // Fim de arquivo
}; 
