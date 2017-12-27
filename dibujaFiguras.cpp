#include <iostream> //libreria
#include <cstdlib>
using namespace std; //namespace standar
    
// Crea cuadrados con el simbolo que se quiera con la anchura que se le da.  
// Ademas he corregido para que solo se puedan elegir anchura de entre 1 y 50
// Ahora podemos elegir también la altura del cuadrado, pudiendo ser un rectangulo la figura
// Muestra un título
// Añadida la opción de poder tener rellena la figura
// Ahora también admite s y n para el si y no mayusculas y minusculas
// Añadida la opcion de elegir el tipo de figura

void cuadrado(int al,int anc, char simb,bool rel)
{
    for (int i=1; i<=al; i++)
    {
        for (int j=1; j<=anc;j++)
        {
            if (i==1 || i==al)
                cout << simb;
            else if ( j==1 || j==anc)
                cout << simb;
            else 
                if(rel)
                    cout << simb;
                else
                    cout << " ";
        }
        cout << endl;
    }
}



int main ()
{
    int al,anc;
    char simb,relleno,fig;
    string numero;
    bool rel=false;
    cout << "-----------------------" << endl;
    cout << "CONSTRUYAMOS UNA FIGURA" << endl;
    cout << "-----------------------" << endl << endl;


    do{

        cout << "Ingrese una anchura entre 1 y 50: " << endl;
        getline(cin,numero);
        anc=atoi(numero.c_str());
        
    }while(anc<1 || anc>50 );
    
        do{
            cout << "Ingrese una altura entre 1 y 50: " << endl;
            getline(cin,numero);
            al=atoi(numero.c_str());
        }while(al<1 || al>50 );
    
    do{
        cout << "Quieres que la figura este rellena con simbolos? (S/N): " << endl;
        cin >> relleno;
    }while(relleno!='S' && relleno!='N' && relleno!='s' && relleno!='n');
    
    if (relleno=='S' || relleno=='s')
        rel=true;
    
    cout << "Ingresa el simbolo que formará la figura: " << endl;
    cin >> simb;
    cout << endl;
    

        cuadrado(al,anc,simb,rel);
}
