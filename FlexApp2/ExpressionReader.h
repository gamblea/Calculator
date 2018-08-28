#pragma once
#include <memory>

class Expression;
class Scanner;

class ExpressionReader
{
private:
	std::unique_ptr<Scanner> scanner;

public:
	ExpressionReader();
	~ExpressionReader();

	std::shared_ptr<Expression> GetExpression();
};

