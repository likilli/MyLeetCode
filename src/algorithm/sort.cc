
#include "sort.h"

#include <iostream>

void TraversalArray(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
    std::cout << arr[i] << ", ";
  std::cout << std::endl;
}

void QuickSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int i = l;
    int j = r;
    int flag = arr[l];

    while (i < j)
    {
      while (i < j && arr[j] >= flag) j--;
      if (i < j) arr[i++] = arr[j];

      while (i < j && arr[i] < flag) i++;
      if (i < j) arr[j--] = arr[i];
    }
    arr[i] = flag;

    QuickSort(arr, l, i - 1);
    QuickSort(arr, i + 1, r);
  }
}

void BubbleSort(int arr[], int length)
{
  TraversalArray(arr, length);
  for (int i = 0; i < length; ++i)
  {
    for (int j = i + 1; j < length; ++j)
    {
      if (arr[i] > arr[j])
      {
        int xt = arr[i];
        arr[i] = arr[j];
        arr[j] = xt;
      }
      //std::cout << '[' << j << "]: ";TraversalArray(arr, length);

    }

    //std::cout << i << ": ";TraversalArray(arr, length);
  }
}

void merge(int a[], int left, int mid, int right)
{
  int i = left; // starting index of left subarray
  int j = mid + 1; // starting index of right subarray
  int index = left; // used to place items in temp[]
  int temp[10];

  while(i<=mid && j<=right)
  {
    // place the smaller item at temp[index]
    if(a[i] < a[j]) { temp[index] = a[i]; i = i+1; } else { temp[index] = a[j]; j = j+1; } index++; } // i > mid would mean all items for left
  // subarray were successfully placed, and there
  // must be unplaced right subarray items
  if(i>mid)
  {
    while(j<=right)
    {
      temp[index] = a[j];
      index++;
      j++;
    }
  }
  // else all items of right subarray must have
  // been placed and there must be
  // unplaced items in the left-subarray
  else
  {
    while(i<=mid)
    {
      temp[index] = a[i];
      index++;
      i++;
    }
  }
  int p = left; // left index of subarray
  // by now index would have reached right
  // most index of right subarray

  // placing all items of temp[] into actual array a[]
  while(p < index)
  {
    a[p]=temp[p];
    p++;
  }
}

void mergeSort(int a[], int left, int right)
{
  int mid;
  if(left < right)
  {
    // can also use mid = left + (right - left) / 2
    // this can avoid data_ type overflow
    mid = (left + right) / 2;

    // recursive calls to sort first half and second half sub arrays
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}


