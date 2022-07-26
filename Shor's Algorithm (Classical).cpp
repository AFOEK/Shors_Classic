#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gen_a_val(int N){
    int a,K;
    do{
        a = rand()%(N-1); //Creating random value of a from 0 to N-1
        K = __gcd(a,N);
    }while(K != 1);
    cout<<a<<" "<<K<<endl;
    return a;
}

auto CPE(int a, int N){
    struct retVals{
        int vecs_rslt,i,r;
    };
    vector<int> arr_mod;
    int temp=0,q=1,r,i;
    while(temp != 1){
        temp = (q*a)%N;
        q = temp;
        arr_mod.push_back(temp);
        r++;
    }
    i=r/2;
    int &vecs_rslt = arr_mod.at(i);
    cout<<r<<" "<<i<<" "<<vecs_rslt<<endl;
    return retVals{vecs_rslt,i,r};
}

int main(){
    int a,vecs_rslt,i,r,N,f1,f2;

    cout<<"Insert value of N: ";
    cin>>N;

    do{
        a=gen_a_val(N);
        auto[vecs_rslt,i,r] = CPE(a,N);
    }while((r%2!=1) && (vecs_rslt+1 != N));

    f1=__gcd(vecs_rslt+1,N);
    f2=__gcd(vecs_rslt-1,N);

    cout<<"Factor founded: " <<f1<<" and "<<f2;
    return 0;
}
