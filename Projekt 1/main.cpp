#include <random>
#include "console.h"

#define TESTS   1000000

int main()
{
    int val;
    int min = INT_MAX;
    int max = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000000);

    for (int i = 0; i < TESTS; i++) {
        val = dist(gen);
        if (val < min)
            min = val;
        if (val > max)
            max = val;
    }

    Message mess;

    mess.show();

    return 0;
}


