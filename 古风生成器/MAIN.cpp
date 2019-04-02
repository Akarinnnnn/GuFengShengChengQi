#include "pch.h"
#include <iostream>
#include <cwchar>
#include <cstdio>
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
#if _WIN32
template <unsigned int length>
void read(Dictionary& D, FILE* f)
{
	while (!feof(f))
	{
		wchar_t temp[length+1] = { 0 };
		fwscanf_s(f, L"%s",temp,length+1);
		D.push_back(temp);
	}
}
#endif
int wmain()
{
	locale chs("chs");
	wcout.imbue(chs);
	{
#if _WIN32
		FILE* dict2 = nullptr;
		FILE* dict4 = nullptr;
		FILE* sentences = nullptr;
		_wfopen_s(&dict2, L".\\两字.txt", L"rt,ccs=UNICODE");
		_wfopen_s(&dict4, L".\\四字.txt", L"rt,ccs=UNICODE");
		_wfopen_s(&sentences, L".\\句子.txt", L"rt,ccs=UNICODE");
		read<2>(两字表, dict2);
		read<4>(四字表, dict4);
		read<25>(句式, sentences);
		_fcloseall();
#endif // WINDOWS
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
}
