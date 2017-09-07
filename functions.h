#include <unistd.h>
int is_background_process(char *cmd);
void execute(char **args , char *path);
char **parse_cmd(char *cmd , char *delim);
char *remove_extra_space(char *cmd);
void show_statistics(pid_t pid);
void jobs(int a);
