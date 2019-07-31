#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%1d %*c %1d",&a,&b);
		printf("%d\n",a+b);
	}
}