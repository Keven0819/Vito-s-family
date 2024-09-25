#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int data; //輸入有幾筆資料
    scanf("%d", &data);
    for (int i = 0; i < data; i++) { //利用data給的數來控制迴圈執行的次數
        int people; //輸入Vito的親戚有幾個
        scanf("%d", &people);
        int arr[people]; //用親戚的數量來宣告陣列
        for (int j = 0; j < people; j++) { //將親戚的門牌號碼依序存入陣列
            scanf("%d", &arr[j]); //輸入親戚的門牌號碼
        }

        //用qsort函數將陣列由小到大排序
        qsort(arr, people, sizeof(int), compare);

        int mid = arr[people / 2]; //找出中間的數字
        int sum = 0; //宣告一個變數來存放結果
        for (int j = 0; j < people; j++) {
            sum += abs(mid - arr[j]); //將每個親戚的門牌號碼與中間的數字相減取絕對值相加
        }
        printf("%d\n", sum); //每次迴圈結束後印出結果，然後換行
    }
    return 0;
}
