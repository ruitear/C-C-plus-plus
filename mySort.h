#ifndef MYSORT_H
#define MYSORT_H
#include"myTitle.h"
using namespace std;
//sort
void bubbleSort(int* arr,int length){	
	if (arr==NULL){
		return;
	}
	//冒泡排序的最后是进行倒数第二个和
	//最后一个进行比较所以循环到倒数第二个就OK
	for (int i=0;i<length-1;++i){ 
		for (int j = i+1; j <length ; ++j){
			if (arr[i]>arr[j]){
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}

void shellSort(int* arr, int length){
	if (arr == NULL)
		return;
	for (int incrD = length / 2; incrD>0; incrD =incrD/2){
		for (int i = 0; i < length - incrD; ++i){
			if (arr[i + incrD]<arr[i]){
				int temp = arr[i + incrD];
				arr[i + incrD] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
void insertSort(int* arr, int length){
	if (arr == NULL)
		return;
	for (int i = 1; i < length; ++i){
		if (arr[i]<arr[i - 1]){//比较待插入元素和它之前的一个元素
			int temp = arr[i];//待插入元素
			int j = i - 1;//之所以在这里声明j是因为如果放到for循环内部后边无法通过编译
			for (; j >= 0 && temp<arr[j]; --j){//一次比较插入区间的元素与待插入得值
				arr[j + 1] = arr[j];//循环借宿的时候j最小减到-1，此时为移动最坏的情况
			}
			arr[j + 1] = temp;
		}
	}
}
int partation(int* arr,int low，int high){
	//随机划分
	if(data==null||low>high)
		return -1;
	srand(unsigned(time(0)));
	int index=low+rand()%(high-low+1);//随机初始化划分项位置
	int indexData=data[index];//划分标准项
	swap(data[index],data[high]);//把划分标志项放到最后一个数上存着，
	//同时与最后一项进行交换
	int small=low-1;//划分位置标识，初始值为low的前一个，
	for (int i = low; i < high; ++i){//在给定的low和high区间内进行划分操作
		if (data[i]<indexData){//当区间内的值小于确定的划分值时，
			small++;//递增small，small的作用是确定循环后与high交换的那个值的位置
			if(small!=i){//循环时遇到到small和i相同就不交换，说明i的值比index值小
				swap(data[i],data[small]);
			}
		}
	}
	small++;
	swap(data[small],data[high]);//交换smll位置的值和存在high的值
	return small;//返回index值所在的位置
}
void quickSort(int data[], int low, int high)
{
	if (low >= high||data==NULL)
	{
		return;
	}
	int index = partation(data, low, high);//得到第一遍大致有序排序
	if (index > low)
		quickSort(data, low, index - 1);//递归对左半边序列换分排序
	if (index <high)
		quickSort(data, index + 1, high);//递归对右半边序列换分排序
}

void binaryInsertSort(int* arr,int length){
	int low,middle,high;
	for(int i=1;i<length;++i){
		int temp=arr[i];
		low=0;high=i-1;
		while(low<=high){
			middle=(low+high)/2;
			if(temp<arr[middle])
				high=middle-1;
			else
				low=middle+1;
		}
		for (int j = i-1; j>=low; --j){
			arr[j+1]=arr[k];
		}
		arr[low]=temp;
	}
}
void selectSort(int data[],int length){//此时参数是int* data与int data[]无异
	if (data==NULL||length<=0){
		return;
	}
	for (int i = 0; i < length-1; ++i){
		int index=i;//在i和n-1之间找最小的元素
		for (int j = i+1; j < length; ++j){
			if (data[j]<data[index]){
				index=j;//遇到比index小的元素就把它的位置信息存到index
			}
		}
		if (index!=i){
			swap(data[i],data[index]);//交换，把每趟得到的最小元祖存放到index的位置
		}
	}
}
void merge(int data[],int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int* L1=new int[n1];//拆分出来的L1和L2
	int* L2=new int[n2]; 
	for (int i = 0; i < n1; ++i){//对L1赋值
		L1[i]=data[left+i];
	}
	for (int i = 0; i < n1; ++i){//对L1赋值
		L2[i]=data[middle+i+1];
	}
	int i=0,j=0;
	int k=left;
	while(i<n1&&j<n2){//三个while实现归并过程
		if(L1[i]<L2[j]) data[k++]=L1[i++];
		else data[k++]=L2[j++];
	}
	while(i<n1) data[k++]=L1[i++];
	while(j<n2) data[k++]=L2[j++];
	delete[] L1;
	delete[] L2;
}

void mergeSort(int data[],int left,int right){
	if(data==NULL||left>=right) return;
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(data,left,mid);
		mergeSort(data,mid+1,right);
		merge(data,left,mid,right);
	}
}
void siftDown(int data[],int start,int len){
	//最大堆每次只把最大的元素保存到堆顶
	int i=start,lChild=start*2+1;
    int temp=data[i];
	while(lChild<=len){
		if(lChild<len&&data[lChild]<data[lChild+1]) lChild++;
		if(temp>=data[lChild]) break;
		else{
			data[i]=data[lChild];i=lChild;lChild=2*lChild+1;
		}
	}
	data[i]=temp;
}
void heapSort(int data[],int len){
	if(data==NULL||len<=0) return;
	for(int i=len/2;i>=0;--i)siftDown(data,i,len);
	for(int j=len-1;j>=1;--j){
		swap(data[0],data[j]);
		siftDown(data,0,--len);
	}
}


#endif