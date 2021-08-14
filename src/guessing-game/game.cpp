#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand(time(0));
    auto counter = 1;
    auto number = 1 + (rand() % 6);
    while (counter <= 5)
    {
        int guess;
        cout << "enter guess: ";
        cin >> guess;
        if (guess > number && counter < 5){cout << "guess lower." <<endl;}
        else if ((guess < number) && counter < 5) {cout << "guess higher." <<endl;}
        else if (guess == number && counter < 5) {cout << "you won!" << endl;break;}
        if (counter == 5){cout << "you lost!" << endl;}
        counter++;

    }

    return 0;

}
