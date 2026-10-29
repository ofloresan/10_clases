#include <iostream>
#include <iomanip>
using namespace std;

class Calculadora {
	private:
		float a;
		float b;
		bool comprobar(float a, float b){
			return b != 0;
		}
		
	public:
		Calculadora();
		
		void setNumero1(float);
		void setNumero2(float);
        void setComprobar(int);
        
        int getcomprobar();
		float geta();
		float getb();
};

Calculadora::Calculadora(){
	a = 0;
	b = 0;
}

void Calculadora :: setNumero1(float new_a){
	a = new_a;
}

void Calculadora :: setNumero2(float new_b){
	b = new_b;
}



float Calculadora :: geta(){
	return a;
}
float Calculadora :: getb(){
	return b;
}


float sumar(float a, float b){
	return a + b;
}
float restar(float a, float b){
	return a - b;
}
float multiplicacion(float a, float b){
	return a * b;
}
bool dividir(float& resultado,float a, float b){
	if(comprobar()){
		resultado = a/b;
		return true;
	}
	else{
		return false;
	}
}

int main(){
	Calculadora casio;
	
	casio.setNumeros(4, 5);

	cout<<"\nPrimer Numero:\n"<<a<<endl;
	cout<<"\nSegundo Numero:\n"<<b<<endl;
	
	cout<<"Sumar: "<< casio.sumar()<<endl;
	cout<<"Restar: "<< casio.restar()<<endl;
	cout<<"Multiplicacion: "<< casio.multiplicacion()<<endl;
	
	if(casio.dividir(resultado)){
		cout<<"Division: "<<resultado<<endl;
	}	
	else{
		cout<<"Division: error, nose puede dividir entre cero."<<endl;
	}
		
	return 0;
}
