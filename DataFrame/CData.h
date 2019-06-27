#include<string>
using namespace std;
class Data
{
public:
	Data(string valor, string tipoDato);
	~Data();
	void setValor(string valor)
	{
		this->valor = valor;
	}
	string getValor()
	{
		return valor;
	}
	void setTipoDato(string tipoDato)
	{
		this->tipoDato = tipoDato;
	}
	string getTipoDato() {
		return tipoDato;
	}

private:
	string valor;
	string tipoDato;
};

Data::Data(string valor, string tipoDato)
{
	this->tipoDato = tipoDato;
	this->valor = valor;
}

Data::~Data()
{
}