#include <iostream>
using namespace std;
# include "minima.h"
#define hello__world \
    do { \
        cout << "Hello world"; \
    } while(0)

int main() {
    hello__world; // Corrected function call
    cout<<minima(87,12);
    return 0;
}