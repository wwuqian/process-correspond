#ifndef _COMM_H_
#define _COMM_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define PATHNAME "msg.tmp"  //用msg.tmp文件的索引结点号和Proj_id 来生成键值
#define Proj_id 0x20  //可以随意指定

#define SERVER_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf{
	long mtype;
	char mtext[1024];
};

int CreateMsgQueue();
int GetMsgQueue();
int DestroyMsgQueue(int msqid);
int SendMsg(int msqid,int who,char *msg);
int RecvMsg(int msqid,int recvType,char out[]);

#endif
