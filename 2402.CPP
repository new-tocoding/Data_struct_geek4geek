// Electricity Bill Generation & Management Project
#include<iostream.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<fstream.h>


struct bil
{
       int mtrno,prevrea,currea;
       char name[30],vil[30],tal[30],dist[30];
}s;

class bill
{
	int metno,dd,mm,yyyy,currea,prevrea,unit,fc;
	char name[30],vil[30],tal[30],dist[30],ch;
	float amnt,tot,fac,ed,ltot,late;

   public:
	void insert();
	void show();
	void search();
	void modify();
	void deletebill();
	void makebill();
	void display();
	void cashcollect();
	void paidlist();
	void deflist();
	bill()
	{
	s.mtrno=1000;
	}
};

void bill::insert()
{
	fstream f;
	clrscr();
	f.open("std.txt",ios::out|ios::app|ios::binary);

	if(!f)
	{
		cout<<"\n File not found";
		exit(0);
	}
	s.mtrno=s.mtrno+1;
	cout<<"\n\n\n\n\n\n\t Your Meter Number  :"<<s.mtrno;
	cout<<"\n\n\t Enter Your Name    :";
	cin>>s.name;
	cout<<"\n\n\t Enter Your address :\n";
	cout<<"\n\t  City / Village    :";
	cin>>s.vil;
	cout<<"\n\t  Taluka            :";
	cin>>s.tal;
	cout<<"\n\t  District          :";
	cin>>s.dist;
	prevrea=0;
	currea=0;


	f.write((char*)&s,sizeof(s));
	f.close();
}

void bill::show()
{
	 fstream f;
    clrscr();
    f.open("std.txt",ios::in|ios::binary|ios::app);
    if(!f)
    {
     cout<<"\n File not found";
     exit(0);
    }
    else
    {
  cout<<"\n Customer's List :";
  cout<<"\n\n********************************************************************************";
  cout<<"\n"<<" Meter No."<<"\t"<<"Name"<<"\t\t"<<"City"<<"\t\t"<<"Taluka"<<"\t\t"<<"District";
  cout<<"\n\n********************************************************************************";
  while(f.read((char*)&s,sizeof(s)))
  {
  cout<<"\n "<<s.mtrno<<"\t\t"<<s.name<<"\t\t"<<s.vil<<"\t\t"<<s.tal<<"\t\t"<<s.dist;
  cout<<"\n--------------------------------------------------------------------------------";
  }
  cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";
  getch();
  }
  f.close();
}

void bill::search()
{
	 fstream f;
	 clrscr();
	 int mno;
	 f.open("std.txt",ios::in|ios::binary);

	 if(!f)
	 {
		 cout<<"\n File not found";
		 exit(0);
	 }
	 cout<<"\n\n\tEnter Meter Number of the record to search :";
	 cin>>mno;
	 while( f.read((char*)&s,sizeof(s)))
	 {
		if(mno==s.mtrno)
		{
			cout<<"\n\n\n\t Record Found .....";
			cout<<"\n\n\t************************************************";
			cout<<"\n\n\t\tName           :"<<s.name;
			cout<<"\n\n\t\tMeter No       :"<<s.mtrno;
			cout<<"\n\n\t\tAddress        :";
			cout<<"\n\t\tCity / Village :"<<s.vil;
			cout<<"\n\t\tTaluka         :"<<s.tal;
			cout<<"\n\t\tDistrict       :"<<s.dist;
			cout<<"\n\n\t************************************************";
			cout<<"\n\n\n\n\n\t\t\tPress Any Key To Countinue ...... ";
		}
		else
		{
			cout<<"\n\n\n\t Record Not Found....";
			cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";
		}
		getch();
		f.close();
	 }
}
void bill::modify()
{
    fstream f;
    clrscr();
    int mno,count;
    long int pos;
    f.open("std.txt",ios::out|ios::in|ios::binary);

    if(!f)
    {
	 cout<<"\n File not found";
	 exit(0);
    }
      cout<<"\n\n\n\t Enter Meter number of the record to be modified :";
      cin>>mno;
      count=0;
      while(f.read((char*)&s,sizeof(s)))
      {
	 if(mno==s.mtrno)
	 {
		 cout<<"\n\n\n\n\t Old Record";
		 cout<<"\n\n\t***************************************";
		 cout<<"\n\t\tName           :"<<s.name;
		 cout<<"\n\n\t\tAddress        :";
		 cout<<"\n\t\tCity / Village :"<<s.vil;
		 cout<<"\n\t\tTaluka         :"<<s.tal;
		 cout<<"\n\t\tDistrict       :"<<s.dist;
		 cout<<"\n\n\t\tMeter No       :"<<s.mtrno;
		 cout<<"\n\t***************************************";

		 cout<<"\n\n\n\t Enter New Record";
		 cout<<"\n\n\t***************************************";
		 cout<<"\n\t\t Enter name        :";
		 cin>>s.name;
		 cout<<"\n\n\t\tEnter Your Address :";
		 cout<<"\n\t\t City / Village    :";
		 cin>>s.vil;
		 cout<<"\n\t\t Taluka            :";
		 cin>>s.tal;
		 cout<<"\n\t\t District          :";
		 cin>>s.dist;
		 cout<<"\n\t***************************************";
		 cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";
		 pos=count*sizeof(s);
		 f.seekp(pos,ios::beg);
		 f.write((char*)&s,sizeof(s));

	 }
		count++;
		f.clear();


	 }
	 f.close();
}

