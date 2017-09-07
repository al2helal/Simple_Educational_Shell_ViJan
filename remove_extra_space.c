char *remove_extra_space(char *cmd)
{
	char *result_cmd;
	int cmd_length = strlen(cmd);
	result_cmd = malloc(sizeof(char)*cmd_length);
	int i=0,j=0;
	for(i=0;i<cmd_length ;i++)
	{
		if(cmd[i] != ' ')
			result_cmd[j++] = cmd[i];
		else
		{
			result_cmd[j++] = cmd[i];
			while(cmd[i] == ' ')
			{
				i++;
			}
			i--;
		}
	}
	if(result_cmd[j-1] == ' ')
		result_cmd[j-1] = '\0';
	else
		result_cmd[j] = '\0';
	if(result_cmd == ' ')
		result_cmd++;
	return result_cmd;
		
}
