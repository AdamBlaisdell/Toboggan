// Adam Blaisdell
// 12/04/2020

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int findtrees(char (*arr)[31], int right, int down); // prototype

int main()
{
    // format output
    cout.setf(ios_base::fixed);
    std::cout.precision(0);

    // open file
    ifstream file;
    file.open("Text.txt");

    // create array
    char patternarray[323][31];

    // populate array with pattern
    for (int r = 0; r < 323; r++)
    {
        for (int c = 0; c < 31; c++)
        {
            file >> patternarray[r][c];
        }
    }

    // call function to find trees
    double a = findtrees(patternarray, 1, 1);
    double b = findtrees(patternarray, 3, 1);
    double c = findtrees(patternarray, 5, 1);
    double d = findtrees(patternarray, 7, 1);
    double e = findtrees(patternarray, 1, 2);
    double product = a * b * c * d * e;

    // print results
    cout << "The number of trees for (1,1) is: " << a << endl;
    cout << "The number of trees for (3,1) is: " << b << endl;
    cout << "The number of trees for (5,1) is: " << c << endl;
    cout << "The number of trees for (7,1) is: " << d << endl;
    cout << "The number of trees for (1,2) is: " << e << endl;
    cout << "The number of trees multiplied together is: " << product << endl;
}

// functiont hat finds the number of trees
int findtrees(char (*arr)[31], int right, int down) {

    // starting file of char to check
    int j = 0;

    // tree count
    int trees = 0;

    // loop that moves down "down" number of files
    for (int i = 0; i < 323; i += down)
    {
        // if character is a tree, add 1 to tree count
        if (arr[i][j] == '#') {
            trees += 1;
        }

        // loop that move to the right "right" number files
        for (int k = 0; k < right; ++k)
        {
            ++j;
            // if file position is longer than length of the line: return to front of line
            if (j > 30)
                j = 0;
        }
    }
    return trees;
}