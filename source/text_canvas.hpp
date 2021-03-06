#include <string>
#include <vector>

using std::string;
using std::vector;

class TextCanvas {
    public:
    class Point {
        public:
        size_t column = 0;
        size_t row = 0;

        Point(const size_t coordinate_value);
        Point(
            const size_t column,
            const size_t row
        );

        bool operator<(const Point &right_hand_side);
    };

    class TextTile {
        protected:
        Point min = 0;
        size_t num_columns = 0;
        size_t layer_depth = 0;
        string data;
        vector<bool> visible_chars;

        public:
        TextTile(
            Point min,
            const size_t square_dimension
        );
        TextTile(
            Point min,
            const size_t num_rows,
            const size_t num_columns
        );

        char* operator[](const size_t row);

        size_t get_num_rows();
        size_t get_num_columns();

        void fill(const char fill_char);
        void row_fill(
            const size_t column_number,
            const char fill_char
        );
        void column_fill(
            const size_t column_number,
            const char fill_char
        );

    void add_border();

        void column_num_fill();
        void row_num_fill();
        void print();
    };

    vector<TextTile*> active_tiles;
    vector<TextTile> layers;
    TextCanvas(){}
};