
# Types

## Boolean type

The `bool` type represents the values `true` and `false`. An object
of type `bool` has size 1.


## Integer types

The integer types are the set of types defined by the following
properties:

- their precision (specified in bits),
- whether they are signed or unsigned, and
- their byte ordering.

The *byte order* of an integer is one of: most significant byte 
first (MSBF), least significant byte first (LSBF), or the native 
byte ordering of the target system. [Note: The native byte order 
is distinct from MSBF or LSBF]. The integer types with native byte 
ordering are called the *native integer types*.

Signed integer types represent their values as 2's complement signed
integers. For some precision N, the set of integers represented by
a signed intger type is −2^(N−1) to 2^(N−1) − 1).

The *precise signed integer types* are:

- `intN`    -- Has native byte ordering and precision `N`.
- `msbfN`  -- Has MSBF byte ordering with N bits of precision.
- `lsbfN`   -- Has LSBF byte ordering with N bits of precision.

The *common signed integer types* are aliases for a precise
integer type whose precision is determined by the target
architecture.

- `short` -- TODO
- `int`   -- Has native bute ordering and implementation-specified precision.
- `long`  -- TODO

The set of integers represented by unsigned integer types is 
0 to 2^N - 1.

The *precise unsigned integer types* are:

- `uintN`  -- Has native byte ordering and precision `N`.
- `umsbfN`  -- Has MSBF byte ordering with N bits of precision.
- `ulsbfN`   -- Has LSBF byte ordering with N bits of precision.

The *common unsigned integer types* are:

- `ushort` -- TODO:
- `uint`   -- Has native bute ordering and implementation-specified precision.
- `long`   -- TODO:


TODO: Should we require that MSBF/LSBF types have precision that
is a power of 2? Or should we adjust the precision to the next
greater power of 2?


Except for members of records, the size of an object with integer
type is greater than or equal to the number of bytes required by its
precision. Otherwise, the exact size of an integer object whose
precision is `N` is given by `(2 ^ (ceil(log2(N)))) / 8`.

[Example:

    var n1 : int1;  // n has size 1
    var n  : int48; // n has size 8
]





## Variant types


## Match types

A match type is defined by a declaration that acts as a
discriminator over a non-empty set of member types. For example:

    record R {
      d : bool;
      v : select(d) {
        true  : int;
        false : float;
      };
    }

Here, the `d` member is a descriminator for the selection type 
of `v`, which can represent either an `int` value or a `float`
value at a given time, depending on the initializatoin of `d`.

The declaration acting as the descriminator is called the
*controlling* declaration. Multiple values of selection type
can be controlled by the same declaration.

    b : bool = true;
    v1 : select(b) { true : int } = 0; // OK
    v2 : select(b) { false : int } = 0; // OK

FIXME: We need to define converions to selection types. We also
need to define what happens when the conversion selects a type
that does not comport with the value of the discriminator. Hint:
undefined behavior.


## If type

  record R {
    b : bool;
    x : if(b) T;
  }

An `if` type can be seen as a simplification of `match` type:

  record R {
    b : bool;
    x : match(b) {
      true : T;
    }
  };


## Sequence types

There are three sequence types:

- `seq(T, n)` types define a sequence `n` elements of type `T`.

- `seqbuf(T n)` types define a sequence of elements of type `T`
   whose total length is no greater than `n` bytes.

- `seqterm(T, p)` types define a sequence of elements of type
  `T` terminated by a sentinel expression, `p`

[Note: For each sequence type, the length is determined by
the length of its elements, which may not be constant.]

[Note: the `seq` type is effectively a variable length array.
In fact, the `match` type is in the same category of types.
This means that an object can only be initialized from members
or constructed from an array. In the case of initialization
from members, we can use `alloca` to grab stack space, but
we have to compute length prior to initialazation.

The static notion of `sizeof` does not apply to these types. We
might consider an operator `lengthof` in its place. ]

[Example
    record R 
    {
      nelems : int;
      seq : seq(T, nelems);
    }


    record R 
    {
      nbytes : int;
      seq : seqbuf(T, nbytes);
    }


    // FIXME: Find better examples.
    record R 
    {
      seq : seqterm(T, pred)
    }
]

TODO: Make the seqterm type a `until` type, so:

    x : until(pred) T;

It's a sequence until pred is satisfied.

Potentially also support `while` types, which would be 
the inverse.
