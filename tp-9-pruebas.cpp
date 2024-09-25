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

