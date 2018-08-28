#include "ExpressionReader.h"
#include "Scanner.h"
#include "Expression.h"
#include "Token.h"
#include "Number.h"
#include "Binary.h"

#include <vector>

using namespace std;


ExpressionReader::ExpressionReader() : scanner{std::make_unique<Scanner>()}
{
}


ExpressionReader::~ExpressionReader()
{
}

bool tokenIsBinary(Token token)
{
	return token.type == Token::TokenType::Add || token.type == Token::TokenType::Sub || token.type == Token::TokenType::Mult || token.type == Token::TokenType::Div;
}

std::shared_ptr<Expression> ExpressionReader::GetExpression()
{
	vector<shared_ptr<Expression>> stack;
	Token token = scanner->get_next_token();
	if (token.type == Token::TokenType::Num)
	{
		stack.emplace_back(make_shared<Number>(token.value));
	}
	else if (tokenIsBinary(token))
	{
		Binary::Type typeB;
		switch (token.type)
		{
		case Token::TokenType::Add:
			typeB = Binary::Type::Add;
			break;
		case Token::TokenType::Sub:
			typeB = Binary::Type::Sub;
			break;
		case Token::TokenType::Mult:
			typeB = Binary::Type::Mult;
			break;
		case Token::TokenType::Div:
			typeB = Binary::Type::Div;
			break;
		default:
			break;
		}
		shared_ptr<Expression> right = GetExpression();
		shared_ptr<Expression> left = stack.back();
		stack.emplace_back(make_shared<Binary>(Binary::Type::Sub, left, right));
	}

	return stack.back();
}
