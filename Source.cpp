/*This program opens, displays, and encrypts a text document. */



#include <stdio.h>		//standard input output header
#include <string.h>		//string header needed for strstr and strcat
#include <ctype.h>		//char type header needed to convert char to upper or lower case
 
void main ()
{
	FILE *input;		//declared input text file location 
	FILE *output;		//declared output text file location
	char filein[999];	//declared user entered text file location
	char cha;			//declared content in specific location in text file
	char key;

	printf("Enter name and full location of .txt file to be encrypted \n(File extension is not mandatory):\n\n");
	
	//---------------------------------------------------------------------------------
	//This segment of code requests location of text file from user
	//If the .txt file extension is left out then it is automatically detected and added
	
	do
	{
	scanf("%s",filein);
	if (strstr(filein,".txt") == NULL)	//string is scanned to see whether .txt is present
	{
		strcat(filein,".txt");			//if not present then .txt is added onto the end of string
	}
		
	
	input = fopen(filein,"r");	//text file is opened
	if (input == NULL)			//if there is an error in doing so, user is asked to try again
	perror ("Please try again");
	else
	{							//prevents error message reappearing from loop
		continue;				//when a valid text file is opened by skipping rest of loop
	}	
	}
	while (input == NULL);		//looped until a valid text file is open

	//-----------------------------------------------------------------------------------
	//This segment of code prints the text file onto the screen
	printf("\nPreview of the opened text file:\n\n");
	while ((cha = fgetc(input)) != EOF) //contents of text file is read and displayed onto screen
	       printf("%c",cha);
	printf("\n\n");

	//-----------------------------------------------------------------------------------
	//This segment of code creates a new text file and saves it under a new filepath and name after encryption
	printf("Enter name and full save location of encrypted .txt file\n(File extension is not mandatory):\n\n");
    
	do
	{
	scanf("%s", filein);
	if (strstr(filein,".txt") == NULL)	//string is scanned to see whether .txt is present
	{
		strcat(filein,".txt");			//if not present then .txt is added onto the end of string
	}
    output = fopen(filein,"w");
	if (output == NULL)			//if there is an error in doing so, user is asked to try again
	perror ("Please try again");
	else
	{							//prevents error message reappearing from loop
		continue;				//when a valid text file is opened by skipping rest of loop
	}	
	}
	while (output == NULL);

	//-----------------------------------------------------------------------------------
	//This segment of code takes a character from the text file and encodes it

	printf("\nEnter the alphabetic offset key you would like to use:\n(For example by entering 'b', \nthe offset will be 1 and so an input 'a' will return 'b'):\n\n");
    scanf(" %c", &key);			//the alphabetic offset key is inputted by the user
	rewind(input);				//the text file is rewound back to the beginning
	
	
	while ((cha = fgetc(input)) != EOF) //contents of text file is read and displayed onto screen
		{ 
			if (cha > 95 && cha < 123)	//if cha is between a and z (lower case)
			{							//cha will be subtracted from the ASCII code for a, and added to the lower case of the key
				cha = (cha - 97) + tolower(key);
				if (cha > 122)			//if the output cha is larger than the ASCII code for z, 26 is subtracted from it
				{
					cha = cha - 26;
				}
				
			}
			else if (cha > 64 && cha < 91)
			{							//if cha is between A and Z (uppper case)
				cha = (cha - 65) + toupper(key);
				if (cha > 90)			//cha will be subtracted from the ASCII code for A, and added to the upper case of the key
				{
					cha = cha - 26;		//if the output cha is larger than the ASCII code for Z, 26 is subtracted from it
				}
			}
			
			fprintf(output, "%c", cha);	//output cha is printed into the text file
		}
	fclose(input);						//both opened text files are closed
    fclose(output);

	printf("\n\nText file has been encoded and saved as:\n'%s'\nProgram will now exit.\n\n",filein);

	//a message appears saying file has been encoded, giving the file location as well.
}