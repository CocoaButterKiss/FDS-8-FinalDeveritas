template<class T>
class Entrada
{
public:
	Entrada(T valor,int id)
	{
		this->valor = valor;
		this->id = id;
	}
	~Entrada()
	{

	}
	void setId(int id)
	{
		this->id = id;
	}
	void setValor(T valor)
	{
		this->valor = valor;
	}
	T getValor()
	{
		return valor;
	}
	int getId()
	{
		return id;
	}

private:
	T valor;
	int id;
};
