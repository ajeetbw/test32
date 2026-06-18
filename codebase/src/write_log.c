#include<cdrheader.h>
#include<time.h>

#define LOG_FILE_PATH "../data/server_log.txt";

void write_to_log(const char* msg){
	FILE *lf=fopen(LOG_FILE_PATH,"a+");
	if(log_file !=NULL){
		time_t c_time;
		char* time_string;
		c_time=time(NULL);
		time_string=ctime(&c_time);
		time_string[strlen(time_string)-1]='\0';
		fprintf(lf,"[%s] %s\n",time_string,msg);
		fclose(lf);
	}
	else{
		perror("Failed to open log file");
		exit(EXIT_FAILURE);
	}
}

