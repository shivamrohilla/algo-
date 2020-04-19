#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

std::vector<string> v;
void allposspermu(string s,string ans)
{
	if(s.length()==0)
	{
		v.push_back(ans);

		//cout<<ans<<endl;

	}

	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		string res= s.substr(0,i)+s.substr(i+1);
		allposspermu(res,ans+ch);
	}
}

int main(int argc, char const *argv[])
{


	string str;
	//cin>>str;
	str="cab";
	allposspermu(str,"");
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<str)
		{
			cout<<v[i]<<endl;
		}
	}
	//allposspermu("abc","");
	return 0;
}