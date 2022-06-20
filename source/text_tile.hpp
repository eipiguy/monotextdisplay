#include "text_canvas.hpp"

class TextCanvas :: Window :: TextTile {
    protected:
    const size_t num_chars = 0;
    const size_t num_columns = 0;
    char* data;

    public:
    TextTile(const size_t square_dimension):
        num_columns(square_dimension),
        num_chars(square_dimension * square_dimension){
            data = new char[num_chars];
    }
    TextTile(
        const size_t num_columns,
        const size_t num_rows
        ):
        num_columns(num_columns),
        num_chars(num_columns * num_rows){
            data = new char[num_chars];
    }
    ~TextTile(){
        delete[] data;
    }

    string operator[](const size_t row){
        char cur_row[num_columns] = {0};
        for(size_t column=0; column<num_columns; ++column){
            cur_row[column] = data[(row*num_columns) + column];
        }
        return cur_row;
    }

    void print(){
        size_t num_rows = num_chars/num_columns;
        for(size_t i=0; i<num_columns; ++i){
            cout << (*this)[i] << endl;
        }
    }
};