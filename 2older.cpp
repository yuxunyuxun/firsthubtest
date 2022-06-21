#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char data;
    int count;
}DataCount;

typedef enum{
    DATA_SMALL_YX = 1,
    DATA_LARGE_YX,
    OTHER_YX,
}DataType;

int LargerWORD(char c){
    if(c >= 'a' && c <= 'z'){
        return DATA_SMALL_YX;//小写字母
    }
    if(c >= 'A' && c <= 'Z'){
        return DATA_LARGE_YX;//大写字母
    }
    return OTHER_YX;
}

int CompareFun(const void *x, const void *y){
    DataCount *dataX = (DataCount *)x;
    DataCount *dataY = (DataCount *)y;
    
    if(dataY->count > dataX->count){
        return 1;
    }else if(dataY->count == dataX->count){
        if((LargerWORD(dataX->data) == DATA_SMALL_YX && LargerWORD(dataY->data) == DATA_SMALL_YX) || 
           (LargerWORD(dataX->data) == DATA_LARGE_YX && LargerWORD(dataY->data) == DATA_LARGE_YX)){
            return dataX->data - dataY -> data;
        }
        if(LargerWORD(dataX->data) == DATA_SMALL_YX && LargerWORD(dataY->data) == DATA_LARGE_YX){
            return -1;
        }
        else if(dataX->data == dataY->data){
            return 0;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

void GetBuffData(char *s){
    int i;
    int idx = 0;
    int len = strlen(s);
    int ascii[128] = {0};
    DataCount data[58];
    
    memset(data, 0, sizeof(data));
    for( i = 0; i < len; i++){
        ascii[s[i]]++;
    }
    
    for(i = 0; i < 128; i++){
        if(ascii[i] != 0){
            data[idx].data = i;
            data[idx].count = ascii[i];
            //printf("%d,%d|", i, ascii[i]);
            idx++;
        }
    }
    
    qsort(data, idx, sizeof(DataCount), CompareFun);
    for(i = 0; i < idx; i++){
        if(idx == 1){
            printf("%c:%d", data[i].data, data[i].count);
        }else{
            if(i == idx - 1){
                printf("%c:%d;", data[i].data, data[i].count);
            }else{
                printf("%c:%d;", data[i].data, data[i].count);
            }
        }
    }
    
    printf("\n");
}

int main(){
    char s[1000] = {0};
    gets(s);
    GetBuffData(s);
}


