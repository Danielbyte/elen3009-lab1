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

    return 0;
}

