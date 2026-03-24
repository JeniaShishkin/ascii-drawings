#include "ascii/canvas.hpp"
#include "ascii/canvas_inl.hpp"
#include "ascii/colored_canvas.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    /*ascii::ColoredCanvas c{60, 17};
	c(0, 0) = '0';
	c(1, 0) = '1';
	c(0, 10) = '1';
	c(1, 10) = '1';
	c(9, 9) = 'x';
	c(10, 10) = 'x';
	c(11, 11) = 'x';
	c.Print(std::cout);
	return 0;*/
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

    ascii::ColoredCanvas canvas{gridNumbers};
    ascii::DrawCircle(canvas, '*', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::YELLOW, ascii::Point(7, 7), 7);
    ascii::DrawLine(canvas, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(15, 7), ascii::Point(40, 7));
    ascii::DrawLine(canvas, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(40, 7), ascii::Point(55, 0));
    ascii::DrawLine(canvas, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(40, 7), ascii::Point(55, 14));
    ascii::DrawCircle(canvas, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(4, 4), 1);
    ascii::DrawCircle(canvas, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(5, 4), 1);
    ascii::DrawCircle(canvas, 'o', ascii::ColoredCanvas::BLUE, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(6, 4), 1);
    ascii::DrawCircle(canvas, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(4, 9), 1);
    ascii::DrawCircle(canvas, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(5, 9), 1);
    ascii::DrawCircle(canvas, 'o', ascii::ColoredCanvas::BLUE, ascii::ColoredCanvas::TERMINAL_COLOR, ascii::Point(6, 9), 1);
    ascii::DrawLine(canvas, '@', ascii::ColoredCanvas::BLACK, ascii::ColoredCanvas::WHITE, 20, 6, 27, 0);
    ascii::DrawLine(canvas, '@', ascii::ColoredCanvas::BLACK, ascii::ColoredCanvas::WHITE, 20, 8, 27, 14);
	canvas(0, 0) = '+';

    ascii::ColoredCanvas canvas2{gridNumbers};
    //canvas2 = canvas2orig;
    ascii::DrawCircle(canvas2, '*', ascii::ColoredCanvas::MAGENTA, ascii::ColoredCanvas::YELLOW, ascii::Point(7, 7), 7);
    ascii::DrawLine(canvas2, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(15, 7), ascii::Point(40, 7));
    ascii::DrawLine(canvas2, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(40, 7), ascii::Point(55, 0));
    ascii::DrawLine(canvas2, '#', ascii::ColoredCanvas::TERMINAL_COLOR, ascii::ColoredCanvas::WHITE, ascii::Point(40, 7), ascii::Point(55, 14));
    ascii::DrawCircle(canvas2, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, 3, 4, 1);
    ascii::DrawCircle(canvas2, 'O', ascii::ColoredCanvas::CYAN, ascii::ColoredCanvas::BLUE, 4, 4, 1);
    ascii::DrawCircle(canvas2, 'O', ascii::ColoredCanvas::CYAN, ascii::ColoredCanvas::BLUE, 5, 4, 1);
    ascii::DrawCircle(canvas2, '#', ascii::ColoredCanvas::RED, ascii::ColoredCanvas::TERMINAL_COLOR, 3, 9, 1);
    ascii::DrawCircle(canvas2, 'O', ascii::ColoredCanvas::CYAN, ascii::ColoredCanvas::BLUE, 4, 9, 1);
    ascii::DrawCircle(canvas2, 'O', ascii::ColoredCanvas::CYAN, ascii::ColoredCanvas::BLUE, 5, 9, 1);
    ascii::DrawLine(canvas2, '@', ascii::ColoredCanvas::BLACK, ascii::ColoredCanvas::WHITE, 20, 6, 13, 0);
    ascii::DrawLine(canvas2, '@', ascii::ColoredCanvas::BLACK, ascii::ColoredCanvas::WHITE, 20, 8, 13, 14);
	canvas2(0, 0) = 'x';

    while (true) {
        //for (int i = 0 ; i < 10 ; ++i) {
        //    std::cout << std::endl << std::endl;
        //}
        canvas.Print(std::cout);
        std::this_thread::sleep_for(1000ms);

        //for (int i = 0 ; i < 10 ; ++i) {
        //    std::cout << std::endl << std::endl;
        //}
        canvas2.Print(std::cout);
        std::this_thread::sleep_for(1000ms);
    }
}
