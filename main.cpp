#include <iostream>

#define lmax 200

using namespace std;

void print_matrix(int M[][lmax], int &n, int &m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(M + i) + j) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void input_data(int M[][lmax], int &n, int &m) {
    do {
        cout << "Введите n и m:\n";
        cin >> n >> m;
    } while (n <= 0 || m <= 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Введите элемент M[" << i << "][" << j << "]\n";
            cin >> *(*(M + i) + j);
        }
    }

}

bool function(int M[][lmax], int n, int m){
    int *pmax, *pmin,t;
    pmax=pmin=*M;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(*(*(M+i)+j)>*pmax) pmax=(*(M+i)+j);
            if(*(*(M+i)+j)<*pmin) pmin=(*(M+i)+j);
        }
    }
    if(pmax!=pmin){
        t=*pmax;
        *pmax=*pmin;
        *pmin=t;
    }
    return pmax!=pmin;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int M[lmax][lmax], n, m;
    input_data(M,n,m);
    cout<< "Matrix:\n";
    print_matrix(M,n,m);
    if(function(M,n,m)){
        cout<<"Success\n";
    }
    else{
        cout<<"No success\n";
    }
    cout<< "Matrix:\n";
    print_matrix(M,n,m);
    return 0;
}
