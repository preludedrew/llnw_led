// Small example how to use the library.
// For more examples, look at demo-main.cc
//
#include "led-matrix.h"
#include "led_chars.h"
#include "threaded-canvas-manipulator.h"

#include <unistd.h>
#include <math.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <pthread.h>

using namespace std;
using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;
using rgb_matrix::ThreadedCanvasManipulator;

class NumberCanvas : public ThreadedCanvasManipulator {
public:
    int maxDays;
    int daysSince;
    NumberCanvas(Canvas *m, int max, int since) : ThreadedCanvasManipulator(m), max_(max), since_(since) {
        maxDays = max;
        daysSince = since;
    }
    void Run() {
    }

static void DrawNumber(Canvas *canvas, int days) {
    string Result;
    ostringstream convert;
    convert << days;
    Result = convert.str();
    int len = Result.length();
    // Convert num to string
    printf("You have chosen: %d\n", days);
    printf("The length of this number: %d\n", len);


    // Set colors based on days
    int r,g,b = 0;
    if (days <= 20) {
        r = 255;
        g = 0;
        b = 0;
    } else if (days < 50 && days > 20) {
        r = 255;
        g = 255;
        b = 0;
    } else if (days > 999) {
        days = 999;
        r = 255;
        g = 0;
        b = 0;
    } else {
        r = 0;
        g = 255;
        b = 0;
    }

    for (int i = 0; i < len; i++) {
        /* Set the offset we'll use for the characters position */
        int offset = 0;
        switch (i) {
            case 1:
                offset = 11;
                break;
            case 2:
                offset = 22;
                break;
        }

       /* Modify the offset, depending on how many characters there are.
        * This allows them to be right justified.
        */
        switch (len) {
            case 1:
                offset += 22;
                break;
            case 2:
                offset += 11;
                break;
        }

        if (Result.substr(i, 1) == "0") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_ZERO[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "1") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_ONE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "2") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_TWO[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "3") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_THREE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "4") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_FOUR[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "5") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_FIVE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "6") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_SIX[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "7") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_SEVEN[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "8") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_EIGHT[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "9") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_NINE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        }
    }
}

static void DrawSecondNumber(Canvas *canvas, int days) {
    string Result;          // string which will contain the result
    ostringstream convert;   // stream used for the conversion
    convert << days;      // insert the textual representation of 'Number' in the characters in the stream
    Result = convert.str(); // set 'Result' to the contents of the stream
    int len = Result.length();
    // Convert num to string
    printf("You have chosen: %d\n", days);
    printf("The length of this number: %d\n", len);


    // Set colors based on days
    int r,g,b = 0;
    if (days <= 20) {
        r = 255;
        g = 0;
        b = 0;
    } else if (days < 50 && days > 20) {
        r = 255;
        g = 255;
        b = 0;
    } else if (days > 999) {
        days = 999;
        r = 255;
        g = 0;
        b = 0;
    } else {
        r = 0;
        g = 255;
        b = 0;
    }

    for (int i = 0; i < len; i++) {
        /* Set the offset we'll use for the characters position */
        int offset = 32;
        switch (i) {
            case 1:
                offset += 11;
                break;
            case 2:
                offset += 22;
                break;
        }

       /* Modify the offset, depending on how many characters there are.
        * This allows them to be right justified.
        */
        switch (len) {
            case 1:
                offset += 22;
                break;
            case 2:
                offset += 11;
                break;
        }

        if (Result.substr(i, 1) == "0") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_ZERO[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "1") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_ONE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "2") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_TWO[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "3") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_THREE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "4") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_FOUR[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "5") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_FIVE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "6") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_SIX[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "7") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_SEVEN[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "8") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_EIGHT[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        } else if (Result.substr(i,1) == "9") {
            for ( int y = 0; y < 10; y++ ) {
                for ( int x = 0; x < 16; x++ ) { 
                    if (CHAR_NINE[x][y] == 1) {
                        canvas->SetPixel(y + offset, x, r, g, b);
                    }
                }
            }
        }
    }
}

};



int main(int argc, char *argv[]) {
    bool debug_mode = true; 
    int since = 0;
    int max = 0;

    int opt;
    while ((opt = getopt(argc, argv, "ds:m:")) != -1) {
        switch (opt) {
            case 'd':
                debug_mode = true;
                break;
            case 's':
                since = atoi(optarg);
                break;
            case 'm':
                max = atoi(optarg);
                break;
        }
    }

    if (argc > 0) {
        //Print help message, arguments are necessary
    }

    /*
     * Set up GPIO pins. This fails when not running as root.
     */
    GPIO io;
    if (!io.Init())
        return 1;

    // Start daemon before we start any threads.
    if (!debug_mode) {
        if (fork() != 0)
            return 0;
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
    }

    /*
     * Set up the RGBMatrix. It implements a 'Canvas' interface.
     */
    int rows = 16;   // A 32x32 display. Use 16 when this is a 16x32 display.
    int chain = 2;   // Number of boards chained together.
    RGBMatrix *matrix = new RGBMatrix(&io, rows, chain);
    Canvas *canvas = matrix;

    ThreadedCanvasManipulator *image_gen = NumberCanvas(canvas, max, since);
    image_gen->Start();

    // Sleep forever!!!
    while (true) {
        usleep(1);
    }
    // Animation finished. Shut down the RGB matrix.
    canvas->ClearScreen();
    delete image_gen;
    delete canvas;

    return 0;
}
