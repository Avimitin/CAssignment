int Less(int *x, int *y);
void Exch(int *x, int *y);
extern void InsertionSort(int length, int *array);

// Insertion sort, change array directly;
void InsertionSort(int length, int *array){
    for (int i = 0; i < length; i++){
        for (int j = i; j > 0; j--) {
            int *x = array + j;
            int *y = array + j - 1;
            if (Less(x, y)) {
                Exch(x, y);
            }
        }
    }
}

