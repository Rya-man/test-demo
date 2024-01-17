#include <stdio.h>

// Function to move disks between towers
void towerOfHanoi(int numDisks, char fromRod, char toRod, char auxRod) {
    if (numDisks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    // Move (numDisks - 1) disks from 'fromRod' to 'auxRod' using 'toRod' as auxiliary
    towerOfHanoi(numDisks - 1, fromRod, auxRod, toRod);

    printf("Move disk %d from rod %c to rod %c\n", numDisks, fromRod, toRod);

    // Move the remaining disks from 'auxRod' to 'toRod' using 'fromRod' as auxiliary
    towerOfHanoi(numDisks - 1, auxRod, toRod, fromRod);
}

int main() {
    int numDisks = 6; // Change the number of disks as needed
    char fromRod = 'A', toRod = 'C', auxRod = 'B';

    printf("Tower of Hanoi solution for %d disks:\n", numDisks);
    towerOfHanoi(numDisks, fromRod, toRod, auxRod);

    return 0;
}
