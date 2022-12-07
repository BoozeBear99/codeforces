/*STATEMENT
Pak Chanek has a prime number† n. Find a prime number m such that n+m is not prime.

† A prime number is a number with exactly 2 factors. The first few prime numbers are 2,3,5,7,11,13,…. In particular, 1 is not a prime number.

For each test case, output a line containing a prime number m (2≤m≤105) such that n+m is not prime. It can be proven that under the constraints of the problem, such m always exists.

If there are multiple solutions, you can output any of them.
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <cmath>
using namespace std;

bool check_prime(int n){													//checks if a number is prime or not, called from main()
    int count=0;
    for(int i=2;i<=sqrt(n);i++)if(n%i==0)count++;									//optimization---this loop is relatively faster than other loops used to find prime
    return count==0 && n!=1;
}

int main(){
    int t=0;
    cin >> t;
    int result[t];
    if(t>=1 && t<=10000){
        int n=0;
        for(int i=1;i<=t;i++){
            cin >> n;
            if(n>=2 && n<=100000){
                for(int m=2;m<=100000;m++)if(check_prime(m)==true && check_prime(m+n)==false){result[i-1]=m;break;}
            }
        }
        for(int i=0;i<t;i++)cout << result[i] << endl;
    }
    return 0;
}