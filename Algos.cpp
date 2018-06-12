#include <iostream>
#include <string.h>
#include <QQueue>

using namespace std;

int A[] = {95,84,74,65,42,36,22,13,7,5,2};
int n = (sizeof(A))/(sizeof(*A));

//------------ ------------ ------------ Fibonacci
int f(int i){
    if(i == 1){
        return 0;
    }
    if(i == 2){
        return 1;
    }
    i--;
    return f(i)+f(i-1);
}

//------------ ------------ ------------ Posicion en Vector A
int Pos(int k){
    int Sup = n;
    int Cnt = 0;
    int Inf = 0;
    int PM = (Sup + Inf)/2;

    while((Sup - Inf) > 0 && Cnt == 0){

        if((Sup - Inf) == 1){
            Cnt = 1;
        }

        if(A[PM] == k){
            return PM;
        }
        else{
            if(A[PM] > k){
                Inf = PM;
                PM  = (Sup + Inf)/2;
            }
            else{
                Sup = PM;
                PM  = (Sup + Inf)/2;
            }
        }
    }
    //Dato i no encontrado
    return -1;
}

//------------ ------------ ------------ Estructura Puesto

class Puesto{
public:
    char * Empleado;
    char * NombrePuesto;
    Puesto * Siguiente;
    Puesto * Subordinado;


    Puesto(){
        Siguiente = NULL;
        Subordinado = NULL;
    }

    Puesto(char * Emp,char * NomP,Puesto * Sig,Puesto * Sub){

        Siguiente = Sig;
        Subordinado = Sub;
        Empleado = new char[strlen(Emp)];
        NombrePuesto = new char[strlen(NomP)];

        strcpy(Empleado,Emp);
        strcpy(NombrePuesto,NomP);
    }

};

//------------ ------------ ------------ Imprimir Puestos
QQueue<Puesto *> cola;
void lista(Puesto * Ps){

    Puesto * TMP = Ps;
    cola<<Ps;
    //Atender a la Cola
    while(!cola.empty()){
        TMP = cola.dequeue();
        if(TMP->Siguiente != NULL){
            cola<<TMP->Siguiente;
        }

        if(TMP->Subordinado != NULL){
            cola<<TMP->Subordinado;
        }

        cout << "Nombre:" << TMP->Empleado << "    Puesto:"<< TMP->NombrePuesto << endl;
    }
}

int main()
{
    //------------ ------------ ------------ Fibonacci
    cout << "Termino n = 1 ->" << f(1) << endl;
    cout << "Termino n = 2 ->" << f(2) << endl;
    cout << "Termino n = 3 ->" << f(3) << endl;
    cout << "Termino n = 4 ->" << f(4) << endl;
    cout << "Termino n = 5 ->" << f(5) << endl;
    cout << "Termino n = 6 ->" << f(6) << endl;
    cout << "Termino n = 7 ->" << f(7) << endl;

    //------------ ------------ ------------ Busqueda Binaria
    cout << "Posicion del Valor: " << Pos(95) << endl;
    cout << "Posicion del Valor: " << Pos(84) << endl;
    cout << "Posicion del Valor: " << Pos(74) << endl;
    cout << "Posicion del Valor: " << Pos(65) << endl;
    cout << "Posicion del Valor: " << Pos(42) << endl;
    cout << "Posicion del Valor: " << Pos(36) << endl;
    cout << "Posicion del Valor: " << Pos(22) << endl;
    cout << "Posicion del Valor: " << Pos(13) << endl;
    cout << "Posicion del Valor: " << Pos(7) << endl;
    cout << "Posicion del Valor: " << Pos(5) << endl;
    cout << "Posicion del Valor: " << Pos(2) << endl;
    //Test elemento no existe
    cout << "Posicion del Valor: " << Pos(975) << endl;


    //------------ ------------ ------------ Imprimir Puestos
    //Carga de la Estructura

    Puesto * Fernando = new Puesto("Fernando","Auxiliar",NULL,NULL);
    Puesto * Oscar = new Puesto("Oscar","Operador",NULL,NULL);
    Puesto * Juan  = new Puesto("Juan","Contador",NULL,NULL);
    Puesto * Jose  = new Puesto("Jose","Contador",Juan,Fernando);
    Puesto * Edwin = new Puesto("Edwin","Supervisor",NULL,Oscar);
    Puesto * Julio = new Puesto("Julio","Gerente de Produccion",NULL,Edwin);
    Puesto * Maria = new Puesto("Maria","Gerente Financiero",Julio,Jose);
    Puesto * Pedro = new Puesto("Pedro","Gerente General",NULL,Maria);

    //Impresion de la Estructura
    lista(Pedro);

    return 0;
}
