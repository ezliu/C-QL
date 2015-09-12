//expression_factory.h

#pragma once
#include <string>
#include "expression.h"

std::unique_ptr<Expression> getExpression(const std::string &s);

