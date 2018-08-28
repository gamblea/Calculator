

%{
#include "Scanner.h"
#include "Token.h"
#include <sstream>
%}

%option c++
%option noyywrap
%option yyclass="Scanner"


dig		[0-9]
number1		{dig}+
number2		{dig}+"."{dig}*
number		{number1}|{number2}
forward		"("
back		")"
add			"+"
sub			"-"
mult		"*"
div			"/"
ws			[ \t\n\r]+

invalid		.


%%

{number}  {
			std::stringstream ss{YYText()};
			double num = 0.0;
			ss >> num;
			std::cout << "Number = " << num << std::endl;
			return Token{Token::TokenType::Num, num};
		}

{forward}	{
			std::cout << "Bracket_F" << std::endl;
			return Token{Token::TokenType::Bracket_F};
			}

{back}		{
			std::cout << "Bracket_B" << std::endl;
			return Token{Token::TokenType::Bracket_B};
			}

{add}		{
				std::cout << "Add" << std::endl;
				return Token{Token::TokenType::Add};
			}

{sub}		{
				std::cout << "Sub" << std::endl;
				return Token{Token::TokenType::Sub};
			}

{mult}		{
				std::cout << "Mult" << std::endl;
				return Token{Token::TokenType::Mult};
			}

{div}		{
				std::cout << "Mult" << std::endl;
				return Token{Token::TokenType::Div};
			}

{ws}		;

{invalid}		{
					std::cout << "Invalid" << std::endl;
					return Token{Token::TokenType::Invalid};
				}



<<EOF>>     { yyterminate();}
%%
