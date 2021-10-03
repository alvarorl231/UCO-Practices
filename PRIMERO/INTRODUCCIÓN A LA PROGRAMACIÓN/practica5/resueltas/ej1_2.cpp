#include <iostream>

using namespace std;

void lee (float v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
}

void imprime (float v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }
}

int main () {
    float v[10];
    lee(v, 10);
    cout << "---------" << endl;
    imprime(v, 10);

    return 0;
}