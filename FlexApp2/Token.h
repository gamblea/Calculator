#pragma once


struct Token
{
	enum class TokenType : int { Bracket_F, Bracket_B, Add, Sub, Mult, Div, Num, Invalid, Eof };
	TokenType type;
	double value;

	Token(TokenType type, double value = 0.0);
};