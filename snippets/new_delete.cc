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
