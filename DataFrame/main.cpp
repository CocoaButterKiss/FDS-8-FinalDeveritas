#include "COperaciones.h"

using namespace std;

void main()
{
	Operaciones* operaciones = new Operaciones();
	//Prueba de Importacion
	//operaciones->ImportarDatos("BaseDeAutos.txt");
	vector<string> campos;
	//Prueba de funcionalidad Seleccionar
	/*
	campos.push_back("Motor");
	campos.push_back("Color");
	operaciones->Seleccionar(campos);
	*/
	//Prueba de Funcionalidad de Filtro
	/*campos.push_back("Marca");
	campos.push_back("Color");
	operaciones->Filtrar("Finaliza con","a", campos);*/
	//Prueba de Ordenamiento
	//operaciones->Ordenar("Texto", "Marca");
	//Prueba de conversion a CSV
	//operaciones->ConvertirACSV(operaciones->getDataFrame());

	cout << "Ingrese nombre del archivo .txt:"<<endl;
	string nombreArchivo;
	cin >> nombreArchivo;
	operaciones->ImportarDatos(nombreArchivo);
	cout << "Operaciones:" << endl;
	cout << "1. Indexar (No funciona D:)" << endl;
	cout << "2. Seleccionar datos por columnas" << endl;
	cout << "3. Filtrar datos por columnas" << endl;
	cout << "4. Ordenamiento de datos por columnas" << endl;
	cout << "5. Exportar dataframe a un archivo .CSV" << endl;
	cout << "6. Salir" << endl;
	int opcion;
	cin >> opcion;
	string valorFiltro;
	string filtro;
	string auxFlag;
	switch (opcion)
	{
	case 1: 
		cout << "Falta implementar, arboles AVL :(" << endl;
		break;
	case 2:
		cout << "Ingrese cuantos campos desea seleccionar" << endl;
		int cantidadCampos;
		cin >> cantidadCampos;
		for (int i = 0; i < cantidadCampos; i++)
		{
			cout << "Ingrese nombre del encabezado de la columna (Se diferencia entre mayusculas y minusculas)" << endl;
			string aux;
			cin >> aux;
			campos.push_back(aux);
		}
		cout << "¿Desea convertir el resultado a un archivo CSV? (S/N)" << endl;
		cin >> auxFlag;
		if (auxFlag == "S")
		{
			operaciones->setImprimirCSV(true);
		}
		else
		{
			operaciones->setImprimirCSV(false);
		}
		operaciones->Seleccionar(campos);
		campos.clear();
		break;
	case 3:
		cout << "1. Mayor" << endl;
		cout << "2. Menor" << endl;
		cout << "3. Igual a" << endl;
		cout << "4. Inicia con" << endl;
		cout << "5. Finaliza con" << endl;
		cout << "6. Está contenido en" << endl;
		cout << "7. No está contenido en" << endl;
		int opcion1;
		cin >> opcion1;
		switch (opcion1)
		{
		case 1:
			filtro = "Mayor";
			break;
		case 2:
			filtro = "Menor";
			break;
		case 3:
			filtro = "Igual a";
			break;
		case 4:
			filtro = "Inicia con";
			break;
		case 5:
			filtro = "Finaliza con";
			break;
		case 6:
			filtro = "Esta contenido en";
			break;
		case 7:
			filtro = "No esta contenido en";
			break;
		default:
			break;
		}
		cout << "Ingrese el valor para el filtro elegido" << endl;
		cin >> valorFiltro;
		cout << "¿Cuantos campos desea usar para el filtro? (Ambos campos deben tener el mismo tipo de dato y solo se pueden elegir un máximo de 2)" << endl;
		int cantCampos;
		cin >> cantCampos;
		for(int i = 0; i < cantCampos; i++)
		{
			cout << "Ingrese nombre del encabezado de la columna (Se diferencia entre mayusculas y minusculas)" << endl;
			string aux;
			cin >> aux;
			campos.push_back(aux);
		}
		cout << "¿Desea convertir el resultado a un archivo CSV? (S/N)" << endl;
		cin >> auxFlag;
		if (auxFlag == "S")
		{
			operaciones->setImprimirCSV(true);
		}
		else
		{
			operaciones->setImprimirCSV(false);
		}
		operaciones->Filtrar(filtro, valorFiltro, campos);
		break;
	case 4:
		cout << "Ingrese el nombre del encabezado de la columna que se usara como referencia para el ordenamiento:" << endl;
		cin >> filtro;
		cout << "Seleccione el tipo de dato de la columna:" << endl;
		cout << "1. Texto" << endl;
		cout << "2. Numero Entero" << endl;
		cout << "3. Numero Decimal" << endl;
		int opcion2;
		cin >> opcion2;
		switch (opcion2)
		{
		case 1:
			valorFiltro = "Texto";
			break;
		case 2:
			valorFiltro = "Numero Entero";
			break;
		case 3:
			valorFiltro = "Numero Decimal";
			break;
		default:
			break;
		}
		cout << "¿Desea convertir el resultado a un archivo CSV? (S/N)" << endl;
		cin >> auxFlag;
		if (auxFlag == "S")
		{
			operaciones->setImprimirCSV(true);
		}
		else
		{
			operaciones->setImprimirCSV(false);
		}
		operaciones->Ordenar(valorFiltro, filtro);
		break;
	case 5:
		operaciones->ConvertirACSV(operaciones->getDataFrame());
		break;
	default:
		break;
	}
	system("pause");
}
