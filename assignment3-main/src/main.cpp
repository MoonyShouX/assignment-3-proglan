#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangle.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;

    /*--------------------------------------------------
    Loop untuk menginputkan data triangle
    (3 titik, masing-masing berupa X Y Z) ke dalam triangles
    --------------------------------------------------*/
    for (int i = 0; i < n; i++) {
        cout << "\n--- Segitiga " << i + 1 << " ---\n";
        float x, y, z;

        cout << "Titik 1 (x y z): "; cin >> x >> y >> z;
        Point2D t1(x, y, z);

        cout << "Titik 2 (x y z): "; cin >> x >> y >> z;
        Point2D t2(x, y, z);

        cout << "Titik 3 (x y z): "; cin >> x >> y >> z;
        Point2D t3(x, y, z);

        triangles.push_back(Triangle(t1, t2, t3));
    }
    /*-------------------------------------------------*/

    /*--------------------------------------------------
    Pengecekan jenis setiap segitiga pada vector triangles
    --------------------------------------------------*/
    cout << "\n========= Hasil =========\n";
    for (int i = 0; i < (int)triangles.size(); i++) {
        cout << "Segitiga " << i + 1 << ": ";
        triangles[i].TriangleType();
    }
    /*-------------------------------------------------*/

    return 0;
}
