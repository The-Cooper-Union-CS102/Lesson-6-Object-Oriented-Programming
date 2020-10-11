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
