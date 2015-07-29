
# Conversions

Implicit conversions are applied to transform an expression `e` into
some destination type `T`. This section describes the semantics of
these conversions.

A *conversion sequence* consists of a set of conversions
applied in the following order:

- Zero or one type promotions.
- Zero or one type conversions.
- Zero or one value transformations.


A *type promotion* changes the type of a value without modifying
it's underlying representation. The type promotions are:
enumeration promotion, ...

A *type conversion* allows the widening of a value to a type
that represents a broader set of values, or the reinterpretation
of a value as a different kind (e.g., signed to unsigned integer).

A *value transformation* modifies the representation of as
value, but not its interpretation.

## Boolean promotion

A value of type bool can be converted to a value of type int.


## Enumeration promotion

A value of enumeration type can be converted to value of its 
underlying type. Note that this conversion is conceptual;
it does not alter the bit pattern of the source value.


## Integer conversion

A value of integer type can be converted to a value of a 
different integer type with the byte order whose precision 
is greater than or equal to that of the source integer.

When the precision of the destination type is greater than
that of the source type, the source value is first promoted
to a greater precision.

This allows signed integers to be converted to unsigned
integers, but this does not change the underlying pattern
of bits after promotiohn.


## Tuple conversion

A value of tuple type can be converted to the value of a record 
type, where the type of each member matches the type of the 
corresponding elements in the tuple value.

TODO: If we have constructors, we need to verify that there
is a suitable constructor that accepts a tuple -- or an
initializer list or some such thing.

TODO: Allow for integer values to initialize bitfields. Note
that truncation may occur!


## Integer transformation

A value of integer type can be converted to a value of a
different integer type with the same signedness and precision
but a different byte ordering.

This allows the following:

    def f(n : intm32);

    f(0); // OK: implicit byte order conversion


## Boolean conversions

In certain contexts, an expression may be converted to `bool`.

The expression is first promoted.

A promoted integer value can be converted to `bool`. If the integer
value is `0`, the converted value is `false`. Otherwise, the converted 
value is `true`.

TODO: What else can be converted to bool?


## Conversion to a common type

The *common type* of two expressions E1 and E2 is a type T to
which both E1 and E2 can be converted. Note that T may be the
type of E1, the type of E2, or some other type. The common type of E1
and E2 is found by a sequence of conversions to E1 and E2 that
would coause them to have the same type. That sequence is defined
as follows:

- If E1 and E2 have the same type, then no conversions are applied.

- Promote both E1 and E2. The following rules are applied to the
  promoted expressions. If, after promotion, E1 and E2 have the
  same type, no further conversions are applied.

- If both promoted expressions are integer expressions, see the 
  rules below for finding the common type of integer expressions.

- Otherwise, the expressions cannot be converted to a common type.


TODO: Verify that the rules for conversion to common type will
allow implicit conversion from either expression to the common
type.


### Common type of integer expressions.

The following rules are used to convert integer expressions E1 and
E2 to a common type.

- Both E1 and E2 are converted to native byte order. If, after 
  conversion, the converted expressions have the same type, 
  no further conversions are applied.

- If the converted expressions have the same signedness the expression 
  with the least precision is converted to the expression with the greater 
  precision.

- Otherwise, both expressions are converted to an unsigned integer
  type whose precision is the greatest precision of either expression.


### Common type of ...

