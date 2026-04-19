#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

class Point2D {
    private:
        float _x, _y, _z;

    public:
        Point2D();
        Point2D(float x, float y, float z);

        float GetX() const { return _x; };
        float GetY() const { return _y; };
        float GetZ() const { return _z; };

        inline void SetX(float x) { _x = x; }
        inline void SetY(float y) { _x = y; }
        inline void SetZ(float z) { _x = z; }

        Point2D operator+(const Point2D inp);
        Point2D operator-(const Point2D inp);
        Point2D operator*(const Point2D inp);
};

#endif 
