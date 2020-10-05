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
