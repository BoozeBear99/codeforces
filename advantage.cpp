#include<iostream>
using namespace std;

int main(){
  int t,n;
  
  cin>>t;
  while(t--){
    cin>>n;
    
    int a[n];
    int first_max=0,sec_max=0,pos=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(first_max<a[i]){
	  first_max=a[i]; 
	  pos=i;
	}
    }

    for(int i=0;i<n;i++)
	if(sec_max<a[i] && pos!=i)sec_max=a[i];

    for(int i=0;i<n;i++){
	cout<<(pos!=i?(a[i]-first_max):(a[i]-sec_max));
	cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}
