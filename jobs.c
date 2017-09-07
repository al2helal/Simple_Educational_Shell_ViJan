void jobs(int a)
{
	char *temp;
	temp = malloc(BUFFER_SIZE * sizeof(char));
	int i;
	if(a == 1)
	{
		for(i=1;i<=bg_proc_no;i++)
		{
			if(bg_proc[i].shown == 0)
			{
				if(getpgid(bg_proc[i].pid)>= 0) //getpgid - get process group
				{						//pid_t getpgid(pid_t pid);
					//sprintf(temp , "[%d] Running %s\n",i,bg_proc[i].comand);
					//sprintf - formatted output conversion
					//int sprintf(char *str, const char *format, ...);
					printf("[%d] Running %s\n",i , bg_proc[i].comand);
				}
				else
				{
					//sprintf(temp , "[%d] Done  %s\n",i,bg_proc[i].comand);
					printf("[%d] Done  %s\n",i,bg_proc[i].comand);
					//printf(temp);
					bg_proc[i].shown = 1;
				}
			}
		}
	}
	else
	{
		for(i=1;i<=bg_proc_no ; i++)
		{
			if(bg_proc[i].shown == 0 && getpgid(bg_proc[i].pid) < 0)
			{
				//sprintf(temp , "[%d] Done %s\n",i,bg_proc[i].comand);
				printf("[%d] Done %s\n",i,bg_proc[i].comand);
				//printf(temp);
				bg_proc[i].shown = 1;
			}
		}
	}
	free(temp);
}
