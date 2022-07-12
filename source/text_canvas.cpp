#include <iostream>

#include "text_canvas.hpp"
#include "terminal_abstraction.hpp"

using std::cout;
using std::clog;
using std::endl;

// Point

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

// TextTile

TextCanvas :: TextTile :: TextTile(
    const Point min,
    const size_t square_dimension
):
min(min), num_columns(square_dimension){
    size_t length = square_dimension * square_dimension;
    data = string(length, ' ');
    visible_chars = vector<bool>(length, true);
}

TextCanvas :: TextTile :: TextTile(
    Point min,
    const size_t num_rows,
    const size_t num_columns
):
min(min), num_columns(num_columns){
    size_t length = num_columns * num_rows;
    data = string(length, ' ');
    visible_chars = vector<bool>(length, true);
}

// ====

char* TextCanvas :: TextTile :: operator[](const size_t row){
    return &data[row*num_columns];
}

size_t TextCanvas :: TextTile :: get_num_rows(){
    return data.length() / num_columns;
}

size_t TextCanvas :: TextTile :: get_num_columns(){
    return num_columns;
}

// ====

void TextCanvas :: TextTile :: fill(const char fill_char){
    for(char &data_char : data){
        data_char = fill_char;
    }
}

void TextCanvas :: TextTile :: row_fill(
    const size_t row_number,
    const char fill_char
){
    //clog << "row number = " << row_number << ", num columns = " << num_columns << endl;
    size_t start_id = row_number*num_columns;
    size_t end_id = start_id + num_columns;
    for(size_t i=start_id; i<end_id; ++i){
        data[i] = fill_char;
    }
}

void TextCanvas :: TextTile :: column_fill(
    const size_t column_number,
    const char fill_char
){
    size_t num_rows = get_num_rows();
    //clog << "num rows = " << num_rows << ", num columns = " << num_columns << endl;
    //clog << "column number = " << column_number << endl;
    for(size_t i=column_number; i<data.length(); i+=num_columns){
        data[i] = fill_char;
    }
}

// ====

void TextCanvas :: TextTile :: add_border(){

}

// ====

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

// ====

void TextCanvas :: TextTile :: print(){
    //std::clog << "num_columns = " << num_columns << endl;
    for(size_t i=0; i<data.length(); i+=num_columns){
        //std::clog << "i = " << i << ", num_columns = " << num_columns << endl;
        cout << data.substr(i,num_columns) << endl;
    }
}