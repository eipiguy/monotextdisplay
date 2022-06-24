#include "test.hpp"

int main(int argc, char* argv[]){
    cout << endl << "Reprinting null terminated command line inputs, each on a separate line:" << endl; 
    for(int i=0; i<argc; ++i){
        cout << endl << "argv[" << i << "] =" << endl;
        PrintNullTerminatedString(argv[i]);
        cout << endl;
    }
    cout << endl << "End of inputs." << endl;
    cout << endl;
    cout << "Initializing main canvas and test tile:" << endl;
    TextCanvas main_canvas;

    TextCanvas::TextTile test_tile(TextCanvas::Point(0), 48);
    main_canvas.active_tiles.push_back(&test_tile);
    cout << "Main canvas tile has " << main_canvas.active_tiles[0]->get_num_columns() << " columns" << endl;

    cout << "Printing blank test tile from (0,0) to (48,48)" << endl;
    test_tile.print();

    test_tile.fill('.');
    test_tile.print();

    return 0;
}

inline void PrintNullTerminatedString(const char* nullTerminatedString){
    size_t i = 0;
    while(nullTerminatedString[i] != '\0'){
        printf("%c", nullTerminatedString[i++]);
    }
    return;
}