#include <iostream>

using namespace std;

int find (string a, string b) {
    int j = 0; //Counter for string b
    int start; //Index where b starts in a

    for (int i = 0; i < a.length(); i++) {
        //Comprobamos si el caracter que estamos mirando es igual en a y b
        if (a[i] == b[j]) {
            //Si es el primer caracter de b
            if (j == 0) {
                start = i; //Asignamos valor a start
            }

            j++; //Incrementamos el contador
            
            //Comprobamos si hemos acabado la cadena b
            if (j == b.length()) {
                return start;
            }
        }
        else {
            //Reseteamos el contador
            j = 0;
        }
    }

    //La cadena b no aparece en a, devolvemos -1
    return -1;
}

int main () {
    cout << find("hola mundo", "mundo") << endl;
    cout << find("prueba", "test") << endl;
    return 0;
}