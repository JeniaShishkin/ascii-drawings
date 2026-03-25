#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "ObjectBase.h"
#include <array>

class Rectangle : public ObjectBase
{
public:
    Rectangle() = delete;
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
    virtual void draw(canvas &canvas) override;
    virtual void resize(double percentage) override;
    virtual void rotate(Point rotationCenter, double degrees) { // RotationCenter point isn's used in this case, as we rotate 
                        for (auto& corner : corners)            // along the center of the rectangle.
                        { corner.RotateAround(m_center.GetX(), m_center.GetY(), degrees); } }                   
                                            
    void recalculateCenter();
    ~Rectangle() = default;

protected:
    Point m_center;
    std::array<Point, 4> corners;
};


#endif