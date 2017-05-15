#include <stdio.h>
#include <time.h>
#include "E101.h"
//IP 130.195.6.196

int main(){
 char addr[15]={'1','3','0','.','1','9','5','.','6','.','1','9','6'};
 printf("addr = %s\n",addr);
 connect_to_server(addr,1024);
 char from_server[24];
 char to_server[24] = {'P','l','e','a','s','e'};
 send_to_server(to_server);	 
 receive_from_server(from_server);
 printf("received from server= %s\n",from_server);
 for ( int i = 0 ; i< 6;i++)
 {
   to_server[i]=from_server[i];
 }
 to_server[6]='P';
 to_server[7]='l';
 to_server[8]='e';
 to_server[9]='a';
 to_server[10]='s';
 to_server[11]='e';
 to_server[12]= 0;
 send_to_server(to_server);	 

 
 
}
