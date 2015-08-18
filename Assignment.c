/* Group Name : BeginnerZero 
   Group Members: H'ng Jaan Lin 1122701742 
                  Lim Zhen Yang 1122701265 */ 


#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main(){ 

  FILE *fp; 
  char returnData[64]; 
  char *token; 
  char a[1000]; 
  fp = popen("/sbin/ifconfig eth0", "r"); 
  
  while (fgets(returnData, 64, fp) != NULL) 
  { 
    /* store the string in returnData into variable a */ 
    strcat(a, returnData); 
  } 
  
  /* get the first token and walk through other tokens until the IP address token */ 
  token = strtok(a, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " "); 
  token = strtok(NULL, " addr:"); 
  
  /* print the IP address token */ 
  printf("IP address: %s\n", token); 
  
  pclose(fp); 
  
  return(0); 
  
}
