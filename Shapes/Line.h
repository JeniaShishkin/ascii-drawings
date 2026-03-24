#ifndef __Line_H__
#define __Line_H__
#include "ObjectBase.h"

class Line : public ObjectBase
{
private:
  
    explicit Line(char brush, color fgColor, color bgColor, Point start, Point end) 
                        : m_start(start), m_end(end), ObjectBase(brush, fgColor, bgColor) { }
    virtual void move(int dx, int dy) override { m_start.MoveBy(dx, dy); m_end.MoveBy(dx, dy); }
    virtual void draw(canvas &canvas) override { ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, m_start, m_end); }
    virtual void rotate(Point rotationCenter, double degrees)override { 
                        m_start.RotateAround(rotationCenter.GetX(), rotationCenter.GetY(), degrees) ; 
                        m_end.RotateAround(rotationCenter.GetX(), rotationCenter.GetY(), degrees); }

    virtual void resize(double percentage) override
{
    double scale = 1.0 + percentage / 100.0;

    int centerX = (m_start.GetX() + m_end.GetX()) / 2;
    int centerY = (m_start.GetY() + m_end.GetY()) / 2;

    auto scalePoint = [&](Point& p)
    {
        double dx = p.GetX() - centerX;
        double dy = p.GetY() - centerY;

        int newX = static_cast<int>(centerX + dx * scale);
        int newY = static_cast<int>(centerY + dy * scale);

        p = Point(newX, newY);
    };

    scalePoint(m_start);
    scalePoint(m_end);
}
    ~Line() = default;
public:

    Point m_start;
    Point m_end;
};



#endif