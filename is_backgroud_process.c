int is_background_process(char *cmd)
{
	int str_len = strlen(cmd);
	if(cmd[str_len - 1] == '&') /* if end char is '&' then it is background process*/
		return 1;
	else
		return 0;
}
