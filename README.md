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

```c
// snippets/class.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle();
    rect.length = 10;
    rect.width = 5;
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Perimeter: 30
Area: 50
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

```c
// snippets/class.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle();
    rect.length = 10;
    rect.width = 5;
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Perimeter: 30
Area: 50
```


### Constructors and Destructors

In the last example we created the rectangoe and then
assigned the values of some properties we needed,
`length` and `width`.  C++ uses a common feature
called **constructors** that allow you to combine this
into one step.  This is demonstrated below:

```c
// snippets/constructor.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        Rectangle(int l, int w) {
            printf("Constructing Rectangle!\n");
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle(10, 5);
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Constructing Rectangle!
Perimeter: 30
Area: 50
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

```c
// snippets/destructor.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        Rectangle(int l, int w) {
            printf("Constructing Rectangle!\n");
            length = l;
            width = w;
        }
        ~Rectangle() {
            printf("Destructing Rectangle!\n");
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle(10, 5);
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Constructing Rectangle!
Perimeter: 30
Area: 50
Destructing Rectangle!
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

```c
// snippets/private.cc
#include <stdio.h>

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle(10, 5);
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Perimeter: 30
Area: 50
```


An attempted violation of the rule with the associated
compiler error is shown below.

```c
// snippets/private_err.cc
#include <stdio.h>

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle(10, 5);
    rect.length = rect.width;
}
```

```
g++ snippets/private_err.cc
```

```
snippets/private_err.cc:22:10: error: 'length' is a private member of 'Rectangle'
    rect.length = rect.width;
         ^
snippets/private_err.cc:5:13: note: declared private here
        int length;
            ^
snippets/private_err.cc:22:24: error: 'width' is a private member of 'Rectangle'
    rect.length = rect.width;
                       ^
snippets/private_err.cc:6:13: note: declared private here
        int width;
            ^
2 errors generated.

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

```c
// snippets/getter_setter.cc
#include <stdio.h>

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int getLength() {
            return length;
        }
        int getWidth() {
            return width;
        }
        void setLength(int l) {
            length = l;
        }
        void setWidth(int w) {
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

int main() {
    Rectangle rect = Rectangle(0, 0);
    rect.setLength(5);
    rect.setWidth(10);
    printf("Width: %d\n", rect.getWidth());
    printf("Length: %d\n", rect.getLength());
    printf("Perimeter: %d\n", rect.perimeter());
    printf("Area: %d\n", rect.area());
}
```


```
Width: 10
Length: 5
Perimeter: 30
Area: 50
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

```c
// snippets/inheritance.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

class Square: public Rectangle {
    public:
        Square(int s): Rectangle(s, s) {}
};

int main() {
    Rectangle r = Rectangle(5, 10);
    Square s = Square(5);
    printf("Rectangle Area: %d\n", r.area());
    printf("Square Area: %d\n", s.area());
}
```


```
Rectangle Area: 50
Square Area: 25
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

```c
// snippets/virtual.cc
#include <stdio.h>

class Shape {
    public:
        virtual int perimeter() = 0;
        virtual int area() = 0;
};

class Rectangle: Shape {
    public:
        int length;
        int width;
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
        int area() {
           return length * width;
        }
};

class Square: public Rectangle {
    public:
        Square(int s): Rectangle(s, s) {}
};

int main() {
    Rectangle r = Rectangle(5, 10);
    Square s = Square(5);
    printf("Rectangle Area: %d\n", r.area());
    printf("Square Area: %d\n", s.area());
}
```


```
Rectangle Area: 50
Square Area: 25
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

```c
// snippets/virtual_err.cc
#include <stdio.h>

class Shape {
    public:
        virtual int perimeter() = 0;
        virtual int area() = 0;
};

class Rectangle: Shape {
    public:
        int length;
        int width;
        Rectangle(int l, int w) {
            length = l;
            width = w;
        }
        int perimeter() {
           return 2 * (length + width);
        }
};

int main() {
    Rectangle r = Rectangle(5, 10);
}
```

```
g++ snippets/virtual_err.cc
```

```
snippets/virtual_err.cc:23:19: error: allocating an object of abstract class type 'Rectangle'
    Rectangle r = Rectangle(5, 10);
                  ^
snippets/virtual_err.cc:6:21: note: unimplemented pure virtual method 'area' in 'Rectangle'
        virtual int area() = 0;
                    ^
snippets/virtual_err.cc:23:15: error: variable type 'Rectangle' is an abstract class
    Rectangle r = Rectangle(5, 10);
              ^
2 errors generated.

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

