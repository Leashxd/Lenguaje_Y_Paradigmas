//Importamos librearia
#include <iostream>
//Usamos para el teclado
using namespace std;


int main(){

    int array[5];
    int pos_1, pos_2;
    cout<<"Posicion_1" <<endl;
    for(pos_1=0; pos_1<5; pos_1++){
        cout<<"Posicion_1 = " << pos_1 << endl;
    }
    cout<<"Posicion_2" <<endl;
    for(pos_2=0; pos_2<5; pos_2++){
        cout<<"Posicion_2 = " << pos_2 << endl;
    }
    cout<<"FOR ANIDADO" <<endl;
    for(pos_1=0; pos_1<5;pos_1++){
        for(pos_2=0; pos_2<5; pos_2++){
            cout<< "Posicion_1 = "<< pos_1 << " Posicion_2= " << pos_2 <<endl;
        }
    }
}