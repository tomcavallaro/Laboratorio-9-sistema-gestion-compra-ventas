# TP9: Administrador de transacciones
## Etapa 1: creamos la estructura base del codigo y las funciones main, RegisterTransaction y ViewTransaction.
  - **main**: se utiliza como menu para seleccionar lo que quiere hacer el usuario a traves de numeros: 
1. RegisterTransaction
2. SearchTransaction
3. UpdateTransaction
4. CalculateProfitlossByProduct
5. CalculateProfitLoss
6. salir del programa

  - **RegisterTransaction**: se utiliza para registrar una transaccion en el programa; colocando el tipo de transaccion(compra/venta), el nombre del producto, la cantidad de productos y cuanto vale ese producto individualmente.

 - **ViewTransaction**: se utiliza para mostrar una transaccion previamente ingresada en el programa.

## Etapa 2: creamos las estructuras SearchTransaction y UpdateTransaction.
  - **SearchTransaction**: se utiliza para buscar una transaccion previamente ingresada en el programa; colocando el nombre del producto.
  - **UpdateTransaction**: se utiliza para cambiar una transaccion previamente ingresada en el programa; colocando el nombre del producto y luego editarla, colocando nuevamente el tipo, nombre, cantidad y precio.
## Etapa 3: creamos la estructura CalculateProfitLoss y CalculateProfitlossByProduct.
  - **CalculateprofitlossByProduct**: se utiliza para calcular las perdidas, ganancias y total final de un producto a traves de las transacciones previamente ingresadas en el sistema
  - **CalculateProfitLoss**: se utiliza para calcular las perdidas, ganancias, perdidas totales, ganancias totales y el total final a traves de las transacciones previamente ingrasadas en el programa.

## Funcionamiento del codigo y su ejecucion parte por parte

![alt text](image.png)

  - ## El menu de nuestro comercio:

  ![alt text](image-1.png)

  Ahora lo que hacemos es entrar a la opcion n°1 en la seccion de compra/transaccion de la misma 

  ![alt text](image-2.png)

  Luego vemos en el mismo menu la parte venta/transaccion de la misma 

  ![alt text](image-4.png)

  Luego vamos a la opcion 4 donde encontramos las ganancias

  ![alt text](image-5.png)
  
  Y por ultimo la opcion 5 que nos saca del programa

  ![alt text](image-6.png)

### Codigo:

Opcion 1 del programa donde se encuentra el menu de compra/venta

![alt text](image-7.png)

Opcion 2 del programa donde se encuentra el menu de busca de transacciones 

![alt text](image-8.png)

Opcion 3 del programa donde se encuentra el menu para poder editar la transaccion

![alt text](image-9.png)

Opcion 4 del programa donde se encuentra el menu para visualizar las perdidas y las ganancias

![alt text](image-10.png)

Opcion 5 del programa donde si lo seleccionamos saldremos de el

![alt text](image-11.png)


#### Codigo "mejorado":

