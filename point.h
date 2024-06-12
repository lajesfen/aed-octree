#ifndef OCTREE_POINT_H
#define OCTREE_POINT_H

struct Point {
    float x, y, z;

    Point(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() {
        std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")\n";
    }
};

#endif //OCTREE_POINT_H
