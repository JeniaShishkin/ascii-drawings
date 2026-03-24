#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "ObjectBase.h"
#include "Point.h"


class Circle : public ObjectBase
{
    
public:

    explicit Circle(char brush, color fgColor, color bgColor, Point center, int radius) 
                : m_center(center), m_radius(radius), ObjectBase(brush, fgColor, bgColor) { }

    virtual void draw(canvas &canvas) override { ascii::DrawCircle(canvas, m_brush, m_fgColor, m_bgColor, m_center, m_radius); }
    virtual void move(int dx, int dy) override { m_center.MoveBy(dx, dy); }
    virtual void resize(double percentage) override { m_radius = std::max(1, int(m_radius * (1 + percentage / 100.0))); } 
    virtual void rotate(Point rotationCenter, double degrees) { } // rotation has no effect on a circle.
    ~Circle() = default;


private:

    Point m_center;
    int m_radius;


};



#endif