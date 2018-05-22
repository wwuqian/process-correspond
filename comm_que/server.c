#include "comm.h"

int main()
{
	int msqid = CreateMsgQueue();
	char buf[1024];
	while(1){
		buf[0] = 0;
		RecvMsg(msqid,CLIENT_TYPE,buf);
		printf("client: %s\n",buf);
		
		printf("Please Enter: ");
		fflush(stdout);
		//从标准输入中读，fd=0
		ssize_t read_size = read(0,buf,sizeof(buf)-1);
		if(read_size > 0){
			buf[read_size] = '\0';
			SendMsg(msqid,SERVER_TYPE,buf);
			printf("send done,wait recv...\n");
		}
	}
	DestroyMsgQueue(msqid);
	return 0;
}
