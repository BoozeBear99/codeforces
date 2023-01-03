/*PROBLEM 1760C
There are n participants in a competition, participant i having a strength of si.

Every participant wonders how much of an advantage they have over the other best participant. In other words, each participant i wants to know the difference between si and sj, where j is the strongest participant in the competition, not counting i (a difference can be negative).

So, they ask you for your help! For each i (1≤i≤n) output the difference between si and the maximum strength of any participant other than participant i.

For each test case, output n space-separated integers. For each i (1≤i≤n) output the difference between si and the maximum strength of any other participant.
*/
//author: Sankalp Bansal
//codeforces-handle: BoozeBear99
#include<iostream>
using namespace std;

int main(){
  int t,n;
  //t stores number of inputs
  //n stores lenght of array
  
  cin>>t;
  while(t--){
    cin>>n;
    
    int a[n];
    int first_max=0,sec_max=0,pos=0,temp=0;
    for(int i=0;i<n;i++){
	cin>>a[i];

	//finding the largest element
	if(first_max<a[i]){
	  temp=first_max;
	  first_max=a[i]; 
	  pos=i;
	}
	
	//finding second largest number

	if((sec_max<a[i] && a[i]!=first_max) || (a[i]==first_max && pos!=i))sec_max=a[i];
	if(sec_max<temp && temp!=first_max)sec_max=temp;
    }


    for(int i=0;i<n;i++){
	cout<<(pos!=i?(a[i]-first_max):(a[i]-sec_max));
	cout<<" ";
    }
    cout<<endl;
  }						//closing while
  return 0;
}						//closing main