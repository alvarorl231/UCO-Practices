#include <iostream>

using namespace std;

void convierte_a_mayuscula (string& cad) {
    for (int i = 0; i < cad.length(); i++) {
        cad[i] = toupper(cad[i]);
    }
}

int main () {
    string test = "T e s t";
    convierte_a_mayuscula(test);

    cout << "<" << test << ">" << endl;

    return 0;
}