void bill::deletebill()
{
	int mno;
	clrscr();
	cout<<"\n\n\n\tEnter the Meter number of the record you want to delete:";
	cin>>mno;
	fstream fin("std.txt",ios::in|ios::binary);
	fstream fout("temp.txt",ios::out|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(mno!=s.mtrno)
		{
		fout.write((char*)&s,sizeof(s));
		
		}
	     	
	}
	fin.close();
	fout.close();
	remove("std.txt");
	rename("temp.txt","std.txt");
	cout<<"\n\n\n\tRecord  Successfully Deleted";
	cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";

}

void bill::makebill()
{
 clrscr();
 int x,y;
 fstream f;
 int mno;
 f.open("std.txt",ios::in|ios::binary);
 if(!f)
 {
   cout<<"\n File not found";
   exit(0);
 }
  cout<<"\n\n\tEnter Meter number of the record to make bill :";
  cin>>mno;
 while( f.read((char*)&s,sizeof(s)))
 {
  if(mno==s.mtrno)
  {
   clrscr();
   cout<<"\n\n\t********* MAHARASHTRA STATE ELECTRICITY BOARD ***************\n ";
   cout<<"\n\t\tName            :"<<s.name;
   cout<<"\n\n\t\tMeter Number    :"<<s.mtrno;
   cout<<"\n\n\t\tAddress         :";
   cout<<"\n\t\tCity / Village  :"<<s.vil;
   cout<<"\n\t\tTaluka          :"<<s.tal;
   cout<<"\n\t\tDistrict        :"<<s.dist;
   cout<<"\n\n\t*************************************************************\n";
   prevrea=currea;
   cout<<"\n\n\t\tPrevious Reading    :"<<prevrea;
   cout<<"\n\n\t\tCurrent Reading     :";
   cin>>currea;
   cout<<"\n\n\t\tEnter Date of Bill (dd/mm/yyyy):" ;
   cin>>dd>>mm>>yyyy;

   unit=currea-prevrea;
   if(unit>500)
    amnt=unit*(5.00);

   else if(unit>400 && unit<=500)
    amnt=unit*(4.00);

   else if(unit>300 && unit<=400)
    amnt=unit*(3.50);

   else if(unit>200 && unit<=300)
    amnt=unit*3.00 ;

   else if(unit>100 && unit<=200)
    amnt=unit*(2.50);

   else
    amnt=unit*2.00;

   fc=40;
   ed=(amnt*(0.12));
   fac=(amnt*(0.11));
   tot=amnt+fc+ed+fac;
   late=10;
   ltot=tot+late;
  if(mm<12)
  {
   mm=mm+1;
  }
  else
  {
   mm=01;
   yyyy=yyyy+1;
  }

 }
 else
 {
 cout<<"\n\n\n\t Record Not Found.....";
 }
f.write((char*)&s,sizeof(s));
f.close();
}
}

