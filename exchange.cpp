/*
Monocarp is playing a MMORPG. There are two commonly used types of currency in this MMORPG — gold coins and silver coins. Monocarp wants to buy a new weapon for his character, and that weapon costs n silver coins. Unfortunately, right now, Monocarp has no coins at all.

Monocarp can earn gold coins by completing quests in the game. Each quest yields exactly one gold coin. Monocarp can also exchange coins via the in-game trading system. Monocarp has spent days analyzing the in-game economy; he came to the following conclusion: it is possible to sell one gold coin for a silver coins (i. e. Monocarp can lose one gold coin to gain a silver coins), or buy one gold coin for b silver coins (i. e. Monocarp can lose b silver coins to gain one gold coin).

Now Monocarp wants to calculate the minimum number of quests that he has to complete in order to have at least n silver coins after some abuse of the in-game economy. Note that Monocarp can perform exchanges of both types (selling and buying gold coins for silver coins) any number of times.

For each test case, print one integer — the minimum possible number of quests Monocarp has to complete.
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int t,a,b;									//t stores number of inputs
											//a stores selling price of one gold coin in silver coins
											//b stores cost price of one gold coin in silver coins
  unsigned long int n;								//n stores each input

  cin >> t;

  int result[t];									//to store output

  if(t>=1 && t<=10000){
    for(int i=1;i<=t;i++){
	cin >> n >> a >> b;
	if(n>=1 && n<=pow(10,7) && a>=1 && b>=1 && a<=50 && b<=50){
	  result[i-1]=1;								//atleast one quest has to be done
	  if(n>a && b>=a)result[i-1]=(n%a==0)?n/a:n/a+1;		//mathematical logic to find number of quests
	}										//closing if checking constraints on inputs
    }
    for(int i=0;i<t;i++)cout << result[i] << endl;
  }											//closing if checking constraints on 't'
  return 0;
}											//closing main()