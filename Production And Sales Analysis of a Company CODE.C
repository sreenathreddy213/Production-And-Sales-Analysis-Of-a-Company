#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class List
{
protected :
int dd,mm,yy;
public:
char name[50];
int qty;
float price;
int icode;
void get()
{
cout<<"\t\tItem code : "<<icode<<endl;
cout<<"\t\tItem name : ";
fflush(stdin);
cin.getline(name,50);
cout<<"\t\tQuantity  : ";
cin>>qty;
cout<<"\t\tDate of Manufacture :"<<endl;
cout<<"\t\tday mon yr"<<endl<<"\t\t";
cin>>dd;
if(cin.get()=='\n')
cout<<"\b\r\t\t"<<dd<<" ";
cin>>mm;
if(cin.get()=='\n')
cout<<"\b\r\t\t"<<dd<<" "<<mm<<" ";
cin>>yy;
cout<<"\t\tPrice :";
cin>>price;
int l=strlen(name);
int i=l;
while(i<20)
{
strcat(name," ");
i++;
}
}
};
class items:public List
{
public:
void display()
{
name[21]='\0';
int d,m,y;d=dd/10;m=mm/10;y=yy/100;
if(y==0)
y=20;
if(yy<10)
y=200;
cout<<"\t\t"<<icode<<"\t      "<<name<<"     \t"<<d<<dd%10<<"/"<<m<<mm%10<<"/"<<y<<yy%100<<"\t   "<<qty<<"\t\t   "<<price<<endl;
cout<<"\t        -----------------------------------------------------------------------------------------\n";
}
};
fstream fp;
items item;

int itemcode()
{
items it;
int inum;
ifstream in("Item_list.dat");
in.seekg(0,ios::end);
if(in.tellg()==0)
{
inum=1000;
}
else
{
in.seekg(-sizeof(items),ios::end);
in.read((char*)&it,sizeof(items));
in.close();
inum= item.icode;
   }
   return inum;
}

void add()
{
system("cls");
cout<<"\n\t\t\t\t\t ===========";
cout<<"\n\t\t\t\t\t     ADD";
cout<<"\n\t\t\t\t\t ===========\n";
fp.open("Item_list.dat",ios::out|ios::app);
item.icode=itemcode()+1;
item.get();
fp.write((char*)&item,sizeof(items));
fp.close();
cout<<"\n\n\t\t\t\"Successfully Added\"\n\n";
}

void show()
{
system("cls");
cout<<"\n\t\t\t\t\t\t======================";
    cout<<"\n\t\t\t\t\t\tIBACO ICECREAM PARLOUR";
    cout<<"\n\t\t\t\t\t\t======================\n";
cout<<"\n\t\t\t             ===================";
cout<<"\n\t\t\t                LIST OF ITEMS\n\t\t\t             ===================\n\n";
fp.open("Item_list.dat",ios::in);
if(fp.read((char*)&item,sizeof(items))==0)
cout<<"\t\tNo item\n";
else
{
cout<<"\t\tItem code    Item name\t\t         MFD\t\t   QTY(ml)\t Price(per 100ml)\n";
cout<<"\t        =========================================================================================\n";
while(fp)
{
item.display();
fp.read((char*)&item,sizeof(items));
}
}
fp.close();
}

