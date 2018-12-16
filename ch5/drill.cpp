#include <iostream>
#include <vector>

// Cout << "Success!\n";
// std::cout << "Success!\n";
//
// cout << "Success!\n;
// std::cout << "Success!\n";
//
// cout << "Success" << !\n";
// std::cout << "Success" << "!\n";
//
// cout << success << '\n';
// std::cout << "Success!" << '\n';
//
// string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
// int res = 7; std::vector<int> v(10); v[5] = res; std::cout << "Success!\n";
//
// vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
// std::vector<int> v(10); v[5] = 7; if (v[5]==7) std::cout << "Success!\n";
//
// if (cond) cout << "Success!\n"; else cout << "Fail!\n";
// if (true) std::cout << "Success!\n"; else std::cout << "Fail!\n";
//
// bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
// bool c = true; if (c) std::cout << "Success!\n"; else std::cout << "Fail!\n";
//
// string s = "ape"; boo c = "fool" <s; if (c) cout << "Success!\n";
// std::string s = "ape"; bool c = "fool" >s; if (c) std::cout << "Success!\n";
//
// string s = "ape"; if (s=="fool") cout << "Success!\n";
// std::string s = "ape"; if (s!="fool") std::cout << "Success!\n";
//
// string s = "ape"; if (s=="fool") cout < "Sucess!\n";
// std::string s = "ape"; if (s!="fool") std::cout << "Success!\n";
//
// string s = "ape"; id (s+"fool") cout < "Success!\n";
// std::string s = "ape"; if (s!="fool") std::cout << "Success!\n";
//
// vector<char> v(5); for (int i=0; 0<v.size(); ++i); cout << "Success!\n";
// std::vector<char> v(5); for (int i=0; i<v.size(); ++i); std::cout << "Success!\n";
//
// vector<char> v(5); for (int i=0; i<=v.size(); ++i); cout << "Success!\n";
// std::vector<char> v(5); for (int i=0; i<=v.size(); ++i); std::cout << "Success!\n";
//
// string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
// std::string s = "Success!\n"; for (int i=0; i<8; ++i) std::cout << s[i];
//
// if (true) then cout << "Success!\n"; else cout << "Fail!\n";
// if (true) std::cout << "Success!\n"; else std::cout << "Fail!\n";
//
// int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
// int x = 2000; char c = x; if (c!=2000) std::cout << "Success!\n";
//
// string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
// std::string s = "Success!\n"; for (int i=0; i<s.size(); ++i) std::cout << s[i];
//
// vector v(5); for (int i=0; i<=v.size(); ++i); cout << "Success!\n";
// std::vector<int> v(5); for (int i=0; i<=v.size(); ++i); std::cout << "Success!\n";
//
// int i=0; int j=9; while (i<10) ++j; if (j<i) cout << "Success!\n";
// int i=0; int j=9; while (i<10) ++i; if (j<i) std::cout << "Success!\n";
//
// int x = 2; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";
// int x = 0; double d = 5/(x-2); if (d!=2*x+0.5) std::cout << "Success!\n";
//
// string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]l;
// std::string s = "Success!\n"; for (int i=0; i<=10; ++i) std::cout << s[i];
//
// int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
// int i=0,j=0; while (i<10) ++i; if (j<i) std::cout << "Success!\n";
//
// int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << "Success!\n";
// int x = 4; double d = 5/(x-2); if (d=2*x+0.5) std::cout << "Success!\n";
//
// cin << "Success!\n";
// std::cout << "Success!\n";

int main() {
    try {
        // code here...
        return 0;
    }
    catch (std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
