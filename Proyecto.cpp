#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <locale>

using namespace std;

//Estructuración de la clase Empleado para que se almacene y regrese el nombre.
class Empleado{
    public:
        string n;
        Empleado (string name){
            n= name;
        }
        string nombre(){ //Nombre del empleado.
            return n;
        }
};

//Estructuración de la clase Producto para que almacene y devuelva el precio del producto cuando se invoque.
class Producto{
    public:
        double d;
        Producto (double dlrs){
            d= dlrs;
        }
        double precio(){ //Valor del producto usado.
            return d;
        }
};

int main(){
    //Declaración de las variables a usar, string para empleados y double para el dinero.
    string a,a1,a2,a3,a4,a5,ID_E,ID_P;
    int num, continuar, respuesta;
    double vent=0,manzana,pera,alcachofa,uvas,platanos,trufa;
    bool registro,turno;

    //Escribir el nombre de los empleados
    a= "Alfredo";
    a1= "Ian";
    a2= "Alan";
    a3= "Fred";
    a4= "Ernesto";
    //Asignación de precios de los productos
    manzana= 5;
    pera= 6;
    alcachofa= 30;
    uvas= 100.15;
    platanos= 15.50;
    trufa= 500.20;

    //asignación de nombre a los empleados usando las variables ya declaradas.
    Empleado e1(a),e2(a1),e3(a2),e4(a3),e5(a4);
    //asignación de precio a los productos usando los precios ya definidos.
    Producto p1(manzana),p2(pera),p3(alcachofa),p4(uvas),p5(platanos),p6(trufa);

    //Mapa de empleados que devuelve el nombre si ingresas la ID/key correcta.
    unordered_map<string, string> work;
    work["E01"]= e1.nombre();
    work["E02"]= e2.nombre();
    work["E03"]= e3.nombre();
    work["E04"]= e4.nombre();
    work["E05"]= e5.nombre();

    //Mapa de productos que devuelve el precio del producto
    unordered_map<string, double> product;
    product["001"]= p1.precio();
    product["002"]= p2.precio();
    product["003"]= p3.precio();
    product["004"]= p4.precio();
    product["005"]= p5.precio();
    product["006"]= p6.precio();

    //Crear un mapa vacío donde se irán almacenando las ventas de cada empleado
    unordered_map<string, double> ventas;

    do
    {
        //Asegurarse de que los ciclos se iniciarán.
        turno=true;
        registro=true;
        //Inicio de sesión de los trabajadores
        cout << "Ingrese la ID del empleado: ";
        cin >> ID_E;

        //Identificación del trabajador, asegura de que el trabajador es válido.
        cout << "Bienvenido: " << work[ID_E] << endl;

        //Ciclo que contrloa el registro de los productos.
        while (registro==true)
        {
            cout << "Ingrese el número de artículos que quiere registrar: ";
            cin >> num;

            //Ciclo donde se ingresan los valores en el acumulador
            for (int i= 1; i<=num; i++){
                cout << "Ingrese la ID del producto: ";
                cin >> ID_P;
                vent= vent + product[ID_P];
            }

            cout << "Si desea terminar el registro presione 1:\t";
            cin >> continuar;
            
            //Condicional para terminar el registro de productos por parte del empleado.
            if (continuar == 1){
                registro = false;
            }
        }

        cout << "Si ya terminó su turno, tecleé 0, sino 1:\t";
        cin >> respuesta;
        
        //Condicional para cambio de empleado
        if (respuesta == 1){
            turno= false;
        }
        //Vaciado de las ventas de los empleados en el hashmap vacío.
        ventas.insert(make_pair(work[ID_E],vent));
    } while (turno==true);

    //Impresión de las ventas totales.
    for (auto itr = ventas.begin(); itr != ventas.end(); itr++){
        cout << "La venta de " << itr->first << " fue de: $" << itr-> second << endl;
    }
}