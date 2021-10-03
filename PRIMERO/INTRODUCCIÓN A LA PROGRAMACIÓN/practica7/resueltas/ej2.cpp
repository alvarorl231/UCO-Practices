#include <iostream>
#include <cctype>

using namespace std;

int digitos (string cad) {
    int count = 0;
    for (int i = 0; i < cad.length(); i++) {
        if (isdigit(cad[i])) {
            count++;
        }
    }

    return count;
}

int main () {
    string test = "owo152w3";
    
    cout << "<" << test << "> tiene "
         << digitos(test) << " digitos"
         << endl;

    return 0;
}