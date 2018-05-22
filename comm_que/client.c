#include "comm.h"

int main()
{
	int msqid = GetMsgQueue();
	char buf[1024];
	while(1){
		buf[0] = 0;
		printf("Please Enter# ");
		fflush(stdout);
		ssize_t read_size = read(0,buf,sizeof(buf)-1);
		if(read_size > 0){
			buf[read_size] = '\0';
			SendMsg(msqid,CLIENT_TYPE,buf);
			printf("send done,wait recv...\n");
		}
		RecvMsg(msqid,SERVER_TYPE,buf);
		printf("server# %s\n ",buf);
	}
	return 0;
}
