#include <iostream>

using namespace std;
class DinamMass
{
private:
	double* m;
	int c;
public:
	DinamMass(int _c, double *_m);
	DinamMass(const DinamMass& d);
	~DinamMass();
	void SetMassSize(int s);
	int GetMassSize();
	double MinElem();
	bool Order();
	DinamMass SubOdd();
	void Consol();
	


	DinamMass& operator=(const DinamMass& a)
	{
		if (this != &a)
		{
			if (c != a.c)
			{
				delete[] m;
				m = new double[a.c];
			}

			c = a.c;
			for (int i = 0; i < c; i++)
				m[i] = a.m[i];
		}
		return *this;
	}
	double& operator[] (int a)
	{
		return m[a];
	}

};
	DinamMass::DinamMass(const DinamMass& d)
	{
		if (this != &d)
		{
			if (c != d.c)
			{
				if (c>0)
				delete[] m;
				m = new double[d.c];
			}
		

			c = d.c;
			for (int i = 0; i < c; i++)
				m[i] = d.m[i];
		}	
	}
	DinamMass::DinamMass(int _c, double *_m)
	{
	if (_c > 0)
	{
		c = _c;
		m = new double[c];
		for (int i = 0; i < c; i++)
			m[i] = _m[i];

	}
	}
	DinamMass::~DinamMass()
	{
		delete[] m;
	}
	void DinamMass::SetMassSize(int s)
	{
		if (s > 0 && s != c)
		{
			DinamMass tmp(s, m);
			*this = tmp;


		}
	}
	
	int DinamMass::GetMassSize()
	{
		return c;
	}
	
	double DinamMass::MinElem()
	{
		double min = m[0];
		for (int i = 0; i < c; i++)
			if (m[i] < min)
				m[i] = min;
		return min;
	}
	bool DinamMass :: Order()
	{
		for (int i = 1; i < c; i++)
			if (m[i - 1] <= m[i])
				return true;
			else return false;  
	}
	DinamMass DinamMass::SubOdd()
	{
		int oc = (c / 2);
		double *_m = new double[oc];
		for (int i = 0; i < oc; i++)
			_m[i] = m[i * 2 + 1];
		DinamMass om(oc, _m);
		delete[] _m;
		return om;
	}
	void DinamMass::Consol()
	{
		cout << "size:" << c << "\n";
		cout << "mass = {";
		for (int i = 0; i < c-1; i++)
			cout <<" " << m[i] << ",";
		cout <<" "<< m[c-1] <<"}";
	}




int main()
{
	double ar[] = { 6,2,18,13,12.5,0,2 };

	DinamMass a(7, ar);
	a.SetMassSize(5);
	a.Consol();

	system("pause");


}