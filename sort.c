/*
AUTHORS: Neeraj Fernandes, Yogen Chaudhari and Mihir Garude

Date: 28th Spetember, 2016

Description: The program prompts the user for ten unique character strings. The program will check the uniqueness of each string.
	     The program checks if the user has entered a string whose length is within the specified limits which is between 1 
	     to 25 characters. The user will be reprompted to enter the string if he/she enters a string below or over the specified limit.
	     After accepting 10 user strings, the program will ask the user whether he wants to sort the string in ascending or 
	     descending order. Depending on the users response, the ten character strings will be sorted in ascending or descending order
	     based on ASCII value. Additionally, the program will print the character string will the lowest and higest ASCII values.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10                        				//This macro defines the maximum number of strings permitted

												
typedef struct storeList					// structure is defined to stores 10 character arrays
{
    char store[26];
}storeList;


//function declarations
void display(int i,struct storeList str1);
void sortAsc(struct storeList *strl1);
void sortDsc(struct storeList *strl1);

int main()
{
  int temp1=0,temp2=0,i=0,j=0,cond=1;	
  char *tempstore;	               				// character pointer to compare user inputed character string
  char check='\n';	                
  char *input;	                      				// character pointer to compare user inputed character string with required condition
  storeList *strl;	                			// pointer to structure to store the user character string in the structure
  strl = (storeList *)malloc(sizeof(storeList) * 26);
  size_t size_string = 26;		
  tempstore = (char *)malloc(size_string);
  size_t size_char = 1;
  input = (char *)malloc(size_char);

  printf("Enter %d unique character strings you wish to sort\n",SIZE);

  /*
  * 	Prompts the user for 10 character string until 10 unique character strings are entered.
  */
  while(i<SIZE)
  {
      printf("\nString %d :",i+1);
      getline(&tempstore, &size_string, stdin);			//accepts the user string of 
      temp1=strlen(tempstore) - 1;	   			//calculates the length of string and excludes'\n' character
      if(temp1>=1&&temp1<=25)					//checks whether the user provided string is within limits
      {
        if(i==0)						//stores the first string
        {
           strcpy((strl + i)->store,tempstore);	        
           i++;
        }else                                           	//compares the current inputted string with all the previous strings
        {
          for(j=i-1;j>=0;j--)
          {
              temp2=strcmp((strl + j)->store,tempstore);
			  if(temp2==0)				//checks for duplicate string input
              {
                printf("Error: Duplicate Strings - please re-enter  \n");
                break;
              }
          }
          if(temp2!=0)						//copies the string into 
          {
            strcpy((strl + i)->store,tempstore);
            i++;
          }
        }
      }else 							//prompts user to re enter string 
      {
          printf("The length of the string should be of Minimum 1 character and Maximum of 25 characters \n");
          continue;
      }
  }
  
  do							
  {
      printf("\nPress 'A' or 'a' to sort strings in Ascending order or 'D' or 'd' to sort in descending order \n");
      getline(&input, &size_char,stdin);
      if((input[0]=='A'||input[0]=='a'||input[0]=='D'||input[0]=='d') && (input[1]=='\n'))
      {
             check=input[0];
             switch(check)
             {
                case 'A':
                sortAsc(strl);
                cond=0;
                break;

                case 'a':
                sortAsc(strl);
                cond=0;
                break;

                case 'D':
                sortDsc(strl);
                cond=0;
                break;

                case 'd':
                sortDsc(strl);
                cond=0;
                break;
             }
      }else
      {
	   printf("Invalid choice: please re-enter\n ");
      }
  }while(cond);

  free(tempstore);
  free(strl);
  free(input);

  return 0;

}


/*
*Description	 :	This function displays the list of strings in ascending or descending order as directed by the user
*
*Input Parameters:	Integer variable i which is the string number and an array of type storeList which is the character string.
*
*Return Value	 :  	None.
*/

void display(int i,struct storeList strl1)
{
      printf("\nString %d: %s",i,strl1.store);
}


/*
*Description	 :	This function sorts the character strings provided by the user in Ascending order.
*
*Input Parameters:	A pointer of type storeList which points to starting address of the structure array
*
*Return Value    :	None
*/
void sortAsc(struct storeList *strl1)
{
    int i=0,j=0;	                       
    char temprefer[26];	                       
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE-i-1;j++)
        {
  	    if(strcmp(strl1[j].store,strl1[j+1].store)>0)
            {
                strcpy(temprefer,strl1[j].store);
                strcpy(strl1[j].store,strl1[j+1].store);
                strcpy(strl1[j+1].store,temprefer);
            }
        }
    }
    printf("\nDisplaying the sorted strings in Ascending order which are as follows:\n");

    for(i=0;i<SIZE;i++)
    {
      display(i+1,strl1[i]);
    }

    printf("\nThe String having Lowest ASCII value is : %s",strl1[0].store);
    printf("\nThe String having Highest ASCII value is : %s",strl1[9].store);
}


/*
*Description	 :	This function sorts the character strings provided by the user in Descending order.
*
*Input Parameters:	A pointer of type storeList which points to a starting address of the structure array
*
*Return Value	 : 	None
*/
void sortDsc(struct storeList *strl1)
{
    int i=0,j=0;	                         
    char temprefer[26];	                         
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE-i-1;j++)
        {
	    if(strcmp(strl1[j].store,strl1[j+1].store)<0)
            {
                strcpy(temprefer,strl1[j].store);
                strcpy(strl1[j].store,strl1[j+1].store);
                strcpy(strl1[j+1].store,temprefer);
            }
        }
    }
    printf("\nDisplaying the sorted strings in Descending order which are as follows:\n");
    for(i=0;i<SIZE;i++)
    {
      display(i+1,strl1[i]);
    }
    printf("\nThe String having Lowest ASCII value is : %s",strl1[9].store);
    printf("\nThe String having Highest ASCII value is : %s",strl1[0].store);
}

