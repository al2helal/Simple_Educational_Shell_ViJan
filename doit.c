#include <stdio.h>
#include <unistd.h>

typedef struct //background process data
{
	int pid;
	int shown;
	char *comand;
}st;

st bg_proc[100];
int bg_proc_no = 0;
int bg_process;

int main()
{
	printf("hello\n");
	char *cmd;
	while(1)
	{
		cmd = readline(cmd);
		cmd = remove_extra_space(cmd);
		bg_process = is_background_process(cmd);
		if(bg_process == 1)
		{
			int cmd_len = strlen(cmd);
			cmd[cmd_len - 2] = '\0';
		}
		char delim = " \r\t\a\n";
		char **args;
		args = parse_cmd(cmd , delim);
		execute_cmd(args, get_current_dir_name());
	}
	return 0;
}
