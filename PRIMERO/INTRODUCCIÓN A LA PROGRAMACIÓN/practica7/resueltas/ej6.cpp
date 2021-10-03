#include <iostream>

using namespace std;

string concatena (string a, string b) {
    return a + b;
}

int main () {
    string cad1 = "ow";
    string cad2 = "o <3";
    cout << concatena(cad1, cad2) << endl;

    return 0;
}