/*quickSort algorithm write by lhn 2018/12/6 
**which time comlplexity is O(nlg(n)),and the worst condition is O(n2)
*/
#include<iostream>
using namespace std;

int partition(int arr[], int startIndex, int endIndex) {
	int pivot = arr[startIndex];
	int left = startIndex;
	int right = endIndex;
	int index = startIndex;

	while (right >= left) {
		while (right >= left) {
			if (arr[right] < pivot) {
				arr[left] = arr[right];
				index = right;
				left++;
				break;
			}
			right--;
		}

		while (right >= left) {
			if (arr[left] > pivot) {
				arr[right] = arr[left];
				index = left;
				right--;
				break;
			}
			left++;
		}
	}
	arr[index] = pivot;
	return index;
}
void quickSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex) {
		return;
	}
	int pivotIndex = partition(arr, startIndex, endIndex);
	quickSort(arr, startIndex, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, endIndex);
}

int main() {
	int arr[8] = { 1, 2, 3, 4, 5, 6, 1, 8 };
	quickSort(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
