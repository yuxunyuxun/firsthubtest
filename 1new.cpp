#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    unsigned int i, flag_yx,codeStreamNum, length,value;
    unsigned int buffer_yx[2] = {0};
    
    while(scanf("%X", &flag_yx) != EOF){
        (void)getchar();
        while(scanf("%X",&codeStreamNum) != EOF){
            (void)scanf("%X", &buffer_yx[0]);
            (void)scanf("%X", &buffer_yx[1]);
            length = buffer_yx[1] << 16 | buffer_yx[0];
            
            if(codeStreamNum == flag_yx){
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