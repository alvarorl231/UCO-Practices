#include <iostream>

using namespace std;

bool palindromo (string cad) {
    for (int i = 0; i < cad.length(); i++) {
        if (cad[i] != cad[cad.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main () {
    string pal = "reconocer";
    string noPal = "si";

    cout << palindromo(pal) << " " << palindromo(noPal) << endl;

    return 0;
}