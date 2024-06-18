#include <iostream>
using namespace std;
#include <string>

bool check_if_rotation(const string &a, const string &b)
{
     string temp = a + a;

     if (a.length() != b.length())
          return false;

     return (temp.find(b) != string::npos);
   }                                         
int main()
{

     return 0;
}