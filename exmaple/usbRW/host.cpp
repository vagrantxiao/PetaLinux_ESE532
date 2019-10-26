#include <stdio.h>
#include <string.h>



int main()
{
	FILE * pFile;
	char buffer [100];

	pFile = fopen ("/usb1/myfile.txt" , "r");
	if (pFile == NULL)
		perror ("Error opening file");
	else
	{
		while ( ! feof (pFile) )
		{
			if ( fgets (buffer , 100 , pFile) == NULL ) break;
			fputs (buffer , stdout);
		}
		fclose (pFile);
	}
	FILE *pFile_out = fopen("/usb1/myout.txt","w");
	fwrite("hello,world!",1,strlen("hello,world!"),pFile_out);
	return 0;
}
