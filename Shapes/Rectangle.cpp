#include "Rectangle.h"





void Rectangle::resize(double percentage)
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

void Rectangle::draw(canvas &canvas)
{
    ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[0], corners[1]); 
    ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[1], corners[2]); 
    ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[2], corners[3]); 
    ascii::DrawLine(canvas, m_brush, m_fgColor, m_bgColor, corners[3], corners[0]);    
}


void Rectangle::recalculateCenter() 
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