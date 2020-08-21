#include <iostream>

int main() {
    // statement expr : we should get z.
    int a = ({
        int x = 1;
        int y = 2;
        int z = 3;
        std::cout << x << " " << y << " " << z << std::endl;
        x += y;
        y += z;
        z += x;
    });

    std::cout << "my a : " << a << std::endl;
}
