#include<stdio.h>
#include<unistd.h>

int main(){
char buf[101] = {0};
const char* 
int i = 0;
for(;i < 100;++i)
{
buf[i] = '#';
printf("[%d%%][%s]\r",buf);
fflush(stdout);
usleep(100000);
}
return 0;

}
