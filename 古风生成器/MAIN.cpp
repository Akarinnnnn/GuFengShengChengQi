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
	wstring output = 四字表[(size_t)floor(rand() % 四字表.size() + 1)];
	return output;
}

inline wstring 两字()
{
	wstring output = 两字表[(size_t)floor(rand() % 两字表.size() + 1)];
	return output;
}

wstring 句子()
{
	wstring output = 句式[(size_t)floor(rand() % 句式.size() + 1)];
	wregex aa(L"aa");
	wregex bbbb(L"bbbb");
	while(regex_match(output,aa))
		output = regex_replace(output, aa, 两字(), std::regex_constants::format_first_only);
	while(regex_match(output,bbbb))
		output = regex_replace(output, aa, 两字(), std::regex_constants::format_first_only);

	return output;
}

int wmain()
{
	locale chs("chs");
	wcout.imbue(chs);
	{
		ifstream dict2(".\\两字.txt");
		ifstream dict4(".\\四字.txt");
		ifstream sentences(".\\句子.txt");
		dict2.imbue(chs);
		dict4.imbue(chs);
		sentences.imbue(chs);
		while (!sentences.eof())
		{
			wchar_t t[20] ={0};
			sentences.get((char*)t, 20*2, L' ');
			句式.push_back(t);
		}
		while (!dict2.eof())
		{
			wchar_t t[3] = { 0 };
			dict2.get((char*)t, 3*2);
			两字表.push_back(t);
		}
		while (!dict4.eof())
		{
			wchar_t t[5] = { 0 };
			dict4.get((char*)t, 5*2);
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
	}	
	system("pause");
}
