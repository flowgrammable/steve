
# Expressions

An expression is a sequence of operators and operands that
specifies a computation. 

The *result* of an operation is the value that the operator computes
when applied to its operand. The *result type* of an expression is
the type of an expression's result.

An expression whose result type `bool` is a *boolean expression*. An 
expression whose result type `int` is an *integer expression*.

Note: The purpose for these definitions is to, in the future, allow
an expression to be defined for a broader set of types (e.g., `+`
should work with integers of different precisions).


## Primary expresssion

    primary-expression ::=
        boolean-literal
        integer-literal
        '(' expression ')'

    literal ::=
        boolean-literal
        integer-literal

    boolean-literal ::= `true` | `false`

    integer-literal ::= decimal-integer-literal


The result of a literal is determined by its spelling. 
A *boolean-literal* has type `bool`. 
An *integer-literal* has type `int`.


## Prefix expressions

The prefix expressions are:

    prefix-expression ::=
        '+' prefix-expression
        '-' prefix-expression
        '~' prefix-expression
        '!' prefix-expression
        primary-expression

The operand of the unary `+` expression shall be an integer expression,
the result shall be the value of the operand, and the result type is
`int`.

The operand of the unary `-` expression shall be an integer expression,
the result shall be the (numeric) negation of the operand, and the result 
type is `int`.


# TODO: Finish documenting the=se...


## Multiplicative expressions

The multiplicative expressions are:

    multiplicative-expression ::=
        multiplicative-expression '*' prefix-expression
        multiplicative-expression '/' prefix-expression
        multiplicative-expression '%' prefix-expression
        prefix-expression

Multiplicative operators `*`, `/, and `%` group left-to-right.


TODO: Document these.


## Length-of operator

