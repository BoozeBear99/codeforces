/*STATEMENT
For his birthday, Kevin received the set of pairwise distinct numbers 1,2,3,…,n

as a gift.

He is going to arrange these numbers in a way such that the minimum absolute difference between two consecutive numbers be maximum possible. More formally, if he arranges numbers in order p1,p2,…,pn
, he wants to maximize the value
mini=1n−1|pi+1−pi|,
where |x| denotes the absolute value of x.

Help Kevin to do that.

Output

For each test case print a single line containing n
distinct integers p1,p2,…,pn (1≤pi≤n

) describing the arrangement that maximizes the minimum absolute difference of consecutive elements.

Formally, you have to print a permutation p
which maximizes the value mini=1n−1|pi+1−pi|

.

If there are multiple optimal solutions, print any of them.
*/

//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <string>
using namespace std;

int main(){
  int t,n,term;																	//t stores number of inputs
  																				//n stores each input
  																				//tern stores each term of permutation
  cin>>t;
  string result[t],s="";
  for(int i=1;i<=t;i++){
    cin>>n;
    term=n/2+1;																	//determined by analysis
    s=to_string(term);
    if(n<=3){																	//EXCEPTIONS
      s=(n==1)?"1":((n==2)?"1 2":"1 2 3");										
      result[i-1]=s;
      continue;
    }
    if(n%2==0){
      for(int j=1;j<n;j++){
      term+=(j%2==0)?(n/2+1):(-n/2);
      s+=" "+to_string(term);													//the greatest possible mininmum difference is n/2
      }
    }																			//closing if checking if 'n' is even
    else{
      for(int j=1;j<n-3;j++){
      term+=(j%2==0)?(n/2+1):(-n/2);
      s+=" "+to_string(term);
      }
      term=term+n/2+2;
      //if n is odd everything remains same for first n-3 numbers and then swap the last and second last numbers to get maximum for odd series
      s+=" "+to_string(term)+" "+to_string(term-n/2-1)+" "+to_string(term-1);	
    }																			//closing else
    result[i-1]=s;
  }																				//clsoing for loop controlling inputs
  for(int i=0;i<t;i++)cout<<result[i]<<endl;									//printing result
  return 0;
}																				//closing main()
