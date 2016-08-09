#include"mySort.h"

int main(){
int arr[] = { 1, 2, -3, 10, -4, 7, 12, -5 };
	
	/*bubbleSort(arr, 8);
	for (auto& a:arr)
	   cout << a<<' ';
	cout << endl;;*/
	shellSort(arr, 8);
	for (auto& a : arr)
		cout << a << ' ';
	cout << endl;
	/*insertSort(arr, 8);
	for (auto& a : arr)
		cout << a << ' ';
	cout << endl;*/
	int brr[] = { 18, -2, 3, 100, -4, 7, 2, -5 };
	/*binaryInsertSort(brr, 8);
	for (auto& a : brr)
		cout << a << ' ';
	cout << endl;*/
	//Test1();
	//cout << endl;
	//cout << numeric_limits<int>::max();

	/*quickSort(brr, 0, 8);
	for (auto& a : brr)
		cout << a << ' ';
	cout << endl;*/

	//selectSort(brr,8);
	//for (auto& a : brr)
	//	cout << a << ' ';
	//cout << endl;

	//mergeSort(brr, 0,7);
	//for (auto& a : brr)
	//	cout << a << ' ';
	//cout << endl;

	heapSort(brr, 8);
	for (auto& a : brr)
		cout << a << ' ';
	cout << endl;
	return 0;
}