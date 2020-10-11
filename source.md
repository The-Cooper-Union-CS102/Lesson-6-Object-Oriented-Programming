# Object Oriented Programming

## Classes and Objects

In C++, classes are primarily used rather than
functions or structures.  They combine both of these
into one thing.  Classes are essentially just a way
of codifying what we found to be a useful design
pattern:  Create a structure containing data, and
create functions which take that structure and do
something with it.

For example, see this code which implements a class
called `Recangle`.

```snippet
{"code": "snippets/class.cc"}
```

We see it has two **properties**: `length` and
`width` and two **methods** `perimeter` and `area`.
In `main` we create a new **object** called `rect`.
On object is just a variable that represents one
particular instance of a class.  Note that when
we create this object, we say it is of type
`Rectangle`, and we create it by calling
`Rectangle` as if it were a function.

We see similar to the *structure*, we can access the
properties of an object using the dot `.` operator.
We can also use it to access and call the methods
of the class.  You can see in the methods we do not
have to explicitly get the length and width from the
class, they are implicitly available.

```snippet
{"code": "snippets/class.cc"}
```

### Constructors and Destructors

In the last example we created the rectangoe and then
assigned the values of some properties we needed,
`length` and `width`.  C++ uses a common feature
called **constructors** that allow you to combine this
into one step.  This is demonstrated below:

```snippet
{"code": "snippets/constructor.cc"}
```

You can see from the example that you can define
the constructor of a class by implementing a method
with the same name of the class.  In this case we
simply take two inputs and set the corresponding
properties of the class, but you can encode whatever
logic you want.  For example, you might assert that
the length and width are greater than 0.

Simiarly, you may also define a **destructor** for
a class by defining a method, `~<ClassName>`.  A
destructor runs whenever the object is deleted, and
is typically used to clean up temporary resources
it needed.

```snippet
{"code": "snippets/destructor.cc"}
```

In the simple example above, we just print that we
are "destructing" the rectangle meaning it no longer
exists after that is printed.

### Public and Private

Note in the above examples, we used a keyword,
`public` before defining all of our properties and
methods.  This keyword says that whatever follows may
be accessed by things outside of the class itself.
The alternative, you might guess, is `private`,
demonstrated below.

```snippet
{"code": "snippets/private.cc"}
```

An attempted violation of the rule with the associated
compiler error is shown below.

```snippet
{
"build": ["g++ snippets/private_err.cc"],
"show": ["snippets/private_err.cc"]
}
```

This is used for two reasons:
1. Prevent programmers from changing a value they shouldn't
2. Allow a division between the implementer and the user of a class

For example, maybe the implementer of `Rectangle`
might want to change the name for `length` and
`width` to `l` and `w` later on.  If they are
private, there is no chance that anyone else will be
using those names in their code, so nothing will
break.

### Getters and Setters

The distiction results in some complications because
you may in fact wnat to allow people to access the
length or width of a rectangle, while keeping some
control.  this is where **getters** and **setters**
come in.  Take a look at the following example
that uses them.

```snippet
{"code": "snippets/getter_setter.cc"}
```

Your reaction may be that this needlessly adds
complexity to the code, and you are correct to some
degree.  However, it is a tradeoff that others have
found to be helpful.  In particular, if you want to
later add code to validate the length and width
that someone is setting, you can easily add that
check in these new methods.

### Inheritance

So far classes can "have" properties, and they can
"do" methods.  Inheritence is a concept that adds
one more word to the vocabulary.  If class A inherits
from class B we can say "A is a B."  That is,
inheritence is useful for when we want a more specific
version of a class.  For example, "A square is a
rectangle and a rectangle is a shape" is mirrored
by the following code.

```snippet
{"code": "snippets/inheritance.cc"}
```

You can see that we say that `Square` inehrits from
`Rectangle` by placing a `: public Rectangle`
afterward.  The `public` indicates that `Square` has
full access to the members of `Rectangle`.  It is
possible to inherit from more than one class, which is
called *multiple inheritance*, but we will not go
through it here.

### Virtual Base Class

Sometimes it is helpful to have a class which has
methods but does not actually implement them.  This
could be useful for setting an expectation on what an
inheriting class should implement.  Such a class is
called a *virtual base class*.  We can create one by
creating a class that has only **virtual** methods.
This is demonstrated in the following example
which extends the previous one.

