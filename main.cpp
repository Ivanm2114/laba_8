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


void input_data(int *A, int &len_A, int *B, int &len_B) {
    do {
        cout << "Введите длину массива A:\n";
        cin >> len_A;
    } while (len_A <= 0);

    for (int *i = A; i < A + len_A; i++) {
        cout << "Введите элемент A[" << i - A << "]:\n";
        cin >> *i;
    }

    do {
        cout << "Введите длину массива B:\n";
        cin >> len_B;
    } while (len_B <= 0);

    for (int *i = B; i < B + len_B; i++) {
        cout << "Введите элемент B[" << i - B << "]:\n";
        cin >> *i;
    }

}


int main() {
    setlocale(LC_ALL, "Russian");
    int A[lmax], B[lmax], C[lmax], len_A, len_B, len_C;
    input_data(A, len_A, B, len_B);
    cout << "Массив A:\n";
    print_arr(A, len_A);
    cout << "Массив B:\n";
    print_arr(B, len_B);
    len_C = function(A, len_A, B, len_B, C);
    if (len_C) {
        cout << "Success\n";
        print_arr(C, len_C);
    }
    else{
        cout<<"No success";
    }

    return 0;
}