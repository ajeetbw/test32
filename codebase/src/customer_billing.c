#include <cdrheader.h>

// Display the requested customer data
char * cdr_customer_billing(struct user *p_us, char msisdnc[])
{
    int k = 0, flag = 0;
    char * p_mkg = (char *)malloc(MAX_BUFF);
    bzero(p_mkg, MAX_BUFF);
    long int n = 100000;
    


	
    while (k < n)
    {
        if (atoi(msisdnc) == atoi(p_us[k].msisdn))
        {
            strcpy(p_mkg, "\n#Customers Data Base:\nCustomer ID: ");
            strcat(p_mkg, p_us[k].msisdn);
            strcat(p_mkg, "(");
            strcat(p_mkg, p_us[k].op_brand_name);
            strcat(p_mkg, ")");
            
            if (strcmp(p_us[k].op_mmc, p_us[k].third_party_mmc) == 0)
            {
                strcat(p_mkg, "\n\t*Services within the mobile operator*");
                
                if (strcmp(p_us[k].call_type, "MOC") == 0 || strcmp(p_us[k].call_type, "MTC") == 0)
                {
                    if (strcmp(p_us[k].call_type, "MOC") == 0)
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: ");
                        strcat(p_mkg, p_us[k].duration);
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                    else
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: ");
                        strcat(p_mkg, p_us[k].duration);
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                }
                else if (strcmp(p_us[k].call_type, "SMS-MO") == 0 || strcmp(p_us[k].call_type, "SMS-MT") == 0)
                {
                    if (strcmp(p_us[k].call_type, "SMS-MO") == 0)
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 1");
                    }
                    else
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 1");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                }
                else if (strcmp(p_us[k].call_type, "GPRS") == 0)
                {
                    strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                    strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                    strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                    strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                }
                
                strcat(p_mkg, "\n\t*Services outside the mobile operator*");
                strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                strcat(p_mkg, "\n\t*Internet use*");
                strcat(p_mkg, "\n\tMB downloaded: ");
                strcat(p_mkg, p_us[k].download);
                strcat(p_mkg, "| MB uploaded: ");
                strcat(p_mkg, p_us[k].upload);
                strcat(p_mkg, "\n\n");
            }
            else
            {
                strcat(p_mkg, "\n\t*Services within the mobile operator*");
                strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                
                strcat(p_mkg, "\n\t*Services outside the mobile operator*");
                
                if (strcmp(p_us[k].call_type, "MOC") == 0 || strcmp(p_us[k].call_type, "MTC") == 0)
                {
                    if (strcmp(p_us[k].call_type, "MOC") == 0)
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: ");
                        strcat(p_mkg, p_us[k].duration);
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                    else
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: ");
                        strcat(p_mkg, p_us[k].duration);
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                }
                else if (strcmp(p_us[k].call_type, "SMS-MO") == 0 || strcmp(p_us[k].call_type, "SMS-MT") == 0)
                {
                    if (strcmp(p_us[k].call_type, "SMS-MO") == 0)
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 1");
                    }
                    else
                    {
                        strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                        strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                        strcat(p_mkg, "\n\tIncoming SMS messages: 1");
                        strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                    }
                }
                else if (strcmp(p_us[k].call_type, "GPRS") == 0)
                {
                    strcat(p_mkg, "\n\tIncoming voice call durations: 0");
                    strcat(p_mkg, "\n\tOutgoing voice call durations: 0");
                    strcat(p_mkg, "\n\tIncoming SMS messages: 0");
                    strcat(p_mkg, "\n\tOutgoing SMS messages: 0");
                }
                
                strcat(p_mkg, "\n\t*Internet use*");
                strcat(p_mkg, "\n\tMB downloaded: ");
                strcat(p_mkg, p_us[k].download);
                strcat(p_mkg, "| MB uploaded: ");
                strcat(p_mkg, p_us[k].upload);
                strcat(p_mkg, "\n\n");
            }
            flag = 1;
            break;
        }
        k++;
    }
    
    if (flag == 0)
    {
        strcpy(p_mkg, "User not found!");
    }
    
    return p_mkg;
}

// Download the requested customer data in CB.txt file
char * cdr_customer_billing_file(struct user *us)
{
	int k=0,flag=0;
	long int n=100000;
	char * mkg=(char *)malloc(MAX_BUFF);
	bzero(mkg,MAX_BUFF);
	FILE *fp=NULL;
	fp=fopen("../data/CB.txt","w+");
	if(fp==NULL)
	{
		perror("fopen() ");
	}
	else{
		strcpy(mkg,"\n#Customers Data Base:\n");
	while(k<n)
	{
		strcpy(mkg,"Customer ID: ");
		strcat(mkg,us[k].msisdn);
		strcat(mkg,"(");
		strcat(mkg,us[k].op_brand_name);
		strcat(mkg,")");
		if(strcmp(us[k].op_mmc,us[k].third_party_mmc)==0)
		{
		strcat(mkg,"\n\t*Services within the mobile operator*");
			if(strcmp(us[k].call_type,"MOC")==0 || strcmp(us[k].call_type,"MTC")==0)
			{
				if(strcmp(us[k].call_type,"MOC")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: ");
					strcat(mkg,us[k].duration);
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
				else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].duration);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].call_type,"SMS-MO")==0 || strcmp(us[k].call_type,"SMS-MT")==0)
				{

					if(strcmp(us[k].call_type,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].call_type,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}

				strcat(mkg,"\n\t*Services outside the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].download);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}

			else
			{

				strcat(mkg,"\n\t*Services within the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");

				strcat(mkg,"\n\t*Services outside the mobile operator*");
				if(strcmp(us[k].call_type,"MOC")==0 || strcmp(us[k].call_type,"MTC")==0)
				{
					if(strcmp(us[k].call_type,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].duration);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].duration);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].call_type,"SMS-MO")==0 || strcmp(us[k].call_type,"SMS-MT")==0)
				{

					if(strcmp(us[k].call_type,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].call_type,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}

				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].download);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			flag=1;
			fprintf(fp,"%s",mkg);		
										
		k++;
	}
	}
	if(flag==0)
	{
		bzero(mkg,MAX_BUFF);
		fclose(fp);


		strcpy(mkg,"failed");
		return mkg;
	}
	else
	{
		bzero(mkg,MAX_BUFF);
		fclose(fp);


		strcpy(mkg,"success");
		return mkg;
	}

}
