//===========================================================
//HW#: Nato HWK
//Your name: Alejandro Aquino
//Complier:  gcc
//File type: C language
//===========================================================
//Purpose: to convert a word into NATO code and to convert NATO code
//to its original phrase

//library declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declaration
void readFileAndDisplay(char word[],int *length);
void convertWords(char word[],int *length);
void convertNATO(char word[],int *length);

int main()
{
  int length=0; //to find its length, used throughout the functions
  char word[500]; // reading word array 
  readFileAndDisplay(word,&length);  // calls function
  
  return 0;
}

//Purpose: this function reads file and outputs
//the results
//Parameter: word array and the size of length
void readFileAndDisplay(char word[],int *length)
{
  //creates a pointer for opening a file
  //opens the .txt file
  FILE *fp;
  fp = fopen("words.txt", "r");

  //checks to see if file exists
 if(fp == NULL)
    {
      printf("ERROR: Can't open the file!\n");
      exit(1);
    }
 
 int lowerCount = 0;//keeps track of lowercase count
 int upperCount = 0;//keeps track of uppercase count
 int sizeFile=0; //counts size of reading each word in a file
 char temp[500][500];//used to copy a whole string into array
 printf("------------[Here is your result]------------\n");
 
 //this while loop is used to keep track of lowerCount,upperCount,sizeFile 
 // counts and reads each word from file then copies it to a temporary array 
 while(fscanf(fp, "%s", word) != EOF)
   { 
     strcpy(temp[sizeFile],word); // to copy every read word into array
     char ch=word[0]; //gets first position of array
     *length = strlen(word) + *length;//keeps adding size of each word read
     //goes to (if) if its between A and Z
     if(ch >= 'A' && ch <= 'Z')
       {
	 upperCount = upperCount + 1;
       }
     //goes to (else if) if its between a and z
     else if(ch >= 'a' && ch <= 'z')
       {
	 lowerCount = lowerCount + 1;
       }
     sizeFile = sizeFile + 1;
   }//end of while

 int temp1 = 0;//used to for array index
 int temp2 = temp1;//used to for array index
 char ch1=temp[temp1][0]; //gets first position of each string word
 
 //this while loop is used to display results
 while(sizeFile != 0) 
   {    
     if(ch1 >= 'A' && ch1 <= 'Z')
       {
	 printf("\n");
	 printf("---[Coverted NATO code into English word:]---\n");
	 int c;
	 //this for loop displays the original word
	 for(c=0;c<upperCount;c++)
	   {
	     printf("%s ",temp[temp1]);
	     temp1 = temp1 + 1;
	   }
	 printf(" ---> ");
	 //this for loop displays converted word to NATO
	 for(c=0;c<upperCount;c++)
           {
	     convertNATO(temp[temp2],length);
	     temp2 = temp2 + 1;
           }

	 ch1=temp[temp1][0];
       }

     else if(ch1 >= 'a' && ch1 <= 'z')
       {
	 printf("\n");
	 printf("---[Coverted English word into NATO code:]---\n");
	 int d;
         //this for loop displays the original word.
	 for(d=0;d<lowerCount;d++)
	   {
	     printf("%s ",temp[temp1]);
	     temp1 = temp1 + 1;
	   }
	 printf(" ---> ");
	 //this for loop displays the converted NATO in English Word.
	 for(d=0;d<lowerCount;d++)
           {
	     convertWords(temp[temp2],length);
	     temp2 = temp2 + 1;
	   }

	 ch1=temp[temp1][0];
       }

     sizeFile = sizeFile - 1;//decrements until while loop fails
   }//end of while

 printf("\n"); 
 
 fclose(fp); //closes the file

}

