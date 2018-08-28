#include "Uniary.h"



Uniary::Uniary(UniaryType type, std::unique_ptr<Expression> &&inside) :type{type}, inside{std::move(inside)}
{
}


Uniary::~Uniary()
{
}
