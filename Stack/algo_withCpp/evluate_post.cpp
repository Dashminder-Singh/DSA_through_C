#include <bits/stdC++.h>
using namespace std;

int evaluate(string P)
{
	stack<int>st;

	int x, y;
	for(int i=0; i<P.length(); i++)
	{
		if(isdigit(P[i]))
		{
			st.push(P[i]- '0');
		}
		else
		{	
			x=st.top();
			st.pop();
			y=st.top();
			st.pop();

			switch(P[i])
			{
				case '+': st.push(y+x);
				break;

				case '-': st.push(y-x);
				break;

				case '*': st.push(y*x);
				break;

				case '/': st.push(y/x);
				break;
			}
		}
	}

	return st.top();
}

int main()
{
	string exp="2354-*+6+";

	printf("Evaluate: %d\n",evaluate(exp));
	return 0;
}