#include <iostream>
using namespace std;

int main ()
{
    int array[5];
    int x=0, numero_a_buscar=0;

    cout << "Ingrese la cantidad de numeros que desea operar" << endl;
    cin >> x;

    for(x=0; x < 5; x++){
        cout << "Ingrese los numeros" << endl;
        cin >> array[x];
    }
    cout << "Ingrese el numero a buscar" << endl;
    cin >> numero_a_buscar;

    for(x=0; x < 5; x++){
        if(array[x] == numero_a_buscar){
            cout << "El numero existe" << endl;
        }else{
            cout << "sorry compare, pero no esta la wea" << endl;

        }

    }
    
return 0;    
}