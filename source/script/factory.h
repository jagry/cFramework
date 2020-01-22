typedef JResult( *Factory )( JIMap , JPBuffer , PUToken ) ;
typedef JResult( *KeywordFactory )( JPBuffer , PUToken ) ;

typedef Factory * PFactory ;
typedef KeywordFactory * PKeywordFactory ;

jInternal( JResult )declareVariableKeywordFactory( JPBuffer , PUToken ) ;
jInternal( JResult )debugTestKeywordFactory( JPBuffer , PUToken ) ;
jInternal( JResult )identifierFactory( JIMap , JPBuffer , PUToken ) ;
jInternal( JResult )keywordFactory( JIMap , JPBuffer , PUToken ) ;