//expression_factory.h

#pragma once
#include <string>
#include "expression.h"

//std::auto_ptr<Expression> getExpression(const std::string &s);
std::auto_ptr<Expression> getExpression(Tokenizer &tokenizer);

