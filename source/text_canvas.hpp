#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

using std::vector;

class TextCanvas {
    public:
    class Point {
        public:
        size_t column = 0;
        size_t row = 0;

        Point(const size_t coordinate_value):
            column(coordinate_value), row(coordinate_value){}

        Point(const size_t column_start, const size_t row_start):
            column(column_start), row(row_start){}
        
        bool operator<(const Point &right_hand_side);
    };

    class Window {
        protected:
        Point min = 0;
        Point max = 0;

        public:
        Window(Point point_in):
            min(point_in), max(point_in){}

        Window(Point min_in, Point max_in):
            min(min_in), max(max_in){}
        
        class TextTile;
    };

    vector<Window*> active_windows;
    TextCanvas(){}
};