#pragma once
#ifndef SCANNER_H
#define SCANNER_H 

/*
#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
//#define yyFlexLexer Scanner // the trick with prefix; no namespace here :(
#include <FlexLexer.h>
*/

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif 

#include "Token.h"

#undef YY_DECL
#define YY_DECL Token Scanner::get_next_token()

#undef yyterminate
#define yyterminate() return Token::TokenType::Eof


class Scanner : public yyFlexLexer
{
public:
	virtual Token get_next_token();
};

#endif // !SCANNER_H


