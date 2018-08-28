#include "Scanner.h"
#include "Expression.h"
#include <memory>

using namespace std;



int main() {
	Scanner *lexer = new Scanner;
	bool valid = true;
	while (valid)
	{
		Token token = lexer->get_next_token();
		/*
		if(token == Token::TokenType::Num)
			printf("Found a number\n");
		else if (token == Token::Eof)
			valid = false;
			*/

	}

	return 0;
}