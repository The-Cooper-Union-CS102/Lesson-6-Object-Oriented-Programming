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
