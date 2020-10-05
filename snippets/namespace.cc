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
