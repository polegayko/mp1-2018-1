#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

using namespace std; 

class Songster
{
private:
	vector<string> SongName;
	vector<string> Poet;
	vector<string> Composer;
	vector<string> Musician;
	vector<string> Album;
	vector<string> ReleaseDate;
	string tmp;
public:
	Songster() {};
	Songster(const Songster& p)
	{
		SongName = p.SongName;
		Poet = p.Poet;
		Composer = p.Composer;
		Musician = p.Musician;
		Album = p.Album;
		ReleaseDate = p.ReleaseDate;
	}
	Songster& operator=(const Songster& d)
	{
		SongName = d.SongName;
		Poet = d.Poet;
		Composer = d.Composer;
		Musician = d.Musician;
		Album = d.Album;
		ReleaseDate = d.ReleaseDate;
		return *this;
	}
	string operator[](int i)
	{
		string s = SongName[i] + " / " + Poet[i] + " / " + Composer[i] + " / " + Musician[i] + " / " + Album[i] + " / " + ReleaseDate[i];
		return s;
	}
	void AddSong(string name, string poet, string composer, string musician, string album, string date)
	{
		SongName.push_back(name);
		Poet.push_back(poet);
		Composer.push_back(composer);
		Musician.push_back(musician);
		Album.push_back(album);
		ReleaseDate.push_back(date);
		for (int j= SongName.size()-1;j>=0;j--) 
		for (int i = 0; i < j; i++)

			if (SongName[i] > SongName[i + 1])
			{
				tmp = SongName[i];
				SongName[i] = SongName[i + 1];
				SongName[i + 1] = tmp;
				tmp = Poet[i];
				Poet[i] = Poet[i + 1];
				Poet[i + 1] = tmp;
				tmp = Composer[i];
				Composer[i] = Composer[i + 1];
				Composer[i + 1] = tmp;
				tmp = Musician[i];
				Musician[i] = Musician[i + 1];
				Musician[i + 1] = tmp;
				tmp = Album[i];
				Album[i] = Album[i + 1];
				Album[i + 1] = tmp;
				tmp = ReleaseDate[i];
				ReleaseDate[i] = ReleaseDate[i + 1];
				ReleaseDate[i + 1] = tmp;
			}
	}
	void ChangeSongInfo(int i, string name, string poet, string composer, string musician, string album, string date)
	{
		SongName[i]=name;
		Poet[i]=poet;
		Composer[i]=composer;
		Musician[i]=musician;
		Album[i]=album;
		ReleaseDate[i]=date;
	} 
	int FindSong(string s, string s1)
	{
		for (int i = 0; i < SongName.size(); i++)
			if ((SongName[i] == s) && (Musician[i] == s1))
				return i;
		return -1;
	}
	vector<string> FindByPoet(string poet)
	{
		vector<string> fbp; 
		for (int i = 0; i < Poet.size(); i++)
			if (Poet[i] == poet)
			{
				string s = SongName[i] + " / " + Poet[i] + " / " + Composer[i] + " / " + Musician[i] + " / " + Album[i] + " / " + ReleaseDate[i];
				fbp.push_back(s);
			}
		return fbp;
	}
	vector<string> FindByComposer(string composer)
	{
		vector<string> fbc;
		for (int i = 0; i < Composer.size(); i++)
			if (Composer[i]==composer)
			{
				string s = SongName[i] + " / " + Poet[i] + " / " + Composer[i] + " / " + Musician[i] + " / " + Album[i] + " / " + ReleaseDate[i];
				fbc.push_back(s);
			}
		return fbc;
	}
	vector<string> FindByMusician(string musician)
	{
		vector<string> fbm;
		for (int i = 0; i < Musician.size(); i++)
			if (Musician[i] == musician)
				{
					string s = SongName[i] + " / " + Poet[i] + " / " + Composer[i] + " / " + Musician[i] + " / " + Album[i] + " / " + ReleaseDate[i];
					fbm.push_back(s);
				}
		return fbm;
	}
	int CountSong()
	{
		int CountSong = (int)SongName.size();
		return CountSong;
	}
	void ChangeSongDate(int i,string date)
	{
		ReleaseDate[i] = date;
	}
	void DeleteSong(int i)
	{
		SongName.erase(SongName.begin()+i);
		Poet.erase(Poet.begin()+i);
		Composer.erase(Composer.begin()+i);
		Musician.erase(Musician.begin()+i);
		Album.erase(Album.begin()+i);
		ReleaseDate.erase(ReleaseDate.begin()+i);
	}
	void Save()
	{
		ofstream f("Songster");
		for (int i = 0; i < SongName.size(); i++)
		{
			f << SongName[i];
			f << " / ";
			f << Poet[i];
			f << " / ";
			f << Composer[i];
			f << " / ";
			f << Musician[i];
			f << " / ";
			f << Album[i];
			f << " / ";
			f << ReleaseDate[i];
			f << "\n";
		}
		f.close();
	}
	void Open()
	{
		SongName.clear();
		Poet.clear();
		Composer.clear();
		Musician.clear();
		Album.clear();
		ReleaseDate.clear();
		char b[200];
		ifstream f("Songster");
		f >> b;
		while (!f.eof())
		{
			string s1;
			while (b[0] != '/')
			{
				s1 += b;
				s1 += " ";
				f >> b;
			}
			f >> b;
			string s2;
			while (b[0] != '/')
			{
				s2 += b;
				s2 += " ";
				f >> b;
			}
			f >> b;
			string s3;
			while (b[0] != '/')
			{
				s3 += b;
				s3 += " ";
				f >> b;
			}
			f >> b;
			string s4;
			while (b[0] != '/')
			{
				s4 += b;
				s4 += " ";
				f >> b;
			}
			f >> b;
			string s5;
			while (b[0] != '/')
			{
				s5 += b;
				s5 += " ";
				f >> b;
			}
			string s6;
			f >> b;
			s6 = b;
			AddSong(s1, s2, s3, s4, s5, s6);
			f >> b;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Songster s;
	s.AddSong("Ясный мой свет", "Аркадий Славоросов", "Олег Молчанов", "Татьяна Буланова", "Моё русское сердце", "1996");
	s.AddSong("Букет", "Николай Рубцов", "Александр Барыкин", "Александр Барыкин", "Букет", "1988");
	s.Save();
	s.Open();
	for (int i = 0; i < s.CountSong(); i++)
		cout << s[i] << "\n";
	system("pause");
}