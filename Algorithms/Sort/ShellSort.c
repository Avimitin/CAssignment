int Less(int *x, int *y);
void Exch(int *x, int *y);
extern void ShellSort(int length, int *array);

/**
    Use insertion sort to sort split array.
    Because insertion sort only change the number beside,
    if it meet a array whose min value is set in the last position.
    It will take n-1 times for changing it to the front.
    For quicker exchange, sort the array in some duration.
    And finally decrease the duration to 1 to sort all the array.
*/
void ShellSort(int length, int *array) {
    int h = 1;
    
    // Increase h;
    while (h < length/3) { h = 3*h +1; }

    // Make array sorted in length h;
    while (h >= 1) {
        // Let start position at h. h will decrease to 1 finally.
        for (int i = h; i < length; i++) {
            // And sort all the number in h duration.
            for (int j = i; j >= h; j-=h) {
                int *x = array + j;
                int *y = array + j - h;
                if (Less(x, y)) {
                    Exch(x, y);
                }
            }
        }
        // decrease duration.
        h /= 3;
    }

}