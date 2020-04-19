#include<iostream>
using namespace std;

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string final="";
int count=0;
void reckeypad(string s,string ans)
{
	if(s.length()==0)
	{
		for(int i=0;i<11;i++)
		{
			string check=searchIn[i];
			if(check.find(ans) != string::npos)
			{
				final=final+check+"\n";
				searchIn[i]="";
			}
		}
		return;

	}

	char ch=s[0];
	string key=code[ch-'0'];
	string res=s.substr(1);

	for(int i=0;i<key.length();i++)
	{
		reckeypad(res,ans+key[i]);
	}


}

int main(int argc, char const *argv[])
{
	
	// reckeypad("12","");
	// cout<<count;
	reckeypad("34","");
	cout<<final;

	return 0;


}
