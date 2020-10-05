#include <stdio.h>

void print(double d) {
    printf("Printing double: %f\n", d);
}

void print(int i) {
    printf("Printing int: %d\n", i);
}

void print(char c) {
    printf("Printing char: %c\n", c);
}

int main() {
    print(1);
    print(2.5);
    print('c');
}
