#include <iostream>
#include <string>

using namespace std;

int espacios (string cad) {
    int count = 0;
    for (int i = 0; i < cad.length(); i++) {
        if (cad[i] == ' ') {
            count++;
        }
    }

    return count;
}

int main () {
    string test = "T e s t";
    
    cout << "<" << test << "> tiene "
         << espacios(test) << " espacios"
         << endl;

    return 0;
}