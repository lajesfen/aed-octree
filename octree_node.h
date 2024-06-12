#ifndef OCTREE_OCTREE_NODE_H
#define OCTREE_OCTREE_NODE_H

#include <vector>
#include "point.h"

class OctreeNode {
public:
    Point *center;
    float halfSize;
    bool isLeaf;
    OctreeNode *children[8];
    std::vector<Point> points;

public:
    OctreeNode(float centerX, float centerY, float centerZ, float size) {
        center = new Point(centerX, centerY, centerZ);
        halfSize = size / 2;
        isLeaf = true;

        for (auto &i : children) {
            i = nullptr;
        }
    }

    ~OctreeNode() {
        delete center;
        for (auto &i : children) {
            delete i;
        }
    }

    void insert(const Point &point) {
        if (!contains(point)) return;

        if (isLeaf) {
            points.push_back(point);
            if (points.size() > 8) {
                subdivide();
                for (const auto &p : points) {
                    for (auto &i : children) {
                        if (i->contains(p)) {
                            i->insert(p);
                            break;
                        }
                    }
                }
                points.clear();
            }
        } else {
            for (auto &i : children) {
                if (i->contains(point)) {
                    i->insert(point);
                    break;
                }
            }
        }
    }

    bool contains(const Point &point) const {
        return (point.x >= center->x - halfSize && point.x <= center->x + halfSize &&
                point.y >= center->y - halfSize && point.y <= center->y + halfSize &&
                point.z >= center->z - halfSize && point.z <= center->z + halfSize);
    }

    void subdivide() {
        float quarterSize = halfSize / 2;
        for (int i = 0; i < 8; ++i) {
            float newX = center->x + quarterSize * ((i & 1) ? 1 : -1);
            float newY = center->y + quarterSize * ((i & 2) ? 1 : -1);
            float newZ = center->z + quarterSize * ((i & 4) ? 1 : -1);
            children[i] = new OctreeNode(newX, newY, newZ, halfSize);
        }
        isLeaf = false;
    }

    std::vector<Point> findClosest(const Point &point) {
        if (!contains(point)) return {};

        if(isLeaf) {
            return points;
        } else {
            for(auto &i : children) {
                if(i->contains(point))
                    return i->findClosest(point);
            }
        }

        return points;
    }

    void print(int depth = 0) const {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Node Info:\n";
        std::cout << indent << "  Center: (" << center->x << ", " << center->y << ", " << center->z << ")\n";
        std::cout << indent << "  Half Size: " << halfSize << " = (" << halfSize*2 << "x" << halfSize*2 << "x" << halfSize*2 << ")\n";
        if (isLeaf) {
            std::cout << indent << "  Points: ";
            for (const auto& point : points) {
                std::cout << "(" << point.x << ", " << point.y << ", " << point.z << "), ";
            }
            std::cout << "\n";
        } else {
            std::cout << indent << "  Children:\n";
            for (int i = 0; i < 8; ++i) {
                if (children[i]) {
                    std::cout << indent << "  Child " << i + 1 << ":\n";
                    children[i]->print(depth + 2);
                }
            }
        }
    }
};

#endif //OCTREE_OCTREE_NODE_H
