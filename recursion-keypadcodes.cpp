#include<iostream>
using namespace std;

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int count=0;
void reckeypad(string s,string ans)
{
	if(s.length()==0)
	{
		cout<<ans<<endl;
		count++;
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
	
	reckeypad("34","");
	cout<<count;
	return 0;
}
