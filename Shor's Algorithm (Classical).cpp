#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

int gen_a_val(int N){
    int a,K;
    do{
        a = rand()%(N); //Creating random value of a from 0 to N-1
        K = __gcd(a,N); //Check if a and N is non-trivial factor
    }while(K != 1);
    return a;   //return value of a
}

auto CPE(int a, int N){ //CPE (Classical Phase Estimation) a.k.a Brute Force for Shor's Algorithm
    struct retVals{ //This necessary since this code use vector to store data
        int vecs_rslt,i,r;
    };
    vector<int> arr_mod;    //Declare and init vector
    int temp=0,q=1,r=0,i=0;
    do{
        temp = (q*a)%N; //Simplified function
        q = temp; //Store temp value to q for next iteration
        arr_mod.push_back(temp);    //put temp to vector for next calculation
        r++;    //Periodic counter
    }while((r%2==1) && (temp != 1)); //Loop until result of f(x) = a^x mod N is 1 and periodic are even
    i=r/2;  //get half of r to become vector index
    int vecs_rslt = arr_mod.at(i); //take value from vector using i as index and store it to vecs_rslt
    return retVals{vecs_rslt,i,r};
}

int main(){
    int a,vecs_rslt,i,r,N,f1,f2;
    srand(time(0)); //make the random number random
    cout<<"Insert value of N: ";
    cin>>N; //ordinary input

    do{
        a=gen_a_val(N); //call the function
        auto[vecs_rslt,i,r] = CPE(a,N);
        //cout<<vecs_rslt<<" "<<i<<" "<<r<<endl;
    }while(vecs_rslt+1 == N); //loop if vecs_rslt+1 == N

    f1=__gcd(vecs_rslt+1,N);    //find the gcd of vecs_rslt+1 and N
    f2=__gcd(vecs_rslt-1,N);    //find the gcd of vecs_rslt-1 and N

    cout<<"Factor founded: " <<f1<<" and "<<f2; //print out the result
    return 0;   //exit program grace fully
}
