#include <iostream>

#define lmax 200

using namespace std;

int count_in_arr(int *arr, int len_arr, int el) {
    int count = 0;
    for (int *i = arr; i < arr + len_arr; i++) if (el == *i) count++;
    return count;
}

void print_arr(int *arr, int len_arr) {
    for (int *i = arr; i < arr + len_arr; i++) cout << *i << " ";
    cout << "\n";
}

int function(int *A, int len_A, int *B, int len_B, int *C) {
    int len_C = 0;
    for (int *i = B; i < B + len_B; i++)
        if (count_in_arr(B, len_B, *i) > 1 && !count_in_arr(A, len_A, *i))
            *(C + len_C++) = *i;
    return len_C;

}




int main() {
    setlocale(LC_ALL,"Russian");
    int A[lmax],B[lmax],C[lmax],len_A,len_B,len_C;


    return 0;
}