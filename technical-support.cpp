/*STATEMENT
You work in the quality control department of technical support for a large company. Your job is to make sure all client issues have been resolved.

Today you need to check a copy of a dialog between a client and a technical support manager. According to the rules of work, each message of the client must be followed by one or several messages, which are the answer of a support manager. However, sometimes clients ask questions so quickly that some of the manager's answers to old questions appear after the client has asked some new questions.

Due to the privacy policy, the full text of messages is not available to you, only the order of messages is visible, as well as the type of each message: a customer question or a response from the technical support manager. It is guaranteed that the dialog begins with the question of the client.

You have to determine, if this dialog may correspond to the rules of work described above, or the rules are certainly breached.

For each test case print "Yes" (without quotes) if dialog may correspond to the rules of work, or "No" (without quotes) otherwise.
*/
//author: Sankalp Bansal
//codeforces handle: BoozeBear99

#include <iostream>
#include <string>
using namespace std;

bool checker(string st){
    int a=0,q=0;
    for(int i=0;i<st.length();i++){
        if(st.at(i)=='Q')q++;
        else a++;
    }
    if(a>=q) return true;								//number of questions cannot be more than number of answers
    else return false;
}
string cropper(string st){								//the cropper function crops the valid part of string and checks the remaining for validity
    int flag=0;										//flag variable ensures the validity of complete string, after every crop it resets to 0
												//if after full crop flag remains 1 it implies chat sequence is valid

    string sub="";									//sub stores the cropped part of string to be checked
    int i=0;										//i is the iterating variable

    while(i<st.length() && st.length()>0){					//after one point when string is fully cropped length of string becomes zero and it is a terminating condition
        if(st.at(i)=='A' && ((i==st.length()-1) || (st.at(i+1)!='A'))){ //crop occours when there are not more concurrent answers in chat sequence
												//for example in seq="QQQAAAQAQQ" first crop occurs at sub="QQAAA" as the next character is Q
												//crop the string because answers before a question cannot be related to each other in the chat sequence 
            if(i==st.length()-1){
                sub=st;									//exception condition as there will not be any character at (i+1)
                if(checker(sub)==true){flag=1;break;}
            }
            else sub=st.substr(0,i+1);
            if(checker(sub)==true){
                flag=1;
                st=st.substr(i+1,st.size()-sub.size());
                i=-1;									//<---i is set to -1 due ---
            }
            else flag=0;								//flag has to be reset to zero after every crop to check the remaining string after crop
        }
        else flag=0;
        i++;										//--->to this
    }
    if(flag==1) return "Yes";
    else return "No";
}
int main(){
    int n=0,t=0;
    cin >> t;
    string chat_seq=""; 								//to store chat history
    string result[t]; 									//to store output
    if(t>=1 && t<=500){
        for(int i=0;i<t;i++){
                cin >> n;
                if(n>=1 && n<=100){
                cin >> chat_seq;
                    if(checker(chat_seq)==true){
                        result[i]=cropper(chat_seq);
                    }
                    else result[i]="No";
                }
        }
        for(int i=0;i<t;i++)cout << result[i] << endl;
    }
    return 0;
}