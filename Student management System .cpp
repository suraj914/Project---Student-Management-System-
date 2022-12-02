//////////////////////////////////////////////////////
/////////////////////////////////////////
//
// Name - Kakade Suraj Savakar
// Date - 02/12/2022
// Mobile No - 9527654139
// 
////////////////////////////////////////
/////////////////////////////////////////////////////

//////////////////////////////////////////////////////
/////////////////////////////////

#include<conio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
bool check = false;
struct node    //structure of node //
{
 char name[20];
 char discipline[20];
 int rollNo;
 char section;//shift
 struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/////////////////////////////////
//////////////////////////////////////////////////////

void Add(PPNODE First)    //Adds record of student//
{
 PNODE newn = new NODE;
 newn -> next = NULL;
 PNODE temp = *First;
 cout<<"Enter name of student:"<<endl;
 gets(newn->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(newn->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>newn->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>newn->section;
 fflush(stdin);
 newn->next=NULL;

 if(*First == NULL)
 {
 *First = newn;
 
 }
 else
 {
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp -> next = newn;
 }
 cout<<endl<<"Recored Entered";
 getch();
}

/////////////////////////////////
//////////////////////////////////////////////////////

void Modify(PPNODE First)   //modifies record of student//
{

 PNODE prev=NULL;
 PNODE current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 prev=(*First);
 current=(*First);
 while(current->rollNo!=roll_no)
 {
    prev=current;
    current=current->next;
 }
 
 PNODE newn = new NODE;
 newn ->next = NULL;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 gets(newn->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(newn->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>newn->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>newn->section;
 fflush(stdin);
 prev->next=newn;
 newn->next=current->next;
 delete current;
 cout<<endl<<"Recored Modified";
 getch();
}

/////////////////////////////////
//////////////////////////////////////////////////////

void Search(PPNODE First)   //searches record of student//
{
 PNODE current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 current=(*First);
 while(current->rollNo!=roll_no)
 {
  current=current->next;
 }
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nRoll No:";
 cout<<current->rollNo;
 cout<<"\nDiscipline:";
 puts(current->discipline);
 cout<<"\nSection:";
 cout<<current->section;
 getch();
}

/////////////////////////////////
//////////////////////////////////////////////////////

void Delete(PPNODE First)    //deletes record of a student//
{
 PNODE prev=NULL;
 PNODE current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to Delete:"<<endl;
 cin>>roll_no;
 prev=(*First);
 current=(*First);
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 delete current;
 cout<<endl<<"Recored Deleted";
 getch();
}

/////////////////////////////////
//////////////////////////////////////////////////////

void Display(PNODE First)
{
    if(First == NULL)
    {
        cout<<"There is no any entry till Now \n";
        return;
    }
    PNODE temp = First;
    cout<<"The entered roll numbers are  with students name are "<<endl;
    cout<<"_____________________________________________"<<endl;

    while(temp != NULL)
    {
        cout<< temp ->rollNo << "---->" << temp ->name << endl;
        cout<<"_____________________________________________"<<endl;
   
        temp = temp -> next;
    }

    cout<<endl<<"Recored Displayed \n";
    getch();
   
}

/////////////////////////////////
//////////////////////////////////////////////////////

int main()
{
 char x ;
 PNODE Head = NULL;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\n\nPress Any Key To Continue . . . ."<<endl;
 getch();
 do
 {
  system("cls");
  cout<<"1--->Press '1' to add New record:"<<endl;
  cout<<"2--->Press '2' to search a record:"<<endl;
  cout<<"3--->Press '3' to modify a record:"<<endl;
  cout<<"4--->Press '4' to delete a record:"<<endl;
  cout<<"5--->Press '5' to display a record:"<<endl;
  cout<<"6--->Press '6' to exit:"<<endl;
  x=getch();
  if(x=='1')
  {
   system("cls");
   Add(&Head);
  }
  else if(x=='2')
  {
   system("cls");
   Search(&Head);
  }
  else if(x=='3')
  {
   system("cls");
   Modify(&Head);
  }
  else if(x=='4')
  {
   system("cls");
   Delete(&Head);
  }
  else if(x=='5')
  {
   system("cls");
   Display(Head);
  }
  else if(x=='6')
  {
    exit(0);
  }
  else
  {

  }
 }while(x != 27);
 getch();
}
/////////////////////////////////
//////////////////////////////////////////////////////

//         *** END OF PROGRAM ***         //