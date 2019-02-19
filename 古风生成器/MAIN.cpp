#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
//能编译
//"aaa,aaa bb了bb" 等
using namespace std;
typedef vector<wstring> 词典;
词典 四字表;
词典 两字表;
词典 句式;

wstring 四字()
{

}

wstring 两字()
{

}

wstring 句子()
{

}

int wmain()
{
	wcout.imbue(locale("chs"));
	wifstream dict2(L".\\两字.txt");
	wifstream dict4(L".\\四字.txt");
	wifstream stances(L".\\句子");
	
}
