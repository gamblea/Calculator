#pragma once
#include "Expression.h"
#include <memory>
class Uniary :
	public Expression
{
public:
	enum class UniaryType {Plus, Minus};
private:
	UniaryType type;
	std::unique_ptr<Expression> inside;
public:
	Uniary(UniaryType type, std::unique_ptr<Expression> &&inside);
	virtual ~Uniary();
};

