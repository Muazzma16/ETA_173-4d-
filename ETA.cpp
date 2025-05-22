#include<iostream>
using namespace std;

class exp {
public:
   int id;
   string name,date;
   float price;
   exp* next;
exp(int i, string n, float p, string d) {
    id=i;
    name=n;
    price=p;
    date=d;
    next=NULL;}
  };
  
  class explist {
public:
    exp* head;
    explist*nextlist;
    explist() {
        head=NULL;
        nextlist=NULL;
}
    void addexp(int id,string name,float price,string date) {
        exp* newexp = new exp(id,name,price,date);
        if(head==NULL)
        head=newexp;
    else{
        exp*temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newexp;
    }
}
    void display() {
        exp*temp=head;
        while(temp!=NULL) {
cout <<"ID: "<<temp->id<<", Name: "<<temp->name
<< ", Price: "<<temp->price<< ", Date: "<<temp->date<<endl;
temp = temp->next;
    }
}

    bool upexp(int id2) {
        exp*temp=head;
        while(temp!=NULL) {
        if(temp->id==id2) {
  cout<<"Updating expense with ID "<<id2<<endl;
  cout<<"Enter New Name: ";
  cin>>temp->name;
  cout<<"Enter New Price: ";
  cin>>temp->price;
  cout<<"Enter New Date: ";
  cin>>temp->date;
  cout <<"Updated successfully"<<endl;
      return true;
   }
          temp = temp->next;
  }
    return false;
}
    exp*max() {
   if(head==NULL)
   return NULL;
   exp*maxexp=head;
   exp*temp=head->next;

  while(temp!=NULL){
     if(temp->price>maxexp->price)
    maxexp = temp;
      temp = temp->next;
      }
     return maxexp;
    }
};

class expmng {
    explist*mhead;
  public:
    expmng() {
    mhead=NULL;
}
void addnewlist() {
    explist*newlist=new explist();
  int n, id;
   string name, date;
   float price;
  cout<<"How many expenses? "<<endl;
  cin>>n;
      for(int i=0;i<n;i++){
          cout<<"Enter ID: "; 
		  cin>>id;
          cout<<"Enter Name: ";
		  cin>>name;
          cout<<"Enter Price: ";
		  cin>>price;
          cout<<"Enter Date: ";
		  cin>>date;
    newlist->addexp(id,name,price,date);
}
   if(mhead==NULL)
   mhead=newlist;
else{
explist*temp=mhead;
   while(temp->nextlist!=NULL)
    temp = temp->nextlist;
    temp->nextlist=newlist;
   }
}
  void view() {
    explist*temp=mhead;
    int count=1;
    while(temp!=NULL) {
  cout<<" List :" <<count++<<endl;
  temp->display();
  temp = temp->nextlist;
  }
}
void upexpp() {
    int listno,eid;
    cout<<"Enter list number: ";
    cin>> listno;

    explist*temp=mhead;
        for(int i=1;i<listno&&temp!=NULL;i++)
    temp=temp->nextlist;

if(temp==NULL){
cout<< "List not found!"<<endl;
 return;
}
    cout<<"Enter Expense ID to update: ";
    cin>>eid; 
    if(temp->upexp(eid)==false)
    cout << "Expense ID not found in this list!"<<endl;
 }
 
 void mostexp() {
       explist*temp=mhead;
       exp*mostexp=NULL;
          while(temp!=NULL) {
       exp*listmax=temp->max();
   if(listmax!=NULL){
    if(mostexp==NULL || listmax->price>mostexp->price)
   mostexp=listmax;
  }
    temp=temp->nextlist;
}
        if(mostexp!=NULL) {
    cout<<"\n Most Expensive Expense:\n";
    cout <<"ID: "<<mostexp->id<<", Name: "<<mostexp->name
<<", Price: "<<mostexp->price<<", Date: "<<mostexp->date<<endl;
  }else{
          cout<<" No expenses found.\n";
       }
   }
};

int main() {
        expmng e;
    int ch;
do {
cout<<"\n--- Expense Tracker ---\n";
cout<<"1. Add Expense List\n";
cout<<"2. View All Lists\n";
cout<<"3. Update Expense by ID\n";
cout<<"4. Show Most Expensive Expense\n";
cout<<"0. Exit\n";
cout<<"Enter choice: ";
cin>>ch;

switch (ch) {
case 1: e.addnewlist(); break;
case 2: e.view(); break;
case 3: e.upexpp(); break;
case 4: e.mostexp(); break;
case 0: cout << "system closed!"; break;
default: cout << "Invalid choice"<<endl;
}
} while(ch!=0);

return 0;
}