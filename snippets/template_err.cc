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
    float xf = 0.5;
    printf("Max (int/float): %d\n", max(xi, xf));
}
