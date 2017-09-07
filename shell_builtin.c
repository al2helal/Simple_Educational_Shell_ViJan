static struct
{
	const char *cmd;
	int (*func)(int nargs, char **args);
}cmdtable[] =
{
	{"cd", cd},
	{"echo", echo},
	{"exit", exit},
	{"help", help},
	{"history", history},
	{"jobs", jobs},
	{"pwd", pwd},
	{"read", read},
	{"type", type},
	{NULL, NULL}
};
int 
shell_builtin(int nargs, char **args )
{
	int i;
	for(i=0; cmdtable[i].cmd; i++)
	{
		if(*cmdtable[i].cmd && !strcmp(args[1], cmdtable[i].cmd))
		{
			cmdtable[i].func(nargs, args);		
		}
	}
	return 0;
}
