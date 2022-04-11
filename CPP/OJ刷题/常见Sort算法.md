#
## 选择排序
在未排序序列中找到最小元素，放到已排序序列末尾
``` c++
    void select_sort(int A[], int len){
        for(int i=0;i<len-1;i++>){
            int min=i;
            for(int j=i+1;j<len-1;j++){
                if(A[j] < A[min] )
                    min = j; 
            }
            swap(A[i], A[min]);
        }
    }
```
## 冒泡排序
比较相邻元素，如果第一个比第二个大，就执行交换，最后最大元素会浮到最末
```c++
    void bubble_sort(int A[], int len){
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-1-i;j++){
                if(A[j+1] < A[j]) swap(A[j+1], A[j]);
            }
        }
    }
```
## 插入排序
将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
```c++
    void insertion_sort(int A[], int len){
        for(int i=1;i<len;i++){
            int key = A[i];
            int j = j - 1;
            while(j >= 0 && key < A[j]){
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = key;
        }
    }
```

## 归并排序
**递归实现**
```c++
    void merge(int A[], int L1, int R1, int L2, int R2){
        int i=L1,j=L2;
        int temp[maxn],index=0;

        while(i <= R1 && j <= R2){
            if(A[i] <= A[j]){
                temp[index++] = A[i++];
            } else {
                temp[index++] = A[j++];
            }
        }

        while(i <= R1) temp[index++] = A[i++];
        while(j <= R2) temp[index++] = A[j++];

        for(int i=0;i<index;i++){
            A[L1 + i] = temp[i];
        } 
    }

    void merge_sort(int A[], int left, int right){
        if(left >= right) 
            return;
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(A, left, mid, mid+1, right);
    }
```
**迭代实现**
```c++
    void merge_sort(int A[]){
        for(int step = 2; step/2 <= n; step += 2){
            for(int i=1;i <= n; i += step){
                //sort(A + i, A + min(i + step, n + 1));
                int mid = i + step / 2 - 1;
                if(mid + 1 <= n){
                    merge(A, i, mid, mid+1, min(i+step-1,n));
                }
            }
        }
    }
```
## 快速排序

```c++
    //标准分割函数
    int partition(int A[], int left, int right){
        int temp = A[left];
        while(left < right){
            while(left < right && A[right] > temp) right--;
            A[left] = A[right];
            while(left < right && A[left] <= temp) left++;
            A[right] = A[left];
        }

        A[left] = temp;
        return left;
    }

    //随机分割
    int rand_partion(int A[], int left, int right){
        int p = (round(1.0*rand() / RAND_MAX * (right - left) + left))  //RAND_MAX是stdlib.h中一个常数，不同系统，该值不同

        swap(A[p], A[left]);

        int temp = A[left];
        while(left < right){
            while(left < right && A[right] > temp) right--;
            A[left] = A[right];
            while(left < right && A[left] <= temp) left++;
            A[right] = A[left];
        }

        A[left] = temp;
        return left;
    }

    void quick_sort(int A[], int left, int right){
        if(left < right){
            int pos = partion(A, left, right); //rand_partion
            quick_sort(A, left, pos-1);
            quick_sort(A, pos + 1, right);
        }
    }
```



## 堆排序

```c++
#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[], int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    // 初始化，i從最後一個父節點開始調整
    // 建堆
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
```



