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
