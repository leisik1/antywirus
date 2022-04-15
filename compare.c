#include <stdio.h>
#include <string.h>
 
int stringcompare(char *s1,char *s2)
{
	int i,c=0;
	if(strlen(s1)==strlen(s2))
    {
    	for(i=0;s2[i];i++)  
        {
        	if(s1[i]==s2[i])
        	 c++;
 	    }
 	    if(c==i)
          return 1;
          
    }
    return 0; 
}

