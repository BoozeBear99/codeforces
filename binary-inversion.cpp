/*STATEMENT
You are given a binary array† of length n. You are allowed to perform one operation on it at most once. In an operation, you can choose any element and flip it: turn a 0 into a 1 or vice-versa.

What is the maximum number of inversions‡ the array can have after performing at most one operation?

† A binary array is an array that contains only zeroes and ones.

‡ The number of inversions in an array is the number of pairs of indices i,j such that i<j and ai>aj.

For each test case, output a single integer  — the maximum number of inversions the array can have after performing at most one operation.
*/

//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
using namespace std;

int main(){
  
  int t,n,pos0,pos1;
  unsigned long long count0,count1,sum,suml,sumf,c0,c1,rec1;	
	
	//t stores number of inputs
	//n stores each input
	//count0 stores total number of zeroes in the binary array
	//count1 stores total number of ones in the binary array
	//sum stores number of inversions in the orignal array
	//suml stores number of inversions of the array when last one is inverted to 0
	//sumf stores number of inversions of the array when first zero is inverted to 1
	//c0 is the live temp counter of zeroes in array
	//c1 is the live counter of ones in array
	//pos0 stores the position of the first zero
	//pos1 stores the position of the last one
	//rec1 counts the number of zeros before the first zero
  
  cin>>t;
  unsigned long long result[t];					//to store output
  
  for(int i=1;i<=t;i++){
    cin>>n;
    int a[n];					//to store binary array
    sum=0,suml=0,sumf=0,c0=0,c1=0,pos0=0,pos1=0,rec1=0,count0=0,count1=0;

    for(int j=0;j<n;j++){
	a[j]=0;
	cin>>a[j];
	if(a[j]==0 && count0==0)pos0=j;	//to locate first zero of binary array
	if(a[j]==1){pos1=j;count1++;}		//to locate last one of binary array
	if(a[j]==0)count0++;			//to count number of zeroes
    }							//closing for loop used to input array elements

    if(count0==0 || count1==0)result[i-1]=n-1;	//special case 1
    else{
	 for(int j=0;j<pos1;j++){		//---optimization: run loop till the last 1 as we can be assured that the remaining elements will be zero
	   if(a[j]==1)c1++;
	   if(a[j]==0)c0++;
	   if(a[j]==0 && a[j+1]!=0){
	     sum+=(c1*c0);
	     c0=0;
	   }
	   if(pos0==j)rec1=c1; 
       }
	 if(pos0>pos1)rec1=count1;		//as rec1=0 if first zero comes after last 1

       sum+=(c1+1)*(n-pos1-1);

       //the last 1 is inverted to 0 will be paired with the 1s before, that is (c1-1) 1s, excluding the inverted 1
       //we need to remove the pair of inversions if the last 1 with following zero if any
       //as these inversion pair doesnot exist anymore
       //as the algorithm determines the last 1 in the binary array
       //therefore we are sure that following elements would only be zero
  
       suml=sum+c1-(n-pos1-1);		//summation if last 1 is inverted

       //the first 0 inverted to 1 will be paired with the following 0s
       //number of following zeros would count-1, exculding the inverted zero
       //rec1 is the pair of inversions with the zero inverted 
       //As zero is now inverted to 1 those inversions do not exist anymore

       sumf=sum-rec1+(count0-1);		//summatioin if first 0 is inverted

       result[i-1]=(sum>suml)?((sum>sumf)?sum:sumf):((suml>sumf)?suml:sumf);
     }						//closing else block
  }							//closing for loop controlling number of terms

  for(int i=0;i<t;i++)cout<<result[i]<<endl;  //printing result

  return 0;
}							//closing main()