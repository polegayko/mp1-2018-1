#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

using namespace std;

class BullsAndCows
{
private:
	int n;
	string s;
	string sc;
	int i;
	int j;
	string bac;
public:
	BullsAndCows(int _n; string _s)
	{
		n = _n;
		s = _s;
	}
	string MakeANumber(int _n)
	{
		RAND_MAX = 9;
		for (i = 0; i < n; i++)
		{
			sc[i] = rand();
			for (j = 0; j < i; i++)
				if (sc[i] == sc[j])
					sc[i] = rand();
		}
		return sc;
			
	}
	string BACGame(string _s)
	{
		for (i = 0; i < n; i++)
			for (j = i; j < n; j++)
				if (s[i] == s[j])
					return -1;
		bac[1] = 0;
		bac[2] = 0;
		for (i = 0; i < n; i++)
		{
			if (sc[i] == s[i])
				bac[2] = bac[2] + 1;
			else
				for (j = i; j < n; j++)
					if (sc[j] == s[i])
						bac[1] = bac[1] + 1;
		}
		return s;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	BullsAndCows G;
	MakeANumber(4);
	cout << "Коровы - " << BACGame(1324)[1] << "\n" << "Быки - " << BACGame(1324)[2] << "\n";

}