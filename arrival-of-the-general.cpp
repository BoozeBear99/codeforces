/*STATEMENT
 Ministry for Defense sent a general to inspect the Super Secret Military Squad under the command of the Colonel SuperDuper. Having learned the news, the colonel ordered to all n squad soldiers to line up on the parade ground.

By the military charter the soldiers should stand in the order of non-increasing of their height. But as there's virtually no time to do that, the soldiers lined up in the arbitrary order. However, the general is rather short-sighted and he thinks that the soldiers lined up correctly if the first soldier in the line has the maximum height and the last soldier has the minimum height. Please note that the way other solders are positioned does not matter, including the case when there are several soldiers whose height is maximum or minimum. Only the heights of the first and the last soldier are important.

For example, the general considers the sequence of heights (4, 3, 4, 2, 1, 1) correct and the sequence (4, 3, 1, 2, 2) wrong.

Within one second the colonel can swap any two neighboring soldiers. Help him count the minimum time needed to form a line-up which the general will consider correct.

Print the only integer — the minimum number of seconds the colonel will need to form a line-up the general will like.
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99
#include <iostream>
using namespace std;

int main(){
  int len;
  cin>>len;
  int line[len];
  
  int max=0,min,pmax,pmin;														//max stores first maximum height
  																				//min stores last minimum height
  																				//pmax stores position of first maximum height
  																				//pmin stores position of last minimum height
  
  for(int i=0;i<len;i++)cin>>line[i];
  min=line[0];
  for(int i=0;i<len;i++){
    if(max<line[i]){max=line[i];pmax=i;}										//distance of first max term from i=0
    if(min>=line[i]){min=line[i];pmin=i;}										//distance of last min term from i=len-1
  }												
  cout<<((max!=min)?((pmax<pmin)?(pmax+len-pmin-1):(pmax+len-pmin-2)):0)<<endl; //if pmax>pmin then there will be a common swap for pmax and pmin
  return 0;
}																				//closing main()
