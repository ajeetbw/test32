// C file to handle server which basically includes the socket creation, binding and then do the process of listening and accept.

#include <cdrheader.h>


// Debug levels
#define DEBUG_LEVEL_FATAL 1
#define DEBUG_LEVEL_INFO  2
#define DEBUG_LEVEL_WARNING 3
#define DEBUG_LEVEL_DEBUG  4
 
// Set the current debug level here
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
 
// Debug macros
#if DEBUG_LEVEL >= DEBUG_LEVEL_ERROR
#define DEBUG_ERROR(msg) fprintf(stderr, "[ERROR] %s\n", msg)
#else
#define DEBUG_ERROR(msg)
#endif
 
#if DEBUG_LEVEL >= DEBUG_LEVEL_INFO
#define DEBUG_INFO(msg) fprintf(stderr, "[INFO] %s\n", msg)
#else
#define DEBUG_INFO(msg)
#endif
 
#if DEBUG_LEVEL >= DEBUG_LEVEL_WARNING
#define DEBUG_WARNING(msg) fprintf(stderr, "[WARNING] %s\n", msg)
#else
#define DEBUG_WARNING(msg)
#endif
 
#if DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
#define DEBUG_DEBUG(fmt, ...) fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
#define DEBUG_DEBUG(fmt, ...)
#endif


