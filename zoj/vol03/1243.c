//run id 3007253	2012-08-07 21:04:15	 Accepted
#include <stdio.h>
char url[62],protocol[62],host[62],port[6];
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    getchar();
    i=1;
    while(i<=t) {
        gets(url);
        printf("URL #%d\n",i);
        for(j=0; url[j]!=':'; j++)
            protocol[j]=url[j];
        protocol[j]='\0';
        j+=3;
        for(k=0; url[j]&&url[j]!=':'&&url[j]!='/'; j++,k++)
            host[k]=url[j];
        host[k]='\0';
        printf("Protocol = %s\n",protocol);
        printf("Host     = %s\n",host);
        if(!url[j]) {
            printf("Port     = <default>\n");
            printf("Path     = <default>\n\n");
        } else {
            if(url[j]=='/')printf("Port     = <default>\n");
            else {  /* url[j]=':' */
                j++;
                for(k=0; url[j]&&url[j]!='/'; j++,k++)
                    port[k]=url[j];
                port[k]='\0';
                printf("Port     = %s\n",port);
            }
            if(!url[j])printf("Path     = <default>\n\n");
            else printf("Path     = %s\n\n",url+j+1);
        }
        i++;
    }
    return 0;
}