//Purpose: to convert a phrase word into NATO code
//Parameter: word array and the size of length
void convertWords(char word[],int *length)
{
  int i;
  //for loops displays NATO code
  for(i=0; i<*length ;i++)
    {
      if(word[i]=='a')
	{
	  printf("%s","Alpha");
	}
      else if(word[i]=='b')
        {
          printf("%s","Bravo");
        }
      else if(word[i]=='c')
	{
	  printf("%s","Charlie");
	}
      else if(word[i]== 'd')
	{
	  printf("%s","Delta");
	}
      else if(word[i]=='e')
        {
          printf("%s","Echo");
        }
      else if(word[i]=='f')
        {
          printf("%s","Foxtrot");
        }
      else if(word[i]=='g')
        {
          printf("%s","Golf");
        }
      else if(word[i]=='h')
        {
          printf("%s","Hotel");
        }
      else if(word[i]=='i')
        {
          printf("%s","India");
        }
      else if(word[i]=='j')
        {
          printf("%s","Juliett");
        }
      else if(word[i]=='k')
        {
          printf("%s","Kilo");
        }
      else if(word[i]=='l')
        {
          printf("%s","Lima");
        }
      else if(word[i]=='m')
        {
          printf("%s","Mike");
        }
      else if(word[i]=='n')
        {
          printf("%s","November");
        }
      else if(word[i]=='o')
        {
          printf("%s","Oscar");
        }
      else if(word[i]=='p')
        {
          printf("%s","Papa");
        }
      else if(word[i]=='q')
        {
          printf("%s","Quebec");
        }
      else if(word[i]=='r')
        {
          printf("%s","Romeo");
        }
      else if(word[i]=='s')
        {
          printf("%s","Sierra");
        }
      else if(word[i]=='t')
        {
          printf("%s","Tango");
        }
      else if(word[i]=='u')
        {
          printf("%s","Uniform");
        }
      else if(word[i]=='v')
        {
          printf("%s","Victor");
        }
      else if(word[i]=='w')
        {
          printf("%s","Whiskey");
        }
      else if(word[i]=='x')
        {
          printf("%s","X-ray");
        }
      else if(word[i]=='y')
        {
          printf("%s","Yankee");
        }
      else if(word[i]=='z')
        {
          printf("%s","Zulu");
	}
    }
  printf(" ");
}

//Purpose: to convert a NATO code into 
//its original phrase.
//Parameter: word array and the size of length
void convertNATO(char word[],int *length)
{
  int i;
  //this for loop displays original english phrase
  for(i=0; i < *length; i++)
    {
      
      if(word[i] >= 'A' && word[i] <= 'Z' )
	{

	  if(word[i] == 'A')
	    {
	      printf("%c",'a');
	    }
	  else if(word[i] == 'B')
	    {
	      printf("%c",'b');
	    }
	  else if(word[i] == 'C')
	    {
	      printf("%c",'c');
	    }
	  else if(word[i] == 'D')
	    {
	      printf("%c",'d');
	    }
	  else if(word[i] == 'E')
            {
              printf("%c",'e');
            }
	  else if(word[i] == 'F')
            {
              printf("%c",'f');
            }
	  else if(word[i] == 'G')
            {
              printf("%c",'g');
            }
	  else if(word[i] == 'H')
            {
              printf("%c",'h');
            }
	  else if(word[i] == 'I')
            {
              printf("%c",'i');
            }
	  else if(word[i] == 'J')
            {
              printf("%c",'j');
            }
	  else if(word[i] == 'K')
            {
              printf("%c",'k');
            }
	  else if(word[i] == 'L')
            {
              printf("%c",'l');
            }
	  else if(word[i] == 'M')
            {
              printf("%c",'m');
            }
	  else if(word[i] == 'N')
            {
              printf("%c",'n');
            }
	  else if(word[i] == 'O')
            {
              printf("%c",'o');
            }
	  else if(word[i] == 'P')
            {
              printf("%c",'p');
            }
	  else if(word[i] == 'Q')
            {
              printf("%c",'q');
            }
	  else if(word[i] == 'R')
            {
              printf("%c",'r');
            }
	  else if(word[i] == 'S')
            {
              printf("%c",'s');
            }
	  else if(word[i] == 'T')
            {
              printf("%c",'t');
            }
	  else if(word[i] == 'U')
            {
              printf("%c",'u');
            }
	  else if(word[i] == 'V')
            {
              printf("%c",'v');
            }
	  else if(word[i] == 'W')
            {
              printf("%c",'w');
            }
	  else if(word[i] == 'X')
            {
              printf("%c",'x');
            }
	  else if(word[i] == 'Y')
            {
              printf("%c",'y');
            }
	  else if(word[i] == 'Z')
            {
              printf("%c",'z');
            }

	}
    }//end of for loop
  printf(" ");
}//end of function
