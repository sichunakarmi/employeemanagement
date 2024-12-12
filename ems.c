#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void welcomemenu(); //function declaration
void login();
void mainmenu ();
void addrecord();
void showrecord();
void searchrecord();
void editrecord();
void deleterecord();


char user[10]="e",password[10]="1";
 struct employee{
 	int emp;
 	char name[20],address[20],post[20];
	 char age[10],salary[20];
 }c;
 
 
FILE *of;
void main() 
{
	FILE *of;
 
	welcomemenu();
	login();
	of=fopen("record.bin","ab+");
    if(of==NULL)
   {
    printf("ERROR");
     exit(0);
   }
   fwrite(&c,sizeof(struct employee),1,of);
    fclose(of);
}
 
 
  
	void welcomemenu()  //function decleration
	{
		char ch;
		printf("____________________________________________\n");
		printf("Welcome to Employee Management System\n");
		printf("____________________________________________\n");
		printf("Press any key to continue");
		ch=getch();
	}

   void login()
   {
   	char uname[10],pass[10],ch;
   	int i;
   	
   	system("cls");
   	printf("You are in login page\n");
   	printf("Enter the username");
   	scanf("%s",&uname);
   	printf("Enter your password");
   	for(i=0;i<100;i++)
   	{
   		ch=getch();
   		if(ch==13)//13 is the askey of enter
   		break;
   		pass[i]=ch;
	    printf("*");
   	}
   	pass[i]='\0';
   	
   	if(strcmp(user,uname)==0 && strcmp(pass,password)==0)
   	{
   		mainmenu();
    }
     else
	   {
	   	char ch;
	   	printf("\nId and password dosenot match \n press any key to try again");
	   	ch=getch();
	   	login();
	   }
   }
	
	void mainmenu()
	{
		int choice;
		char ch;
		system("cls");
		printf("____________Menu_____________");
		printf("\n1 Add Record\n2 Show Record\n3 Search Record\n4 Edit Record\n5 Delete Record\n6  Exit ");
		printf("\nChoose any option:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				
				addrecord();
				break;
			case 2:
				
				showrecord();
				break;
			case 3:
				 searchrecord();
				break;
			case 4:
				editrecord();
				 break;
		    case 5:
		    	deleterecord();
				 break;	
			case 6:
				system("cls");
				printf("\n\n\t\t\t\t\tTHANKYOU\n\n");
			ch=getch();
				break;
			default :
				printf("Invalid Choice");	
				mainmenu();
				
		}
		}
		
		
		void addrecord()
		{
			char ch,name[20],post[20],address[20];
			char salary[20],age[10];
		    system("cls");
		    printf("\t\t\t..ADD RECORD..\n");
		         printf("Enter the name of the employee: ");
		         scanf("%s",&name);
		         printf("Address: ");
		         scanf("%s",&address);
		         printf("Age: ");
		         scanf("%s",&age);
		         printf("Salary: ");
		         scanf("%s",&salary);
		         printf("Post: ");
		         scanf("%s",&post);
		         
				 //fseek(of,0,2);//file ko pointer lai last ma lanxa 2 le file ko last
		         fwrite(&c,sizeof(c),1,of);//file ma write gareko
		   printf("\nRecord entered sucessfully");
		   printf("\n\nPress any key to continue:");   
		   strcpy(c.age,age);
		   strcpy(c.salary,salary);
		   strcpy(c.address,address);
		   strcpy(c.name,name);
		   strcpy(c.post,post);
		   	FILE *of;
 
			of=fopen("record.bin","ab+");
		    if(of==NULL)
		   {
		    printf("ERROR");
		   exit(0);
		   }
		   fwrite(&c,sizeof(struct employee),1,of);
		    fclose(of);
		
				   ch=getch();
				   mainmenu();   
				}
		
		void showrecord()
		{
			system("cls");
			printf("\t\t\t..SHOW RECORD..\n");
			char ch;
			FILE *inf;
			struct employee c;
			inf=fopen("record.bin","rb");
			
			printf("The record of employee:\n");
			//rewind(of);//file ko pointer lai suru ma lageko,fseek(fptr,0,0)
			while(fread(&c,sizeof(struct employee),1,inf))
			{
				printf("\nName:%s \t \n",c.name);
				printf("Address:%s\n",c.address);
				printf("Age:%s\n",c.age);
				printf("Salary:%s\n",c.salary);
				printf("Post:%s\n",c.post);
				printf("\n\n");
				printf("----------------------------------------------------------------------------\n");
		    }
		    fclose(inf);
		    printf("Press any key to contuine:");
			ch=getch();
			mainmenu();
			exit(0);
		
		}
	
