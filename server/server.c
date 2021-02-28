//
//   server v 0.5
//
// gcc server.c -o server
// ./server &
// [1] 26182
//


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

// void doprocessing (int sock);

char *c_start   = "start_measure";
char *c_set     = "set_range";
char *c_stop    = "stop_measure";
char *c_get_s   = "get_status";
char *c_get_res = "get_result";
char *c_get_res2 = "get_result";


void doprocessing (int sock) {
   int n, sel;
   char buffer[256];
   char *istr,*istr1,*istr2,*istr3,*istr4,*istr5;
   char Report4[72];
   float  Siz0 = 10.99;


   bzero(buffer,256);

   n = read(sock,buffer,255);

   if (n < 0) {        perror("ERROR reading from socket");       exit(1);
   }

//   printf("SERVER GOT> %s\n",buffer);


  istr1 = strstr (buffer,c_start);
  istr2 = strstr (buffer,c_set);
  istr3 = strstr (buffer,c_stop);
  istr4 = strstr (buffer,c_get_s);
  istr5 = strstr (buffer,c_get_res);

   if ( istr1 == NULL)   {   sel=1;}
   else {
      printf ("V3 START\n");
   n = write(sock,"ok      ",26);

   };

   if ( istr2 == NULL)   {  sel=2; }
   else {
      printf ("V3 SeT\n");
   n = write(sock,"ok, rangeN   ",26);


   };

   if ( istr3 == NULL)  {  sel=3; }
   else {
      printf ("V4 STop\n");
   n = write(sock,c_stop,12);

   };

   if ( istr4 == NULL) { sel=4; }
   else {
   n = write(sock,"measure_state     ",26);

      printf ("V4 Get stat\n");
   };

   if ( istr5 == NULL) {  sel=5; }
   else {

   sprintf (Report4, "ok, %7.4f %7.4f ", Siz0 , Siz0 );

//   n = write(sock,"ok/fail , result1,...resultN  ",26);
    n = write(sock,Report4,42);

      printf ("%s \n", Report4);
      printf ("V4 Get RES\n");
   };



   if (n < 0) {       perror("ERROR writing to socket");
      exit(1);
   }

}


//
//     main
//


int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno, clilen;
   char buffer[256];
   struct sockaddr_in serv_addr, cli_addr;
   int n, pid;

   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5001;

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);

   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   /* Now start listening for the clients, here
      * process will go in sleep mode and will wait
      * for the incoming connection
   */

   listen(sockfd,5);
   clilen = sizeof(cli_addr);
 
   while (1) {
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }

      /* Create child process */
      pid = fork();

      if (pid < 0) {
         perror("ERROR on fork");
         exit(1);
      }

      if (pid == 0) {
         /* This is the client process */
         close(sockfd);
         doprocessing(newsockfd);
         exit(0);
      }
      else {
         close(newsockfd);
      }

   } /* end of while */
}
