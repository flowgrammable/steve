

## Types
This builds expansivel on the type system and includes support
for:

### Kind typpe

The kind type represents the higher-order type of type
declarations (record and enum declarations).

### Tuple types

The tuple type is the type of a tuple expression. It is
the sequence of types of the elements of the expression:

    {true, 0, 'a'} // has type {bool, int, char}


### User-defined type

A user-defined type is the type corresponding to the declaration
of a record or enum.



## Expressions

### Tuples

A tuple expression is a sequence of values enclosed in braces.

    {true, false, 0}

This is a primary expression.


### Projections

A projection access a member of composite type.

  var t : {int, int} = {2, 2};
  print t.1, t2; // Prints 2, 2

  record R { a : int, b : bool };
  var r : {0, true};
  print r.a, r.b; // Prints 0, true

There are two expressions involved in this representation:
index expressions (for numeric selectors) and member expressions
for id selectors.


## Declarations


### Record declarations

### Enum declarations

An enumeration declares a sequence of enumerators. Each enumerator
is a constant declaration whose type is that of declared enumeration
and whose value is determined by its initializer.

TODO: The current rule for typing the initializer is to allow
iff it matches the base type of the enumeration. However, during
evaluation, the type of the initializer is actually unchanged.
We probably want to do is evaluate the initializer and produce
a new expression that has the type of the enumeration.


## Constant declarations

A constant declaration binds a name to a compile-time value.
There are several ways in which we m




## Initializaiton concepts

The following concepts are added to the language:

### Direct initialization

In direct initialization, the initializer of a variable is
an expression.


### Aggregate initialization

A declaration whose type `T` is a composite type may be initialized
by a tuple, provided that there exists a projection from `T` to
the type of the initializer.

    record R {
      a : int;
      b : bool;
    };

    var r1 : R { 0, true };  // OK
    var r2 : R { false, 0 }; // error: type mismatch


### Constant initialization


Constant initialization is required for constant declarations.
In order for a constant declaration to be initialized, the
initializer muse evaluate to a compile-time constant. For
example:

    var x : int = 0;

    enum E { 
      A = 3 + 4;  // OK
      B = x;      // error: 'x' is not a constant expression
    }


## Evaluation changes

With the addition of compound types (tuples, aggregates), the
evaluation system also becomes more complex. A simple Integer
representation is insufficient to define the values of tuples
and records.

The value system is now defined inductively as

    value ::= int | value[n]

This will likely be extended as a we add more types (e.g.,
floats, string literals?).


## TODO

The ability to declare and later define an entity is important.

Support record inheritance.