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
        float ventas(float v){ //Acumulador de cuánto ha vendido el empleado, se usará en un ciclo while más tarde.
            return v;
        }
};

//Estructuración de la clase Producto para que almacene y devuelva el precio del producto cuando se invoque.
class Producto{
    public:
        float d;
        Producto (float dlrs){
            d= dlrs;
        }
        float precio(){ //Valor del producto usado.
            return d;
        }
};



int main(){
    //Declaración de las variables a usar, string para empleados y float para productos.
    string a,a1,a2,a3,a4,a5;
    float manzana,pera,alcachofa,uvas,platanos,trufa;
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
    uvas= 100;
    platanos= 15;
    trufa= 500;

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
    unordered_map<string, float> product;
    product["001"]= p1.precio();
    product["002"]= p2.precio();
    product["003"]= p3.precio();
    product["004"]= p4.precio();
    product["005"]= p5.precio();
    product["006"]= p6.precio();

    string ID_E;
    //El usuario ingresará la llave para identificarse como un trabajador.
    cout << "Ingrese la ID del empleado: ";
    cin >> ID_E;
    //Prueba de si funciona correctamente la asignación de llaves de empleado.
    cout << "\nBienvenido: " << work[ID_E] << endl;


    //Usar get y set para el contador de los trabajadores.
}