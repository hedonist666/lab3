#include "Point.h"


Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator+=(int v) {
    x += v;
    y += v;
    return *this;
}
// Point p(1, 2); // p.x == 1, p.y == 2
// p += 4; вызываем метод operator+= c аргументом 4 (v == 4), после этого p.x == 5, p.y == 6
// и в конце объект возвращает сам себя измененного. p +=4 внутри оператора this = &p;
// A тип у this это Point* 
// когда мы пишем *this это то же самое что *(&p), то есть p

Point Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}
// Point p1(1, 2);
// Point p2(4, 5);
// p1 += p2 // p1.x = 5, p1.y = 7, то есть мы вызываем метод operator+= с в котором other
// будет равно p2 
// а в конце так же объект возвращает себя (измененного)

/*
Point operator+=(Point& that, Point& other) {
   that.x += other.x;
   that.y += other.y;
   return that;
} 

// Point p1(1, 2);
// Point p2(4, 5);
// p1 += p2 // p1.x = 5, p1.y = 7, то есть мы вызываем функцию operator+= с в которой
// that это p1, а other это p2
// p1.x == 5, p1.y == 7
// а в конце так же объект возвращает себя (измененного)

Point operator+=(Point& that, int v) {
   that.x += v;
   that.y += v;
   return that;
}

// Point p(1, 2); // p.x == 1, p.y == 2
// p += 4; вызываем функцию operator+= с аргументами p и 4
// в конце возвращаем p (измененное) 
*/


Point operator-=(Point& that, Point& other) {
   that.x -= other.x;
   that.y -= other.y;
   return that;
} 

Point operator-=(Point& that, int v) {
   that.x -= v;
   that.y -= v;
   return that;
}


Point Point::operator+(int v) {
    Point res(x + v, y + v);
    return res;
}

Point Point::operator+(const Point& other) {
    Point res(x + other.x, y + other.y);
    return res;
}


Point operator-(Point& that, int v) {
    Point res(that.x - v, that.y - v);
    return res;
}

Point operator-(Point& that, const Point& other) {
    Point res(that.x - other.x, that.y - other.y);
    return res;
}

Point operator+(int v, Point& other) {
    return other + v;
}

Point operator-(int v, Point& other) {
    return other - v;
}

Point Point::operator+() {
    return *this;
}
Point Point::operator-() {
    Point res(-x, -y);
    return res;
}
