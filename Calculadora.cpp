#include <iostream>
#include <iomanip>
using namespace std;

class Calculadora {
	private:
		float primero;
		float segundo;
		
		bool comprobar() const;
	
	public:
		Calculadora();
		
		void setNumeros(float, float);
		
		float getPrimero() const;
		float getSegundo() const;
		
		float sumar() const;
		float restar() const;
		float multiplicar() const;
		bool dividir(float& resultado) const;
};

Calculadora::Calculadora(){
	primero = 0;
	segundo = 0;
}

bool Calculadora::comprobar() const {
	return segundo != 0;
}

void Calculadora::setNumeros(float a, float b){
	primero = a;
	segundo = b;
}

float Calculadora::getPrimero() const {
	return primero;
}
float Calculadora::getSegundo() const {
	return segundo;
}

float Calculadora::sumar() const {
	return primero + segundo;
}
float Calculadora::restar() const {
	return primero - segundo;
}
float Calculadora::multiplicar() const {
	return primero * segundo;
}

bool Calculadora::dividir(float& resultado) const {
	if (comprobar()){
		resultado = primero / segundo;
		return true;
	}
	return false; // no se modifica resultado
}


int main(){
	Calculadora casio;
	int opcion;
	float a, b, resultado;
	
	do {
		cout<<"\n===== CALCULADORA =====\n";
		cout<<"1. Establecer numeros\n";
		cout<<"2. Sumar\n";
		cout<<"3. Restar\n";
		cout<<"4. Multiplicar\n";
		cout<<"5. Dividir\n";
		cout<<"6. Salir\n";
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Primer numero: ";
				cin>>a;
				cout<<"Segundo numero: ";
				cin>>b;
				casio.setNumeros(a, b);
				cout<<"Numeros guardados: "<<casio.getPrimero()<<" y "<<casio.getSegundo()<<"\n";
				break;
			case 2:
				cout<<"Resultado: "<<casio.sumar()<<"\n";
				break;
			case 3:
				cout<<"Resultado: "<<casio.restar()<<"\n";
				break;
			case 4:
				cout<<"Resultado: "<<casio.multiplicar()<<"\n";
				break;
			case 5:
				if (casio.dividir(resultado))
					cout<<"Resultado: "<<fixed<<setprecision(2)<<resultado<<"\n";
				else
					cout<<"Error: no se puede dividir entre cero.\n";
				break;
			case 6:
				cout<<"Saliendo...\n";
				break;
			default:
				cout<<"Opcion invalida.\n";
		}
	} while (opcion != 6);
	
	return 0;
}
