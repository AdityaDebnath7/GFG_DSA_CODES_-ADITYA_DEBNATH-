#include <iostream>
using namespace std;
 // for printing permutation

///UNDERSTANDING BACKTRACKING CONCEPT



void permute(string str, int l, int r)
{

    if (l == r)
    {

        cout << str << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[i], str[l]);
            permute(str, l + 1, r);
            swap(str[i], str[l]);
        }
    }
}



// using backtracking
// preventing those call which we are sure will result in undesired outcome


// here we prevent the string which have substring AB present inside the permutation

bool isSafe(string str,int l, int i, int r){
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
        return false;                                // CASE LIKE when string is "ACB" AND l=1,i=2  // general case
    if(r==(l+1) && str[i]=='A' && str[l]=='B')     
        return false;                                // case when string is like  "CBA" and l=1,i=2 and r=l+1  // edge case 
    return true;
}

void permute_pro(string str, int l, int r){
                                                  // intoduced isSafe not before printing permutation but befor calling the recursion
    if(l==r){
        cout<<str<<endl;
        return;                                  // saves a lot of computation
    }else{
        for(int i=l;i<=r;i++){
            if(isSafe(str,l,i,r)){
                swap(str[i],str[l]);
                permute_pro(str,l+1,r);
                swap(str[i],str[l]);}
        }   
    }
}


int main()
{   permute_pro("ACDEFB",0,5);

    return 0;
}