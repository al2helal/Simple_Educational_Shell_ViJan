void execute(char **args , char *path)
{
	int BUFFER_SIZE = 100;
	if(!strcmp(args[0] , "pwd")) //strcmp - compare two strings ;; int strcmp(const char *s1 , const char *s2);
	{
		printf("%s\n", path);
	}
	else if (!strcmp(args[0] , "cd"))
	{
		chdir(args[1]); //chdir - change current directory ;; int chdir(const char *path);
	}
	else if (!strcmp(args[0] , "echo"))
	{
		int i = 1;
		char *temp;
		temp = malloc(BUFFER_SIZE * sizeof(char));
		while(args[i])
		{
			strcat(temp , args[i]);
			strcat(temp , " ");
			i++;
		}
		printf("%s\n", temp);
		free(temp);
	}
	else if (!strcmp(args[0] , "jobs"))
	{
		jobs(1); //invoke job() function
	}
	else if (!strcmp(args[0] , "help"))
	{
		printf("cd - change directory\npwd - print name of current/working directory\necho - display a line of text\nexit - cause normal process termination\n");
	}
	else if (!strcmp(args[0] , "exit"))
	{
		exit(1);
	}
	else
	{
		int status;
		int child_pid = fork(); /* create a child process;; pid_t fork(void)
		On success, the PID of child process is returned in the parend and 0 is returned in the child.On failure, -1 is returned in the parent and no child process is created. */
		if(child_pid == 0)
		{				/* Code executed by child */
			execvp(args[0] , args);//execvp - execute a file
							//int execvp(const char *file , char *const argv[])
							//execvp() function returns only if an error has
							//occured. The return value is -1
			perror("a2h: execvp() error");
			_exit(1); //_exit - terminate the calling process ;; void _exit(int status)
		}
		else if(child_pid == -1) //child not created
		{
			perror("a2h: fork() failed\n");
			exit(1);
		}
		if(bg_process == 1) //background process
		{
			//char *temp_id;
			//temp_id = malloc(4*sizeof(char));
			//sprintf(temp_id,"[%d] %d\n",bg_proc_no , child_pid);
			printf("[%d] %d\n",bg_proc_no , child_pid);
			//printf(temp_id);
			//free(temp_id);
			bg_proc[bg_proc_no].pid = child_pid;
		}
		else 			//foreground process 
			wait(&status); //wait - wait for process to change state
							//pid_t wait(int *status)
						 //The wait() system call suspends the execution of
					//calling process until one of it's child process terminates
	}
}
