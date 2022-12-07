/*
You are given three integers n, a, and b. Determine if there exist two permutations p and q of length n, for which the following conditions hold:

The length of the longest common prefix of p and q is a.
The length of the longest common suffix of p and q is b.

For each test case, if such a pair of permutations exists, output "Yes"; otherwise, output "No". You can output each letter in any case (upper or lower).
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
using namespace std;

int main(){
  int t,n,a,b;							//t stores number of inputs
									//n stores each input
									//a stores longest prefix length
									//b stores longest suffix length

  cin >> t;

  string result[t];						//declaring string array to store output for each input

  if(t>=1 && t<=10000){
    for(int i=1;i<=t;i++){
	cin >> n >> a >> b;
	if(a>=1 && a <=n && b>=1 && b<=n && n<=100){
	  if((a==b && a==n) || (a+b<=n-2))result[i-1]="Yes";
	  else result[i-1]="No";
	}								//closing if checking constraints on 'a', 'b' and 'n'
    }									//closing for loop controlling inputs
    for(int i=0;i<t;i++)cout << result[i] << endl;
  }									// closinf if checking constraints on 't'
  return 0;
}									//closing main()