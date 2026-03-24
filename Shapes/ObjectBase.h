#ifndef __OBJECTBASE_H__
#define __OBJECTBASE_H__

#include "../ascii/colored_canvas.hpp"
#include "Point.h"

using canvas = ascii::ColoredCanvas;
using color = ascii::ColoredCanvas::Color;

// Pure virtual interface, cannot create an instance of it.
class ObjectBase 
{
public:

    constexpr explicit ObjectBase(char brush, color fgColor, color bgColor) 
                                : m_brush(brush), m_fgColor(fgColor), m_bgColor(bgColor) {}
    ObjectBase(const ObjectBase&) = delete;
    ObjectBase& operator=(const ObjectBase&) = delete;
    void setDrawingBrush(const char &newBrush) { m_brush = newBrush; }
    void changeFgColor(color newFgColor) { m_fgColor = newFgColor; }
    virtual void changeBgColor(color newBgColor) { m_bgColor = newBgColor; }
    void selectBrush(char newBrush) { m_brush = newBrush; }
    virtual void draw(canvas& canvas) = 0;
    virtual void move(int dx, int dy) = 0;
    virtual void resize(double percentage) = 0;
    virtual void rotate(Point rotationCenter, double degrees) = 0;
    virtual ~ObjectBase() = default;

protected:
    char m_brush;
    color m_fgColor;
    color m_bgColor;
};



#endif