#include <iostream>
using namespace std;

int main ( )
{
    int notificacion_cobro=10000;
    int pago=35450; //Monto pagado por el cliente
    int vuelto = pago-notificacion_cobro;
    float Billetes_Entregar=0;

    int veintemil,
        diezmil,
        cincomil,
        dosmil,
        mil,
        quinientos,
        cien;
/*  
cout<< "¿Cuanto debe pagar el cliente?"<<endl;
cin>>notificacion_cobro;
cout<< "¿Con cuanto paga el cliente?"<<endl;
cin>>pago; */

if(notificacion_cobro>pago){
  cout<< "Al cliente le falta"<<vuelto*(-1)<<endl;
  
}
if(notificacion_cobro == pago){
  cout<< "Tu vuelto es igual a : "<<vuelto<<endl;
}
if(notificacion_cobro<pago){
  cout<< "Tu vuelto es igual a :"<<vuelto<<endl;
  if(vuelto){
      veintemil = vuelto/20000; // Los billetes de 20, el numero entero
      vuelto= vuelto%20000;
      cout << "Tu vuelto en billetes de 20.000 es: " << (veintemil) << endl;

      diezmil = vuelto/10000; // Los billetes de 20, el numero entero
      vuelto= vuelto%10000;
      cout << "Tu vuelto en billetes de 10.000 es: " << int(diezmil) << endl;

      cincomil = vuelto/5000;
      vuelto= vuelto%5000;
      cout << "Tu vuelto en billetes de 5.000 es: " << int(cincomil) << endl;
      
      dosmil = vuelto/2000;
      vuelto= vuelto%2000;
      cout << "Tu vuelto en billetes de 2.000 es: " << int(dosmil) << endl;

      mil = vuelto/1000;
      vuelto= vuelto%1000;
      cout << "Tu vuelto en billetes de 1.000 es: " << int(mil) << endl;

      quinientos = vuelto/500;
      vuelto= vuelto%500;
      cout << "Tu vuelto en billetes de 500 es: " << int(quinientos) << endl;

      cien = vuelto/100;
      vuelto= vuelto;
      cout << "Tu vuelto en billetes de 100 es: " << int(cien) << endl;

      




      

      
    if (vuelto/1000){
        
    }


  }

}

    return 0;
}