``` cpp 

#include <iostream>
#include <string>
using namespace std;

struct Transaccion {
    string tipo;
    string nombre;
    int cantidad;
    float precio;
    float total;
};

int totalcompra = 0;
int totalventa = 0;
int totalfinal = 0;

void RegisterTransaction();
void ViewTransaction();
void SearchTransaction();
void UpdateTransaction();
void calculateProfitLoss();
void mostrarMenu();

const int MaxTransaccion = 100;
Transaccion transacciones[MaxTransaccion];
int cont_transaccion = 0;

int main() {
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcion;
    do {
        cout << "\nSeleccione una opcion:" << endl;
        cout << "1. Registrar una transaccion (compra o venta)" << endl;
        cout << "2. Buscar una transaccion" << endl;
        cout << "3. Editar una transaccion" << endl;
        cout << "4. Mostrar perdidas y ganancias" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                RegisterTransaction();
                break;
            case 2:
                SearchTransaction();
                break;
            case 3:
                UpdateTransaction();
                break;
            case 4:
                calculateProfitLoss();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);
}

void RegisterTransaction() {
    Transaccion t;
    cout << "Ingrese el tipo de transaccion (compra o venta): ";
    cin >> t.tipo;

    if (t.tipo != "compra" && t.tipo != "venta") {
        cout << "Tipo invalido. La transaccion debe ser 'compra' o 'venta'." << endl;
        return;
    }

    cout << "Nombre del producto: ";
    cin >> t.nombre;
    cout << "Cantidad: ";
    cin >> t.cantidad;
    cout << "Precio unitario: ";
    cin >> t.precio;

    t.total = t.cantidad * t.precio;

    if (t.tipo == "compra") {
        totalcompra += t.total;
    } else if (t.tipo == "venta") {
        totalventa += t.total;
    }

    if (cont_transaccion < MaxTransaccion) {
        transacciones[cont_transaccion++] = t;
        cout << "Transaccion registrada correctamente." << endl;
    } else {
        cout << "Error: no se pueden registrar mas transacciones." << endl;
    }

    ViewTransaction();
}

void ViewTransaction() {
    cout << "\n--- Lista de Transacciones ---" << endl;
    for (int i = 0; i < cont_transaccion; i++) {
        cout << "Transaccion #" << i + 1 << ":" << endl;
        cout << "Tipo: " << transacciones[i].tipo << endl;
        cout << "Producto: " << transacciones[i].nombre << endl;
        cout << "Cantidad: " << transacciones[i].cantidad << endl;
        cout << "Precio: " << transacciones[i].precio << endl;
        cout << "Total: " << transacciones[i].total << endl;
        cout << "----------------------------" << endl;
    }
}

void SearchTransaction() {
    string producto;
    bool encontrado = false;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin >> producto;

    for (int i = 0; i < cont_transaccion; i++) {
        if (transacciones[i].nombre == producto) {
            cout << "\nTransaccion encontrada:" << endl;
            cout << "Tipo: " << transacciones[i].tipo << endl;
            cout << "Producto: " << transacciones[i].nombre << endl;
            cout << "Cantidad: " << transacciones[i].cantidad << endl;
            cout << "Precio: " << transacciones[i].precio << endl;
            cout << "Total: " << transacciones[i].total << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ninguna transaccion con ese nombre." << endl;
    }
}

void UpdateTransaction() {
    string producto;
    bool encontrado = false;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> producto;

    for (int i = 0; i < cont_transaccion; i++) {
        if (transacciones[i].nombre == producto) {
            // Retsar el valor de la transaccion original del total
            if (transacciones[i].tipo == "compra") {
                totalcompra -= transacciones[i].total;
            } else if (transacciones[i].tipo == "venta") {
                totalventa -= transacciones[i].total;
            }

            // Solicitar nuevos valores
            cout << "Ingrese el nuevo tipo de transaccion (compra o venta): ";
            cin >> transacciones[i].tipo;
            cout << "Ingrese el nuevo nombre del producto: ";
            cin >> transacciones[i].nombre;
            cout << "Ingrese la nueva cantidad: ";
            cin >> transacciones[i].cantidad;
            cout << "Ingrese el nuevo precio unitario: ";
            cin >> transacciones[i].precio;

            // Recalcular el total
            transacciones[i].total = transacciones[i].cantidad * transacciones[i].precio;

            // Actualizar el total general
            if (transacciones[i].tipo == "compra") {
                totalcompra += transacciones[i].total;
            } else if (transacciones[i].tipo == "venta") {
                totalventa += transacciones[i].total;
            }

            encontrado = true;
            cout << "Transaccion actualizada correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ninguna transaccion con ese nombre." << endl;
    }
}

void calculateProfitLoss() {
    cout << "\n--- Reporte de Ganancias y Perdidas ---" << endl;
    cout << "Ganancias por ventas: " << totalventa << endl;
    cout << "Perdidas por compras: " << totalcompra << endl;
    totalfinal = totalventa - totalcompra;
    cout << "Resultado final (ganancia/perdida neta): " << totalfinal << endl;
    cout << "----------------------------" << endl;
}

```