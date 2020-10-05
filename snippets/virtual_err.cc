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
