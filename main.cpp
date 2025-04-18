#include <iostream>
#include "geometry.h"

using namespace std;

int main()
{
    point A = {1, 2};
    point B = {3, 4};
    cout << distance(A, B) << endl;

    point C = {4, 8};
    if (is_triangle(A, B, C))
        cout << "Istnieje trojkat z podanymi punktami, a jego pole to: " << area_triangle(A, B, C) << endl;
    else
    cout << "Nie istnieje taki trojkat." << endl;

    point P[5] = {{1, 2}, {3, 4}, {5, 4}, {7, -1}, {3, -2}};
    cout << "Pole wielokata to: " << area_polygon(P, 5) << endl;

    point D = {2, 5};
    if (is_inside(A, B, C, D))
    cout << "Punkt D znajduje sie w trojkacie.";
    else
    cout << "Punkt D nie znajduje sie w trojkacie.";

    return 0;
}