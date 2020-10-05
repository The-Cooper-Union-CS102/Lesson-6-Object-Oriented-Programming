#include <stdio.h>
#include <vector>

int main() {
    std::vector<int> vi;
    vi.push_back(100);
    vi.push_back(200);
    vi.push_back(300);
    printf("%d\n", vi[2]);
    printf("%d\n", vi[1]);
    printf("%d\n", vi[0]);

    std::vector<double> vd;
    vd.push_back(1.00);
    vd.push_back(3.14);
    vd.push_back(2.72);
    printf("%g\n", vd[2]);
    printf("%g\n", vd[1]);
    printf("%g\n", vd[0]);
}
