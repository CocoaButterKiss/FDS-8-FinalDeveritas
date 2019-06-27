#include <fstream>
#include <iostream>
#include <sstream>
#include<algorithm>

#include "CDataFrame.h"
#include "CompararTextos.h"
class Operaciones
{
public:
	Operaciones();
	~Operaciones();
	DataFrame* getDataFrame()
	{
		return dataFrame;
	}
	void ImportarDatos(string nombreCSV);
	void IndexarDatos();
	void Seleccionar(vector<string> campos);
	void Filtrar(string filtro,string valorFiltro, vector<string> campos);
	void Ordenar(string NumOText, string campo);
	void ConvertirACSV(DataFrame* dataFrame);
	void setImprimirCSV(bool flag)
	{
		imprimirCSV = flag;
	}
private:
	DataFrame * dataFrame;
	bool imprimirCSV;
};

Operaciones::Operaciones()
{
}

Operaciones::~Operaciones()
{
	delete dataFrame;
}
void Operaciones::ImportarDatos(string nombreCSV)
{
	vector<Data> fila;
	vector<Row> tabla;
	string aux;
	int cont = 0;
	int cont2 = 0;
	ifstream Archivo;
	Data data = Data("","");
	Archivo.open(nombreCSV);
	if (!Archivo)
	{
		cout << "No se pudo abrir el archivo :(" << endl;
	}
	while (Archivo>>aux)
	{
		switch (cont)
		{
		case 0: data.setTipoDato(aux);
			cont++;
			if (aux==".")
			{
				Row filaAux = Row(fila, cont2);
				cont2++;
				tabla.push_back(filaAux);
				fila.clear();
				cont = 0;
			}
			break;
		case 1: data.setValor(aux);
			cont--;
			fila.push_back(data);
		default:
			break;
		}
	}
	dataFrame = new DataFrame(tabla);
	dataFrame->imprimirTabla();


}
void Operaciones::IndexarDatos()
{}
void Operaciones::Seleccionar(vector<string> campos)
{
	DataFrame* dataFrameAux;
	vector<Row> tabla;
	vector<Data> fila;
	for (int i = 0; i < dataFrame->getTabla().size(); i++)
	{
		for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
		{
			for (int k = 0; k < campos.size(); k++)
			{
				if (campos[k] == dataFrame->getTabla()[i].getFila()[j].getTipoDato())
				{
					fila.push_back(dataFrame->getTabla()[i].getFila()[j]);
				}
			}
		}
		Row filaAux = Row(fila, i);
		tabla.push_back(filaAux);
		fila.clear();
	}
	dataFrameAux = new DataFrame(tabla);
	dataFrameAux->imprimirTabla();
	if (imprimirCSV)
	{
		this->ConvertirACSV(dataFrameAux);
		imprimirCSV = false;
	}
}
void Operaciones::Filtrar(string filtro,string valorFiltro,vector<string> campos)
{
	DataFrame* dataFrameAux;
	vector<Row> tabla;
	for (int i = 0; i < dataFrame->getTabla().size(); i++)
	{
		for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
		{

			for (int k = 0; k < campos.size(); k++)
			{
				if (campos[k] == dataFrame->getTabla()[i].getFila()[j].getTipoDato())
				{
					string valor = dataFrame->getTabla()[i].getFila()[j].getValor();

					if (filtro == "Mayor")
					{
						std::istringstream iss(valorFiltro);
						std::istringstream iss1(valor);
						int valorFiltro1;
						int valorCampo;
						iss >> valorFiltro1;
						iss1 >> valorCampo;
						if (valorCampo>valorFiltro1)
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size()-1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if (filtro == "Menor")
					{
						std::istringstream iss(valorFiltro);
						std::istringstream iss1(valor);
						int valorFiltro1;
						int valorCampo;
						iss >> valorFiltro1;
						iss1 >> valorCampo;
						if (valorCampo<valorFiltro1)
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if (filtro == "Igual a")
					{
						std::istringstream iss(valorFiltro);
						std::istringstream iss1(valor);
						int valorFiltro1;
						int valorCampo;
						iss >> valorFiltro1;
						iss1 >> valorCampo;
						if (valorCampo==valorFiltro1)
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if(filtro=="Inicia con")
					{
						if (valor[0] == valorFiltro[0])
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if (filtro == "Finaliza con")
					{
						if ( valor[valor.size()-1]== valorFiltro[0])
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if (filtro == "Esta contenido en")
					{
						if (valor.find(valorFiltro)!=std::string::npos)
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
					else if (filtro == "No esta contenido en")
					{
						if (valor.find(valorFiltro) == std::string::npos)
						{
							tabla.push_back(dataFrame->getTabla()[i]);
							if (i < dataFrame->getTabla().size() - 1)
							{
								i++;
								j = 0;
							}
						}
					}
				}
			}
		}
	}
	dataFrameAux = new DataFrame(tabla);
	dataFrameAux->imprimirTabla();
	if (imprimirCSV)
	{
		this->ConvertirACSV(dataFrameAux);
		imprimirCSV = false;
	}
}
void Operaciones::Ordenar(string NumOText, string campo)
{
	DataFrame* dataFrameAux;
	vector<Row> tabla;
	vector<Data> fila;
	int posCampo = 0;
	string DataType = "";
	if (NumOText == "Texto")
	{
		vector<Entrada<string>> diccionario;
		Entrada<string> entradaAux = Entrada<string>("", 0);
		for (int i = 0; i < dataFrame->getTabla().size(); i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
				{
					if (dataFrame->getTabla()[i].getFila()[j].getTipoDato() == campo)
					{
						posCampo = j;
						break;
					}
				}
			}
			entradaAux.setId(dataFrame->getTabla()[i].getId());
			entradaAux.setValor(dataFrame->getTabla()[i].getFila()[posCampo].getValor());
			diccionario.push_back(entradaAux);
		}
		sort(diccionario.begin(), diccionario.end(), [](Entrada<string>& valorIzq, Entrada<string>& valorDec) {
			return valorIzq.getValor() < valorDec.getValor();
		});
		for (int i = 0; i < diccionario.size(); i++)
		{
			tabla.push_back(dataFrame->getTabla()[diccionario[i].getId()]);
		}
	}
	else if (NumOText == "Numero Entero")
	{
		vector<Entrada<int>> diccionario;
		Entrada<int> entradaAux = Entrada<int>(0, 0);
		for (int i = 0; i < dataFrame->getTabla().size(); i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
				{
					if (dataFrame->getTabla()[i].getFila()[j].getTipoDato() == campo)
					{
						posCampo = j;
						break;
					}
				}
			}
			std::istringstream iss(dataFrame->getTabla()[i].getFila()[posCampo].getValor());
			int valorCampo;
			iss >> valorCampo;
			entradaAux.setId(dataFrame->getTabla()[i].getId());
			entradaAux.setValor(valorCampo);
			diccionario.push_back(entradaAux);
		}
		std::sort(diccionario.begin(), diccionario.end(), [](Entrada<int>& valorIzq, Entrada<int>& valorDec) {
			return valorIzq.getValor() < valorDec.getValor();
		});
		for (int i = 0; i < diccionario.size(); i++)
		{
			tabla.push_back(dataFrame->getTabla()[diccionario[i].getId()]);
		}
	}
	else if(NumOText == "Numero Decimal")
	{
		vector<Entrada<double>> diccionario;
		Entrada<double> entradaAux = Entrada<double>(0.0f, 0);
		for (int i = 0; i < dataFrame->getTabla().size(); i++)
		{
			if (i == 0)
			{
				for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
				{
					if (dataFrame->getTabla()[i].getFila()[j].getTipoDato() == campo)
					{
						posCampo = j;
						break;
					}
				}
			}
			std::istringstream iss(dataFrame->getTabla()[i].getFila()[posCampo].getValor());
			double valorCampo;
			iss >> valorCampo;
			entradaAux.setId(dataFrame->getTabla()[i].getId());
			entradaAux.setValor(valorCampo);
			diccionario.push_back(entradaAux);
		}
		std::sort(diccionario.begin(), diccionario.end(), [](Entrada<double>& valorIzq, Entrada<double>& valorDec) {
			return valorIzq.getValor() < valorDec.getValor();
		});
		for (int i = 0; i < diccionario.size(); i++)
		{
			tabla.push_back(dataFrame->getTabla()[diccionario[i].getId()]);
		}
	}
	dataFrameAux = new DataFrame(tabla);
	dataFrameAux->imprimirTabla();
	if (imprimirCSV)
	{
		this->ConvertirACSV(dataFrameAux);
		imprimirCSV = false;
	}
}
void Operaciones::ConvertirACSV(DataFrame* dataFrame)
{
	std::ofstream myfile;
	myfile.open("Output.csv");
	for (int i = 0; i < dataFrame->getTabla().size(); i++)
	{
		if (i == 0)
		{
			myfile << "ID"<<";";
			for (int k = 0; k < dataFrame->getTabla()[0].getFila().size(); k++)
			{
				myfile << dataFrame->getTabla()[0].getFila()[k].getTipoDato()<<";";
			}
			myfile << endl;
		}
		for (int j = 0; j < dataFrame->getTabla()[i].getFila().size(); j++)
		{
			if (j == 0)
			{
				myfile << dataFrame->getTabla()[i].getId()<<";";
			}
			myfile << dataFrame->getTabla()[i].getFila()[j].getValor() << ";";
		}
		myfile << endl;
	}
	myfile.close();
}
