/*
	-----------------------------------------------------Linear Search-------------------------------------------------------------
	
	Algorithm:
		[array, size, key, i]
		array -> list of numbers from which we are going to find the location
		size -> length of array
		key -> number which have to be find 
		
		Step 1: Set i=0
		Step 2: if i>size, then return -1
		Step 3: if array[i] == key, then return i+1
		Step 4: else, then i+1 and repeat step 3
		
					
	Time Complexity: 
		Worst-case performance	O(size)
		Best-case performance	O(1)
		Average performance		O(size/2)
		
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
	int i=0;
	while(i<size){
		if(arr[i]==key){
			return i+1;
		}
		i++;
	}
	return -1;
}

int main(){
	int arr[] = {3,4,2,5,1,8,9,11};
	int size = sizeof(arr)/sizeof(arr[0]);
	int key;
	cin>>key;
	int pos = linearSearch(arr,size,key);
    if(pos == -1){
        cout<<"Not Found";
    }
    else{
        cout<<"Found at: "<<pos<<" position";
    }

	return 0;
}