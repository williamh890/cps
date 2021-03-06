#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <cstdlib>
#include <string>

class Circle : public Shape {
    private:
        double _radius;

    public:
        Circle(double radius);
        ~Circle() override = default;

        std::string postscript() override;
        const BoundingBox makeBoundingBox() const;
};

#endif // CIRLCE_H
