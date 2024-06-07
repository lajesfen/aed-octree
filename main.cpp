#include <iostream>

#include "octree.h"

int main() {
    Octree octree(0, 0, 0, 8);

    octree.insert(Point(1, 1, 1));
    octree.insert(Point(-1, -1, -1));
    octree.insert(Point(1, -1, 1));
    octree.insert(Point(-1, 1, -1));
    octree.insert(Point(2, 2, 2)); // Forces subdivision

    // Insert points to create a subcube in one of the octants
    octree.insert(Point(3, 3, 3));
    octree.insert(Point(3.5, 3.5, 3.5)); // Forces further subdivision

    // Insert points in the smallest octant
    octree.insert(Point(3.25, 3.25, 3.25));
    octree.insert(Point(3.75, 3.75, 3.75));

    octree.print(1);

    return 0;
}
