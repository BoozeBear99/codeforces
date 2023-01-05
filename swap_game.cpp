/*STATEMENT
Alice and Bob are playing a game on an array a of n positive integers. Alice and Bob make alternating moves with Alice going first.

In his/her turn, the player makes the following move:

If a1=0, the player loses the game, otherwise:
Player chooses some i with 2≤i≤n. Then player decreases the value of a1 by 1 and swaps a1 with ai.
Determine the winner of the game if both players play optimally.

For each test case, if Alice will win the game, output "Alice". Otherwise, output "Bob".

You can output each letter in any case. For example, "alIcE", "Alice", "alice" will all be considered identical.
*/

//author: Sankalp Bansal
//codeforces-handle: BoozeBear99

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