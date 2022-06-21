#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char aerf;
    int count_yx;
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
    DataCount *aerfX = (DataCount *)x;
    DataCount *aerfY = (DataCount *)y;
    
    if(aerfY->count_yx > aerfX->count_yx){
        return 1;
    }else if(aerfY->count_yx == aerfX->count_yx){
        if((LargerWORD(aerfX->aerf) == DATA_SMALL_YX && LargerWORD(aerfY->aerf) == DATA_SMALL_YX) || 
           (LargerWORD(aerfX->aerf) == DATA_LARGE_YX && LargerWORD(aerfY->aerf) == DATA_LARGE_YX)){
            return aerfX->aerf - aerfY -> aerf;
        }
        if(LargerWORD(aerfX->aerf) == DATA_SMALL_YX && LargerWORD(aerfY->aerf) == DATA_LARGE_YX){
            return -1;
        }
        else if(aerfX->aerf == aerfY->aerf){
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
    DataCount aerf[58];
    
    memset(aerf, 0, sizeof(aerf));
    for( i = 0; i < len; i++){
        ascii[s[i]]++;
    }
    
    for(i = 0; i < 128; i++){
        if(ascii[i] != 0){
            aerf[idx].aerf = i;
            aerf[idx].count_yx = ascii[i];
            //printf("%d,%d|", i, ascii[i]);
            idx++;
        }
    }
    
    qsort(aerf, idx, sizeof(DataCount), CompareFun);
    for(i = 0; i < idx; i++){
        if(idx == 1){
            printf("%c:%d", aerf[i].aerf, aerf[i].count_yx);
        }else{
            if(i == idx - 1){
                printf("%c:%d;", aerf[i].aerf, aerf[i].count_yx);
            }else{
                printf("%c:%d;", aerf[i].aerf, aerf[i].count_yx);
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


