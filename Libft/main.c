/* A C program to demonstrate working of memcpy */
#include <stdio.h> 
#include <string.h> 
  
int main () 
{ 
  char str1[] = "Geeks";   
  char str2[] = "Quiz";   
  
  printf("str1 before memmove \n"); 
  printf("%s\n", str1); 
  
  /* Copies contents of str2 to sr1 */
 	memmove(str1, str2, sizeof(str2));
  /*strcpy (str1, str2);*/
  
  printf("str1 after memmove \n"); 
  printf("%s\n", str1); 
  
  return 0; 
} 


// C program to demonstrate working of memset() 
/*int main() 
{ 
    char str[30] = ""; 
    printf("\nBefore memset(): %s\n", str); 
  
    // Fill 8 characters starting from str[13] with '.' 
    memset(str + 13, '0', 8*sizeof(char)); 
  
    printf("After memset():  %s", str); 
    return 0; 
} */