```c
// snippets/template.cc
#include <stdio.h>

template <typename MyType>
MyType max(MyType x, MyType y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
};

int main() {
    int xi = 0;
    int yi = 1;
    float xf = 0.5;
    float yf = -1.0;
    char xc = 'x';
    char yc = 'y';
    printf("Max (int): %d\n", max<int>(xi, yi));
    printf("Max (float): %f\n", max<float>(xf, yf));
    printf("Max (char): %c\n", max<char>(xc, yc));
}
```


```
Max (int): 1
Max (float): 0.500000
Max (char): y
```


You can think of this as essentially generating code
for each type used.  So the compiler goes through
your code, finds everywhere you call the function,
the type you call it with, and defines the function
for that type, fitting the template.

This can also be applied to classes. Take a look at
this example which allows us to create a `Rectangle`
with either float or integer dimensions.

```c
// snippets/template_class.cc
#include <stdio.h>

template<typename T>
class Rectangle {
    public:
        T length;
        T width;
        Rectangle(T l, T w) {
            length = l;
            width = w;
        }
        T perimeter() {
           return 2 * (length + width);
        }
        T area() {
           return length * width;
        }
};

int main() {
    Rectangle<int> recti = Rectangle<int>(10, 5);
    Rectangle<float> rectf = Rectangle<float>(3.5, 5.5);
    printf("Perimeter (int): %d\n", recti.perimeter());
    printf("Area (int): %d\n", recti.area());
    printf("Perimeter (float): %f\n", rectf.perimeter());
    printf("Area (float): %f\n", rectf.area());
}
```


```
Perimeter (int): 30
Area (int): 50
Perimeter (float): 18.000000
Area (float): 19.250000
```


One important example of templates is the use of
the `vector` class from the standard library, which
can be used as a variable sized array of any type.

```c
// snippets/vector.cc
#include <stdio.h>
#include <vector>

int main() {
    std::vector<int> vi;
    vi.push_back(100);
    vi.push_back(200);
    vi.push_back(300);
    printf("%d\n", vi[2]);
    printf("%d\n", vi[1]);
    printf("%d\n", vi[0]);

    std::vector<double> vd;
    vd.push_back(1.00);
    vd.push_back(3.14);
    vd.push_back(2.72);
    printf("%g\n", vd[2]);
    printf("%g\n", vd[1]);
    printf("%g\n", vd[0]);
}
```


```
300
200
100
2.72
3.14
1
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

```c
// snippets/namespace.cc
#include <stdio.h>

namespace shapes {
    class Square {
        public:
            float side;
            Square(float s) {
                side = s;
            }
            float perimeter() {
               return 4 * side;
            }
            float area() {
               return side * side;
            }
    };
    class Circle {
        public:
            float radius;
            Circle(float r) {
                radius = r;
            }
            float perimeter() {
               return 2 * 3.1415 * radius;
            }
            float area() {
               return 3.1415 * radius * radius;
            }
    };
}

int main() {
    shapes::Square sq = shapes::Square(2);
    shapes::Circle ci = shapes::Circle(1);
    printf("Square Area: %f\n", sq.area());
    printf("Circle Area: %f\n", ci.area());
}
```


```
Square Area: 4.000000
Circle Area: 3.141500
```


## Overloading

Overloading is a term meaning to apply more than one
meaning to a sybmol.

## Function Overloading

We can apply more than one definition for a function
name if we use different types, as in the following
example:

```c
// snippets/overload.cc
#include <stdio.h>

void print(double d) {
    printf("Printing double: %f\n", d);
}

void print(int i) {
    printf("Printing int: %d\n", i);
}

void print(char c) {
    printf("Printing char: %c\n", c);
}

int main() {
    print(1);
    print(2.5);
    print('c');
}
```


```
Printing int: 1
Printing double: 2.500000
Printing char: c
```


## Operator Overloading

We can also implement our own definitions for
operators on our own classes.  Let's take the example
of a 3D vector (or point in 3D space)

```c
// snippets/operator_overload.cc
#include <stdio.h>

class Vector {
    public:
        double x, y, z;
        Vector(double xx, double yy, double zz) {
            x = xx;
            y = yy;
            z = zz;
        }
        Vector operator + (Vector obj) {
            Vector v = Vector(
                x + obj.x,
                y + obj.y,
                z + obj.z);
            return v;
        }
};

int main() {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(0, 1, 2);
    Vector u = v + w;
    printf("(%g, %g, %g)\n", u.x, u.y, u.z);
}
```


```
(1, 3, 5)
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

```c
// snippets/reference.cc
#include <stdio.h>

int main() {
    int x = 10;
    int &ref = x;
    ref = 5;
    printf("x: %d, ref: %d\n", x, ref);
}
```


```
x: 5, ref: 5
```


