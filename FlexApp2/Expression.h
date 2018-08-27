#pragma once
class Expression
{
public:
	Expression();
	virtual ~Expression();
	

	virtual double Evaluate() = 0;
};

