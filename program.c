#include"program.h"

int main(int argc, char *argv[])
{
	
	int pipefd[2], res;
	char buf, data[100]={"Hello World"};
	
	res = pipe(pipefd);	
	if(res != 0)
		perror("pipe");
	
	if(fork() == 0)
	{
		close(pipefd[1]);	// close unused write end
		
		while(read(pipefd[0],&buf,1) > 0)
			write(STDOUT_FILENO,&buf,1);
		
		write(STDOUT_FILENO,"\n",1);
	}
	else
	{
		int status,res;
		
		close(pipefd[0]);	// close unused read end
		
		write(pipefd[1],data,strlen(data));
		close(pipefd[1]);
		
		res = wait(&status);
	}
	return 0;
}

