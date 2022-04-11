/*
    判断原序列与目标序列是插入排序还是归并排序形成的；
    输出排序名，并输出下一次排序迭代后的序列
    注意：牛客上一次迭代是指序列发生变化，在排序迭代中有可能不对序列进行改变
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int n;
int origin[maxn],temp[maxn],target[maxn];

int check(int A[]){
    for(int i=0;i<n;i++){
        if(A[i] != target[i]) return 0;
    }
    return 1;
}

int insertion(int a[]){
    int flag = 0;
    for(int i=1;i<n;i++){    
        if(check(a) && i!=1){
            flag = 1;
        }

        int key = a[i];
        int j = i-1;
        while(j>=0 && (key<a[j])){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;

        if(flag){
            return 1;
        }

    }

    return 0;
}

void mergesort(int A[]){
    int flag = 0;
    for(int step=2;step / 2 <= n;step *= 2){
        if(check(A) && step != 2){
            flag  = 1;
        }

        for(int i = 0;i < n;i += step){
            sort(A + i, A + min(i+step, n));
        }
        if(flag){
            cout << "Merge Sort" << endl;
            return;
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> origin[i];
        temp[i] = origin[i];
    }

    for(int i=0;i<n;i++){
        cin >> target[i];
    }

    if(insertion(temp)){
        cout << "Insertion Sort" << endl;
        for(int i=0;i<n;i++){
            cout << temp[i];
            if(i < n-1) cout << " ";
        }
        cout << endl;
    }
    else {
        for(int i=0;i<n;i++){
            temp[i] = origin[i];
        }
        mergesort(temp);
        for(int i=0;i<n;i++){
            cout << temp[i];
            if(i < n-1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
