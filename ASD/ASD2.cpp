#include<iostream>
#include<ctype.h>//itisincludedforusingfunction..isalnum() 
#include<string.h>
#include<math.h>using 
namespace std; struct 
node
{
chardata;struct 
node *next;
};
classstack
{
node*top; 
public : 
stack()
{
top=NULL;
}
charTop()
{
return(top->data);
}
voidpush(charx)
{
node *temp; 
temp=new node; 
temp>data=x;
temp->next=top; 
top=temp;
}
charpop()
{
charvalue;value=top-
>data;top=top->next; 
return(value);
}
intisempty()
{
if(top==NUL 
L)return 1;
elsereturn0;
}
};
intpriority(charop)
{
if(op=='(' || op==)') return 0; else 
if(op=='+' || op==-') return 1; else 
if(op=='*'||op=='/'|op=='%')return 
2; else if(op=='^') return 3; else
return4;
}
intoperation(charop,intA,intB)
{
if(op=='*')
returnA*B;else 
if(op=='/')return 
A/B; else 
if(op==^')
return 
pow(A,B);
elseif(op=='+')return 
A+B;
else if(op=='-
') returnA-B; 
elsereturn-1;
}
voidinfixtopostfix(charinfix[50])//(a+b)*cinfixexpre...itisstring
{
chartoken,operand,post[50];//token=willreadallcharactersfromgivenexpressionint 
i, j=0; //operand=a, b, c // post[50] will stored our output
stackS;for(i=0;infix[i]!='\0';i++)//i=01 
2 3 4 5 6 7
{//( a +b )* c '\0'
token=infix[i]; // when i=2, token=infix[2], token=+ 
if(isalnum(token))//itwillcheckthetokenisalphabetornumber 
post[j++]=token; //post[]= aelseif(token=='(') //this will get 
execute
S.push(token);//(...itwillbepushedintostack 
elseif(token==')')
while((operand=S.pop())!='(')
post[j++]=operand; 
else
{
while(!S.isempty()&&priority(S.Top())>=priority(token)) 
post[j++]=S.pop();
S.push(token);
}
}
while(!S.isempty())post[j++]=S.pop();//ab+c* 
post[j]='\0'; //this will indicate end of the string 
cout<<post;
}
voidinfixtoprefix(charinfix[50])
{
chartoken,operand,pre[50]; 
int i, j=0;stack S; 
for(i=strlen(infix)-1; i>=0; i-
-)
{
token=infix[i]; 
if(isalnum(token)) 
pre[j++]=token;else 
if(token==')')S.push(token); 
else if(token=='(') 
while((operand=S.pop())!=')') 
pre[j++]=operand;else
{
while(!S.isempty()&&priority(S.Top())>priority(token))pre[j++]=S.pop(); 
S.push(token);
}
}
while(!S.isempty())
pre[j++]=S.pop(); 
pre[j]='\0';//Displayingin 
reversefor(i=strlen(pre)1; 
i>=0; i)cout<<pre[i];
}
floatpostfixevaluation(charexp[50])
{
inti,val;
char token; float 
Operand1,Operand2,Result; 
stackS;for(i=0;exp[i]!='\0';i++)
{
token=exp[i]; 
if(isdigit(token))
{
S.push(token48);
}
else
{
Operand2=S.pop(); 
Operand1=S.pop();
Result=operation(token,Operand1,Operand2); 
S.push(Result);
}
}
returnS.pop();
}
floatprefixevaluation(charStr[50])
{
inti,val;
floatOp1,Op2,Result;
stackS;for(i=strlen(Str)1;i>=0;i
)
{
if(isdigit(Str[i]))
{
S.push(Str[i]-48);
}
else
{
Op1=S.pop();
Op2=S.pop(); 
Result=operation(Str[i],Op1,Op2); 
S.push(Result);
}
}
returnS.pop();
}
intmain()
{
intchoice;charexpression[50];//Delaringcharacterarraytoenter 
expression (a+b)*c do
{
cout<<"\nEnterChoiceofOperation:\n1.InfixtoPostfix2.InfixtoPrefix3.PostfixEvaluation
4.PrefixEvaluation5.Exit\n";cin>>choice;switch(choice)
{
case 1: cout<<"Enter Infix Expression\n"; 
cin>>expression;//(a+b)*cinfixtopostfix(expression);
//function will get called break; case 2: cout<<"Enter Infix 
Expression\n";cin>>expression;infixtoprefix(expression); 
break; case 3: cout<<"Enter postfix Expression\n"; 
cin>>expression; 
cout<<"Answer:\n"<<postfixevaluation(expression)<<endl
; break; case 4: cout<<"Enter prefix Expression\n"; 
cin>>expression; 
cout<<"Answer:\n"<<prefixevaluation(expression)<<endl; 
break; case5: cout<<"Endof program\n";break; default: 
cout<<"Wrong Choice\n";break;
}
}while(choice!=5);
}
