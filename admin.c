#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_USER_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
	

}b;


void insert_details();//for inserting movie details
void old_record(); //for view old recorrds of users,booked tickets 
void main(){
    
    int ch;
    
    char username[20],password[20];
    printf("Enter the login credential for the admin\n");
    printf("Enter the usernaem\n");
    scanf("%s",username);
    printf("Enter the password\n");
    scanf("%s",password);
    if(strcmp(username,"admin")==0 && strcmp(password,"pass") == 0){
    	printf("Admin login successful\n");
    	printf("\n===============================\n");
    	while(1){ 
    	printf("\nPress <1> Insert Movie\n");
    	printf("\npress <2> View all transections\n");
    	printf("\npress <3> Exit\n");
    	
    	printf("Enter your choice\n");
    	scanf("%d",&ch);
    	switch(ch){
    		case 1: insert_details();
    			break;
    		case 2: old_record();
    			break;
    		case 3:exit(0);
    			break;
    		default: printf("Please enter the valid choice\n");
    		break;
    	}
    	}
    }
    else{
    	printf("Login failed\n");
    }

}




void insert_details()
{
	
	int fd;
	struct book b;
	printf("Enetr movie code :- ");	
	scanf("%s",b.code);
	printf("Enetr  name :- ");	
	scanf("%s",b.name);
	printf("Enetr Relice Date:- ");	
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");	
	scanf("%d",&b.cost);
	
	fd=open("data.txt",O_CREAT|O_APPEND|O_WRONLY,0666);

	if(fd == -1)
	{
		printf("FIle not Found");
	}
	else
	{
		dprintf(fd,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	close(fd);
}




void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);


}
