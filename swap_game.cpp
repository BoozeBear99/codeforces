#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int t,n;
  unsigned long min;
  //t stores number of test cases
  //n stores length of each array
  //min stores minimum term of each array

  cin>>t;

  string result[t];
  //stores output of each test case

  for(int k=1;k<=t;k++){
    cin>>n;
    unsigned long a[n];

    min=pow(10,9);
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(min>a[i])min=a[i];
    }
    
    //******************************************LOGIC*********************************************

    //if the smallest number is not the first number then Alice can push it in front
    //Bob is forced to reduce the smallest number and push it back
    //Alice again push the reduced number infront and Bob again reduces it and push it back
    //As everytime Bob is reducing the smallest number, a common situation will be reached
    //Alice will push 1 in front and Bob reduces it to 0 and pushes it back
    //Alice would now push 0 in front and hence Bob would loose
    
    //Similarly if smallest number is the first number then Alice would reduce it and push it back
    //And Bob would push it infront and force Alice to reduce it further
    //********************************************************************************************

    result[k-1]=(a[0]==min)?"Bob":"Alice";
  }

  for(int k=0;k<t;k++)cout<<result[k]<<endl;
  return 0;
}