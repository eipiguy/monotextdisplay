#include <stdio.h>
#include <string>
#include <iostream>
#include "test.hpp"

using std::string;

inline void PrintNullTerminatedString(const char* nullTerminatedString);

int main(int argc, char* argv[]){
    cout << "Reprinting null terminated command line inputs, each on a separate line:" << endl; 
    for(int i=0; i<argc; ++i){
        cout << endl << "argv[" << i << "] =" << endl;
        PrintNullTerminatedString(argv[i]);
        cout << endl;
    }
    cout << endl << "End of inputs." << endl;
    cout << endl;
    cout << "Initializing main canvas and window:" << endl;
    TextCanvas main_canvas;
    TextCanvas::Window main_window(
        TextCanvas::Point(0),
        TextCanvas::Point(48)
    );

    main_canvas.active_windows.push_back(&main_window);

    return 0;
}

inline void PrintNullTerminatedString(const char* nullTerminatedString){
    size_t i = 0;
    while(nullTerminatedString[i] != '\0'){
        printf("%c", nullTerminatedString[i++]);
    }
    return;
}