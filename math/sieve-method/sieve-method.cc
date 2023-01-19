#include <iostream>

using namespace std;

constexpr int maxn = 1e8+10;
bitset<maxn> pri;
int primes[maxn];

void era() {
    int N = 1e8,cnt=0;
    double s=clock();
    for (int i=2;i*i<=N;++i){
        if (!pri[i]){
            for (int j=i*i;j<=N;j+=i) pri[j]=1;
        }
    }
    for(int i=2;i<=N;i++)
        if(!pri[i])cnt++;
    double e=clock();
    printf("%d\ntime = %.0lftic",cnt,e-s);
    /*5761455
time = 4252883tic[Finished in 4.9s]*/
}

void euler() {
    int N = 1e8,cnt=0;
    double s=clock();
    for (int i=2;i<=N;++i){
        if (!pri[i])primes[++cnt]=i;
        for (int j=1;i*primes[j]<=N;j++) {
            pri[i*primes[j]]=1;
            if (i%primes[j]==0)break;
        }
    }
    double e=clock();
    printf("%d\ntime = %.0lftic",cnt,e-s);
    /*5761455
time = 2730051tic[Finished in 3.5s]*/
}

int main(int argc, char const *argv[])
{
    // era();
    euler();
    return 0;
}
