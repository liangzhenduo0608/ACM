#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
	int n,t=0,i,j,k,m,len[101],length[30]={2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,4,4,4,4};
	char str[101],mor[401],morse[4][30]={
    {'.','-','-','-','.','.','-','.','.','.','-','.','-','-','-','.','-','.','.','-','.','.','.','-','-','-','.','.','-','-'},
	{'-','.','.','.',' ','.','-','.','.','-','.','-','-','.','-','-','-','-','.',' ','.','.','-','.','.','-','.','-','-','-'},
    {' ','.','-','.',' ','-','.','.',' ','-','-','.',' ',' ','-','-','.','.','.',' ','-','.','-','.','-','.','-','.','-','-'},
	{' ','.','.',' ',' ','.',' ','.',' ','-',' ','.',' ',' ',' ','.','-',' ',' ',' ',' ','-',' ','-','-','.','-','-','.','-'}};
	scanf("%d",&n);
	while(n-t)
    {
        scanf("%s",str);
        int l=strlen(str),flag;
        memset(mor,0,sizeof(mor));
        for(i=0,k=0;i<l;i++)
        {
            len[i]=str[i]>64&&str[i]<91?length[str[i]-65]:4;
            for(j=0;j<len[i];j++,k++)
                mor[k]=str[i]>64?(str[i]<91?morse[j][str[i]-65]:morse[j][26]):(str[i]<63?(str[i]<45?morse[j][27]:morse[j][28]):morse[j][29]);
        }
        std::reverse(len,len+l);
        printf("%d: ",++t);
        for(i=0,k=0;i<l;k+=len[i++])
            for(j=0;j<30;j++)
            {
                flag=1;
                for(m=0;m<len[i]&&flag;m++)
                    flag=mor[k+m]-morse[m][j]?0:1;
                flag=flag&&m<4&&morse[m][j]-' '?0:flag;
                if(flag)
                {
                    printf("%c",j<27?(j<26?j+65:95):(j<29?(j<28?44:46):63));
                    break;
                }
            }
        printf("\n");
    }
}
