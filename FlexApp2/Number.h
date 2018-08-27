#pragma once
#include "Expression.h"
class Number :
	public Expression
{
private:
	const double value;
public:
	Number(double value);
	virtual ~Number();
	virtual double Evaluate();
};

