#include<bits/stdc++.h>
using namespace std;
class moz
{
public:
    int pnr;
    int sem;
    char branch[20];
    char name[20];
    char role[20];
    moz *next;

};
void saveandexit(moz *head)
{
    fstream f;
    f.open("aks.txt" ,ios::out | ios::in | ios::app);
    while(head->next!=NULL)
    {
        f<<head->pnr<<"        "<<head->name<<"        "<<head->branch<<"        "<<head->sem<<"        "<<head->role<<endl;
        head=head->next;
    }
    f.close();
}
void addmember(moz **first)
{
    system("CLS");
    moz *new_node=new moz(), *temp=*first;
    cout<<"pnr : "; cin>>new_node->pnr; cout<<endl;
    cout<<"NAME : ";cin>>new_node->name;
    cout<<endl;
    cout<<"BRANCH : ";cin>>new_node->branch;
    cout<<endl;
    cout<<"SEMESTER : ";cin>>new_node->sem;
    cout<<endl;
    cout<<"ROLE : "; cin>>new_node->role;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
    //if(role=="tech" || role=="marketing" ||)

}
void addpresident(moz **head)
{
    system("CLS");
    fstream f;
    f.open("aks.txt" ,ios::out | ios::in);
    cout<<"pnr : "; cin>>(*head)->pnr; cout<<endl;
    cout<<"NAME : ";cin>>(*head)->name;
    cout<<endl;
    cout<<"BRANCH : ";cin>>(*head)->branch;
    cout<<endl;
    cout<<"SEMESTER : ";cin>>(*head)->sem;
    cout<<endl;
    cout<<"ROLE : ";cin>>(*head)->role;
    cout<<endl;
    f.seekg(0,ios::beg);
    f<<(*head)->pnr<<"        "<<(*head)->name<<"        "<<(*head)->branch<<"        "<<(*head)->sem<<"        "<<(*head)->role<<endl;
    f.close();
}

void searchamember(moz **head)
{
    system("CLS");
    long int n;
    moz *temp=*head;
    cout<<"ENTER PNR ";cin>>n;
    while(temp->pnr!=n && temp!=NULL)
        temp=temp->next;
    if(temp->pnr==n)
    {
        cout<<"NAME :";puts(temp->name); cout<<endl;
        cout<<"BRANCH :";puts(temp->branch);cout<<endl;
        cout<<"ROLE :";puts(temp->role);cout<<endl;
        cout<<"SEMESTER :";cout<<temp->sem;cout<<endl;
    }
    else cout<<"PNR NOT FOUND";
}

void printlist(moz *head,moz *first)
{
    system("CLS");
   moz *temp=head;
   cout<<"=============================================================";cout<<endl;
   cout<<"PNR        NAME        BRANCH        SEMESTER        ROLE";cout<<endl;
   cout<<"=============================================================";cout<<endl;

    cout<<temp->pnr<<"        "<<temp->name<<"        "<<temp->branch<<"        "<<temp->sem<<"        "<<temp->role;
    temp=first;
   while(temp!=NULL)
   {
       cout<<temp->pnr<<"        "<<temp->name<<"         "<<temp->branch<<"            "<<temp->sem<<"              "<<temp->role;
       cout<<endl;
       temp=temp->next;
   }
}

void deleteamember(moz **head)
{
    int n;
    system("CLS");
    moz *temp=*head,*prev;
    cout<<"ENTER THE PNR OF THE MEMBER TO BE DELETED ";
    cin>>n;
     while(temp!=NULL && temp->pnr!=n)
     {
         prev=temp;
         temp=temp->next;
     }
     if(temp->pnr==n)
     {
         prev->next=temp->next;
         free(temp);
     }
     else cout<<"PNR NOT FOUND";
}

void modify(moz **head)
{
   system("CLS");
    long int n;
    moz *temp=*head;
    cout<<"ENTER PNR ";cin>>n;
    while(temp->pnr!=n && temp!=NULL)
        temp=temp->next;
    if(temp->pnr==n)
    {
        cout<<"NAME :";gets(temp->name); cout<<endl;
        cout<<"BRANCH :";gets(temp->branch);cout<<endl;
        cout<<"ROLE :";gets(temp->role);cout<<endl;
        cout<<"SEMESTER :";cin>>temp->sem;cout<<endl;
    }
    else cout<<"PNR NOT FOUND";
}


int main()
{
    int i,j,p;
    char ch='y';
    moz *head=new moz(),*first=new moz();
    head->next=first;
    //initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");

    setw(10);
    while(ch=='y')
    {
    system("CLS");
     cout<<"=============================================================";cout<<endl;
    cout<<setw(20)<<"                WELCOME TO MOZILLA CLUB"               <<endl;
    cout<<"=============================================================";cout<<endl;
   cout<<endl<<endl<<endl;
    cout<<"1. ADD PRESIDENT"<<endl;
    cout<<"2. ADD MEMBER"<<endl;
    cout<<"3. SEARCH A MEMBER"<<endl;
    cout<<"4. PRINT ALL MEMBERS LIST "<<endl;
    cout<<"5. DELETE A MEMBER "<<endl;
    cout<<"6. MODIFY "<<endl;
    cout<<"7. SAVE AND EXIT"<<endl<<endl;
    cout<<"   CHOOSE A OPTION : ";
    cin>>p;
    switch(p)
    {
   case 1:
        addpresident(&head);  break;
    case 2:
        addmember(&first);  break;
    case 3:
        searchamember(&head);break;
    case 4:
        printlist(head,first);  break;
    case 5:
        deleteamember(&first); break;
    case 6:
        modify(&head); break;
    case 7:
        saveandexit(head);
        return 0;
    }
    cout<<" \n DO YOU WANT TO REURN TO THE MAIN MENU (y/n)";
    cin>>ch;
    }

 saveandexit(head);

 }
