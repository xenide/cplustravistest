#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numWays(int numSteps) {

    static unordered_map <int,int> ways;

    if (numSteps == 1) {
        return 1;
    }
    else if (numSteps == 2) {
        return 2;
    }
    else if (numSteps == 3) {
        return 4;
    }

    if (ways.find(numSteps) == ways.end()) {
        int answer = numWays(numSteps-1) + numWays(numSteps-2) + numWays(numSteps-3);
        ways[numSteps] = answer;
    }

    return ways[numSteps];

    /* Bottom up approach

    static vector <int> table(numSteps + 1, -1);


    table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    table[3] = 4;

    for (int i = 4; i < numSteps + 1; ++i) {
        table[i] = table[i-1] + table[i-2] + table[i-3];
    }

    return table[numSteps];
    */
}

int main() {
    cout << numWays(50) << endl;
    return 0;
}