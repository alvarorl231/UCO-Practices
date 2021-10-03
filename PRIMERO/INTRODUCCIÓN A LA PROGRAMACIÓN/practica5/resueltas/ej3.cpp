#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fijaValorAleatorio (int v[], int n, int max) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (max + 1);

        //TESTING
        cout << "v[" << i << "] = " << v[i] << endl;
    }
}

int main () {
    srand(time(NULL));
    int v[10];
    fijaValorAleatorio(v, 10, 100);

    return 0;
}