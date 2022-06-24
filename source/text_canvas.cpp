#include "text_canvas.hpp"

TextCanvas :: Point :: Point(const size_t coordinate_value):
column(coordinate_value), row(coordinate_value){}

TextCanvas :: Point :: Point(const size_t column, const size_t row):
column(column), row(row){}

bool TextCanvas :: Point :: operator<(const Point &right_hand_side){
    if(row == right_hand_side.row){
        return column < right_hand_side.column;
    }
    return row < right_hand_side.row;
}

TextCanvas :: TextTile :: TextTile(
    Point min,
    const size_t square_dimension
):
min(min), num_columns(square_dimension){
    data = string(square_dimension * square_dimension, ' ');
}

TextCanvas :: TextTile :: TextTile(
    Point min,
    const size_t num_columns,
    const size_t num_rows
):
min(min), num_columns(num_columns){
    data = string(num_columns * num_rows, ' ');
}

string TextCanvas :: TextTile :: operator[](const size_t row){
    size_t row_start = row*num_columns;
    return data.substr(row_start, row_start+num_columns-1);
}

size_t TextCanvas :: TextTile :: get_num_columns(){
    return num_columns;
}

void TextCanvas :: TextTile :: fill(const char fill_char){
    for(char &data_char : data){
        data_char = fill_char;
    }
}

void TextCanvas :: TextTile :: column_num_fill(){
    size_t i = 0, j = 0;
    for(char &data_char : data){
        data_char = '0' + j++;
        if(++i >= num_columns){
            //clog << "column end. i = " << i << ", j = " << j << endl;
            i = 0;
            j = 0;
        }else if(j>9){
            j = 0;
        }
    }
}

void TextCanvas :: TextTile :: row_num_fill(){
    size_t i = 0, j = 0;
    for(char &data_char : data){
        data_char = '0' + j;
        if(++i >= num_columns){
            i = 0;
            if(++j > 9){
                j = 0;
            }
        }
    }
}

void TextCanvas :: TextTile :: print(){
    for(size_t i=0; i<data.length(); i+=num_columns){
        //clog << "i = " << i << ", num_columns = " << num_columns << endl;
        cout << data.substr(i,num_columns) << endl;
    }
}