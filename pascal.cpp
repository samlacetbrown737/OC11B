#include <iostream>
using namespace std;
int n, k, a;
int factorial(int m) {
	int r=1;
	for (int i=2; i<=m; i++) {
		r*=i;
	}
	return r;
}
int combination(int n, int k) 
{
	a = (factorial(n)/(factorial(k)*factorial((n-k))));
	return a;
}
int main() {
	int x;
	int i = 0;
	while(i<10) {
		for(x=0;x<=i;x++) {
			n=i;
			k=x;	
			cout<<combination(n,k)<<" ";
		}
		cout<<endl;
		i++;
	}
}
