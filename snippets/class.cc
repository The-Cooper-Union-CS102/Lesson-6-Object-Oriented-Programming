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
