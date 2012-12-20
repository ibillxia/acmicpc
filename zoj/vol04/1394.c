#include <stdio.h>
#define PI 3.14159

int main(){
	int x,y,z;
	float n;
	char s[12];
	while(gets(s)){
		if(!strcmp(s,"ENDOFINPUT")) break;
		scanf("%d%d%d",&x,&y,&z);
		getchar();
		gets(s);
		if(z>180) z = 360-z;
		n = PI*x*z/90.0/5.0;
		if(y==0&&z==0 || (y>0 && n<=y))
			printf("YES %d\n",(int)(y-n/2));
		else
			printf("NO %d\n",5*y);
	}
	return 0;
}

