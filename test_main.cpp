#include "ascii/canvas.hpp"
#include "ascii/canvas_inl.hpp"
#include "ascii/colored_canvas.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "Shapes/Circle.h"
#include "Shapes/Point.h"

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
//    test_circle.move(0,3);
    test_circle.changeBgColor(ascii::ColoredCanvas::GREEN);
    test_circle.draw(test_canvas);
    test_canvas.Print(std::cout);



    return 0;
}