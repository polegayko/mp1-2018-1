#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 
#include <string>
#include <vector>
#include <locale.h> 
using namespace std;

struct Goods
{
	string name;
	string barcode;
	double price;
	double discount;
	int count = 1;
	Goods &operator=(const Goods &g)
	{
		barcode = g.barcode;
		name = g.name;
		price = g.price;
		count = g.count;
		discount = g.discount;
		return *this;
	}
	friend ostream &operator<<(ostream &os, const Goods &ch);
};
ostream &operator<<(ostream &os, const Goods &gd)
{
	os << "Штрихкод: " << gd.barcode << endl;
	os << "Наименование: " << gd.name << endl;
	os << "Цена: " << gd.price << endl;
	os << "Скидка: " << gd.discount << endl;
	os << "Количество: " << gd.count << endl;
	return os;
}
struct Check
{
	vector<Goods> goods;
	double cost;
	double finalCost;
	double sumdiscount;
	Check &operator=(const Check &g)
	{
		goods = g.goods;
		cost = g.cost;
		finalCost = g.finalCost;
		sumdiscount = g.sumdiscount;
		return *this;
	}
	friend ostream &operator<<(ostream &os, const Check &pr);
};
ostream &operator<<(ostream &os, const Check &pr)
{
	os << "Check:" << endl;
	for (int i = 0; i < pr.goods.size(); i++)
	{
		os << "Штрихкод: " << pr.goods[i].barcode << endl;
		os << "Наименование: " << pr.goods[i].name << endl;
		os << "Цена: " << pr.goods[i].price << endl;
		os << "Скидка: " << pr.goods[i].discount << endl;
		os << "Количество: " << pr.goods[i].count << endl;
	}
	os << endl;
	os << "Стоимость: " << pr.cost << endl;
	os << "Суммарная скидка: " << pr.sumdiscount << endl;
	os << "Итоговая стоимость: " << pr.finalCost << endl << endl;
	return os;
};

class Stock
{
protected:
	vector<Goods> goods;
public:
	Stock & operator=(const Stock &st)
	{
		if (this == &st)
			return *this;
		else
		{
			goods = st.goods;
		}
	}

	void AddGoodsInStock(Goods good)
	{
		goods.push_back(good);
	}
};
class CashBox :public Stock
{
	Check check;
	vector<Goods> goodsScan;
public:
	CashBox & operator=(const CashBox &sc)
	{
		if (this == &sc)
			return *this;
		else
		{
			check = sc.check;
			goodsScan = sc.goodsScan;
		}
	}
	bool ScanProduct(string _barcode)
	{
		for (int i = 0; i < goodsScan.size(); i++)
		{
			if (_barcode == goodsScan[i].barcode)
			{
				goodsScan[i].count++;
				return true;
			}
		}
		for (int i = 0; i <goods.size(); i++)
		{
			if (goods[i].barcode == _barcode)
			{
				goodsScan.push_back(goods[i]);
				return true;
			}
		}
		return false;
	}
	void ShowGoods(string _barcode)
	{
		for (int i = 0; i < goods.size(); i++)
		{
			if (_barcode == goods[i].barcode)
			{
				cout << goods[i] << endl;
				return;
			}
		}
	}
	void ShowStock()
	{
		for (int i = 0; i < goods.size(); i++)
		{
			cout << goods[i] << endl;;
		}
	}
	void GoodsInCheck()
	{
		for (int i = 0; i < goodsScan.size(); i++)
		{
			check.goods.push_back(goodsScan[i]);
		}
	}
	Check FormCheck()
	{
		check.cost = 0;
		check.finalCost = 0;
		check.sumdiscount = 0;
		for (int i = 0; i < check.goods.size(); i++)
		{
			check.cost += check.goods[i].price * check.goods[i].count;
			check.finalCost += check.goods[i].price * check.goods[i].count*(1 - (check.goods[i].discount / 100));
		}
		check.sumdiscount = check.cost - check.finalCost;
		return check;
	}
	double FinalCost()
	{
		double _finalCost = 0;
		for (int i = 0; i < goodsScan.size(); i++)
		{
			_finalCost += goodsScan[i].price*(1 - (goodsScan[i].discount / 100));
		}
		return _finalCost;
	}
	void DeleteGood(string _barcode)
	{
		for (int i = 0; i < goodsScan.size(); i++)
		{
			if (_barcode == goodsScan[i].barcode)
			{
				if (goodsScan[i].count == 1)
				{
					goodsScan.erase(goodsScan.begin() + i);
					return;
				}
				else
				{
					goodsScan[i].count--;
					return;
				}
			}
		}
	}
	void Clear()
	{
		check.goods.clear();
		goodsScan.clear();
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	CashBox cashbox;
	string _barcode;
	string _name;
	double _price;
	double _discount;
	cashbox.AddGoodsInStock({ _barcode="1488",_name="chocolate",_price=350,_discount=15 });
	cashbox.AddGoodsInStock({ _barcode = "1337",_name = "духи",_price = 3530,_discount = 25 });
	cashbox.ShowGoods(_barcode="1488");


	system("pause");
}
