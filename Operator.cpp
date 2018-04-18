/*
*	Defines the Operator class, for tagging and storing operator tokens.
*/

#include "Operator.h"

Operator::Operator(OperatorToken type) : type(type) {}

// Returns the precedence (lower is first) of this operator
int Operator::GetPrecedence() const {
	switch (type) {
	case OperatorToken::L_PAREN:
	case OperatorToken::R_PAREN:
		return 0;
		break;

	case OperatorToken::FACTORIAL:
		return 1;
		break;

	case OperatorToken::MULTIPLY:
	case OperatorToken::DIVIDE:
		return 2;
		break;

	case OperatorToken::ADD:
	case OperatorToken::SUBTRACT:
		return 3;
		break;

	case OperatorToken::UNKNOWN:
		return -1;	// error output
		break;
	}
}

OperatorToken Operator::GetOperatorToken(char raw) {
	switch (raw) {
	case '+':
		return OperatorToken::ADD;
		break;
	case '-':
		return OperatorToken::SUBTRACT;
		break;
	case '*':
		return OperatorToken::MULTIPLY;
		break;
	case '/':
		return OperatorToken::DIVIDE;
		break;
	case '!':
		return OperatorToken::FACTORIAL;
		break;
	case '(':
		return OperatorToken::L_PAREN;
		break;
	case ')':
		return OperatorToken::R_PAREN;
		break;
	default:
		return OperatorToken::UNKNOWN;	// error output
		break;
	}
}