```snippet
{"code": "snippets/virtual.cc"}
```

You can see that the inheritance works the same as
before, but in our virtual base class, we used
the `virtual` keyword to indicate that we expect
the method to be implemented by the inheriting class,
which `Rectangle` does.  A virtual base class
is mostly synonymous with *abstract base class* and
*interface* from other languages.

You can see if you tried to create an object which
did not implement all `virtual` functions, you would
get a compiler error:

```snippet
{
"build": ["g++ snippets/virtual_err.cc"],
"show": ["snippets/virtual_err.cc"]
}
```

## Templating

Before we had a common issue where we would have to
implement a function once per type we wanted to use
it for.  For example, if we wanted a function that
takes the max of two numbers, we may have to
write an implementation for `int` and `float`, or
even worse write a macro.  Because C++ allows us to
define our own types, this could result in a lot of
duplicate code for each type we define.  This issue
is remedied with **templates**.  Essentially, a
template allows you to define a function not with
one known type, but with a placeholder for a type.
This is demonstrated below for the `max` function.

```snippet
{"code": "snippets/template.cc"}
```

You can think of this as essentially generating code
for each type used.  So the compiler goes through
your code, finds everywhere you call the function,
the type you call it with, and defines the function
for that type, fitting the template.

This can also be applied to classes. Take a look at
this example which allows us to create a `Rectangle`
with either float or integer dimensions.

```snippet
{"code": "snippets/template_class.cc"}
```

One important example of templates is the use of
the `vector` class from the standard library, which
can be used as a variable sized array of any type.

```snippet
{"code": "snippets/vector.cc"}
```

## Namespaces

One thing you should notice about the vector example
is that we did not simply use `vector` but
`std::vector`.  The `std` (which stands for standard)
is a **namespace**, another new feature of C++ that
allows you to organize your variables, functions and
classes to avoid interference.  They are similar
to code blocks except that you can reference the
code block by name.

```snippet
{"code": "snippets/namespace.cc"}
```

## Overloading

Overloading is a term meaning to apply more than one
meaning to a sybmol.

## Function Overloading

We can apply more than one definition for a function
name if we use different types, as in the following
example:

```snippet
{"code": "snippets/overload.cc"}
```

## Operator Overloading

We can also implement our own definitions for
operators on our own classes.  Let's take the example
of a 3D vector (or point in 3D space)

```snippet
{"code": "snippets/operator_overload.cc"}
```

You can see in the case of the addition operator `+`
it is essentially just defining a method of the class
that takes another of object of the same type and
produces one of the same type.  The same basic
concept applies to most operators.

## References

References are similar to pointers but a little bit
more restricted and therefore safer.  A reference
is like a point in that you can use it to get the
value of or modify a variable.  It is different in
that it must always point to a valid piece of data.
That is, you cannot have a null or uninitialized
reference.

In its simplest case, is it merely another name
for the same piece of data, as demonstrated here:

```snippet
{"code": "snippets/reference.cc"}
```

You can pass a value by reference to a function by
placing the `&` symbol after the type, as in the
following example:

```snippet
{"code": "snippets/pass_reference.cc"}
```

## `this` Keyword

It is not often necessary, however you can use the
`this` keyword in C++ to refer to the object itself.
This can be used to get members or call member
functions.

```snippet
{"code": "snippets/this.cc"}
```

## New and Delete

The C++ companions to our old friends, `malloc` and
`free` are `new` and `delete`.  These keywords can
be used to allocate and free memory for the creation
and deletion of objects.  The `new` operator returns
a pointer to the created object, and the `delete`
operator takes the same pointer, and frees the space.

```snippet
{"code": "snippets/new_delete.cc"}
```

# Other C++ Things

## String Streams

Streams make input and output a lot easier.  While our
examples above used `printf`, there is actually almost
no need for it anymore!  Here is an example that uses
**string streams** from the standard library in order
to output some variables.

```snippet
{"code": "snippets/output.cc"}
```

We can also use these to store inputs into variables.

```snippet
{
"build": ["g++ snippets/input.cc"],
"show": ["snippets/input.cc"]
}
```

## Strings

In C++, we no longer have to deal with char arrays!
C++ offers **strings** in the common library which
offer several useful bulit in methods:

```snippet
{"code": "snippets/string.cc"}
```
