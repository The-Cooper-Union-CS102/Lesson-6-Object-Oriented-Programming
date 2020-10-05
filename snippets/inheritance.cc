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
