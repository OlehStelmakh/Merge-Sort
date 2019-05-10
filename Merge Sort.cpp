#include <iostream>
#include <ctime>

using namespace std;

void merge(int* arr, int left, int middle, int right);
void mergeSort(int* arr, int left, int right);
int sizeOfArray();
int* createArray(int size);
void random(int* arr, int size);
void outputArray(int* arr, int size);

int main() {

	int size = sizeOfArray();
	int* arr = createArray(size);
	random(arr, size);
	cout << "Initial array: " << endl;
	outputArray(arr, size);
	mergeSort(arr, 0, size - 1);
	cout << "Sorted array: " << endl;
	outputArray(arr, size);

	delete[]arr;
	return 0;
	
}

void merge(int *arr, int left, int middle, int right)
{
	int size1 = middle - left + 1;
	int size2 = right - middle;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	for (int i = 0; i < size1; i++)
		arr1[i] = arr[left + i];
	for (int j = 0; j < size2; j++)
		arr2[j] = arr[middle + 1 + j];

	int i = 0; 
	int j = 0; 
	int k = left; 
	while (i < size1 && j < size2) {
		if (arr1[i] <= arr2[j]) {
			arr[k] = arr1[i];
			i++;
		}
		else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < size1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while (j < size2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
	delete[]arr1;
	delete[]arr2;
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}


int sizeOfArray() {
	cout << "Enter a size of array: ";
	int size;
	cin >> size;
	while (size < 0) {
		cout << "Enter a correct size: ";
		cin >> size;
	}
	return size;
}

int *createArray(int size) {
	int* tempArr = new int[size];
	return tempArr;
}

void random(int* arr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void outputArray(int* arr, int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

