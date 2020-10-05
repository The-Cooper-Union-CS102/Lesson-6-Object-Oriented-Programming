#include <stdio.h>

void triple(int a, int b, int c) {
    for (a = 1;; a++) {
        for (b = 1; b <= a; b++) {
            for (c = 1; c <= b; c++) {
                if (c*c + b*b == a*a) {
                    return;
                }
            }
        }
    }
}

int main() {
    int x, y, z;
    x = y = z = 0;
    int &a = x;
    int &b = y;
    int &c = z;
    triple(a, b, c);
    printf("(%d, %d, %d)\n", x, y, z);
}
