#ifndef OCTREE_POINT_H
#define OCTREE_POINT_H

struct Point {
    float x, y, z;

    Point(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif //OCTREE_POINT_H
