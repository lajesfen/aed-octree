#ifndef OCTREE_OCTREE_H
#define OCTREE_OCTREE_H

#include <iostream>
#include "octree_node.h"

class Octree {
public:
    OctreeNode *root;

public:
    Octree(float centerX, float centerY, float centerZ, float size) {
        root = new OctreeNode(centerX, centerY, centerZ, size);
    }

    ~Octree() {
        delete root;
    }

    void insert(const Point &point) {
        root->insert(point);
    }

    bool contains(const Point &point) {
        return root->contains(point);
    }

    void print(int depth) const {
        root->print(depth);
    }
};

#endif //OCTREE_OCTREE_H
