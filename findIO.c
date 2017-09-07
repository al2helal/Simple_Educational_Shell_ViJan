char **find_IO(char *cmd)
{
	int BUFFER_SIZE = 100;
	char **new_cmd;
	char **delim;
	delim = malloc(BUFFER_SIZE * sizeof(char)); 
	delim[0] = ">>"; //output file in append mode
	delim[1] = ">"; //output file in write mode
	delim[2] = "<"; //input file in read mode
	new_cmd = malloc(BUFFER_SIZE * sizeof(char)); 
	if(strstr(cmd , delim[0]))
	{
		new_cmd[0] = strtok(cmd , delim[0]); // strtok - extracts tokens from string
		printf("new_cmd[0]\n");
		new_cmd[2] = strtok(NULL , delim[0]); //In each subsequent call that should parse
									//char *strtok(char *str , const char *delim)
								  //the same string , str must be NULL;
		new_cmd[3] = "a"; // append mode(>>)
	}
	else if(strstr(cmd , delim[1]))
	{
			new_cmd[0] = strtok(cmd , delim[1]); // strtok - extracts tokens from string
			new_cmd[2] = strtok(NULL , delim[1]);
			new_cmd[3] = "w"; // write mode(>)
	}
	if(new_cmd[0])
	{
		new_cmd[0] = strtok(new_cmd[0] , delim[2]);
		new_cmd[1] = strtok(NULL , delim[2]);
	}
	else
	{
		new_cmd[0] = strtok(cmd , delim[2]);
		new_cmd[1] = strtok(NULL , delim[2]);
	}
	return new_cmd;//cmd[0]=cmd,cmd[1]=infile,cmd[2]=outfile,cmd[3]=outfile_mode
}
