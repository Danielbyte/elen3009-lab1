// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

void draw_row (Screen& myScreen)
{
    for (auto i = 0; i < 11; i++)
    {
        if (i%2 == 0)
        {
            myScreen.set('*');
        }
        else
            myScreen.forward();
    }
}

void first_column (Screen& myScreen)
{
    for (auto i = 0; i < 6; i++)
    {

            if (i%2 != 0)
            {
                myScreen.set('*');
                // myScreen.down();
            }
            else
                myScreen.down();

    }
}

void last_row (Screen& myScreen)
{
    for (auto i = 0; i < 11; i++)
    {
        if (i%2 == 0)
        {
            myScreen.set('*');
        }
        else
            myScreen.back();
    }
}


int main()
{
    auto myScreen = Screen{6,6};

    myScreen.clear(' ');
    draw_row (myScreen);
    myScreen.home(); // reset cursor to top left corner
    first_column (myScreen);
    draw_row(myScreen);
    myScreen.down();
    myScreen.set('*');
    myScreen.down();
    last_row(myScreen);
    myScreen.display();

    // square creation
    myScreen.reSize(6, 6);
    myScreen.clear(' ');
    myScreen.create_square (1,1,4);
    myScreen.display();

    // This function can be implemented using the existing interface.
    // internal representation is not necessary. Only knowledge of
    // what this class does is needed which does not require the
    // internal interface.

    // A function like this does not really form part of the responsibilities
    // of the Screen object.
    // This is because this function only uses the functionality of the
    // Screen object to attain its functionality. It does not add any
    // functionality of the screen object.
    // This function is like client code.

    return 0;
}

