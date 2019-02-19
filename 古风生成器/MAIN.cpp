#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
//能编译
//"aaa,aaa,bb了bb" 等
using namespace std;
typedef vector<wstring> 词典;
词典 四字表;
词典 两字表;
词典 句式;

wstring 四字()
{
	return wstring();
}

wstring 两字()
{
	return wstring();
}

wstring 句子()
{
	return wstring();
}

int wmain()
{
	wcout.imbue(locale("chs"));
	wifstream dict2(L"两字.txt");
	wifstream dict4(L"四字.txt");
	wifstream stances(L"句子");
	while (!stances.eof())
	{
		wchar_t t[20];
		stances >> t;
		句式.push_back(t);
	}
	while (!dict2.eof())
	{
		wchar_t t[2];
		stances >> t;
		两字表.push_back(t);
	}
	while (!dict4.eof())
	{
		wchar_t t[4];
		stances >> t;
		四字表.push_back(t);
	}
	dict2.close();
	dict4.close();
	stances.close();

}
