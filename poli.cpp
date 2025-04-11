#include <iostream>
#include <cmath>
using namespace std;

// Класс ТОЧКА
class Point {
protected:
    float x, y, z;
public:
    Point(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    virtual void print() const {
        cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    void setX(float nx) { x = nx; }
    void setY(float ny) { y = ny; }
    void setZ(float nz) { z = nz; }
};

// Класс ОТРЕЗОК (наследуется от Point)
class Segment : public Point {
protected:
    Point end;

public:
    Segment(Point start = Point(), Point end = Point())
        : Point(start.getX(), start.getY(), start.getZ()), end(end) {}

    Segment(Point start, float length, float azi, float nakl)
        : Point(start.getX(), start.getY(), start.getZ()) {
        // Рассчитываем координаты конца отрезка на основе длины, азимута и наклона
        float x2 = start.getX() + length * cos(azi) * cos(nakl);
        float y2 = start.getY() + length * sin(azi) * cos(nakl);
        float z2 = start.getZ() + length * sin(nakl);
        end = Point(x2, y2, z2);
    }

    virtual void print() const override {
        cout << "Segment from ";
        Point::print();
        cout << "       to ";
        end.print();
    }

    float length() const {
        return sqrt(pow(end.getX() - x, 2) + pow(end.getY() - y, 2) + pow(end.getZ() - z, 2));
    }

    Point getEnd() const { return end; }
    void setEnd(Point p) { end = p; }
};

// Класс ПРЯМОУГОЛЬНИК (наследуется от Segment)
class Rectangle : public Segment {
protected:
    Point corner2, corner3;

public:
    Rectangle(Point p1, Point p2, Point p3)
        : Segment(p1, p2), corner2(p2), corner3(p3) {}

    virtual void print() const override {
        cout << "Rectangle corners:" << endl;
        Point::print();
        corner2.print();
        corner3.print();
        end.print();
    }

    float area() const {
        float a = sqrt(pow(corner2.getX() - x, 2) + pow(corner2.getY() - y, 2) + pow(corner2.getZ() - z, 2));
        float b = sqrt(pow(corner3.getX() - x, 2) + pow(corner3.getY() - y, 2) + pow(corner3.getZ() - z, 2));
        return a * b;
    }
};

// Класс ПАРАЛЛЕЛЕПИПЕД (наследуется от Rectangle)
class Parallelepiped : public Rectangle {
protected:
    Point fourthCorner;

public:
    Parallelepiped(Point p1, Point p2, Point p3, Point p4)
        : Rectangle(p1, p2, p3), fourthCorner(p4) {}

    virtual void print() const override {
        cout << "Parallelepiped corners:" << endl;
        Point::print();
        corner2.print();
        corner3.print();
        fourthCorner.print();
    }

    float volume() const {
        float a = sqrt(pow(corner2.getX() - x, 2) + pow(corner2.getY() - y, 2) + pow(corner2.getZ() - z, 2));
        float b = sqrt(pow(corner3.getX() - x, 2) + pow(corner3.getY() - y, 2) + pow(corner3.getZ() - z, 2));
        float c = sqrt(pow(fourthCorner.getX() - x, 2) + pow(fourthCorner.getY() - y, 2) + pow(fourthCorner.getZ() - z, 2));
        return a * b * c;
    }
};



int main() {
    Point p1(0, 0, 0);
    Point p2(3, 0, 0);
    Point p3(0, 4, 0);
    Point p4(0, 0, 5);

    Parallelepiped box(p1, p2, p3, p4);

    box.print();
    cout << "Volume: " << box.volume() << endl;

    return 0;
}
