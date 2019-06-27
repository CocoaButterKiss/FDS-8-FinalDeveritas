#include "CData.h"
#include <vector>

class Row
{
public:
	Row(vector<Data> campos, int id);
	~Row();
	vector<Data> getFila()
	{
		return fila;
	}
	int getId()
	{
		return id;
	}
private:
	vector<Data> fila;
	int id;
};

Row::Row(vector<Data> campos, int id)
{
	fila = campos;
	this->id = id;
}

Row::~Row()
{
	fila.clear();
}
