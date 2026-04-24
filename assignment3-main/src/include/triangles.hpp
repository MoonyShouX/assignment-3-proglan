#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "point2d.hpp"
#include <iostream>
#include <cmath>

class Triangle {
    private:
        Point2D _t1, _t2, _t3;

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
            float ab = _t1.distanceTo(_t2);
            float bc = _t2.distanceTo(_t3);
            float ca = _t3.distanceTo(_t1);

            const float EPS = 1e-4f;

            // Sama sisi: ketiga sisi sama
            if (std::fabs(ab - bc) < EPS && std::fabs(bc - ca) < EPS) {
                std::cout << "sama sisi" << std::endl;
                return;
            }

            // Cek siku-siku via dot product pada setiap sudut
            // Vektor dari tiap titik ke dua titik lainnya
            Point2D v_ab(_t2.GetX()-_t1.GetX(), _t2.GetY()-_t1.GetY(), _t2.GetZ()-_t1.GetZ());
            Point2D v_ac(_t3.GetX()-_t1.GetX(), _t3.GetY()-_t1.GetY(), _t3.GetZ()-_t1.GetZ());
            Point2D v_ba(_t1.GetX()-_t2.GetX(), _t1.GetY()-_t2.GetY(), _t1.GetZ()-_t2.GetZ());
            Point2D v_bc(_t3.GetX()-_t2.GetX(), _t3.GetY()-_t2.GetY(), _t3.GetZ()-_t2.GetZ());
            Point2D v_ca(_t1.GetX()-_t3.GetX(), _t1.GetY()-_t3.GetY(), _t1.GetZ()-_t3.GetZ());
            Point2D v_cb(_t2.GetX()-_t3.GetX(), _t2.GetY()-_t3.GetY(), _t2.GetZ()-_t3.GetZ());

            bool isRight = std::fabs(v_ab.dot(v_ac)) < EPS ||
                           std::fabs(v_ba.dot(v_bc)) < EPS ||
                           std::fabs(v_ca.dot(v_cb)) < EPS;

            if (isRight) {
                std::cout << "siku-siku" << std::endl;
                return;
            }

            // Sama kaki: tepat dua sisi sama
            bool isIsosceles = std::fabs(ab - bc) < EPS ||
                               std::fabs(bc - ca) < EPS ||
                               std::fabs(ab - ca) < EPS;

            if (isIsosceles) {
                std::cout << "sama kaki" << std::endl;
                return;
            }

            std::cout << "sembarang" << std::endl;
        }
};

#endif