void Delete()
{
show();
int delc;int found=0;
fp.open("Item_list.dat",ios::in);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
if(fp.read((char*)&item,sizeof(items))!=0)
{
cout<<"\t\t\t\t    ==============";
cout<<"\n\t\t\t\t        DELETE\n";
cout<<"\t\t\t\t    ==============\n";
cout<<"\t\tEnter the code of product to be deleted ";
cin>>delc;
while(fp)
{
if(delc!=item.icode)
{
fp2.write((char*)&item,sizeof(items));
}
else
{
found=1;
}
fp.read((char*)&item,sizeof(items));
}
fp.close();
fp2.close();
remove("Item_list.dat");
rename("Temp.dat","Item_list.dat");
if(found==1)
{
cout<<"\n\n\t\t\t  \"Successfully deleted\"\n\n";
}
else
{
cout<<"\n\n\t\t\t    \"NOT AVAILABLE\"\n\n";
}
}
fp.close();
fp2.close();
}
void remain()
{
    system("cls");
                 system("color f6");
       cout<<"\n\t\t\t\t\t\t======================";
                cout<<"\n\t\t\t\t\t\tIBACO ICECREAM PARLOUR";
                cout<<"\n\t\t\t\t\t\t======================\n";
cout<<"\n\n\t     ======================\n";
cout<<"\t     PRODUCTS QUANTITY LIST ";
cout<<"\n\t     ======================\n\n";
fp.open("Item_list.dat",ios::in);
if(fp.read((char*)&item,sizeof(items))==0)
cout<<"\t\tNo item\n";
else
{
cout<<"\t\tItem code    Item name\t\t         MFD\t\t   QTY(ml)\t Price(per 100ml)\n";
cout<<"\t        =========================================================================================\n";
while(fp)
{
item.display();
fp.read((char*)&item,sizeof(items));
}
}
fp.close();
}
void update()
{
show();
int updc;int found=0;
fp.open("Item_list.dat",ios::in);
fstream fp2;
fp2.open("Temp.dat",ios::out);
fp.seekg(0,ios::beg);
if(fp.read((char*)&item,sizeof(items))!=0)
{
cout<<"\n\t\t\t\t    ==============";
cout<<"\n\t\t\t\t        UPDATE\n";
cout<<"\t\t\t\t    ==============\n";
cout<<"\t\tEnter the code of product to be updated  ";
cin>>updc;
while(fp)
{
if(updc!=item.icode)
{
fp2.write((char*)&item,sizeof(items));
}
else
{
found=1;
item.get();

fp2.write((char*)&item,sizeof(items));
}
fp.read((char*)&item,sizeof(items));
}
fp.close();
fp2.close();
remove("Item_list.dat");
rename("Temp.dat","Item_list.dat");
if(found==1)
{
cout<<"\n\n\t\t\t  \"Successfully Updated\"\n\n";
}
else
{
cout<<"\n\t\t\t    \"NOT AVAILABLE\"\n\n";
}
}
fp.close();
fp2.close();
}
void gen_bill()
{
show();
ifstream in("Item_list.dat");
if(in.read((char*)&item,sizeof(items))!=0)
{
cout<<"\n\t\t\t\t =================";
cout<<"\n\t\t\t\t   CUSTOMER BILL\n";
cout<<"\t\t\t\t =================\n";
int n=0,i=0;float sum=0,p;
int y=1;
int pr[20];
float q[20];
while(y)
{
cout<<"\t\tEnter product code :";
cin>>pr[n];
cout<<"\t\tQuantity :";
cin>>q[n];
n++;
cout<<"\tpress y for more or else press Enter  ";
if(getch()!='y')
y=0;
cout<<"\r\t        ------------------------    \n";
}
system("cls");
cout<<"\n\t\t\t\t\t\t======================";
cout<<"\n\t\t\t\t\t\tIBACO ICECREAM PARLOUR";
    cout<<"\n\t\t\t\t\t\t======================\n";
cout<<"\n\t\t\t\t\t ============";
cout<<"\n\t\t\t\t\t     BILL\n";
cout<<"\t\t\t\t\t ============\n\n";
cout<<"\t\tItem code    Item name\t\t       Quantity\t\tPrice\n";
cout<<"\t        ===============================================================\n";
in.close();
for(i=0;i<n;i++)
{
ifstream in("Item_list.dat");
fstream cp;
        cp.open("Demo.dat",ios::out);
int ind=1;
in.seekg(0,ios::beg);
while(in.read((char*)&item,sizeof(items)))
{
            if(pr[i]==item.icode)
   {
            if(item.qty==0||item.qty<q[i])
            {
               ind=0;
            }
            else
            {
            item.qty=item.qty-q[i];
p=(q[i]*item.price)/100;
sum+=p;
ind=1;
cout<<"\t\t"<<pr[i]<<"\t     "<<item.name<<"\t"<<q[i]<<"\t\t"<<p<<endl;


/*in.seekg(sizeof(items),ios::cur);
ofstream ot("Item_list.dat");
ot.write((char*)&item,sizeof(items));
ot.close();
break;*/
int j=0;
            in.seekg(0,ios::beg);
if(in.read((char*)&item,sizeof(items))!=0)
        {
        while(in)
       {
    if(pr[j]!=item.icode)
    {
cp.write((char*)&item,sizeof(items));
   }
  else
   {
            item.qty=item.qty-q[i];
cp.write((char*)&item,sizeof(items));
   }
   in.read((char*)&item,sizeof(items));
   j++;
        }
       in.close();
       cp.close();
       remove("Item_list.dat");
       rename("Demo.dat","Item_list.dat");
   }
   }
   }
   /*int j=0;
            in.seekg(0,ios::beg);
if(in.read((char*)&item,sizeof(items))!=0)
        {
        while(in)
       {
    if(pr[j]!=item.icode)
    {
cp.write((char*)&item,sizeof(items));
   }
  else
   {
            //item.qty=item.qty-q[i];
cp.write((char*)&item,sizeof(items));
   }
   in.read((char*)&item,sizeof(items));
   j++;
        }
       in.close();
       cp.close();
       remove("Item_list.dat");
       rename("Demo.dat","Item_list.dat");
   }*/
if(ind==0)
{
cout<<"\t\t"<<pr[i]<<"\t     NOT AVAILABLE\n";
in.close();
break;
}
}
cout<<"\t\t---------------------------------------------------------------\n";

}
cout<<"\t\tTotal  : Rs "<<sum<<endl;
in.close();
}
}
void ex()
{
system("cls");
cout<<"\n\n\n\n\t\t\t\t\t\t  THANKYOU\n\n";
cout<<"\t\t\t\t\t   **********************\n";
exit(1);
}
main()
{
    //remove("Item_list.dat");
char ch1,ch2;
start:
system("cls");
system("color e4");
cout<<"\n\t\t\t\t\t\t======================";
cout<<"\n\t\t\t\t\t\tIBACO ICECREAM PARLOUR";
cout<<"\n\t\t\t\t\t\t======================\n";
cout<<"\n\n\t\t   ===============\n";
cout<<"\t\t      MAIN MENU ";
cout<<"\n\t\t   ===============\n\n";
cout<<"\n\t\tPress 1. Customer Billing\n";
cout<<"\n\t\tPress 2. Display Items\n";
cout<<"\n\t\tPress 3. Edit Item List\n";
cout<<"\n\t\tPress 4. Display quantity list\n";
cout<<"\n\t\tPress Backspace to EXIT\n\n";
cout<<"\n\t\tEnter your choice  ::  ";
fflush(stdin);
while(1)
{
ch1=getch();
if(ch1!='1'&&ch1!='2'&&ch1!='3'&&ch1!='4'&&ch1!='\b')
cout<<"Invalid input\n\t\tEnter again\n\t\t";
else
break;
}
ed:
switch(ch1)
{
case '1':
{
gen_bill();
cout<<"\n\n\n";
cout<<"\t0:EXIT";
cout<<"\n\tbackspace:BACK\n\t";
char cc1;
while(1)
{
cc1=getch();
if(cc1=='\b'||cc1=='0')
break;
else
cout<<"Invalid input\n\t\tEnter again\n\t";
}
if(cc1=='\b')
goto start;
else
ex();
break;
}
case '2':
{
show();
cout<<"\n\n\n";
cout<<"\t0:EXIT";
cout<<"\n\tbackspace:BACK\n\t";
char cc1;
while(1)
{
cc1=getch();
if(cc1=='\b'||cc1=='0')
break;
else
cout<<"Invalid input\n\t\tEnter again\n\t\t";
}
if(cc1=='\b')
goto start;
else
ex();
break;
}
case '3':
{
system("cls");
       cout<<"\n\t\t\t\t\t\t======================";
                cout<<"\n\t\t\t\t\t\tIBACO ICECREAM PARLOUR";
                cout<<"\n\t\t\t\t\t\t======================\n";
system("color a5");
cout<<"\n\n\t     =======================\n";
cout<<"\t        EDIT PRODUCT LIST ";
cout<<"\n\t     =======================\n\n";
cout<<"\n\t\t1.Add Product\n";
cout<<"\n\t\t2.Delete Product\n";
cout<<"\n\t\t3.Modify Detail\n";
cout<<"\n\t\t0.EXIT\n";
cout<<"\n\t\tBackspace.BACK\n\t\t";
fflush(stdin);
while(1)
{
ch2=getch();
if(ch2!='1'&&ch2!='2'&&ch2!='3'&&ch2!='\b'&&ch2!='0')
cout<<"Invalid input\n\t\tEnter again\n\t\t";
else
break;
}
again:
switch(ch2)
{
case '1':
{
add();
cout<<"\n\t1:Add again";
break;
}
case '2':
{
Delete();
cout<<"\n\t1:Delete again";
break;
}
case '3':
{
update();
cout<<"\n\t1:Update again";
break;
}
case '\b':
{
goto start;
break;
}
case '0':
{
ex();
}
}
cout<<"\n\t2:Main menu\n";
cout<<"\t0:EXIT\n\t";
cout<<"backspace:BACK\n\t";
char cc;
while(1)
{
cc=getch();
if(cc=='1'||cc=='2'||cc=='0'||cc=='\b')
break;
else
cout<<"Invalid input\n\tEnter again\n\t";
}
if(cc=='1')
goto again;
else
if(cc=='2')
goto start;
else if(cc=='\b')
goto ed;
else
ex();
break;
}
            case '4':
            {
                 remain();
                 cout<<"\n\n\n";
cout<<"\t0:EXIT";
cout<<"\n\tbackspace:BACK\n\t";
char cc1;
while(1)
{
cc1=getch();
if(cc1=='\b'||cc1=='0')
break;
else
cout<<"Invalid input\n\t\tEnter again\n\t\t";
}
if(cc1=='\b')
goto start;
else
ex();
break;

            }
case '\b':
{
ex();
}
}
}
