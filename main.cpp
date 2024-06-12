#include <iostream>

#include "octree.h"

int main() {
    // 1. Crea un cubo de 8x8x8 con centro en (0; 0; 0)
    Octree octree(0, 0, 0, 8);

    // 2. Agrega 8 puntos
    octree.insert(Point(1, 1, 1));
    octree.insert(Point(1, -1, 1));

    octree.insert(Point(-1, 1, 1));
    octree.insert(Point(-1, -1, 1));

    octree.insert(Point(1, 1, -1));
    octree.insert(Point(1, -1, -1));

    octree.insert(Point(-1, 1, -1));
    octree.insert(Point(-1, -1, -1));

    // 3. Agrega un punto adicional, se subdivide el arbol y envia a todos los puntos a un octante diferente.
    octree.insert(Point(2, 2, 2)); // Este punto se inserta junto al punto (1, 1, 1) ya que se encuentran en el mismo octante (Cubo de 4x4x4 con centro en (2; 2; 2)).

    // 4. Agrega 7 puntos dentro de un octante (Cubo de 4x4x4 con centro en (2; 2; 2))
    octree.insert(Point(3, 3, 3));
    octree.insert(Point(3, 1, 3));

    octree.insert(Point(1, 3, 3));
    octree.insert(Point(1, 1, 3));

    octree.insert(Point(1, 3, 1));
    // Ya se habia insertado previamente el (1; 1; 1)

    octree.insert(Point(3, 3, 1));
    octree.insert(Point(3, 1, 1));

    // 5. Imprime arbol con sus hijos
    octree.print(2);

    // 6. Demostracion: Halla el punto mas cercano verificando si el objetivo esta contenido dentro de cada hijo
    std::vector<Point> closest = octree.findClosest(Point(1, 3.5, 1.5));
    std::cout << "\nLos puntos mas cercanos son: \n";
    for(auto &c : closest)
        c.print();

    return 0;
}
