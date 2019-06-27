#include "CRow.h"
class DataFrame
{
public:
	DataFrame(vector<Row> filas);
	~DataFrame();
	void insertarFila(Row fila);
	void imprimirTabla();
	vector<Row> getTabla() {
		return tabla;
	}
private:
	vector<Row> tabla;
};

DataFrame::DataFrame(vector<Row> filas)
{
	this->tabla = filas;
}

DataFrame::~DataFrame()
{
}
void DataFrame::insertarFila(Row fila)
{
	tabla.push_back(fila);
}
void DataFrame::imprimirTabla()
{
	for (int i = 0; i < tabla.size(); i++)
	{
		if (i == 0)
		{
			cout << "ID\t";
			for (int aux = 0; aux < tabla[0].getFila().size(); aux++)
			{
				cout << tabla[i].getFila()[aux].getTipoDato() << "\t";
			}
			cout << endl;
		}
		for (int j = 0; j < tabla[i].getFila().size(); j++)
		{
			if (j == 0)
			{
				cout << tabla[i].getId() << "\t";
			}
			cout << tabla[i].getFila()[j].getValor()<<"\t";
		}
		cout << endl;
	}
}

