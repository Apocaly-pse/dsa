#include <iostream>
// #include <unistd.h>
using namespace std;

int isprime(int n) {
    bool is[n+1];
    is[0]=false;
    is[1]=false;
    for (int i=2;i<=n;i++) {
        is[i]=true;
    }
    for (int i=2;i*i<=n;i++) {
        if (is[i]) {
            int j=i*i;
            while (j<=n){
                is[j]=false;
                j+= i;
            }
        }
    }
    int j=n;
    for (;j>0;j--)
    if (is[j]) return j;
}


int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n;
    while (n--){
        cin>>m;
        cout<<isprime(m)<<endl;
    }
    // pause();
    return 0;
}