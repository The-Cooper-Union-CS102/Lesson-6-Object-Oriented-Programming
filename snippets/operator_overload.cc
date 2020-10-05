#include <stdio.h>

class Vector {
    public:
        double x, y, z;
        Vector(double xx, double yy, double zz) {
            x = xx;
            y = yy;
            z = zz;
        }
        Vector operator + (Vector obj) {
            Vector v = Vector(
                x + obj.x,
                y + obj.y,
                z + obj.z);
            return v;
        }
};

int main() {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(0, 1, 2);
    Vector u = v + w;
    printf("(%g, %g, %g)\n", u.x, u.y, u.z);
}
