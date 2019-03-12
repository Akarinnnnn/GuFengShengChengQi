#include "pch.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>
#include <vector>
//能编译
//"aaa,aaa,bb了bb" 等
using namespace std;
typedef vector<wstring> Dictionary;
Dictionary 四字表;
Dictionary 两字表;
Dictionary 句式;

inline wstring 四字()
{
	wstring output = 四字表[(size_t)floor(rand() % 四字表.size())];
	return output;
}

inline wstring 两字()
{
	wstring output = 两字表[(size_t)floor(rand() % 两字表.size())];
	return output;
}

wstring 句子()
{
	wstring output = 句式[(size_t)floor(rand() % 句式.size())];
	wregex aa(L"aa");
	wregex bbbb(L"bbbb");
	while(regex_search(output,aa))
		output = regex_replace(output, aa, 两字(), std::regex_constants::format_first_only);
	while(regex_search(output,bbbb))
		output = regex_replace(output, bbbb, 四字(), std::regex_constants::format_first_only);

	return output;
}

int wmain()
{
	locale chs("chs");
	wcout.imbue(chs);
	{
		ifstream dict2(".\\两字.txt",ios::binary);
		ifstream dict4(".\\四字.txt",ios::binary);
		ifstream sentences(".\\句子.txt",ios::binary);
		dict2.imbue(chs);
		dict4.imbue(chs);
		sentences.imbue(chs);
		while (true) 
		{
			wchar_t t[30] = { 0 };
			for (int i = 0; i < 30; i++)
			{
				sentences.read((char*)(t+i), 2);
				if (t[i] == 0xFEFFUi16)
				{
					i--;
					continue;
				}
				if (t[i] == 0x0020Ui16)
				{
					t[i] = 0x0000;
					break;
				}
				if (sentences.eof())break;
			}
			句式.push_back(t);
			if (sentences.eof())break;
		}
		while (!dict2.eof())
		{
			wchar_t t[3] = { 0 };
			for (int i = 0; i < 3; i++)
			{
				dict2.read((char*)(t + i), 2);
				if (t[i] == 0xFEFFUi16)
				{
					i--;
					continue;
				}
				if (t[i] == 0x0020Ui16)
				{
					t[i] = 0x0000;
					break;
				}
				if (dict2.eof())break;
			}
			两字表.push_back(t);
		}
		while (!dict4.eof())
		{
			wchar_t t[5] = { 0 };
			for (int i = 0; i < 5; i++)
			{
				dict4.read((char*)(t + i), 2);
				if (t[i] == 0xFEFFUi16)
				{
					i--;
					continue;
				}
				if (t[i] == 0x0020Ui16)
				{
					t[i] = 0x0000;
					break;
				}
				if (dict4.eof())break;
			}
			四字表.push_back(t);
		}
		dict2.close();
		dict4.close();
		sentences.close();
	}
	while (true)
	{
		int count = 0;
		wcout << L"输入生成的句子数量" << endl;
		wcin >> count;
		srand((unsigned int)time(nullptr));
		for (int i = 0; i < count; i++)
			wcout << 句子() << endl;
		wcout << endl;
	}	
	system("pause");
}