void searchrecord()
	{
		system("cls");
		printf("\t\t\t..SEARCH RECORD..");
		char ch[30],g;
		char f;
		FILE *inf;
		struct employee c;
		inf=fopen("record.bin","rb");
		
		printf("\nEnter the name to search:");
		scanf("%s",&ch);
			while(fread(&c,sizeof(struct employee),1,inf))
			{
				if (strcmp(ch,c.name)==0)
				{
					printf("\nName=%s\n",c.name);
					printf("Address=%s\n",c.address);
					printf("Age=%s\n",c.age);
					printf("Post=%s\n",c.post);
					printf("Salary=%s",c.salary);
					f==1;
					break;
				}
		    }
		   
		fclose(inf);
		    printf("Press any key to contuine:");
			g=getch();
			mainmenu();
			exit(0);
			
		
	}
	void editrecord()
	{	
	 system("cls");
		FILE *inf,*fptr;
		int choice;	
 	char ch[30],h;
 	char f,namee[20],newname[20],newaddress[20],newage[20],newpost[20],newsalary[20];
 	struct employee c1;
 	 printf("\t\t\t..EDIT RECORD.. ");
			printf("\nEnter name to edit: ");
 	scanf("%s",&namee);
 	inf=fopen("record.bin","rb");
 	fptr=fopen("newfile.bin","ab+");
 	while(fread(&c,sizeof(struct employee),1,inf))
			{
				
					if (strcmp(c.name,namee)==0){
						
							printf("\nName=%s\n",c.name);
							printf("Address=%s\n",c.address);
							printf("Age=%s\n",c.age);
							printf("Post=%s\n",c.post);
							printf("Salary=%s",c.salary);
							printf("\n\nWhat do you want to edit:\n1.Name\n2.Address\n3.Age\n4.Post\n5.Salary\nEnter your choice:");
							scanf("%d",&choice);
							
							switch(choice)
							{
								case 1:
									   printf("\n Enter new name:");
							           scanf("%s",&newname);
							strcpy(c1.name,newname);
							strcpy(c1.address,c.address);
							strcpy(c1.age,c.age);
							strcpy(c1.post,c.post);
							strcpy(c1.salary,c.salary);
							fwrite(&c1,sizeof(struct employee),1,fptr);	
							f==1;
							           break;
							    case 2:
								         printf("\n Enter new address:");
							             scanf("%s",&newaddress);
						    strcpy(c1.name,c.name);
							strcpy(c1.address,newaddress);
							strcpy(c1.age,c.age);
							strcpy(c1.post,c.post);
							strcpy(c1.salary,c.salary);
							fwrite(&c1,sizeof(struct employee),1,fptr);	
							f==1;
										 break;
								case 3:
									    printf("\n Enter new age:");
							            scanf("%s",&newage);
							strcpy(c1.name,c.name);            
							strcpy(c1.address,c.address);
							strcpy(c1.age,newage);
							strcpy(c1.post,c.post);
							strcpy(c1.salary,c.salary); 
							fwrite(&c1,sizeof(struct employee),1,fptr);	
							f==1;   
										break;
								case 4:
									   	printf("\n Enter new post:");
							            scanf("%s",&newpost);
							strcpy(c1.name,c.name);            
							strcpy(c1.address,c.address);
							strcpy(c1.age,c.age);
							strcpy(c1.post,newpost);
							strcpy(c1.salary,c.salary);
							fwrite(&c1,sizeof(struct employee),1,fptr);	
							f==1;
							            break;
							    case 5:
								        printf("\n Enter new salary:");
							            scanf("%s",&newsalary); 
							strcpy(c1.name,c.name);            
							strcpy(c1.address,c.address);
							strcpy(c1.age,c.age);
							strcpy(c1.post,c.post);
							strcpy(c1.salary,newsalary); 
							fwrite(&c1,sizeof(struct employee),1,fptr);	
							f==1; 
										break;
								default:
								        printf("\n!!!Invalid Choice!!!");
										break;		    
								       			        
							}
							
					}
				
				else{
					fwrite(&c,sizeof(struct employee),1,fptr);
				
				}

		    }
		  
		   	fclose(inf);
		   	fclose(fptr);
		   	remove("record.bin");
		   	rename("newfile.bin","record.bin");
		   	 printf("Press any key to contuine:");
			h=getch();
			mainmenu();
			exit(0);

	}
	void deleterecord()
	{
		system("cls");
		 	FILE *of, *fptr;
 	char ch[30],h;
 	char f,namee[20],newname[20];
 	
 	
 	of = fopen("record.bin","rb+");
 	fptr = fopen("newfile.bin","ab+");
 	printf("\t\t\t..DELETE RECORD..");
 	 printf("\nEnter record to delete:");
 	scanf("%s",&namee);
 	while(fread(&c,sizeof(struct employee),1,of))
			{
					if (strcmp(c.name,namee)==0){
						  
						   printf("\n\t!!DELETED!!\n\n");
						
					}
				
				else{
					fwrite(&c,sizeof(struct employee),1,fptr);
				}
					
		    }
		   
		   	fclose(of);
		   	fclose(fptr);
		   	remove("record.bin");
		   	rename("newfile.bin","record.bin");
		   	 printf("Press any key to contuine:");
			h=getch();
			mainmenu();
			exit(0);
	}
	
