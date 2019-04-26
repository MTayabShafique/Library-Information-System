                                                //**************** Muhammad Tayyab Shafique *****************
                             
                                               //**************** Reg # SP14-BCS-113 **********************
                             
                                              //**************** library System Information ***************

// **** Some Header Files ****
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
// **** Structure 1 ****
struct record
{
int book_No;
char book_Title [40];
int isbn;
int D_O_P;
char N_O_P [40];
char Author [40];
char Keyword [40];
}
r;
//  **** structure 2 ****
struct issued
{
	char n_Person[40];
    int  B_NO;
    char B_Title[40];
    char Dep[40];
    char D_O_I[20];
    char D_O_R[20];
};
struct issued i;	

// **** Filing ****
FILE *fp;
FILE *fpi;
FILE *ft;
// ****Some functions section 1 ****
void gotoxy(int x, int y);
void S1_Record();
void add_Record(FILE *fp); 
void D_Record(FILE *fp); 
void M_Record(FILE *fp);  
void Del_Record(FILE *fp); 
void Q_Record (FILE *fp);
void Q_Title(FILE *fp);
void Q_Key(FILE *fp);
void Q_Auth(FILE *fp);
void Q_Isbn(FILE *fp);

// **** some fun sec 2 ****
void ad_Record(FILE *fpi);
void S2_Issued();
void dis_Record(FILE *fpi);
void Edt_Record(FILE *fpi);
void de_Record(FILE  *fpi);
void Q1_record ( FILE *fpi);
void Q_Person(FILE *fpi);
void Q_title(FILE *fpi);
void gotoxy(int x, int y)
{
	static HANDLE h = NULL; 
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y }; 
	SetConsoleCursorPosition(h,c);
}
void mainmenu();
main()
{
fp = fopen("r.dat","rb+");
	if (fp == NULL)
	{
		fp = fopen("r.dat","wb+");
		if (fp == NULL)
		{
	    	printf("File Cannot Open");	
	   		exit(0);
		}
	}
	fpi = fopen("i.dat","rb+");
	if (fpi == NULL)
	{
		fpi = fopen("i.dat","wb+");
		if (fpi == NULL)
		{
	    	printf("File Cannot Open");	
	   		exit(0);
		}
	}
	
	mainmenu();
	getch();
}
	
