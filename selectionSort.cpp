#include <iostream>
using namespace std;

void Initialize(string a[]);
void SelectionSort(string a[]);
int FindMin(string a[],int start);
void Swap(string a[],int p1,int p2);
void Display(string a[]);

int main()
{
    string a[10];
    int i;
    for(i=0;i<10;i++)
    {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
    SelectionSort(a);
    cout<<a[0]<<", "<<a[1]<<", "<<a[2]<<", "<<a[3]<<", "<<a[4]<<", "<<a[5]<<", "<<a[6]<<", "<<a[7]<<", "<<a[8]<<", "<<a[9];
    return 0;
}

void SelectionSort(string a[])
{
    int i, index;
    
    for(i=0;i<10;i++)
    {
        index=FindMin(a,i);
        Swap(a,i,index);
    }
}

int FindMin(string a[],int start)
{
    int i, min;
    min=start;
    
    for(i=start+1;i<10;i++)
    {
        if(a[i]<a[min])
            min=i;
    }
    
    return min;
}

void Swap(string a[],int p1,int p2)
{
    string temp=a[p1];
    a[p1]=a[p2];
    a[p2]=temp;
}
