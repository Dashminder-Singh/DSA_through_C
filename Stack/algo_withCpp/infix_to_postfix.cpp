#include <bits/stdc++.h>
using namespace std;

int preced(char ch)
{
	if(ch=='/' || ch=='*')
	{
		return 2;
	}
	else if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operands(char ch)
{
	if(ch>='a' && ch<='z'  || ch>='A' && ch<='Z')
		return 1;
	else
		return 0;
}

string infix_to_postfix(string Q)
{
	stack<char>st;
	string P;

	for(int i=0; i<Q.length(); i++)
	{
		if(operands(Q[i]))
		{
			P= P+ Q[i];
		}
		else if(Q[i]=='(')
		{
			st.push(Q[i]);
		}
		else if(Q[i]==')')
		{
			while(!st.empty() && st.top()!='(')
			{
				P=P+st.top();
				st.pop();
			}
			if(!st.empty())
				st.pop();
		}
		else
		{
			while(!st.empty() && preced(Q[i])<= preced(st.top()))
			{
				P=P+st.top();
				st.pop();
			}
			st.push(Q[i]);
		}
	}

	while(!st.empty() && st.top()!='(')
	{
		P=P+st.top();
		st.pop();
	}
	st.pop();
	return P;
}
int main()
{
	string exp="(A+B";

	cout<<infix_to_postfix(exp);
	return 0;
}