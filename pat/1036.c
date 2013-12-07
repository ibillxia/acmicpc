//file: 1036.c
//author: ibillxia
//ac: 2012年8月25日 星期六 00:51:02 HKT
//run id: 63878

#include <stdio.h>
#include <string.h>
int n,gd,mm,fm;
char ge,na[12],mn[12],fn[12],id[12],mid[12],fid[12];
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%s %c %s %d",na,&ge,id,&gd);
        if(ge=='F'){
            if((!fn[0])||(gd>fm)){
                fm=gd;
                strcpy(fn,na);
                strcpy(fid,id);
            }
        }else{
            if((!mn[0])||(gd<mm)){
                mm=gd;
                strcpy(mn,na);
                strcpy(mid,id);
            }
        }
    }
    if(!fn[0])printf("Absent\n");
    else printf("%s %s\n",fn,fid);
    if(!mn[0])printf("Absent\n");
    else printf("%s %s\n",mn,mid);
    if(!mm||!fm)printf("NA\n");
    else printf("%d\n",fm-mm);
    return 0;
}
