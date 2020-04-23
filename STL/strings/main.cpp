#include <iostream>
#include <string>
//#define C_WIDE_STRINGS

void main()
{
	setlocale(LC_ALL, ".OCP");
#ifdef C_WIDE_STRINGS
	wchar_t str[256] = L"Привет";
	std::wcout << str << std::endl;

	std::cout << sizeof(wchar_t) << std::endl;
	std::wcout << L"Введите строку: "; std::wcin >> str;
	//std::wcin.getline (str,256);
	wcscat_s(str, 256, L"World!");
	std::wcout << str << std::endl;
	std::wcout << wcslen(str) << std::endl;
#endif // C_WIDE_STRINGS
	std::wstring str = L"Hello world";
	std::wcout << str << std::endl;
}