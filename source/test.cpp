#include <stdio.h>
#include <iostream>

#include "test.hpp"
#include "text_canvas.hpp"
#include "terminal_abstraction.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    cout << endl << "Reprinting null terminated command line inputs, each on a separate line:" << endl; 
    for(int i=0; i<argc; ++i){
        cout << endl << "argv[" << i << "] =" << endl;
        PrintNullTerminatedString(argv[i]);
        cout << endl;
    }
    cout << endl << "End of inputs." << endl << endl;

    cout << "Testing getter for number of terminal rows and columns:" << endl;
    cout << "Terminal is " << get_terminal_rows() << " rows by " << get_terminal_columns() << " columns" << endl;

    cout << "Initializing main canvas and test tile:" << endl;
    TextCanvas main_canvas;
    TextCanvas::TextTile test_tile(
        TextCanvas::Point(0),
        get_terminal_rows(),
        get_terminal_columns()-1
    );
    main_canvas.active_tiles.push_back(&test_tile);
    cout << "Main canvas tile has " << main_canvas.active_tiles[0]->get_num_columns() << " columns" << endl;

    cout << "Printing blank test tile:" << endl;
    test_tile.print();
    cout << endl;

    cout << "Filling with period character and printing:" << endl;
    test_tile.fill('.');
    test_tile.print();
    cout << endl;

    cout << "Filling columns with digits and printing:" << endl;
    test_tile.column_num_fill();
    test_tile.print();
    cout << endl;

    cout << "Filling rows with digits and printing:" << endl;
    test_tile.row_num_fill();
    test_tile.print();
    cout << endl;

    test_tile.fill(' ');
    size_t num_rows = test_tile.get_num_rows();
    size_t num_columns = test_tile.get_num_columns();
    for(size_t current_row=0; current_row < num_rows; ++current_row){
        test_tile.row_fill(current_row, '-');
        test_tile.print();
        test_tile.row_fill(current_row, ' ');
    }

    for(size_t current_column=0; current_column < num_columns; ++current_column){
        test_tile.column_fill(current_column, '|');
        test_tile.print();
        test_tile.column_fill(current_column, ' ');
    }

    return 0;
}

inline void PrintNullTerminatedString(const char* nullTerminatedString){
    size_t i = 0;
    while(nullTerminatedString[i] != '\0'){
        printf("%c", nullTerminatedString[i++]);
    }
    return;
}