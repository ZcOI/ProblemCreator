#include <io.h>
#include <fcntl.h>
#include <iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>

using namespace std;
std::string WStringToString(const std::wstring &wstr)
{
    std::string str;
    int nLen = (int)wstr.length();
    str.resize(nLen, ' ');
    int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);
    if (nResult == 0)
    {
        return "";
    }
    return str;
}
std::wstring StringToWString(const std::string& str)
{
    setlocale(LC_ALL, "chs");
    const char* point_to_source = str.c_str();
    size_t new_size = str.size() + 1;
    wchar_t *point_to_destination = new wchar_t[new_size];
    wmemset(point_to_destination, 0, new_size);
    mbstowcs(point_to_destination, point_to_source, new_size);
    std::wstring result = point_to_destination;
    delete[]point_to_destination;
    setlocale(LC_ALL, "C");
    return result;
}
void preout(){
    cout<<"<!DOCTYPE html><html lang=\"zh\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>AkyOI~AkyooOI</title><link href=\"https://www.2weima.com/static/gongshi/mathml.css/mathml.css\" rel=\"stylesheet\" ><link rel=\"stylesheet\" href=\"../CSS/reset.css\"><link rel=\"stylesheet\" href=\"../CSS/head.css\"><link rel=\"shortcut icon\" href=\"https://s1.ax1x.com/2022/12/23/zjSIPS.jpg\"><style>.back{z-index: -999;background-color: rgba(255,255,255,0.7);position: fixed;width: 100%; height: 100%;}*{background-repeat: no-repeat;}html,main{height: auto;width: 100%;/* background-color:rgba(255,255,255,0.7); */}";
    cout<<"\n/* ------------------------------------------------------------------- */\n";
    cout<<".prob{background-color: rgba(255, 255, 255,0.7);position: relative;top: 40px;border: 2px solid blueviolet;border-radius: 10px;width: 70%;margin-left: 15%;margin-right: 15%;line-height: 20px;}\n"
    <<".probhead{font-family: 'Cascadia Code','楷体', Courier, monospace;color: rgb(135, 0, 212);height: 50px;line-height: 50px;font-size: 40px;}\n"
    <<".cont{font-family: 'Consolas', Courier, monospace;font-size: 20px;line-height: 25px;}\n"
    <<".part{margin-bottom: 20px;line-height: 30px;font-size: 28px;font-family: 'Consolas', Courier, monospace;}"
    <<".prob a{text-decoration: none;line-height: 100%; font-size: 25px;font-family: 'Consolas', Courier, monospace;}\n"
    <<".ttop a{text-decoration: none;line-height: 100%; font-size: 25px;font-family: 'Consolas', Courier, monospace;}\n"
    <<".input,.output{font-family: 'Consolas', Courier, monospace;line-height: 25px;/* width: auto; */border: 1px solid black;border-radius: 5px;margin: 5px;background-color: rgba(137, 178, 255,0.5);}\n"
    <<".ttop{/* box-shadow: 1px 1px; */font-family: 'Courier New', Courier, monospace;font: bold;text-align: center;line-height: 80px;font-size: 30px;height: 80px;width: 80px;border: 2px solid black;border-radius: 50px;position:fixed;right: 40px;bottom: 60px;float: right;background-color: #fff;color: blueviolet;}\n"
    <<"/* ------------------------------------------------------------------- */\n"
    <<"</style><script type=\"text/javascript\" src=\"http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=AM_HTMLorMML-full\"></script></head>\n"
    <<"<body>\n<header>\n<div><ul class=\"head1\"><li><a href=\"../index.html\">~AkyOI~</a></li></ul></div><div><ul class=\"head1\"><li><a href=\"../ProblemList/\">ProblemList</a></li></ul></div><div><ul class=\"head1\"><li><a href=\"../Softwares/\">Softwares</a><ul class=\"part1\"><li><a href=\"../Softwares/Online/\">OnlineJudge</a></li><li><a href=\"../Softwares/Offline/\">OfflineJudge</a></li></ul></li></ul></div><div><ul class=\"head1\"><li><a href=\"../Downloads/\">Downloads</a><ul class=\"part1\"><li><a href=\"../Downloads/Problems/\">Problems</a></li><li><a href=\"../Downloads/Books/\">EBooks</a></li><li><a href=\"../Downloads/Learning/\">Learning</a></li></ul></li></ul></div><div><ul class=\"head1\"><li><a href=\"../About/\">About</a></li></ul></div></header><div class=\"back\"></div><main><div class=\"prob\"><div class=\"probhead\">\n";
}
void writecontent(){
    wcout<<endl;
    wstring text;
    while(getline(wcin,text)){
        string ck=WStringToString(text);
        if(ck[ck.length()-4]=='#' && ck[ck.length()-3]=='e' && ck[ck.length()-2]=='n' && ck[ck.length()-1]=='d')break;
        wcout<<text<<L"<br>";
    }
}
void writesample(int label,string filename,int fd_stdout,int fd_stdin){
    
    wcout<<L"\nEnter the input of the sample "<<label<<" , leaving a line #end at the end:\n";
    freopen(filename.c_str(),"a",stdout);
    wcout<<L"\n<li><div class=\"cont\">Input#"<<label<<L":</div><div class=\"input\">";
    wstring content;
    while(getline(wcin,content)){
        string ck=WStringToString(content);
        if(ck[ck.length()-4]=='#' && ck[ck.length()-3]=='e' && ck[ck.length()-2]=='n' && ck[ck.length()-1]=='d')break;
        wcout<<content<<L" <br>";
    }
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");
    wcout<<L"\nThe output of the sample "<<label<<" , the last line #end:\n";
    freopen(filename.c_str(),"a",stdout);
    wcout<<L"</div><div class=\"cont\">Output#"<<label<<L":</div><div class=\"output\">";
    wstring ans;
    while(getline(wcin,ans)){
        string ck=WStringToString(ans);
        if(ck[ck.length()-4]=='#' && ck[ck.length()-3]=='e' && ck[ck.length()-2]=='n' && ck[ck.length()-1]=='d')break;
        wcout<<ans<<L" <br>";
    }
    wcout<<L"</div></li>\n";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");
    
}
int main()
{
    const int fd_stdout = dup( fileno(stdout) );
    const int fd_stdin=dup(fileno(stdin));
    // _setmode(_fileno(stdout), _O_U16TEXT); // 重点
    // _setmode(_fileno(stdin), _O_U16TEXT);  // 重点
    wstring name;
    wstring wproblemnumber;
    string problemnumber;

    wcout<<L"Enter the question number (number only such as 1, 2, 100):";
    wcin>>wproblemnumber;
    problemnumber=WStringToString(wproblemnumber);
    wcout<<endl;

    wcout<<L"Input Question Objective:";
    wstring problemhead;
    wcin>>problemhead;
    wcout<<endl;

    wcout<<L"Input the Question, please add #end at the end:"<<endl;
    string filename="A";
    for(int i=0;i<5-problemnumber.length();i++)filename+="0";
    filename+=problemnumber;
    problemhead=StringToWString(filename)+L"  "+problemhead;
    filename+=".html";
    freopen(filename.c_str(),"a",stdout);
    preout();
    wcout<<problemhead;
    wcout<<L"\n</div><br><br><div class=\"part\">[Descriptions]</div><div class=\"cont\">";
    writecontent();
    wcout<<L"\n</div><div class=\"part\"><br>[Input Form]</div><div class=\"cont\">";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    wcout<<L"[Input form], please add #end at the end:"<<endl;
    freopen(filename.c_str(),"a",stdout);
    writecontent();
    wcout<<L"\n</div><div class=\"part\"><br>[Output Form]</div><div class=\"cont\">";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    wcout<<L"[Output form], please add #end at the end:"<<endl;
    freopen(filename.c_str(),"a",stdout);
    writecontent();
    wcout<<L"\n</div><div class=\"part\"><br>[Samples]</div><ul>";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    int samplenum;
    wcout<<"Number of samples:";
    cin>>samplenum;
    wcout<<endl;
    
    for(int i=1;i<=samplenum;i++)writesample(i,filename,fd_stdout,fd_stdin);
    freopen(filename.c_str(),"a",stdout);
    wcout<<L"\n</ul><div class=\"part\"><br>[Limits]</div><div class=\"cont\">Time: ";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    wcout<<L"Time limit, in the format of number + unit (e.g. 1s, 512ms):";
    wstring timelimits;
    wcin>>timelimits;
    wcout<<endl;
    freopen(filename.c_str(),"a",stdout);
    wcout<<timelimits;
    wcout<<L"<br>Memory: ";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    wcout<<L"Space restrictions, in the format of numbers + units (e.g. 1Gib, 512MB):";
    wstring memlimits;
    wcin>>memlimits;
    wcout<<endl;
    freopen(filename.c_str(),"a",stdout);
    wcout<<memlimits;
    wcout<<L"\n<br><br>Data-Limits: ";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    //fdopen(fd_stdout, "w" );
    //fdopen(fd_stdin,"r");

    wcout<<L"Data Limits:";
    wstring datalimits;
    wcin>>datalimits;
    wcout<<endl;
    freopen(filename.c_str(),"a",stdout);
    wcout<<datalimits;
    wcout<<L"\n     <br></div><br></div><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br></main><div class=\"footer\">AkyOI ~ 2022 | By Zchared </div\n</body>\n</html>";
    fclose(stdout);wcout.clear();freopen("CON","w",stdout);
    return 0;
}
