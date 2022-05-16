
//Importamos librearia
#include <iostream>
//Usamos para el teclado
using namespace std;

int main(){

    int array[5];
    int pos;
    int numero_a_buscar;
    int Bool = 0;//Suponemos que 
    
     for(pos=0; pos<5; pos++){
        // Creamos un string
        cout<<"Ingresa tu numero"<<pos <<endl;
        //Ahora ingresamos el numero CIN en la posicion X del array
        pos >> array[pos];
    }

    cout << "Ingresa el numero que quieres buscar" << endl;
    cin >> numero_a_buscar; 
        
    for(pos=0; pos<5;pos=pos+1){
        if(array[pos] == numero_a_buscar){
            Bool = 1;
            break;
        }
        else{
            //cout<<"El numero "<<numero_a_buscar<< "no se encuentra en la posicion "<< pos<<endl;
        }
    }
    
    if(Bool == 1){
        cout<<"El numero ingresado se encuentra dentro del arreglo y este essta en la posición"<< pos <<endl;

    }else{
        cout << "El numero a buscar realmente no se encuentra en ninguna de las "<<pos+1<<" posiciones del arreglo"<<endl;
    }
}
