#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char* convert(char* s, int numRows) {
    int step = 2*(numRows-1),length=0;
    char *p = s,*ret=0;
    while(*p++) length++;
    ret = p = (char*)malloc(sizeof(char)*(length+1));
    //边界处理
    if(numRows==1)  step = 1;
    for(int r=0;r<numRows;r++){
        //分类，首尾两行和其他中间行有不同的处理。
        if(r==0||r==(numRows-1)){
            int i=0,t=0;
            while((t=i*step+r)<length){
                *p++=s[t];
                i++;
            }
        }else{
            int i=0,t=0;
            while(1){
                if((t=i*step+r)<length) *p++=s[t];
                else break;
                if((t+=(2*(numRows-r)-2))<length) *p++=s[t];
                else break;
                i++;
            }
        }
    }
    *p='\0';
    return ret;
}

int main()
{
    puts(convert("PAYPALISHIRING", 3));
}