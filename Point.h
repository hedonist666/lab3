#pragma once

class Point {
public:
    int x;
    int y;
    Point();
    Point(int, int);
    Point operator+=(int);
    Point operator+=(const Point&);
    friend Point operator-=(Point&, Point&);
    friend Point operator-=(Point&, int);

    Point operator+(int);
    Point operator+(const Point&);
    friend Point operator-(Point&, int);
    friend Point operator-(Point&, const Point&);

    Point operator+();
    Point operator-();
};


Point operator+(int, Point&);
Point operator-(int, Point&);
