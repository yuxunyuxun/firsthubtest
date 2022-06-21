#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    unsigned int i, tag,codeStreamNum, length,value;
    unsigned int buf[2] = {0};
    
    while(scanf("%X", &tag) != EOF){
        (void)getchar();
        while(scanf("%X",&codeStreamNum) != EOF){
            (void)scanf("%X", &buf[0]);
            (void)scanf("%X", &buf[1]);
            length = buf[1] << 16 | buf[0];
            
            if(codeStreamNum == tag){
                for(i = 0; i < length; i++){
                    (void)scanf("%X", &value);
                    if(i != length - 1){
                        printf("%X ", value);
                    }else{
                        printf("%X\n",value);
                    }
                }
            }else{
                for(i = 0; i < length; i++){
                    (void) scanf("%X", &value);
                }
            }
            if(getchar() == '\n'){
                break;
            }
        }
    }
    return 0;
}