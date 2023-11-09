
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct student
    {
    int roll_no;
    char name[15];
    int sem;
    int sub[3];
    int st_total;
    };
   struct student total;
//void create(struct student,int );
void getdata(struct student[],int );
void display(struct student[],int);
void find_total(struct student[],int);
void display_result(struct student[],int);
int main()
{
struct student s[5];

int i,j,n,ch;
while(1)
{
printf("MENU\n");
printf("1->Enter student details\n2->display student details\n3->find totals\n4->display result\n5->exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:printf("Enter number of students");
        scanf("%d",&n);
        getdata(s,n);
        break;
  case 2:display(s,n);
        break;
  case 3:find_total(s,n);
         break;
  case 4:display_result(s,n);
         break;
  case 5:exit(0);
default:printf("INVALID CHOICE\n");
}
}
return 0;
}
void getdata(struct student s[] ,int n)
{
int i,j;
printf("enter %d student details\n",n);
for(i=0;i<n;i++)
{
printf("enter student%d roll_no,name and sem details\n",i+1);
scanf("%d%s%d",&s[i].roll_no,s[i].name,&s[i].sem);
printf("enter student%d marks in 3 subjects\n",i+1);
for(j=0;j<3;j++)
scanf("%d",&s[i].sub[j]);
}
}
void display(struct student s[],int n)
{
int i,j;
printf("%d student details\n",n);
printf("Roll_no\t Name\t Sem \t Sub1 \t Sub2 \t Sub3 \n");
for(i=0;i<n;i++)
{
printf("%d\t %s\t %d\t",s[i].roll_no,s[i].name,s[i].sem);

for(j=0;j<3;j++)
printf("%d\t ",s[i].sub[j]);
printf("\n");
}
}

void find_total(struct student s[],int n)
{
int i,j;
for(i=0;i<n;i++)
s[i].st_total=0;
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
{
s[i].st_total+=s[i].sub[j];
total.sub[j]+= s[i].sub[j];
}
}
printf("\n totals computed");
}

void display_result(struct student s[],int n)
{
int i,j;
printf("studentwise total\n");
printf("STUDENT\t TOTAL\n");
for(i=0;i<n;i++)
printf("Student[%d]\t %d\n",i+1,s[i].st_total);
printf("\nSubjectwise total\n");
printf("SUBJECT\t Total\n");
for(j=0;j<3;j++)
printf("subject[%d]\t%d\n",j+1,total.sub[j]);

}