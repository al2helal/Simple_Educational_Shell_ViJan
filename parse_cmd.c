char **parse_cmd(char *cmd , char *delim)
{
	int BUFFER_SIZE = 100;
	char **args;
	char *arg;
	int i = 0; //counts the argument
	int buffer_size = BUFFER_SIZE;
	args = malloc(buffer_size * sizeof(char));
	arg = strtok(cmd , delim);
	while(arg)
	{
		args[i] = arg;
		i++;
		if(i >= buffer_size)
		{
			buffer_size += BUFFER_SIZE; //increase buffer_size
			args = realloc(args , buffer_size);
			if(!args) //allocation error
			{
				perror("a2h: realloc() error");//void perror(constant char *s)
				exit(EXIT_FAILURE);//void exit(int status)
			}
		}
		arg = strtok(NULL , delim);
	}
		args[i] = NULL;
	return args;
}
