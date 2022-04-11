#include <iostream>
using namespace std;

int main ( )
{
// Definir las variables
int Base,ladoA,ladoB;

cout<< "Clasificador de triangulos"<<endl;
cout<< "Ingrese la base del triangulo"<<endl;
cin>>Base;
cout<< "Ingrese el primer lado del triangulo"<<endl;
cin>>ladoA;
cout<< "Ingrese el segundo lado del triangulo"<<endl;
cin>>ladoB;

// Clasificamos las opciones
if(Base == ladoA == ladoB){
  cout<< "Tu triangulo es equilatero"<<endl;
}
if(Base != ladoA != ladoB && ladoB!= Base){
  cout<< "Tu triangulo es escaleno"<<endl;
}
else{
  cout<< "Tu triangulo es isosceles"<<endl;
}

    return 0;
}