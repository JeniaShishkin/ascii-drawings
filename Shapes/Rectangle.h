#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "ObjectBase.h"
#include <array>

class Rectangle : public ObjectBase
{
private:
    explicit Rectangle(char brush, color fgColor, color bgColor, Point topLeftCorner, int width, int height)
        : ObjectBase(brush, fgColor, bgColor),
          m_center(topLeftCorner.GetX() + width / 2,topLeftCorner.GetY() + height / 2),
          corners{
              topLeftCorner,
              Point(topLeftCorner.GetX() + width, topLeftCorner.GetY()),
              Point(topLeftCorner.GetX() + width, topLeftCorner.GetY() + height),
              Point(topLeftCorner.GetX(), topLeftCorner.GetY() + height)
          } { }

    virtual void move(int dx, int dy) override {for (Point& corner : corners){ corner.MoveBy(dx,dy); recalculateCenter(); } }
    virtual void draw(canvas &canvas) override 
    {
        ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[0], corners[1]); 
        ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[1], corners[2]); 
        ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[2], corners[3]); 
        ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[3], corners[0]);

    }
    virtual void resize(double percentage) override 
    {
        double scale = 1.0 + percentage / 100.0;

        for (auto& c : corners)
        {
            double dx = c.GetX() - m_center.GetX();
            double dy = c.GetY() - m_center.GetY();

            int newX = static_cast<int>(m_center.GetX() + dx * scale);
            int newY = static_cast<int>(m_center.GetY() + dy * scale);

            c = Point(newX, newY);
        }
    }
    virtual void rotate(Point rotationCenter, double degrees) { // RotationCenter point isn's used in this case, as we rotate 
                        for (auto& corner : corners)            // along the center of the rectangle.
                        { corner.RotateAround(m_center.GetX(), m_center.GetY(), degrees); } }                   
                                            
    void recalculateCenter() 
    {
        int centerX = 0;
        int centerY = 0;
        // Calculate center point of the rectangle.
        for (const auto& corner : corners) 
        {
            centerX += corner.GetX();
            centerY += corner.GetY();
        }

        centerX /= 4;
        centerY /= 4;
        m_center = Point{centerX, centerY};
    }
    ~Rectangle() = default;

public:
    Point m_center;
    std::array<Point, 4> corners;
};


#endif