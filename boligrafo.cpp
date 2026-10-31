#include <iostream>
#include <string>
using namespace std;

class Boligrafo {
	private:
		int tinta;
		string color;
		
		static const int CAPACIDAD = 100;
	
	public:
		Boligrafo();
		
		int getTinta() const;
		string getColor() const;
		
		bool setColor(string);
		bool escribir(int);
		bool recargar(int);
		
		void mostrarEstado() const;
};

const int Boligrafo::CAPACIDAD;

Boligrafo::Boligrafo(){
	tinta = 100;
	color = "azul";
}

int Boligrafo::getTinta() const {
	return tinta;
}
string Boligrafo::getColor() const {
	return color;
}

bool Boligrafo::setColor(string nuevoColor){
	if (nuevoColor == "azul" || nuevoColor == "rojo" ||
		nuevoColor == "verde" || nuevoColor == "negro"){
		color = nuevoColor;
		return true;
	}
	return false;
}

bool Boligrafo::escribir(int unidades){
	if (unidades > 0 && unidades <= tinta){
		tinta -= unidades;
		return true;
	}
	return false;
}

bool Boligrafo::recargar(int unidades){
	if (unidades > 0 && tinta + unidades <= CAPACIDAD){
		tinta += unidades;
		return true;
	}
	return false;
}

void Boligrafo::mostrarEstado() const {
	cout<<"Color: "<<color<<"\n";
	cout<<"Tinta disponible: "<<tinta<<" unidades\n";
}


int main(){
	Boligrafo boli;
	int opcion, unidades;
	string nuevoColor;
	
	do {
		cout<<"\n===== BOLIGRAFO =====\n";
		cout<<"1. Escribir\n";
		cout<<"2. Recargar\n";
		cout<<"3. Cambiar color\n";
		cout<<"4. Consultar estado\n";
		cout<<"5. Salir\n";
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Unidades de tinta a consumir: ";
				cin>>unidades;
				if (boli.escribir(unidades)){
					cout<<"Escritura realizada.\n";
					cout<<"Tinta consumida: "<<unidades<<"\n";
					cout<<"Tinta restante: "<<boli.getTinta()<<"\n";
				} else {
					cout<<"Operacion rechazada: cantidad invalida o tinta insuficiente.\n";
					cout<<"Tinta restante: "<<boli.getTinta()<<"\n";
				}
				break;
			case 2:
				cout<<"Unidades a recargar: ";
				cin>>unidades;
				if (boli.recargar(unidades))
					cout<<"Recarga realizada. Tinta actual: "<<boli.getTinta()<<"\n";
				else
					cout<<"Operacion rechazada: cantidad invalida o excede la capacidad (100).\n";
				break;
			case 3:
				cout<<"Nuevo color (azul, rojo, verde, negro): ";
				cin>>nuevoColor;
				if (boli.setColor(nuevoColor))
					cout<<"Color cambiado a "<<boli.getColor()<<".\n";
				else
					cout<<"Color no permitido.\n";
				break;
			case 4:
				boli.mostrarEstado();
				break;
			case 5:
				cout<<"Saliendo...\n";
				break;
			default:
				cout<<"Opcion invalida.\n";
		}
	} while (opcion != 5);
	
	return 0;
}
