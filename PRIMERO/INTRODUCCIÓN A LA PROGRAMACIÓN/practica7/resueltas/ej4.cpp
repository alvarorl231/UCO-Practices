#include <iostream>
#include <cctype>

using namespace std;

int vocales (string cad) {
    int count = 0;
    for (int i = 0; i < cad.length(); i++) {
        char c = tolower(cad[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    return count;
}

int main () {
    string test = "T e s t";
    
    cout << "<" << test << "> tiene "
         << vocales(test) << " vocales"
         << endl;

    return 0;
}