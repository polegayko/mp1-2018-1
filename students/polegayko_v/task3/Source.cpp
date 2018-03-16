#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary
{
private:
	vector<string> EnglishWord;
	vector<string> Translation;
	int FindWord(string s)
	{
		for (int i = 0; i < EnglishWord.size(); i++)
			if (EnglishWord[i] == s)
				return i;
		return -1;
	}

public:
	Dictionary() {};
	Dictionary(const Dictionary& ER)//ER - англо-русский
	{
		EnglishWord = ER.EnglishWord;
		Translation = ER.Translation;
	}
	Dictionary& operator=(const Dictionary& d)
	{
		EnglishWord = d.EnglishWord;
		Translation = d.Translation;
		return *this;
	}
	int AddWord(string enword, string translation)
	{
		EnglishWord.push_back(enword);
		Translation.push_back(translation);
		return EnglishWord.size();
	}
	string& operator[](const string& e)
	{
		int i = FindWord(e);
		if (i != -1)
		return Translation[i];
		else throw("error");
	}
	bool CheckWord(const string& enword)
	{
		if (FindWord(enword) != -1)
			return true;
		else return false;
	}
	int SizeD()
	{
		return EnglishWord.size();
	}
	void Save()
	{
		ofstream f("DictionaryER");
		for (int i = 0; i < EnglishWord.size(); i++)
		{
			f << EnglishWord[i];
			f << " - ";
			f << Translation[i];
			f << "\n";
		}
		f.close();
	}
	void Open()
	{
		EnglishWord.clear();
		Translation.clear();
		char b[200];
		ifstream f("DictionaryER");
		f >> b;
		while (!f.eof())
		{
			string s1(b);
			f >> b;
			f >> b;
			string s2(b);
			AddWord(s1, s2);
			f >> b;
		}
	}

};
void main()
{
	setlocale(LC_ALL, "");
	Dictionary d;
	d.AddWord("pot", "горшок");
	d.AddWord("cat", "кот");
	d.Save();
	d.Open();

	system("pause");
}