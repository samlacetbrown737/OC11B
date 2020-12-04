//find mean median and mode oof college kid movie viewings
#include <iostream>

using namespace std;

void mode(int[], int);
void mean(int[], int);
void sort(int[], int);
void median(int[], int);

int main()
{
	int n;
	cout<<"How many students? >";
	cin>>n;
	int array[n];
	float total = 0;
	float mode;
	for(int i=0; i<n; i++){
		cout << "How many movies did the "<< i+1 << " kid watch? >";
		cin >> array[i];
	}

	sort(array, n);
	return 0;
}

void mean(int new_array[], int num){
	float total = 0;
	for(int i=0;i<num; i++){
		total += new_array[i];
	}
	cout << "The mean is " << total/num << endl;
	mode(new_array, num);
	}

void median(int new_array[], int num){
	if(num % 2 != 0){
		int temp = ((num+1)/2)-1;
		cout << "The median is " << new_array[temp] << endl;
	}
	else{
		cout << "The medians are "<< new_array[(num/2)-1] << " and " << new_array[num/2] << endl;
	}
	mean(new_array, num);
}

void mode(int new_array[], int num) {
	int* ipRepetition = new int[num];
	for (int i = 0; i < num; i++) {
		ipRepetition[i] = 0;
		int j = 0;//
		while ((j < i) && (new_array[i] != new_array[j])) {
			if (new_array[i] != new_array[j]) {
				j++;
			}
		}
		(ipRepetition[j])++;
	}
	int iMaxRepeat = 0;
	for (int i = 1; i < num; i++) {
		if (ipRepetition[i] > ipRepetition[iMaxRepeat]) {
			iMaxRepeat = i;
		}
	}
	cout<< "The mode is " << new_array[iMaxRepeat] << endl;

}

void sort(int new_array[], int num){
	for(int x=0; x<num; x++){
		 for(int y=0; y<num-1; y++){
			 if(new_array[y]>new_array[y+1]){
				int temp = new_array[y+1];
				new_array[y+1] = new_array[y];
				new_array[y] = temp;
			}
		}
	}
	cout << "List: ";
	for(int i =0; i<num; i++){
		cout << new_array[i] << " ";
	}
	cout << "\n";
	median(new_array, num);
}