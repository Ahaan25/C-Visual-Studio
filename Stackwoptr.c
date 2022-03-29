#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Stack{
double array[500];
int size;
}stack;

int StackIsEmpty(stack *pf){
  //  if empty return 1 or else 0
  if(pf->size==-1){
      return 1;
  }
  else{
      return 0;
  }
}

void Push(double elt,stack* pf){
    (*pf).size+=1;
    (*pf).array[(*pf).size]=elt;
    printf("%d",pf->size);
}

double Top(stack *pf){
    if(StackIsEmpty(pf)){
        return -1;
    }
    else{
        return pf->array[pf->size];
    }
}

double Pop(stack *pf){
if(StackIsEmpty(pf)){
    return -1;
}
else{
    (*pf).size-=1;
    return pf->array[pf->size+1];
}
}

int main(){
stack postfix;
char input_string[500];
//scanf("%s",input_input_string);
gets(input_string);
int i=0;
double val_1,val_2;
while(input_string[i]!='\n' && input_string[i]!='\0'){
    if(input_string[i]!=','){
        if(input_string[i]>='0' && input_string[i]<='9')
            Push(atof(&input_string[i]),&postfix);
        else{
            switch (input_string[i])
            {
            case '*':
                Push(Pop(&postfix)*Pop(&postfix),&postfix);
                
                break;
            case '+':
                val_1=Pop(&postfix);
                val_2=Pop(&postfix);
                printf("%f %f",val_1,val_2);
                //Push(Pop(&postfix)+Pop(&postfix),&postfix);
                break;
            case '-':
                Push(Pop(&postfix)-Pop(&postfix),&postfix);
                break;
            case '/':
                Push(Pop(&postfix)/Pop(&postfix),&postfix);
                break;
            }
        }
    }
    i++;
}

printf("%.6f",Top(&postfix));
return 0;
}