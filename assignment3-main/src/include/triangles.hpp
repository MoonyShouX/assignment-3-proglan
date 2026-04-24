#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "point2d.hpp"
#include <iostream>
#include <cmath>

class Triangle {
    private:
        Point2D _t1, _t2, _t3;

        float distance(const Point2D& a, const Point2D& b) const;
        float dot(const Point2D& v1, const Point2D& v2) const;
        Point2D makeVec(const Point2D& from, const Point2D& to) const;

    public:
        Triangle();
        Triangle(Point2D t1, Point2D t2, Point2D t3);

        void SetT1(Point2D t1);
        void SetT2(Point2D t2);
        void SetT3(Point2D t3);

        Point2D GetT1() const { return _t1; }
        Point2D GetT2() const { return _t2; }
        Point2D GetT3() const { return _t3; }

        void TriangleType() const;
};

#endif
