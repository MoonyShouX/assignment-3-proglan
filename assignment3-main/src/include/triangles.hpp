/* 
Anda diminta untuk mengimplementasikan class dengan nama Triangle 
yang didalamnya memuat 3 data dalam class Point2D yang telah diimplementasikan

Tujuan dari program adalah menentukan apakah suatua Triangle adalah 
sama kaki, sama sisi, siku-siku, dan sembarang

Input:
    vector dari suatu Triangle (dengan banyak sebesar 3*N) --> N = total Triangle

Output
    print setiap line dengan "sama kaki", "sama sisi", "siku-siku", atau "sembarang"


Silahkan gunakan teori dan implementasi yang telah diajarkan dikelas
*/

class Triangle {
    private:
        Point2D _t1, _t2, _t3;
    
    public:
        Triangle();
        Triangle(Point2D t1, Point2D t2, Point2D t3);
        
        void SetT1(Point2D t1);
        void SetT2(Point2D t2);
        void SetT3(Point2D t3);
    
        Point2D GetT1() const { return _t1; }
        Point2D GetT2() const { return _t2; }
        Point2D GetT3() const { return _t3; }
    
        void TriangleType(); 
};
