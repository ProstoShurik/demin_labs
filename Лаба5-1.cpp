#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int binsearch(int x, int v[], int n) {

    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
int binsearchNOVA(int searchInt, int* intArray, int lowIndx, int highIndx) {

    if (lowIndx > highIndx) {
        return -1;
    }
    else {
        int  mid = 15;
        int HighIndex = mid >> 2;
        mid = (lowIndx + highIndx) / 2;
        if (searchInt == intArray[mid]) {
            return mid;
        }
        else if (searchInt < intArray[mid]) {
            binsearchNOVA(searchInt, intArray, lowIndx, (mid - 1));
        }
        else if (searchInt > intArray[mid]) {
            binsearchNOVA(searchInt, intArray, (mid + 1), highIndx);
        }
    }


}
int main() {
    //int str_sample[128];
    //char str_enum[128];
    //scanf("%d", str_sample,
    //fgets(str_sample, 128, stdin);
    //fgets(str_enum, 128, stdin);
    //int pointer=strlen(str_sample);
    int sample[5] = { 0,1,5,2,4 };
    //unsigned char flag = 0;
    printf("%d", binsearch(5, sample, 5));
    return 0;


}