//Create the server for the CDR application.
int main()
{
	int sfd = 0, ret_value=0, csfd=0;
	unsigned int client_addlen = 0;


	struct user *CS=NULL;
	interop *IOS=NULL;
	
	int data_flag=0;

	struct sockaddr_in serv_address, client_address;

	char msg[MAXBUFF] = {0,};

	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	DEBUG_INFO("\nSocket created\n");


	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret_value = bind(sfd, (struct sockaddr *)&serv_address,sizeof(serv_address));
	
	if(ret_value < 0)
	{
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	DEBUG_INFO("\nBinded the server\n");

	ret_value = listen(sfd, 5);
	
	if(ret_value < 0)
	{
		perror("listen() ");
		exit(EXIT_FAILURE);
	}
	
	DEBUG_INFO("\nListening to the clients\n");
	client_addlen=sizeof(client_address);

	while(1)
	{
		csfd = accept(sfd,(struct sockaddr *)&client_address,&client_addlen);

		if(csfd < 0)
		{
			perror("accept() ");
			exit(EXIT_FAILURE);
		}
		DEBUG_INFO("\nGot a new client connection.\n");
		char uid[MAXBUFF]={0,};
		char upass[MAXBUFF]={0,};
		
		while(1)
		{
			bzero(msg,MAXBUFF);
			read(csfd,msg,MAXBUFF);
			DEBUG_DEBUG("Message received from client: %s", msg);
			if(atoi(msg)==3)
			{
				close(csfd);
				break;
			}
			else if(atoi(msg) ==1)
			{
				bzero(msg,MAXBUFF);
				strcpy(msg,"Enter username:");
				write(csfd,msg,strlen(msg));
				bzero(msg,MAXBUFF);
				read(csfd,uid,MAXBUFF);
				bzero(msg,MAXBUFF);
				strcpy(msg,"Enter password:");
				write(csfd,msg,strlen(msg));
				bzero(msg,MAXBUFF);
				read(csfd,upass,MAXBUFF);
				FILE *p_fp = NULL;
				p_fp = fopen("./data/user_details.txt","a+");
				if(p_fp == NULL)
				{
					printf("Sorry,,please try after some time");
					exit(EXIT_FAILURE);
				}
				if(cdr_signup(uid,upass))
				{
					fprintf(fp,"%s %s\n",uid,upass);
					bzero(uid,MAXBUFF);
					bzero(upass,MAXBUFF);
					bzero(msg,MAXBUFF);
					strcpy(msg,"1");
					fclose(p_fp);
					write(csfd,msg,strlen(msg));
				}
				else
				{
					bzero(msg,MAXBUFF);
					bzero(uid,MAXBUFF);
					bzero(upass,MAXBUFF);
					strcpy(msg,"0");	
					fclose(p_fp);
					write(csfd,msg,strlen(msg));
				}
			}
			else if(atoi(msg)==2)
			{
				strcpy(msg,"Enter username:");
				write(csfd,msg,strlen(msg));
				bzero(msg,MAXBUFF);
				read(csfd,uid,MAXBUFF);
				bzero(msg,MAXBUFF);
				strcpy(msg,"Enter password:");
				write(csfd,msg,strlen(msg));
				read(csfd,upass,MAXBUFF);
				int k=logIn(uid,upass);
				bzero(uid,MAXBUFF);
				bzero(upass,MAXBUFF);
				if(k==1)
				{
					bzero(msg,MAXBUFF);
					strcpy(msg,"1");
					write(csfd,msg,strlen(msg));
					bzero(msg,MAXBUFF);
					while(1)
					{
						read(csfd,msg,MAXBUFF);
						if(atoi(msg)==1)
						{
							bzero(msg,MAXBUFF);

							if(data_flag==0)
							{
								
								CS=(struct user*)malloc(100000*(sizeof(struct user)));
								IOS=(interop *)malloc(5*(sizeof(interop)));
								cdr_dataprocess(CS,IOS);
								if(CS!=NULL && IOS!=NULL)
								{
									data_flag=1;
									strcpy(msg,"1");
									write(csfd,msg,strlen(msg));
								}
								else
								{
									strcpy(msg,"2");
									write(csfd,msg,strlen(msg));
								}
							}
							else
							{
								strcpy(msg,"3");
								write(csfd,msg,strlen(msg));
							}
						}
						else if(atoi(msg)==2)
						{
							bzero(msg,MAXBUFF);
							strcpy(msg,"\n\n1.Customer Billing\n2.Inter operator  Billing\nChoice: ");
							write(csfd,msg,strlen(msg));
							bzero(msg,MAXBUFF);
							read(csfd,msg,MAXBUFF);
							if(atoi(msg)==1)
							{
								bzero(msg,MAXBUFF);
								strcpy(msg,"\n---------------> CUSTOMER BILLING <--------------\n\n");
								strcat(msg,"1.Display on screen\n2.Download the  CB.txt\nChoice: ");
								write(csfd,msg,strlen(msg));
								bzero(msg,MAXBUFF);
								read(csfd,msg,MAXBUFF);
								if(atoi(msg)==1)
								{
									bzero(msg,MAXBUFF);
									strcpy(msg,"\n\nEnter MSISDN:");
									write(csfd,msg,strlen(msg));
									bzero(msg,MAXBUFF);
									read(csfd,msg,MAXBUFF);
									char msisdn[MAXBUFF]={0,};
									strcpy(msisdn,msg);
									bzero(msg,MAXBUFF);
									char * p_customer_ack=cdr_customer_billing(CS,msisdn);
									bzero(msisdn,MAXBUFF);
									strcpy(msg,p_customer_ack);
									free(p_customer_ack);
									write(csfd,msg,strlen(msg));

								}
								else if(atoi(msg)==2)
								{
									bzero(msg,MAXBUFF);
									strcpy(msg,"\n\nEnter MSISDN:");
									write(csfd,msg,strlen(msg));
									bzero(msg,MAXBUFF);
									read(csfd,msg,MAXBUFF);
									char msisdn[MAXBUFF]={0,};
									strcpy(msisdn,msg);
									bzero(msg,MAXBUFF);
									char * p_customer_ack=cdr_customer_billing_file(CS,msisdn);
									bzero(msisdn,MAXBUFF);
									strcpy(msg,p_customer_ack);
									free(p_customer_ack);
									write(csfd,msg,strlen(msg));
								}

							}
							else if(atoi(msg)==2)
							{
								bzero(msg,MAXBUFF);
								strcpy(msg,"\n----------------> INTER OPERATOR BILLING <---------------");
								strcat(msg,"\n\n1.Display result on the user screen\n2.Download  IOSB.txt\nChoice : ");
								write(csfd,msg,strlen(msg));
								bzero(msg,MAXBUFF);
								read(csfd,msg,MAXBUFF);
								if(atoi(msg)==1)
								{
									bzero(msg,MAXBUFF);
									strcpy(msg,"\n\nEnter Operator Code :");
									write(csfd,msg,strlen(msg));
									bzero(msg,MAXBUFF);
									read(csfd,msg,MAXBUFF);
									char msisdn[MAXBUFF]={0,};
									strcpy(msisdn,msg);
									bzero(msg,MAXBUFF);
									char * p_customer_ack=cdr_interoperator_billing(IOS,msisdn);
									strcpy(msg,p_customer_ack);
									bzero(msisdn,MAXBUFF);
									free(p_customer_ack);
									write(csfd,msg,strlen(msg));

								}
								else if(atoi(msg)==2)
								{
									bzero(msg,MAXBUFF);
									char * p_customer_ack=cdr_interoperator_billingfile(IOS);
									strcpy(msg,p_customer_ack);
									free(p_customer_ack);
									write(csfd,msg,strlen(msg));
								}
								
							}
						}
						else if(atoi(msg)==3)
						{
							free(CS);
							free(IOS);
							CS=NULL;
							IOS=NULL;
							break;
						}
					}
				}
			
				else
				{
					bzero(msg,MAXBUFF);
					strcpy(msg,"2");
					write(csfd,msg,strlen(msg));
				}
			
			}
		}

	}

	return 0;
}
