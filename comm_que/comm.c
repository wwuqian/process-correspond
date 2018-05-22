#include "comm.h"
static int CommMsgQueue(int flags){
	key_t key = ftok(PATHNAME,Proj_id);
	if(key < 0){
		perror("ftok");
		return -1;
	}

	int msqid = msgget(key,flags);
	if(msqid < 0){
		perror("msgget");
		//失败返回-1
	}
	return msqid;
}

int CreateMsgQueue(){
	return CommMsgQueue(IPC_CREAT|IPC_EXCL|0666);
	//参数含义：创建消息队列，如果该消息队列存在，就返回错误，
	//权限为可读可写
}

int GetMsgQueue(){
	return CommMsgQueue(IPC_CREAT);
}

int DestroyMsgQueue(int msqid){
	if(msgctl(msqid,IPC_RMID,NULL) < 0){
		perror("msgctl");
		return -1;
	}
	return 0;
}

int SendMsg(int msqid,int who,char* msg){
	struct msgbuf buf;
	buf.mtype = who;
	strcpy(buf.mtext,msg);

	if(msgsnd(msqid,(void*)&buf,sizeof(buf.mtext),0) < 0){
		perror("msgsnd");
		return -1;
	}
	return 0;
}

int RecvMsg(int msqid,int recvType,char out[]){
	struct msgbuf buf;
	if(msgrcv(msqid,(void*)&buf,sizeof(buf.mtext),recvType,0) < 0){
		perror("msgrcv");
		return -1;
	}
	strcpy(out , buf.mtext);
	return 0;
}




