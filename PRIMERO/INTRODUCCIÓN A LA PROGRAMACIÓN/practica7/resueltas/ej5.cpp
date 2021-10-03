#include <iostream>

using namespace std;

void replace (string& cad, char a, char b) {
    for (int i = 0; i < cad.length(); i++) {
        if (cad[i] == a) {
            cad[i] = b;
        }
    }
}

int main () {
    string test = "owo";
    replace(test, 'o', 'u');

    cout << test << endl;

    return 0;
}