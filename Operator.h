/*
*	Declares the OperatorToken enumerator and Operator class, for tagging and storing operator tokens.
*	
*	OperatorToken:
*	- Lists all possible operator tokens.
*
*	Operator:
*	- Stores an OperatorToken type, and contains functions to identify and manage operators as part of the string-to-token-list conversion process.
*/

#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include "Expression.h"
using namespace std;

/*	[ OperatorToken ]
*	Lists all possible operator tokens.
*/
enum class OperatorToken
{
	ADD = '+',
	SUBTRACT = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	EXPONENT = '^',
	SIN = 's',
	COS = 'c',
	TAN = 't',
	LN = 'n',
	LOG = 'l',
	PI = 'p',
	E = 'e',
	L_PAREN = '(',
	R_PAREN = ')',
	UNKNOWN = '?'
};

/*
*	[ Operator ]
*	(Of type Expression so it can be stored in ExpressionList vectors)
*	Stores an OperatorToken type, and contains functions to identify and manage operators as part of the string-to-token-list conversion process.
*/
class Operator : public Expression
{
	private:

	// fields
	const OperatorToken type;		// stores the type of OperatorToken this operator is

	public:

	// constructor
	Operator(OperatorToken type);	// create a new operator with the provided OperatorToken type

	// accessors
	OperatorToken getType() const;	// return the OperatorToken type of this object
	int getPrecedence() const;		// returns the precedence (lower is first) of this operator

	// utility methods
	string toString() const override;	// return the char/string representation of this operator
	bool isNumber() const override;		// always returns false, as Operator is not of type RationalExpression
	bool isOperator() const override;	// always returns true, as Operator is always of type Operator
};

/*
*	[ getOperatorToken ]
*	Get the OperatorToken type associated with this char.
*	For example, '+' returns OperatorToken::ADD, and 's' returns OperatorToken::SIN.
*	Also returns OperatorToken::UNKOWN if the char is not associated with a valid operator.
*	Used to quickly and easily parse the raw input string into Operator tokens wherever they show up.
*/
OperatorToken getOperatorToken(char raw);

#endif