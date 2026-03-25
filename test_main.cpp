#include "ascii/canvas.hpp"
#include "ascii/canvas_inl.hpp"
#include "ascii/colored_canvas.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "Shapes/Circle.h"
#include "Shapes/Square.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Line.h"
#include "Shapes/Point.h"
#include "Shapes/group.h"

int main()
{
	using namespace std::chrono_literals;

    ascii::ColoredCanvas gridNumbers{60, 17};
    for (size_t i = 0 ; i < gridNumbers.GetHeight() ; ++i) {
		if (i / 10)
		{
	        gridNumbers(gridNumbers.GetWidth() - 2, i) = '0' + (i / 10);
		}
		else
		{
			gridNumbers(gridNumbers.GetWidth() - 2, i) = '.';
		}
        gridNumbers(gridNumbers.GetWidth() - 1, i) = '0' + (i % 10);
    }
    for (size_t i = 0 ; i < gridNumbers.GetWidth() ; ++i) {
        gridNumbers(i, gridNumbers.GetHeight() - 2) = '0' + (i / 10);
        gridNumbers(i, gridNumbers.GetHeight() - 1) = '0' + (i % 10);
    }

    ascii::ColoredCanvas test_canvas{gridNumbers};
    Circle test_circle{'*', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::YELLOW, Point{5, 7}, 5};
    // Group group1{ { std::make_shared<Circle>('*', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::YELLOW, Point{5, 7}, 5 ) } };
    // Group group2{ { std::make_shared<Circle>('*', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::YELLOW, Point{25, 7}, 5 ) } };
    // Group group3 = group1 + group2;
    //Line line{'#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, Point{15, 7}, Point{40, 7}};
    //Rectangle rec{'#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, Point{15, 7}, 2, 5};
    Square sqr{'#', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::WHITE, Point{30, 7}, 5};
    //    test_circle.move(0,3);
//    test_circle.changeBgColor(ascii::ColoredCanvas::GREEN);
//    sqr.rotate(Point{0,0}, 90);
    //sqr.draw(test_canvas);
    sqr.resize(50);
    sqr.draw(test_canvas);
    sqr.draw(test_canvas);
//    line.resize(50);
    test_canvas.Print(std::cout);


    return 0;
}