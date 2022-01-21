#include<stdio.h>
#include<unistd.h>
int main()
{
    int pipe_[2];
    int check;
    int pid;
    char w_message[2][20]={"Hi","Jarvis"};
    char r_message[20];
    check=pipe(pipe_);
    if(check==-1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }
    pid=fork();
    if(pid==0)
    {
        read(pipe_[0], r_message, sizeof(r_message));
        printf("Child Process (Reading from pipe): Message is %s\n",r_message);
        read(pipe_[0],r_message,sizeof(r_message));
        printf("Message 2 is : %s\n",r_message);
    }
    else
    {
    printf("Parent Process (writing to pipe) : Message 1 is %s\n",w_message[0]);
    write(pipe_[1], w_message[0], sizeof(w_message[0]));
    printf("Message 2 is : %s\n",w_message[1]);
    write(pipe_[1],w_message[1],sizeof(w_message[1]));
    }
    return 0;
}