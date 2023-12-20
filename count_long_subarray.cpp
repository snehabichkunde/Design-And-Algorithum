#include<iostream>
using namespace std;

int count_long_subarray(int arr[], int n)
{
    int max = 1;
    int count = 1;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i + 1] > arr[i]){
            count++;
        }
        else{
            if(count > max){
                max = count;
            }
            count = 1;
        }
    }
    if(count > max){
        max = count;
    }
    return max;
}

int main()
{
    int arr[] = {1,3,4,2,7,5,6,9,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The count of the longest subarray is: " << count_long_subarray(arr, n);
    cout << endl;
    return 0;
}
