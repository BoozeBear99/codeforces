/*
Vlad came home and found out that someone had reconfigured the old thermostat to the temperature of a.

The thermostat can only be set to a temperature from l to r inclusive, the temperature cannot change by less than x. Formally, in one operation you can reconfigure the thermostat from temperature a to temperature b if |a−b|≥x and l≤b≤r.

You are given l, r, x, a and b. Find the minimum number of operations required to get temperature b from temperature a, or say that it is impossible.
*/

//author: Sankalp Bansal
//codeforce-handle: BoozeBear99

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  
  int t;
  long l,r,a,b;
  unsigned long x;
  //t stores number of test cases
  //l stores the lower bound of thermostat in each test case
  //r stores the upper bound of thermostat in each test case
  //a stores the initial temperature of thermostat of each test case
  //b stores the target temperature of thermostat of a each test case
  //x stores the minimum increment/decrement in each test case

  t=0,l=0,r=0,a=0,b=0,x=0;

  cin>>t;
  int result[t];
  //to store output of each test case

  for(int i=1;i<=t;i++){
    cin>>l>>r>>x;
    cin>>a>>b;

    //*********************************************LOGIC*******************************************************
    //only possible number of operations are {-1,0,1,2,3}

    //when 3 operations are needed
    //as if operation is possible b has to be either at greater or equal distance from r or l
    //if it is not possible to move at the end farther from a at first step then we go the only possible option
    //from here we go to the end farther from b
    //a--->only possible end(not directly reachable to b)--->farther end--->b

    //when 2 operations are needed
    //if we can reach the end farther from b directly from a
    //a--->father end--->b

    //when 1 operation is needed
    //if we can directly reach b from a
    //a--->b

    //if a=b, we donot need any operation
    
    //In all other situations b cannot be reached
    //*********************************************************************************************************

    if(a==b)result[i-1]=0;
    else if(abs(r-a)<x && abs(l-a)<x)result[i-1]=-1;
    else if(abs(a-b)>=x)result[i-1]=1;
    else if((abs(r-a)>=x && abs(r-b)>=x) || (abs(l-a)>=x && abs(l-b)>=x))result[i-1]=2;
    else if(abs(l-b)<x && abs(r-b)<x)result[i-1]=-1;
    else result[i-1]=3;
  }

  for(int i=0;i<t;i++)cout<<result[i]<<endl;
  return 0;
}