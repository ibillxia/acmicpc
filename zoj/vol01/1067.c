//run id 2977884	2012-07-26 09:34:52	 Accepted
#include <stdio.h>

int main()
{
    int d[16][3];
    int i,r,g,b,x,y,z,m,t;
    for(i=0; i<16; i++)
        scanf("%d%d%d",d[i],d[i]+1,d[i]+2);
    while(1) {
        scanf("%d%d%d",&r,&g,&b);
        if((r==-1)&&(g==-1)&&(b==-1))break;
        x=d[0][0];
        y=d[0][1];
        z=d[0][2];
        m=(r-d[0][0])*(r-d[0][0])+(g-d[0][1])*(g-d[0][1])+(b-d[0][2])*(b-d[0][2]);
        for(i=1; i<16; i++) {
            t=(r-d[i][0])*(r-d[i][0])+(g-d[i][1])*(g-d[i][1])+(b-d[i][2])*(b-d[i][2]);
            if(t<m) {
                x=d[i][0];
                y=d[i][1];
                z=d[i][2];
                m=t;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,x,y,z);
    }
    return 0;
}
