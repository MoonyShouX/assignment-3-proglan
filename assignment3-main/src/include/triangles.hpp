#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "point2d.hpp"
#include <iostream>
#include <cmath>

class Triangle {
    private:
        Point2D _t1, _t2, _t3;

        // Hitung jarak antara dua Point2D secara manual
        float distance(const Point2D& a, const Point2D& b) const {
            return std::sqrt(
                std::pow(a.GetX() - b.GetX(), 2) +
                std::pow(a.GetY() - b.GetY(), 2) +
                std::pow(a.GetZ() - b.GetZ(), 2)
            );
        }

        // Dot product dua vektor (dari selisih koordinat)
        float dot(const Point2D& v1, const Point2D& v2) const {
            return v1.GetX()*v2.GetX() + v1.GetY()*v2.GetY() + v1.GetZ()*v2.GetZ();
        }

        // Buat vektor dari titik a ke titik b
        Point2D makeVec(const Point2D& from, const Point2D& to) const {
            return Point2D(
                to.GetX() - from.GetX(),
                to.GetY() - from.GetY(),
                to.GetZ() - from.GetZ()
            );
        }

    public:
        Triangle() {}
        Triangle(Point2D t1, Point2D t2, Point2D t3)
            : _t1(t1), _t2(t2), _t3(t3) {}

        void SetT1(Point2D t1) { _t1 = t1; }
        void SetT2(Point2D t2) { _t2 = t2; }
        void SetT3(Point2D t3) { _t3 = t3; }

        Point2D GetT1() const { return _t1; }
        Point2D GetT2() const { return _t2; }
        Point2D GetT3() const { return _t3; }

        void TriangleType() const {
            float ab = distance(_t1, _t2);
            float bc = distance(_t2, _t3);
            float ca = distance(_t3, _t1);

            const float EPS = 1e-4f;

            // Sama sisi: ketiga sisi sama panjang
            if (std::fabs(ab - bc) < EPS && std::fabs(bc - ca) < EPS) {
                std::cout << "sama sisi" << std::endl;
                return;
            }

            // Siku-siku: dot product salah satu sudut = 0
            Point2D v_ab = makeVec(_t1, _t2), v_ac = makeVec(_t1, _t3);
            Point2D v_ba = makeVec(_t2, _t1), v_bc = makeVec(_t2, _t3);
            Point2D v_ca = makeVec(_t3, _t1), v_cb = makeVec(_t3, _t2);

            if (std::fabs(dot(v_ab, v_ac)) < EPS ||
                std::fabs(dot(v_ba, v_bc)) < EPS ||
                std::fabs(dot(v_ca, v_cb)) < EPS) {
                std::cout << "siku-siku" << std::endl;
                return;
            }

            // Sama kaki: tepat dua sisi sama panjang
            if (std::fabs(ab - bc) < EPS ||
                std::fabs(bc - ca) < EPS ||
                std::fabs(ab - ca) < EPS) {
                std::cout << "sama kaki" << std::endl;
                return;
            }

            // Sembarang
            std::cout << "sembarang" << std::endl;
        }
};

#endif
