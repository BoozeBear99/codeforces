/*
A sequence of n numbers is called a permutation if it contains all integers from 1 to n exactly once. For example, the sequences [3,1,4,2], [1] and [2,1] are permutations, but [1,2,1], [0,1] and [1,3,4] — are not.

Polycarp lost his favorite permutation and found only some of its elements — the numbers b1,b2,…bm. He is sure that the sum of the lost elements equals s.

Determine whether one or more numbers can be appended to the given sequence b1,b2,…bm such that the sum of the added numbers equals s, and the resulting new array is a permutation?

Print t lines, each of which is the answer to the corresponding test set. Print as the answer YES if you can append several elements to the array b, that their sum equals s and the result will be a permutation. Output NO otherwise.

You can output the answer in any case (for example, yEs, yes, Yes and YES will be recognized as positive answer).
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99
#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
  int t,m,s,sum,n,max;						//t stores number of terms
									//m stores number of known terms of permutation
									//s stores sum of lost terms of permutation
									//sum stores the calculated sum of all terms of permutations
									//n stores number of terms
									//max stores the largest term of found terms
  float nf;								//nf stores number of terms calculated from the quadratic formula
 
  cin>>t;
 
  string result[t];						//to store the output
  if(t>=1 && t<=100){
    for(int i =1;i<=t;i++){
      cin>>m>>s;
      if(m>=1 && m<=50 && s>=1 && s<=1000){
	  int efound[m];
        sum=0;n=0;nf=0.0;max=0;
        for(int j=0;j<m;j++){
          cin>>efound[j];
          if(efound[j]>=1 && efound[j]<=50)sum+=efound[j];
	    if(efound[j]>max)max=efound[j];
	  }								//closing for loop inputing found elemnets
      }								//closing if block checking 'm' and 's'	
      sum+=s;
      nf=(-1.0+sqrt(1+8.0*sum))/2.0;
	n=nf/1;
      result[i-1]=(nf>0 && n*1==nf && n>=max)?"Yes":"No";		//checks if n is an integer or not			
    }									//closing for controlling no. of terms
    for(int i=0;i<t;i++)cout<<result[i]<<endl;
  }
  return 0;
}									//closing main