void mainmenu()          // *** Main Menu ***
{
	system("cls");
	int choice;
	gotoxy(27,4);
	printf("Welcome to Main Menu");
	gotoxy(0,5);
	printf("--------------------------------------------------------------------------------");
	gotoxy(24,6);
	printf("1. Press 1 For Record of All Books");
	gotoxy(24,8);
	printf("2. Press 2 For Issued Books");
    gotoxy(24,10);
    printf("3. Press 3 For Exit");
    gotoxy(24,12);
    printf("Enter Your Choice  :");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		S1_Record();
    		break;
    	case 2:
    		S2_Issued();
		    break;
		case 3:
		    exit(0);
			break;	
    }
}
void S1_Record()
{
	int choice;
	system("cls");
    gotoxy(15,3);
    printf("--------------------- Section 1 ------------------------");
    gotoxy(25,5);
    printf("Press 1 for Add Record");
    gotoxy(25,7);
    printf("Press 2 for Display All Record");
    gotoxy(25,9);
    printf("Press 3 for Edit Record");
    gotoxy(25,11);
    printf("Press 4 for Delete Record");
    gotoxy(25,13);
    printf("Press 5 for Qurey");
    gotoxy(25,15);
    printf("Press 6 for Back to Main Menu");
    gotoxy(25,17);
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		add_Record(fp);
    		break;
    	case 2:
    		D_Record(fp);
    		break;
    	case 3:
    		M_Record(fp);
    		break;
    	case 4:
    		Del_Record(fp);
    		break;
    	case 5:
    		Q_Record(fp);
    		break;
    	case 6:
    		mainmenu();
    		break;
    }
}
void add_Record(FILE *fp)                 // *** Add Record ***
{
	
	int choice;
	system("cls");
    gotoxy(10,5);
	printf("------------------ Add Record Menu ---------------------");	
	gotoxy(25,7);
	printf("Enter Book Number :");
	scanf("%d",&r.book_No);
	gotoxy(25,9);
	fflush(stdin);
	printf("Enter Book Titel :");
	gets(r.book_Title);
	gotoxy(25,11);
	printf("Enter Book ISBN :");
	scanf("%d",&r.isbn);
	gotoxy(25,13);
	printf("Enter Date of Publication :");
	scanf("%d",&r.D_O_P);
	gotoxy(25,15);
	fflush(stdin);
	printf("Enter Name of Publisher :");
	gets(r.N_O_P);
	gotoxy(25,17);
	fflush(stdin);
	printf("Enter Author Name :");
	gets(r.Author);
	gotoxy(25,19);
	fflush(stdin);
	printf("Enter Book KeyWord :");
    gets(r.Keyword);
	fseek(fp,0,SEEK_END);
    fwrite(&r,sizeof(r),1,fp);
    fclose(fp);
    fp=fopen("r.dat","rb+");
    fflush(stdin);
    printf("want to add more ?");
    choice = getch();
    if (choice == 'y' || choice == 'Y')
    add_Record(fp);
    else 
    mainmenu();
}
void D_Record(FILE *fp)    // *** Display Record ***
{
    int y=11;
	system("cls");
	gotoxy(10,5);
	printf("---------------------- Display Record -----------------------");
	gotoxy(0,6);
	printf("--------------------------------------------------------------------------------");
	gotoxy(0,7);
	printf("ID    Book Title    ISBN    D-O-P    N-O-P    Author    Keywords");
	gotoxy(0,8);
	printf("--------------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)
{
	gotoxy(0,y);
	printf("%d",r.book_No);
	gotoxy(6,y);
	printf("%s",r.book_Title);
	gotoxy(20,y);
	printf("%d",r.isbn);
	gotoxy(28,y);
	printf("%d",r.D_O_P);
	gotoxy(37,y);
	printf("%s",r.N_O_P);
	gotoxy(46,y);
	printf("%s",r.Author);
	gotoxy(56,y);
	printf("%s",r.Keyword);
	y++;
}
	getch();
	
}
void M_Record(FILE *fp)            //  *** Edit Record ***
{

int y=11;
int num;
system("cls");
gotoxy(7,5);
printf("----------------------------Edit Record----------------------------");
gotoxy(0,6);
printf("--------------------------------------------------------------------------------");
gotoxy(0,7);
printf("Enter Book no :");
scanf("%d",&num);
rewind(fp);
while (fread(&r,sizeof(r),1,fp)==1)
{
	if (num==r.book_No)
	{
	gotoxy(25,7);
	printf("Enter Book Number :");
	scanf("%d",&r.book_No);
	gotoxy(25,9);
	fflush(stdin);
	printf("Enter Book Titel :");
	gets(r.book_Title);
	gotoxy(25,11);
	printf("Enter Book ISBN : ");
	scanf("%d",&r.isbn);
	gotoxy(25,13);
	printf("Enter Date of Publication :");
	scanf("%d",&r.D_O_P);
	gotoxy(25,15);
	fflush(stdin);
	printf("Enter Name of Publisher :");
	gets(r.N_O_P);
	gotoxy(25,17);
	fflush(stdin);
	printf("Enter Author Name :");
	gets(r.Author);
	gotoxy(25,19);
	fflush(stdin);
	printf("Enter Book KeyWord :");
    gets(r.Keyword);
	fseek(fp,-sizeof(r),SEEK_CUR);
	fwrite(&r,sizeof(r),1,fp);
	break;	
	}
}
fclose(fp);
fp=fopen("r.dat","rb+");
}
void Del_Record(FILE *fp)                // **** Delete Record ****
{
int y=11;
int bookno;
char log[]="TAYYAB";
char p[40];
FILE *ft;
char name[40];
char another='Y';
system("cls");
printf("\nEnter the Password\n");
fflush(stdin);
gets(p);
if (strcmp(log,p)==0)
{
	printf("Password Wrong\n");
}
 while (another=='Y'||another=='y')
 {
 
system("cls");
gotoxy(5,5);
printf("----------------------------Delete Record----------------------------");
gotoxy(0,6);
printf("--------------------------------------------------------------------------------");
gotoxy(0,7);
printf("Enter Book Number :");
scanf("%d",&bookno);
ft=fopen("TEMP.DAT","wb+");
rewind(fp);
while (fread(&r,sizeof(r),1,fp)==1)
{
	if((r.book_No)!=bookno)
	fwrite(&r,sizeof(r),1,ft);
}
fclose(fp);
fclose(ft);
remove("r.dat");
rename("TEMP.DAT","r.dat");
fp=fopen("r.dat","rb+");
fclose(fp);
printf("Do you want to delet another record... (Y/N)");
scanf("%c",&another);
}
}
void Q_Record(FILE *fp)
{                     //  ******  Querey ******
int choice;
while(1)
{
	system("cls");
	gotoxy(15,4);
	printf("---------------***Query Record***---------------");
	gotoxy(0,5);
	printf("--------------------------------------------------------------------------------");
	gotoxy(24,6);	
	printf("> Press 1 for Query by Title  ");
	gotoxy(24,8);
	printf("> Press 2 for Query by Key Words ");
    gotoxy(24,10);
    printf("> Press 3 for Query by Authors ");
    gotoxy(24,12);
    printf("> press 4 for Query by Isbn ");
    gotoxy(24,14);
    printf("Enter your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    	Q_Title(fp);
    		break;
    	case 2:
    	Q_Key(fp);	
		    break;
		case 3:
		Q_Auth(fp);
			break;
		case 4:	
		  Q_Isbn(fp);  
		    break;
    }
 }

}
void Q_Title(FILE *fp)           //       * Query by Title *
{
    int y = 11;
    system("cls");
    char t[15];
    gotoxy(10,5);
	printf("----------------Qurey by Title--------------------\n");
	fflush(stdin);
	printf("Enter the Title Of Book : ");
	gets(t);
	system("cls");
	gotoxy(20,4);
	printf("------------ Books Record ------------");
	gotoxy(4,6);
	printf("Book No    Book Title    ISBN    D-O-P    N-O-P    Author    Key Word");
	gotoxy(0,8);
	printf("-------------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)
	{
	if(strcmp(r.book_Title,t)==0)
	{

	gotoxy(5,y);
	printf("%d",r.book_No);
	gotoxy(15,y);
	printf("%s",r.book_Title);
	gotoxy(29,y);
	printf("%d",r.isbn);
	gotoxy(37,y);
	printf("%d",r.D_O_P);
	gotoxy(45,y);
	printf("%s",r.N_O_P);
	gotoxy(55,y);
	printf("%s",r.Author);
	gotoxy(67,y);
	printf("%s",r.Keyword);
	y++;
    }
	
    }
 getch();
 
}

void Q_Key(FILE *fp)        // *** Query by Key Word ***

{
    int y = 11;
    system("cls");
    char k[15];
    gotoxy(10,5);
	printf("----------------Qurey by Key Word--------------------\n");
	fflush(stdin);
	printf("Enter the Key Word of Book : ");
	gets(k);
	system("cls");
	gotoxy(20,4);
	printf("------------ Books Record ------------");
	gotoxy(4,6);
	printf("Book No    Book Title    ISBN    D-O-P    N-O-P    Author    Key Word");
	gotoxy(0,8);
	printf("---------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)
	{
	if(strcmp(r.Keyword,k)==0)
	{
	gotoxy(5,y);
	printf("%d",r.book_No);
	gotoxy(15,y);
	printf("%s",r.book_Title);
	gotoxy(29,y);
	printf("%d",r.isbn);
	gotoxy(37,y);
	printf("%d",r.D_O_P);
	gotoxy(46,y);
	printf("%s",r.N_O_P);
	gotoxy(55,y);
	printf("%s",r.Author);
	gotoxy(67,y);
	printf("%s",r.Keyword);
	y++;
    }
	
    }
 getch();
 
}

void Q_Auth(FILE *fp)     // *** Query by Authors

{
    int y = 11;
    system("cls");
    char A[15];
    gotoxy(10,5);
	printf("----------------Qurey by Author--------------------\n");
	fflush(stdin);
	printf("Enter the Author of Book : ");
	gets(A);
	system("cls");
	gotoxy(20,4);
	printf("------------ Books Record ------------");
	gotoxy(4,6);
	printf("Book No    Book Title    ISBN    D-O-P    N-O-P    Author    Key Word");
	gotoxy(0,8);
	printf("--------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)
	{
	if(strcmp(r.Author,A)==0)
	{
	gotoxy(5,y);
	printf("%d",r.book_No);
	gotoxy(15,y);
	printf("%s",r.book_Title);
	gotoxy(29,y);
	printf("%d",r.isbn);
	gotoxy(37,y);
	printf("%d",r.D_O_P);
	gotoxy(46,y);
	printf("%s",r.N_O_P);
	gotoxy(55,y);
	printf("%s",r.Author);
	gotoxy(67,y);
	printf("%s",r.Keyword);
	y++;
    }
	
	}
 getch();
 
}

void Q_Isbn(FILE *fp)           // *** Query by ISBN ***

{
    int y = 11;
    system("cls");
    int I;
    gotoxy(10,5);
	printf("----------------Qurey by Isbn--------------------\n");
	fflush(stdin);
	printf("Enter Isbn Of Book : ");
	scanf("%d",&I);
	system("cls");
	gotoxy(20,4);
	printf("------------ Books Record ------------");
	gotoxy(4,6);
	printf("Book No    Book Title    ISBN    D-O-P    N-O-P    Author    Key Word");
	gotoxy(0,8);
	printf("---------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&r,sizeof(r),1,fp)==1)
	{
	if(r.isbn==I)
	{
	gotoxy(5,y);
	printf("%d",r.book_No);
	gotoxy(15,y);
	printf("%s",r.book_Title);
	gotoxy(29,y);
	printf("%d",r.isbn);
	gotoxy(37,y);
	printf("%d",r.D_O_P);
	gotoxy(46,y);
	printf("%s",r.N_O_P);
	gotoxy(55,y);
	printf("%s",r.Author);
	gotoxy(67,y);
	printf("%s",r.Keyword);
	y++;
    }
	
    }
 getch();
 
}






//----------------------------------------------------[Section 2]---------------------------------------------------------------------------
void S2_Issued()
{
	int choice;
	while(1)
	{
		system("cls");
		gotoxy(20,6);
		printf("------------ Section 2 ------------ ");
		gotoxy(25,8);
		printf("* press 1 for Add Record");
		gotoxy(25,10);
		printf("* press 2 for Display All Record");
		gotoxy(25,12);
		printf("* press 3 for Edit Record");
		gotoxy(25,14);
		printf("* press 4 for Delete  Record");
		gotoxy(25,16);
		printf("* press 5 for Query");
		gotoxy(25,18);
		printf("* press 6 for back to Main Menu ");
		gotoxy(25,20);
		printf("* Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			   ad_Record(fpi);		
			   break;
			case 2:
				dis_Record(fpi);
			    break;
			case 3:
				Edt_Record(fpi);
		    	break;
			case 4:
				de_Record(fpi);
			    break;
			case 5:
				Q1_record ( fpi);        
			    break;
			case 6:
				mainmenu();
			    break;
				
		}
		
    }
getch();
}
void ad_Record(FILE *fpi)         // *** Add Record ***
{

	int choice;
	system("cls");
    gotoxy(15,5);
	printf("------------------ Add Record Menu ---------------------");	
	gotoxy(25,7);
	fflush(stdin);
	printf("Enter Name Of Person:");
	gets(i.n_Person);
	gotoxy(25,9);
	printf("Enter Book No :");
	scanf("%d",&i.B_NO);
	gotoxy(25,11);
	fflush(stdin);
	printf("Enter Book Title :");
	gets(i.B_Title);
	gotoxy(25,13);
	fflush(stdin);
	printf("Enter Department of person :");
	gets(i.Dep);
	gotoxy(25,15);
	fflush(stdin);
	printf("Enter Date of Issue :");
	gets(i.D_O_I);
	gotoxy(25,17);
	fflush(stdin);
	printf("Enter Date of Return :");
	gets(i.D_O_R);
	fseek(fpi,0,SEEK_END);
    fwrite(&i,sizeof(i),1,fpi);
    fclose(fpi);
    fpi=fopen("i.dat","rb+");
    fflush(stdin);
    printf("want to add more ?");
    choice = getch();
    if (choice == 'y' || choice == 'Y')
    add_Record(fpi);
    else 
    mainmenu();
}
void dis_Record(FILE *fpi)          // *** Display Record ***
{
	int y=11;
	system("cls");
	gotoxy(5,5);
	printf("--------------------------- Display Record --------------------------");
	gotoxy(0,6);
	printf("--------------------------------------------------------------------------------");
	gotoxy(0,7);
	printf("Person    Book No    Book Title    Department    D-O-I    D-O-R    ");
	gotoxy(0,8);
	printf("--------------------------------------------------------------------------------");
	rewind(fp);
	while(fread(&i,sizeof(i),1,fpi)==1)
	{
	gotoxy(0,y);
	printf("%s",i.n_Person);
	gotoxy(10,y);
	printf("%d",i.B_NO);
	gotoxy(21,y);
	printf("%s",i.B_Title);
	gotoxy(35,y);
	printf("%s",i.Dep);
	gotoxy(49,y);
	printf("%s",i.D_O_I);
	gotoxy(60,y);
	printf("%s",i.D_O_R);
	y++;
    }
	getch();
}
void Edt_Record(FILE *fpi)   // *** Edit Record ***
{

int y=11;
char n[40];
system("cls");
gotoxy(10,5);
printf("---------------------Edit Record-----------------------");
gotoxy(0,6);
printf("-----------------------------------------------------------------------------------");
fflush(stdin);
gotoxy(0,7);
printf("Enter The Name Wants To Edit :");
gets(n);
rewind(fpi);
while (fread(&i,sizeof(i),1,fpi)==1)
{
	if(n==i.n_Person)
	gotoxy(0,8);
	fflush(stdin);
	printf("Enter Person Name :");
	gets(i.n_Person);
	gotoxy(0,9);	
	printf("Enter Book No :");
	scanf("%d",&i.B_NO);
	gotoxy(0,10);
	fflush(stdin);
	printf("Enter Book Title :");
	gets(i.B_Title);
	gotoxy(0,11);
	fflush(stdin);
	printf("Enter Department of Person:");
	gets(i.Dep);
	gotoxy(0,12);
	fflush(stdin);
	printf("Enter Date Of Issue :");
	gets(i.D_O_I);
	gotoxy(0,13);
	fflush(stdin);
	printf("Enter Date Of Return :");
	gets(i.D_O_R);
	fseek(fpi,-sizeof(i),SEEK_CUR);
	fwrite(&i,sizeof(i),1,fpi);
	break;	
	}
	
fclose(fpi);
fpi=fopen("i.dat","rb+");
}
void de_Record(FILE *fpi)      // *** Delete Record ***
{
int y=11;
char p[40];
char pass[]="TAYYAB";
char m[40];
FILE *ft;
char name[40];
char another='Y';
system("cls");
printf("\nEnter the Password\n");
fflush(stdin);
gets(p);
if (strcmp(pass,m)==0)
{
	printf("Password Wrong\n");
}
while (another=='Y'||another=='y')
{	                                                                   
system("cls");
gotoxy(5,5);
printf("----------------------------Delete Record----------------------------");
gotoxy(0,6);
printf("--------------------------------------------------------------------------------");
gotoxy(0,7);
fflush(stdin);
printf("Enter Person Name :");
gets(p);
ft=fopen("TEMP.DAT","wb+");
rewind(fpi);
while (fread(&i,sizeof(i),1,fpi)==1)
{
	if(strcmp(i.n_Person,p)!=0)
	fwrite(&i,sizeof(i),1,ft);
}
fclose(fpi);
fclose(ft);
remove("i.dat");
rename("TEMP.DAT","i.dat");
fp=fopen("i.dat","rb+");
fclose(fpi);
printf("Do you want to delet another record... (Y/N)");
scanf("%c",&another);
}
}
void Q1_record ( FILE *fpi)          // *** Query ***
{                    
int choice;
while(1)
{
	system("cls");
	gotoxy(15,4);
	printf("---------------***Query Record***---------------");
	gotoxy(0,5);
	printf("--------------------------------------------------------------------------------");
	gotoxy(24,6);	
	printf("> Press 1 for Query by Person Name : ");
	gotoxy(24,8);
	printf("> Press 2 for Query by Title : ");
	gotoxy(24,10);
    printf("Enter your Choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    	Q_Person(fpi);
    		break;
    	case 2:
    	Q_title(fpi);
		    break;
    }
}
}
void Q_Person(FILE *fpi) // *** Query by Person ***
{
    int y = 11;
    system("cls");
    char p[15];
    gotoxy(10,5);
	printf("----------------Qurey by Person Name--------------------\n");
	fflush(stdin);
	printf("Enter the Person Name\n");
	gets(p);
	system("cls");
	gotoxy(20,4);
	printf("------------ Books Record ------------");
	gotoxy(0,6);
	printf("N-O-P    Book No     Book Title    Department    D-O-I     D-O-R");
	gotoxy(0,8);
	printf("--------------------------------------------------------------------------------");
	rewind(fpi);
	while(fread(&i,sizeof(i),1,fpi)==1)
	{
	if(strcmp(i.n_Person,p)==0)
	{
	gotoxy(0,y);
	printf("%s",i.n_Person);
	gotoxy(10,y);
	printf("%d",i.B_NO);
	gotoxy(21,y);
	printf("%s",i.B_Title);
	gotoxy(35,y);
	printf("%s",i.Dep);
	gotoxy(49,y);
	printf("%s",i.D_O_I);
	gotoxy(60,y);
	printf("%s",i.D_O_R);
	y++;
    }
	
    getch();
 
    }
	
}
void Q_title(FILE *fpi)  // *** Query by Title ***
{
    int y = 11;
    system("cls");
    char a[15];
    gotoxy(10,5);
	printf("----------------Qurey by Book Title--------------------\n");
	fflush(stdin);
	printf("Enter the Book Title\n");
	gets(a);
	system("cls");
	gotoxy(22,4);
	printf("------------Books Record ------------");
	gotoxy(0,6);
	printf("N-O-P    Book No    Book Title    Department   D-O-I    D-O-R");
	gotoxy(0,8);
	printf("------------------------------------------------------------------------------");
	rewind(fpi);
	while(fread(&i,sizeof(i),1,fpi)==1)
	{
	if(strcmp(i.B_Title,a)==0)
	{
	gotoxy(0,y);
	printf("%s",i.n_Person);
	gotoxy(10,y);
	printf("%d",i.B_NO);
	gotoxy(20,y);
	printf("%s",i.B_Title);
	gotoxy(34,y);
	printf("%s",i.Dep);
	gotoxy(47,y);
	printf("%s",i.D_O_I);
	gotoxy(56,y);
	printf("%s",i.D_O_R);
	y++;
    }
	
    getch();
 
    }

}