You can pass a value by reference to a function by
placing the `&` symbol after the type, as in the
following example:

```c
// snippets/pass_reference.cc
#include <stdio.h>

void triple(int &a, int &b, int &c) {
    for (a = 1;; a++) {
        for (b = 1; b <= a; b++) {
            for (c = 1; c <= b; c++) {
                if (c*c + b*b == a*a) {
                    return;
                }
            }
        }
    }
}

int main() {
    int x, y, z;
    x = y = z = 0;
    triple(x, y, z);
    printf("(%d, %d, %d)\n", x, y, z);
}
```


```
(5, 4, 3)
```


## `this` Keyword

It is not often necessary, however you can use the
`this` keyword in C++ to refer to the object itself.
This can be used to get members or call member
functions.

```c
// snippets/this.cc
#include <stdio.h>

class Rectangle {
    public:
        int length;
        int width;
        Rectangle(int length, int width) {
            this->length = length;
            this->width = width;
        }
        int perimeter() {
            return 2 * (this->length + this->width);
        }
        int area() {
            return this->length * this->width;
        }
        int greaterAreaThan(Rectangle *that) {
            return this->area() > that->area();
        }
};

int main() {
    Rectangle *a = new Rectangle(10, 5);
    Rectangle *b = new Rectangle(2, 5);
    if (a->greaterAreaThan(b)) {
        printf("A has a greater area than B\n");
    } else {
        printf("B has a greater area than A\n");
    }
}
```


```
A has a greater area than B
```


## New and Delete

The C++ companions to our old friends, `malloc` and
`free` are `new` and `delete`.  These keywords can
be used to allocate and free memory for the creation
and deletion of objects.  The `new` operator returns
a pointer to the created object, and the `delete`
operator takes the same pointer, and frees the space.

```c
// snippets/new_delete.cc
#include <stdio.h>

class Rectangle {
    public:
        int *length;
        int *width;
        Rectangle(int l, int w) {
            length = new int(l);
            width = new int(w);
        }
        ~Rectangle() {
            delete length;
            delete width;
        }
        int perimeter() {
            return 2 * (*length + *width);
        }
        int area() {
            return (*length) * (*width);
        }
};

int main() {
    Rectangle *rect = new Rectangle(10, 5);
    printf("Perimeter: %d\n", rect->perimeter());
    printf("Area: %d\n", rect->area());
    delete rect;
}
```


```
Perimeter: 30
Area: 50
```


# Other C++ Things

## Exceptions

Exceptions are a new feature which allow your function to "return" (throw) an error in the case that it gets some wrong or unexpected input.  In the example below, we pass a value that is larger than expected to the function, and we "throw" the error.  With every throw, we should have a "catch" which takes the error that was thrown and does something with it.

```c
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
    //...
}

int main()
{
    try
    {
        MyFunc(256); //cause an exception to throw
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}
```

The advantage of exceptions is that we can

1. Return a different type which gives more information on the error; and
2. Catch from any level in the call stack - meaning we do not have to propagate the error through all functions.

Note however that (in C++) exceptions should be used sparingly.  If you can get away with returning a value instead of throwing an error, you should generally do that.  They are generally much slower than regular control flow.

## String Streams

Streams make input and output a lot easier.  While our
examples above used `printf`, there is actually almost
no need for it anymore!  Here is an example that uses
**string streams** from the standard library in order
to output some variables.

```c
// snippets/output.cc
#include <stdio.h>
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    std::string name = "Cory";
    std::cout << "Hello, " << name << std::endl;
    std::cout << "1 + 1 is " << 1 + 1 << std::endl;
}
```


```
Hello, world!
Hello, Cory
1 + 1 is 2
```


We can also use these to store inputs into variables.

```c
// snippets/input.cc
#include <stdio.h>
#include <iostream>

int main() {
    std::string name;
    std::cout << "What is your name: ";
    std::cin >> name;
    std::cout << "Your name is " << name << std::endl;
}
```

```
g++ snippets/input.cc
```



## Strings

In C++, we no longer have to deal with char arrays!
C++ offers **strings** in the common library which
offer several useful bulit in methods:

```c
// snippets/string.cc
#include <stdio.h>
#include <iostream>

int main() {
    std::string str = "Hello!";
    std::cout << str << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << str[0] << std::endl;
    std::cout << str.back() << std::endl;
    str[str.length()-1] = ' ';
    std::cout << str << std::endl;
    str += "Cory";
    std::cout << str << std::endl;
    std::cout << str.find('C') << std::endl;
    std::string newstr = "Hello Cory";
    std::cout << str.compare(newstr) << std::endl;
}
```


```
Hello!
6
H
!
Hello 
Hello Cory
6
0
```

