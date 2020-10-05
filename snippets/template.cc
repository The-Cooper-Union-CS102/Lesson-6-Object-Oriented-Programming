#include <stdio.h>

template <typename MyType>
MyType max(MyType x, MyType y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
};

int main() {
    int xi = 0;
    int yi = 1;
    float xf = 0.5;
    float yf = -1.0;
    char xc = 'x';
    char yc = 'y';
    printf("Max (int): %d\n", max<int>(xi, yi));
    printf("Max (float): %f\n", max<float>(xf, yf));
    printf("Max (char): %c\n", max<char>(xc, yc));
}
