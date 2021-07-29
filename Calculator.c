#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_REG 10
int operand(char *op1,int *Reg )
{   op1=strtok(NULL," ");
  if(strncmp(op1,"0x",2)==0)
return strtol(op1,NULL,16);

else if(strncmp(op1,"R",1)==0)
{
    int j=atoi(op1+1);
return Reg[j];
}
}

 int main (void){
FILE *fp=fopen("input.txt","r");
if (fp==NULL) exit(EXIT_FAILURE);
char *op1=NULL;
char *op2=NULL;
char *op3=NULL;
char *line=NULL;
int Reg[MAX_REG]={0};
size_t len =0;
ssize_t read;
char linesave[100][30];
int n=0; int fline=0;int r=0;int t=0;
while ((read=getline(&line, &len, fp)) != -1){
    strcpy(linesave[fline], line);
        fline++;}

while(1){
      strcpy(line,linesave[n++]);
      op1=strtok(line," ");

if(strchr("+-*/",*op1) != NULL)
{ switch(*op1){
  case'+': Reg[0]=operand(op1,Reg)+operand(op1,Reg);
           break;
  case'-': Reg[0]=operand(op1,Reg)-operand(op1,Reg);
       break;
  case'*': Reg[0]=operand(op1,Reg)*operand(op1,Reg);
           break;
  case'/': r=operand(op1,Reg); t=operand(op1,Reg);
           if(t==0)
         {  printf("Program Error!!!!!!!!!\n");
             return 0;
}
            else
           Reg[0]=r/t;
           break;

}
}
else if(strchr("M",*op1) != NULL)
{     op2=strtok(NULL," ");
    int i=atoi(op2+1);
     op3=strtok(NULL," ");
   printf("Reg[%d] = %d\n",i,  Reg[i]=strtol(op3,NULL,16));

}
else if(strchr("C",*op1) != NULL)
{
       if(operand(op1,Reg)>=operand(op1,Reg))
        Reg[0]=0;
       else if(operand(op1,Reg)<operand(op1,Reg))
        Reg[0]=1;

}
else if(strchr("J",*op1) != NULL)
{      n=operand(op1,Reg)-1;
  continue;
}
else if(strchr("B",*op1) != NULL)
{    if(Reg[0]==1)
      {n=operand(op1,Reg)-1;
       continue;
}

}
if(strchr("H",*op1) != NULL)
break;
printf("Now the value of Register[0] is %d\n",Reg[0]);
}

free(line);
fclose(fp);
exit(EXIT_SUCCESS);

return 0;

}
