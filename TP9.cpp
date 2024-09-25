#include <iostream>
#include <string>
using namespace std;

struct Transaccion{
    string tipo;
    string nombre;
    int cantidad;
    float precio;
    float total;
};
	int totalcompra;
    int totalventa;
    int totalfinal;
void RegisterTransaction (Transaccion);
void ViewTransaction (void);
void SearchTransaction (void);
void UpdateTransaction (void);
void calculateProfitLoss();

void reset();

const int MaxTransaccion=100;
Transaccion transacciones[MaxTransaccion];
int cont_transaccion=0;



int main(){
	int opcion;
	char letra;
	Transaccion t;
    cout<<"seleccione una opcion:"<<endl;
	cout<<"escriba 1 para comprar o venta"<<endl;
	cout<<"escriba 2 para buscar una transaccion"<<endl;
	cout<<"escriba 3 para editar una transaccion"<<endl;
	cout<<"escriba 4 para mostrar las perdidas y ganancias"<<endl;
	cout<<"escriba 5 para salir del programa"<<endl;
	cin>>opcion;
	switch(opcion){
		
		case 1:
			RegisterTransaction(t);
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
			cout<<"se salio del programa..."<<endl;
			exit(0);
			break;
	}
}

void RegisterTransaction(Transaccion t){//registro y creacion de transacciones
	cout << "tipo: ";
	cin >> t.tipo;
	while(t.tipo=="compra" or t.tipo=="venta"){
	cout << "nombre: ";
	cin >> t.nombre;
	cout << "cantidad: ";
	cin >> t.cantidad;
	cout << "precio: ";
	cin >> t.precio;
	
	t.total=t.cantidad*t.precio;
	
	if(t.tipo=="compra"){
	totalcompra=t.total+totalcompra;	
	}
	if(t.tipo=="venta"){
	totalventa=t.total+totalventa;	
	}
	
	transacciones[cont_transaccion] = t;
	cont_transaccion++;
	ViewTransaction ();
	}
	cout<<"----------------------------"<<endl;
	main();
	
}

void ViewTransaction (){
	cout<<"----------------------------"<<endl;
    for (int i = 0; i < cont_transaccion; i++){
    	cout<<"TRANSACCION:"<<endl;
        cout<<"tipo: "<<transacciones[i].tipo<<endl;
        cout<<"nombre: "<<transacciones[i].nombre<<endl;
        cout<<"cantidad: "<<transacciones[i].cantidad<<endl;
        cout<<"precio: "<<transacciones[i].precio<<endl;
        cout<<"total: "<<transacciones[i].total<<endl;
        cout<<""<<endl;
    }
    cout<<"----------------------------"<<endl;
    main();
}

void SearchTransaction() {//buscador y visualizador de transacciones especificas
	string producto;
	bool encontrado=false;
	cout <<"ingrese un producto: ";
	cin >> producto;
	for(int i=0;i < MaxTransaccion;i++ ){
		if (transacciones[i].nombre==producto){
            cout<<"TRANSACCION ENCONTRADA:"<<endl; 
            cout<<"tipo: "<<transacciones[i].tipo<<endl;
        	cout<<"nombre: "<<transacciones[i].nombre<<endl;
        	cout<<"cantidad: "<<transacciones[i].cantidad<<endl;
        	cout<<"precio: "<<transacciones[i].precio<<endl;
        	cout<<"total: "<<transacciones[i].total<<endl;
			encontrado=true;
		}
	}
	if(encontrado==false){
		cout<<"no se encontro ninguna transaccion con ese nombre"<<endl;
	}
	cout<<"----------------------------"<<endl;
	main();
}

void UpdateTransaction(){//editador de transacciones especificas
    string producto;
    bool encontrado=false;
    cout<< "ingrese un producto"<<endl;
    cin>> producto;
    for (int i = 0; i < MaxTransaccion; i++)
    {
        if (transacciones[i].nombre==producto){
        	if(transacciones[i].tipo=="compra"){
			totalcompra=totalcompra-transacciones[i].total;
			}
			if(transacciones[i].tipo=="venta"){
			totalventa=totalventa-transacciones[i].total;	
			}
            cout << "tipo: ";
			cin >> transacciones[i].tipo;
			cout << "nombre: ";
			cin >> transacciones[i].nombre;
			cout << "cantidad: ";
			cin >> transacciones[i].cantidad;
			cout << "precio: ";
			cin >> transacciones[i].precio;
			transacciones[i].total=transacciones[i].cantidad*transacciones[i].precio;
			if(transacciones[i].tipo=="venta"){
			totalcompra=transacciones[i].total+totalventa;	
			}
			if(transacciones[i].tipo=="compra"){
			totalventa=transacciones[i].total+totalcompra;	
			}
            encontrado = true;
            ViewTransaction ();
        }
    }
    if(encontrado==false){
		cout<<"no se encontro ninguna transaccion con ese nombre"<<endl;
	}
	main();
}

void calculateProfitLoss(){//visualizador de ganancias y perdidas realizadas en transacciones
	for(int i=0; i<MaxTransaccion; i++){
		if(transacciones[i].tipo=="venta"){
		cout<<"ganancia: "<<transacciones[i].total<<endl;
		}
		if(transacciones[i].tipo=="compra"){
		cout<<"perdida: "<<transacciones[i].total<<endl;
		}
	}
	cout<<"ganancia total: "<<totalventa<<endl;
	cout<<"perdida total: "<<totalcompra<<endl;
	totalfinal=totalventa-totalcompra;
	cout<<"total final: "<<totalfinal<<endl;
	
	cout<<"----------------------------"<<endl;
	main();
}

