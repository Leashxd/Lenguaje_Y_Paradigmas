#include <iostream>
#include <math.h>
using namespace std;
int main ( )
{

  float xA,yA,xB,yB,xC,yC;
  float distancia_AB;
  float distancia_BC;
  float distancia_CA;

  cout << "Ingrese el x de su punto A" <<endl;
  cin>>xA;
  cout << "Ingrese el y de su punto A" <<endl;
  cin>>yA;
  cout << "Ingrese el x de su punto B" <<endl;
  cin>>xB;
  cout << "Ingrese el y de su punto B" <<endl;
  cin>>yB;
  cout << "Ingrese el x de su punto C" <<endl;
  cin>>xC;
  cout << "Ingrese el y de su punto C" <<endl;
  cin>>yC;

  // tengo que sacar la distancia entre AB, BC ,CA
  distancia_AB = sqrt((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA));
  distancia_BC = sqrt((xC-xB)*(xC-xB)+(yC-yB)*(yC-yB));
  distancia_CA = sqrt((xA-xC)*(xA-xC)+(yA-yC)*(yA-yC));

  cout << "La distancia  entre AB o BA es : "<<distancia_AB<<endl;
  cout << "La distancia entre BC o CB es : "<<distancia_BC<<endl;
  cout << "La distancia entre CA o AC es : "<<distancia_CA<<endl;

  if(distancia_AB == distancia_BC && distancia_BC == distancia_CA && distancia_CA == distancia_AB){
    cout << "Su triangulo es equilatero"<<endl;

  }else if(distancia_AB == distancia_BC || distancia_BC == distancia_CA || distancia_CA == distancia_AB){
    cout << "Su triangulo es isosceles"<<endl;

  }else{
    cout << "Su triangulo es escaleno"<<endl;
  }



    return 0;
}