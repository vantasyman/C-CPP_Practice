#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"
#include "Stack.h"
//插入排序
void insertsort(int* a, int n)
{
	for (int count = 0; count < n; count++)
	{
		int end = count;
		int tmp = a[count+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end+1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end+1] = tmp;
	}

}
//希尔排序
void ShellSort(int*a,int n)
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int count = 0; count < n - gap; count++)
		{
			int end = count;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}

	}
}
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void bubblesort(int *p,int sz)
{
	for (int count = 0; count < sz; count++)
	{
		for (int cur = 0; cur < sz - count-1; cur++)
		{
			if (p[cur] > p[cur+1])
			{
				swap(p + cur, p + cur + 1);
			}
		}
	}
}

void selectsort(int*arr,int n)//双头选择
{
	
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int* max = arr+begin;
		int* min = arr+begin;
		for (int count=begin;count<=end;count++)
		{
			if (*max < arr[count])
			{
				max = arr+count;
			}
			if (*min > arr[count])
			{
				min = arr + count;
			}
		}
		swap(arr + begin, min);
		if (arr+begin == max)
		{
			max=min;
		}
		swap(arr + end, max);
		begin++;
		end--;
	}
}
//使用三数取中，去规避最坏的情况
int mid_inthree(int* arr, int begin, int end)
{
	if (arr[begin] > arr[end] && arr[begin] < arr[(begin + end) / 2])
		return begin;
	else if (arr[end] > arr[begin] && arr[end] < arr[(begin + end) / 2])
		return end;
	else
		return (end + begin) / 2;
}
void my_qsort(int* arr, int begin, int end)//双指针快排
{
	if (end <= begin)
	{
		return;
	}
	swap(arr+end, arr+mid_inthree(arr, begin, end));
	int left = begin, right = end - 1;
	while (left <= right)
	{
		while (arr[left] <= arr[end]&&left<=right)
		{
			left++;
		}
		while (arr[right] >= arr[end]&&right>=left)
		{
			right--;
		}
		if (left < right)
		{
			swap(arr + left, arr + right);
		}
	}
	swap(arr + end, arr + left);
	my_qsort(arr, begin, left - 1);
	my_qsort(arr, left + 1, end);
}
//挖坑法快排
//前后指针法快排
void my_qsort2(int* arr, int begin, int end)
{
	if (end <= begin)
	{
		return;
	}
	swap(arr + end, arr + mid_inthree(arr, begin, end));
	int cur = begin, prev = begin-1;
	while (cur<end)
	{
		while (cur < end && arr[cur] >= arr[end])
		{
			cur++;
		}
		prev++;
		swap(arr + cur, arr + prev);
	}
	swap(arr + prev+1, arr + end);
	my_qsort(arr, begin, prev - 1);
	my_qsort(arr, prev + 1, end);
}
int partsort(int* arr, int begin, int end)
{
	swap(arr + end, arr + mid_inthree(arr, begin, end));
	int left = begin, right = end - 1;
	while (left <= right)
	{
		while (left <= right&&arr[left] <= arr[end])
		{
			left++;
		}
		while (right >= left &&arr[right] >= arr[end] )
		{
			right--;
		}
		if (left < right)
		{
			swap(arr + left, arr + right);
		}
	}
	swap(arr + end, arr + left);
	return left;
}
void my_qsort3(int* arr, int begin, int end)//非递归快排
{
	Stack* tmp=StackIni();
	StackPush(&tmp, end);
	StackPush(&tmp, begin);
	while (!Stackempty(tmp))
	{
		int begin = Stacktop(tmp);
		StackPop(&tmp);
		int end = Stacktop(tmp);
		StackPop(&tmp);
		int div = partsort(arr, begin, end);
		
		if (div + 1 < end)
		{
			StackPush(&tmp, end);
			StackPush(&tmp, div+1);

		}
		if (div - 1 > begin)
		{
			StackPush(&tmp, div - 1);
			StackPush(&tmp, begin);
		}
	}
	Stackdestory(tmp);
}

void _MergeSort(int* a, int left, int right, int* tmp)//递归回退就是归并
{
	if (left >=right)
	{
		return;
	}
	int mid = (left+right) / 2;
	_MergeSort(a, left, mid,tmp);
	_MergeSort(a, mid + 1, left, tmp);
	int begin_1 = left, end_1 = mid;
	int begin_2 = mid + 1, end_2 = right;
	int begin_tmp = begin_1;
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (a[begin_1] >= a[begin_2])
		{
			tmp[begin_tmp++] = a[begin_2++];
		}
		else 
		{
			tmp[begin_tmp++] = a[begin_1++];
		}
	}
	while (begin_1 <= end_1)//因为是不等长的，所以我们需要考虑不等长的情况
	{
		tmp[begin_tmp++] = a[begin_1++];
	}
	while (begin_2 <= end_2)
	{
		tmp[begin_tmp++] = a[begin_2++];
	}
	while (left <=end_2)//复制过去
	{
		a[left] = tmp[left];
		left++;
	}
}
void MergeSortpart(int* a, int left,int mid,int right, int* tmp)
{
	int begin_1 = left, end_1 = mid;
	int begin_2 = mid + 1, end_2 = right;
	int begin_tmp = begin_1;
	while (begin_1 <= end_1 && begin_2 <= end_2)
	{
		if (a[begin_1] >= a[begin_2])
		{
			tmp[begin_tmp++] = a[begin_2++];
		}
		else
		{
			tmp[begin_tmp++] = a[begin_1++];
		}
	}
	while (begin_1 <= end_1)//因为是不等长的，所以我们需要考虑不等长的情况
	{
		tmp[begin_tmp++] = a[begin_1++];
	}
	while (begin_2 <= end_2)
	{
		tmp[begin_tmp++] = a[begin_2++];
	}
	while (left <= right)//复制过去
	{
		a[left] = tmp[left];
		left++;
		//printf("%d ", a[left]);
	}
}
void MergeSort(int* arr, int n)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int) * n);
	//_MergeSort(arr,0,n,tmp);
	int gap = 1;
	for (gap = 1; gap <= n-1; gap=gap*2+1)
	{
		for (int x = 0; x+gap<=n; x += gap+1)
		{
			int begin_1 = x, end_1 = x + gap;
			int mid = (begin_1 + end_1) / 2;
			MergeSortpart(arr, begin_1,mid,end_1,tmp);
		}
		for (int i = 0; i < n + 1; i++)
		{
			printf(" %d", arr[i]);
		}
		printf("\n");
	}

	if (gap/2 != n-1)
	{
		MergeSortpart(arr, 0, gap/2, n,tmp);
	}
	//_MergeSort(arr,0,n-1,tmp);
}



void FileSort(FILE* p, int n)
{


}