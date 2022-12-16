/*STATEMENT
Let's call a positive integer extremely round if it has only one non-zero digit. For example, 5000, 4, 1, 10, 200 are extremely round integers; 42, 13, 666, 77, 101 are not.

You are given an integer n. You have to calculate the number of extremely round integers x such that 1≤x≤n.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases.

Then, t lines follow. The i-th of them contains one integer n (1≤n≤999999) — the description of the i-th test case.

For each test case, print one integer — the number of extremely round integers x such that 1≤x≤n.
*/
//author:Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <cmath>
using namespace std;

//called from main()
//counts extremely rounds for input n

int rounds(int n){
  int p=1,x=0;
  //p stores power of ten just greater than n
  //x stores total extremely rounds <=n

  //finding power of ten just greater than n
  while(pow(10,p)<n)p++;

  x=n/(int)pow(10,--p);
  while(--p>=0)x+=9;

  return x;
}
int main(){
  int n,t;
  //n stores each input
  //t stores number of inputs

  cin>>t;
  int result[t];							//stores output

  if(t>=1 && t<=pow(10,4)){
    for(int i=1;i<=t;i++){
	cin>>n;

	//storing result for respective inputs
	if(n>=1 && n<pow(10,7))result[i-1]=rounds(n);
    }									//closing for loop controlling inputs
    for(int i=0;i<t;i++)cout<<result[i]<<endl;		//printing output
  }									//closing if checking 't'
  return 0;
}									//closing main