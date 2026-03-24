#include "Line.h"


void Line::resize(double percentage)
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