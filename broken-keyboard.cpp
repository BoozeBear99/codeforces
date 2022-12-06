/*
Recently, Mishka started noticing that his keyboard malfunctions — maybe it's because he was playing rhythm games too much. Empirically, Mishka has found out that every other time he presses a key, it is registered as if the key was pressed twice. For example, if Mishka types text, the first time he presses a key, exactly one letter is printed; the second time he presses a key, two same letters are printed; the third time he presses a key, one letter is printed; the fourth time he presses a key, two same letters are printed, and so on. Note that the number of times a key was pressed is counted for the whole keyboard, not for each key separately. For example, if Mishka tries to type the word osu, it will be printed on the screen as ossu.

You are given a word consisting of n lowercase Latin letters. You have to determine if it can be printed on Mishka's keyboard or not. You may assume that Mishka cannot delete letters from the word, and every time he presses a key, the new letter (or letters) is appended to the end of the word.
*/

//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <string>
#include <array>
using namespace std;

int main(){
  int t,n,c,flag,j;							//t stores number of terms
										//n stores length of string
										//flag is the check variable 1 for true 0 for false

  string s;									//s stores the string input
  char c1,c2;								//c1 and c2 store adjacent characters	

  cin >> t;
  string result[t];							//to store output

  if(t>=1 && t<=100){							
    for(int i=1;i<=t;i++){
	cin >> n;
	cin >> s;
	flag=1;c=0;								//to be reinitialized for each input
      if(n>=1 && n<=100 && s.length() == n){
	  if((n+1)%3==0){result[i-1]="NO";continue;}		//optimization---By analysis lengths cannot be equal to 2,5,8,11....or(in general (3r-1))
	  for(j=0;j<n-1;j++){						
	    if(c++%2!=0){
		c1=s.at(j);c2=s.at(j+1);
		if(c1!=c2){flag=0;break;}
	      j++;								//incremented to make the loop directly jump to next pair as it is to be verified next
	    }									//closing if to check c
	  }									//closing for-loop traversing string
	  result[i-1]=(flag==0)?"NO":"YES";							
      }									//closing if to check 'n'
    }										//closing for-loop controlling terms

    for(int i=0;i<t;i++)cout << result[i] << endl;		//printing result

  }										//closing if to check 't'
  return 0;
}										//closing main()