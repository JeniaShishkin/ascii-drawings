#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "ObjectBase.h"
#include "Rectangle.h"
#include "Point.h"
#include <array>


class Square : public Rectangle
{
public:
    explicit Square(char brush, color fgColor, color bgColor, Point topLeftCorner, int size)
        : Rectangle(brush, fgColor, bgColor, topLeftCorner, size, size) { }
    ~Square() = default;

private:
    Point m_center;
    std::array<Point, 4> corners;
};


#endif