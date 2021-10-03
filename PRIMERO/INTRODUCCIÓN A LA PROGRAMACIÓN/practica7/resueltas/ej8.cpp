#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool checkDNI (string& dni) {
    //Comprueba la longitud del dni
    if (dni.length() != 9) {
        return false;
    }

    //Comprueba que los 8 primeros caracteres sean digitos
    for (int i = 0; i < 8; i++) {
        if (!isdigit(dni[i])) {
            return false;
        }
    }

    //Pasa a mayuscula el ultimo caracter y comprueba que sea la letra adecuada
    //(en caso de que el ultimo caracter sea un numero entraremos 
    //al if tambien y deveolveremos false)
    dni[8] = toupper(dni[8]);
    int numero = stoi(dni);
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    char letra = letras[numero % 23];
    if (dni[8] != letra) {
        return false;
    }

    //Si ha pasado todos los tests imprime el DNI y devuelve true
    cout << dni << endl;
    return true;
}

int main () {
    string dni;
    cin >> dni;
    cout << checkDNI(dni) << endl; 
}