void bill::display()
 {
 clrscr();
 fstream f;
 int mno;
 f.open("std.txt",ios::in|ios::binary);
 if(!f)
 {
   cout<<"\n File not found";
   exit(0);
 }
  cout<<"\n\n\n\tEnter meter number to display bill :";
  cin>>mno;
 while( f.read((char*)&s,sizeof(s)))
 {
  if(mno==s.mtrno)
  {
   clrscr();
   cout<<"\n\n\t**************************************************************\n";
   cout<<"\n\t\t Name                          :"<<s.name;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Meter Number                  :"<<s.mtrno;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Address                       :";
   cout<<"\n\t\t   City / Village              :"<<s.vil;
   cout<<"\n\t\t   Taluka                      :"<<s.tal;
   cout<<"\n\t\t   District                    :"<<s.dist;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Total Unit is                 :"<<unit;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Energy Charges is             :"<<amnt;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Fixed Charges is              :"<<fc;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Energy Duty is                :"<<ed;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Fuel Adjustment Charges is    :"<<fac;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Total Amount is               :"<<tot;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Last Date To Be Paid is       :"<<dd<<"-"<<mm<<"-"<<yyyy;
   cout<<"\n\t\t----------------------\n";
   cout<<"\n\t\t Total Amount After This Date  :"<<ltot;
   cout<<"\n\n\t**************************************************************\n";
   cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";
   getch();
  } 

  cout<<"\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";

 
  }
    f.close();
}

pass()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\tc\bgi");
 int valid=0,retry=1;
 char  pass[4]="",password[]="ebill";

 cout<<"\n\n\n\n\n\n\n\n\n\t\t ***************************************";
 cout<<"\n\n\t\t   MAHARASHTRA STATE ELECTRICITY BOARD  ";
 cout<<"\n\n\t\t ***************************************";
 do
 {
cout<<"\n\n\n\n\n\n\n\t\t\tEnter The Password: ";
  int i=0, p=0;
  while(p!=13)
  {
   p=getch();
   if(p!=13)
   {
    pass[i]=p;
    i++;
    cout<<"*";
   }
  }

  if(strcmp(pass,password)==0)
  {  valid=1; break;}
  else
  {
   clrscr();
   cout<<"\n\n\t\tIncorrect Password! Try Again..\n";
   valid=0;
   retry+=1;
  }
  valid=1;
  }while(!valid || retry<=3);

  if(retry>3)
  {
  cout<<"\n\n\t\tMaximum 3 try only! Try Again...";
  getch();
  exit(0);
  }
  else
 {
   clrscr();
   cout<<"\n\n\n\n\n\n\t                          Welcome To                                 ";
   cout<<"\n\n\n\t MAHARASHTRA STATE ELECTRICITY BOARD's BILL MANAGEMENT PROJECT ";
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Any Key To Continue ...... ";
   getch();
  clrscr();
  }
 return 0;
}

  void main()
 {
 clrscr();
 int d;
 char ch;
 bill s1;
 pass();
 do
 {
  clrscr();
  do
  {
 cout<<"\n\n\n\n\t\t****** MAHARASHTRA STATE ELECTRICITY BOARD ******";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  1.  Enter New Record                         |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  2.  List of Customers                        |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  3.  Search a Record                          |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  4.  Modify a Record                          |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  5.  Delete a Record                          |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  6.  Make a Bill                              |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  7.  Display a Bill                           |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t|  8.  Exit                                     |";
 cout<<"\n\t\t|                                               |";
 cout<<"\n\t\t*************************************************";

 cout<<"\n\n\n\t\tEnter your choice:";
 cin>>d;

       switch(d)
       {

   case 1:s1.insert();
  break;
   case 2:s1.show();
  break;
   case 3:s1.search();
  break;
   case 4:s1.modify();
  break;
   case 5:s1.deletebill();
  break;
   case 6:s1.makebill();
  break;
   case 7:s1.display();
  break;
   case 8:
   exit(0);
   }

       }while(ch=='y'||ch=='Y');

     }   while(d<8);
       getch();
}
