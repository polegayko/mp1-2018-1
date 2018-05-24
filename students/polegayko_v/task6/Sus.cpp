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
	int bac[2];
public:
	BullsAndCows() {}
	bool IsItNumberOkay()
	{
		for (j = 0; j < i; j++)
			if (sc[i] == sc[j])
				return false;
		return true;
	}
	string MakeANumber(int _n)
	{
		n = _n;
		for (i = 0; i < n; i++)
			sc += " ";
		for (i = 0; i < n; i++)
		{
			sc[i] ='0'+ rand() % 10;
			while (!IsItNumberOkay())
				sc[i] ='0'+ rand() % 10;
		}
		return sc;

	}
	int* BACGame(string _s)
	{
		s = _s;
		bac[0] = 0;
		bac[1] = 0;
		for (i = 0; i < n; i++)
		{ 
			for (j = 0; j < n; j++)
					if (sc[i] == s[j]) 
					{
						if(i == j)
						bac[1]++;
						else bac[0]++;
					}
		}
		return bac;
	}
};
void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	BullsAndCows G;
	G.MakeANumber(4);
	string s;
	cin >> s;
	while (G.BACGame(s)[1] != 4)
	{
		cout << "Коровы - " << G.BACGame(s)[0] << "\n" << "Быки - " << G.BACGame(s)[1] << "\n";
		cin >> s;
	}
	system("pause");
}