#include "text_canvas.hpp"

bool TextCanvas :: Point :: operator<(const Point &right_hand_side){
    if(row == right_hand_side.row){
        return column < right_hand_side.column;
    }
    return row < right_hand_side.row;
}