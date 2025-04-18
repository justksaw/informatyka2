#include <iostream>
#include "geometry.h"
#include <cmath>

using namespace std;

double distance(point A, point B) 
{
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

bool is_triangle(point A, point B, point C) 
{
    double area = 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    return area > 0;
}

double area_triangle(point A, point B, point C) {
    return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

}

double area_polygon(point P[], int n) {
    double area = 0;
    for (int i = 0; i < n; i++) 
    {
        int j = (i + 1) % n;
        area += P[i].x * P[j].y - P[j].x * P[i].y;
    }
    return fabs(area) / 2.0;
}

bool is_inside(point A, point B, point C, point D) {
    double area_ABC = area_triangle(A, B, C);
    
    double area_ABD = area_triangle(A, B, D);
    
    double area_BCD = area_triangle(B, C, D);
    
    double area_CDA = area_triangle(C, A, D);
    
    return (area_ABC == area_ABD + area_BCD + area_CDA);
}