#include <iostream>

int area(int width, int length) {
    if (width <= 0 || length <= 0) {
        return -1;
    }
    return length*width;
}

int framed_area(int x, int y) {
    return area(x-2, y-2);
}

int f(int x, int y, int z) {
    int area1 = area(x, y);
    if (area1 <= 0) std::cerr << "area1 should be positive" << std::endl;
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1)/area3;
    std::cout << "area1: " << area1 << ", area2: " << area2 << ", area3: " << area3 << ", ratio: " << ratio << std::endl;
    return int(ratio);
}

int main() {
    std::cout << "f: " << f(-1, 2, 4) << std::endl;

    return 0;
}
