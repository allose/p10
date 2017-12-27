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

void triangulo(int anc, char simb,bool rel)
{
    if (anc==1)
        anc+=2;
    int principio=(anc-1)/2;
    int fin=(anc-1)/2;
    for (int i=1; i<=(anc-1)/2; i++)
    {
        for (int j=0; j<anc;j++)
        {
            if (j==principio || j==fin)
                cout << simb;
            else if (j>=principio && j<=fin && rel)
                cout << simb;
            else if (i==(anc-1)/2 && j>=principio && j<=fin)
                cout << simb;
            else
                cout << " ";
        }
        principio--;
        fin++;
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
    do {
         cout << "Que figura quieres triangulo, rombo o cuadrado? (t/r/c)" << endl;
        cin >> fig;
        cout << endl;
    }while(fig!='t' && fig!='T' && fig!='c' && fig!='C');
        cin.get();
    do{
        if (fig=='t' || fig=='T' )
            cout << "La anchura tiene que ser un número impar" << endl;
        
        cout << "Ingrese una anchura entre 1 y 50: " << endl;
        getline(cin,numero);
        anc=atoi(numero.c_str());
        
    }while(anc<1 || anc>50 || (anc%2==0 && fig!='c' && fig!='C'));
    
    if (fig=='c' || fig=='C'){
        do{
            cout << "Ingrese una altura entre 1 y 50: " << endl;
            getline(cin,numero);
            al=atoi(numero.c_str());
        }while(al<1 || al>50 );
    }
    
    do{
        cout << "Quieres que la figura este rellena con simbolos? (S/N): " << endl;
        cin >> relleno;
    }while(relleno!='S' && relleno!='N' && relleno!='s' && relleno!='n');
    if (relleno=='S' || relleno=='s')
        rel=true;
    
    cout << "Ingresa el simbolo que formará la figura: " << endl;
    cin >> simb;
    cout << endl;
    
    if (fig=='c' || fig=='C')
        cuadrado(al,anc,simb,rel);
    else if (fig=='t' || fig=='T')
        triangulo(anc,simb,rel);

}
