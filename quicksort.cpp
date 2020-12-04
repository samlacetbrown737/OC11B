#include <iostream>
using namespace std;
int arrSize = 10;
void InitArr(string array[]);
void sortArr(string array[], int s, int e);
void swap(string array[], int a, int b);
void showArr(string array[]);
int main() {
	string arr[10];
	InitArr(arr);
	sortArr(arr, 0, arrSize-1);
	showArr(arr);
	return 0;
}

void InitArr(string array[]) {
	cout<<arrSize<<" elements"<<endl;
	for(int i=0; i<arrSize; i++) {
		cout<<"> ";
		cin>>array[i];
	}
}

void sortArr(string array[], int s, int e) {
	string p;
	int l;
	int r;
	l = s;
	r = e;
	p = array[(l+r)/2];
	while(l<=r) {
		while(array[l]<p) {
			l++;
		}
		while(array[r]>p) {
			r--;
		}
		if (l<=r) {
			swap(array, l, r);
			l++;
			r--;
		}
	}
	if(s<r) {
		sortArr(array, s, r);
	}
	if(l<e) {
		sortArr(array, l, e);
	}
}

void swap(string array[], int a, int b) {
	string temp;
	temp = array[a];
	array[a]=array[b];
	array[b]=temp;
}
void showArr(string array[]) {
	cout<<"The sorted array is ";
	for(int i=0; i<arrSize; i++) {
		cout<<"Element "<<i<<" = "<<array[i]<<endl;
	}
}
