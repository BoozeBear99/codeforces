/*You are given an integer n.
To find two positive (greater than 0) integers a and b such that a+b=n and the least common 
multiple (LCM) of a and b is the minimum among all possible values of a and b. If there are multiple answers,
you can print any of them.
*/

//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
using namespace std;

bool isPrime(int num){										//return if a number is prime or not
  int count=0;
  for(int i=2;i<=sqrt(num);i++)if(num%i==0)count++;
  return count==0 && num!=1;
}
int main(){
  unsigned long long int t,n,p;								//t stores number of inputs to be taken
													//n stores the input from user
													//p stores first prime factor of n

  cin >> t;												//number of inputs
  
  long int result[t][2];									//2D Array to store output

  for(long int i=0;i<t;i++){									//initializing array
	for(int j=0;j<2;j++)result[i][j]=0;
  }

  if(t>=1 && t<=100){				
    for(long int i=1;i<=t;i++){
	cin >> n;											//taking inputs 't' times
	if(n>=2 && n<=pow(10,9)){
	  result[i-1][0]=1;
	  result[i-1][1]=n-1;
	  if(isPrime(n))continue;								//optimization---if number itself is prime then we get minimum at 1, n-1
	  if(n%2==0){result[i-1][0]=result[i-1][1]=n/2;continue;}			//optimization---2 is the only even prime number so we can make a special case to optimize the code
	  else{
	    for(p=3;p<=sqrt(n);p+=2)if(n%p==0 && isPrime(p))break;			//loop runs till sqrt(n) as there will be atleast one prime factor before the sqrt(n)				
													//optimization---all prime excpet 2 are odd so we start from 3 and increment by 2 to get only odd numbers

	    result[i-1][0]=n/p;									//using number theory we get the minimum lcm of pair summing to n at n/i where i is the first prime factor of n
	    result[i-1][1]=n-result[i-1][0];
	  }												//else block
	}												//closing if block that checks 'n'
    }													//closing outer-for loop that controls number of input
    for(long int i=0;i<t;i++){
	for(int j=0;j<2;j++)cout << result[i][j] << " ";
	cout << endl;
    }
  }													//closing if block to check 't'
  return 0;
}													//closing main()
