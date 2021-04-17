#include <bits/stdc++.h>
using namespace std;

int match(char a, char b)
{
	if(a=='(' && b==')')
	{
		return 1;
	}
	if(a=='[' && b==']')
	{
		return 1;
	}
	if(a=='{' && b=='}')
	{
		return 1;
	}
	return 0;
}

int Multi_match(string exp)
{
	stack<char>st;

	char ch;
	for(int i=0; i<exp.length(); i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		{
			st.push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(st.empty())
			{
				return 0;
			}
			ch=st.top();
			st.pop();

			if(!match(ch, exp[i]))
			{
				return 0;
			}
		}
	}

	if(st.empty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	string exp="((3-2)";

	if(Multi_match(exp)!=1)
	{
		cout<<"Not balanced";
	}
	else
	{
		cout<<"balanced";
	}
	return 0;
}