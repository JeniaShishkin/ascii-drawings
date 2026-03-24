#ifndef __Line_H__
#define __Line_H__
#include "ObjectBase.h"

class Line : public ObjectBase
{
public:
    explicit Line(char brush, color fgColor, color bgColor, Point start, Point end) 
                : m_start(start), m_end(end), ObjectBase(brush, fgColor, bgColor) { }
    ~Line() = default;
    virtual void move(int dx, int dy) override { m_start.MoveBy(dx, dy); m_end.MoveBy(dx, dy); }
    virtual void draw(canvas &canvas) override { ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, m_start, m_end); }
    virtual void rotate(Point rotationCenter, double degrees) override { 
                        m_start.RotateAround(rotationCenter.GetX(), rotationCenter.GetY(), degrees) ; 
                        m_end.RotateAround(rotationCenter.GetX(), rotationCenter.GetY(), degrees); }
    virtual void resize(double percentage) override;



private:

    Point m_start;
    Point m_end;
};



#endif