#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
int glob = 3;
int main(){


	struct timeval start, end;
	int check_time = gettimeofday(&start,NULL);
	printf("%ld\n",start.tv_sec);
	


	pid_t pid;
	int loc = 3;
	printf("before fork, glob=%d, loc=%d.\n",glob,loc);
	if((pid=vfork())<0){
		printf("fork() failed.\n");
		exit(0);
	}else if(pid==0){
		glob++;
		loc--;
		printf("child process changes glob and loc.\n");
		printf("glob=%d, loc=%d.\n",glob,loc);
	}else{
		printf("parent process doesn't change glob and loc.\n");
		printf("glob=%d, loc=%d.\n",glob,loc);
	}
	exit(0);

}

