#include <iostream>
#include <fstream>
#include <codecvt>
#include <locale>
using namespace std;

int main()
{
    locale china("chs");//use china character
	wcin.imbue(china);//use locale object
	wcout.imbue(china);

    wstring content ;
    wcin>>content;
    wcout<<endl<<content;
    wofstream ofs("save_as_utf_8_no_bom.txt", ios::ate);
    ofs.imbue(std::locale(ofs.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>));
    ofs << content;
    ofs.close();
    return 0;
}