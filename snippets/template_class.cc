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
