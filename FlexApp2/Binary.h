#pragma once
#include "Expression.h"
#include <memory>
class Binary :
	public Expression
{
public:
	enum class Type {Add, Sub, Mult, Div};
private:
	Type type;
	std::shared_ptr<Expression> left;
	std::shared_ptr<Expression> right;
public:
	Binary(Type type, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
	virtual ~Binary();
	virtual double Evaluate();
};

