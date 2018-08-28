#include "Binary.h"



Binary::Binary()
{
}


Binary::Binary(Type type, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
	: type{type}, left{left}, right{right}
{
}

Binary::~Binary()
{
}

double Binary::Evaluate()
{
	switch (type)
	{
	case Binary::Type::Add:
		return left->Evaluate() + right->Evaluate();
		break;
	case Binary::Type::Sub:
		return left->Evaluate() - right->Evaluate();
		break;
	case Binary::Type::Mult:
		return left->Evaluate() * right->Evaluate();
		break;
	case Binary::Type::Div:
		return left->Evaluate() / right->Evaluate();
		break;
	default:
		break;
	}
	
}
