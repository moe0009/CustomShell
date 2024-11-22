#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

// function prototypes to let the compiler know these functions are coming up later
void sh_tree();
void sh_list();
void sh_path();
void sh_exit(char commands[1024][50], int count);
void runShell();
void currentDirectory();
void help();

void help() {  // this function shows the available commands when you type 'help'
    printf("Available Commands:\n");
    printf("tree - Creates Dir0 and Dir1 inside it\n");
    printf("list - Clears the screen and lists all directory content to tree.txt\n");
    printf("path - Displays and logs the current path to path.txt\n");
    printf("exit - Prints session history, lists directory contents, and exits after Enter\n");
}

void sh_tree() {
    mkdir("Dir0", 0755); // makes a directory called Dir0
    chdir("Dir0");       // goes into Dir0
    mkdir("Dir1", 0755); // makes another directory inside Dir0 called Dir1
    chdir("..");         // goes back to the previous directory
}

void sh_list() {
    system("clear");                         // clears the screen
    system("ls -l > tree.txt");              // lists details about files and dirs to tree.txt
    printf("Current directory content is listed in tree.txt and below:\n");
    system("cat tree.txt");                  // shows what's inside tree.txt
}

void sh_path() {
    char current[1024];
    getcwd(current, sizeof(current));        // gets the current directory path
    printf("Current Path: %s\n", current);   // prints the path

    FILE *f = fopen("path.txt", "w");        // opens path.txt to write the path in it
    if (f != NULL) {
        fprintf(f, "Current Path: %s\n", current);
        fclose(f);
    } else {
        printf("Error opening path.txt\n");
    }
}

void sh_exit(char commands[1024][50], int count) {
    printf("Session History:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, commands[i]); // shows the history of commands
    }
    printf("Current directory content:\n");
    system("ls -l");                           // lists everything in the directory in detail
    printf("Press Enter to exit...\n");
    getchar();                                 // waits for you to press Enter
    FILE *f = fopen("session_history.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n", commands[i]);       // writes the history to session_history.txt
    }
    fclose(f);
    printf("Exiting now...\n");
    printf("\n This project was made by:\n Mohammad Bazrouk, Daniel Nadeem, Abanob Sadek, Seifeldin Osman, Jason Armanious\n");
}

void runShell() {
    char current[1024];
    char commands[1024][50];
    int count = 0;
    getcwd(current, sizeof(current));         // gets the current directory
    while (1) {
        printf("user@customshell:%s$ ", current); // custom prompt
        char input[1024];
        fgets(input, 1024, stdin);            // gets your command
        int length = strlen(input);
        input[length-1] = '\0';               // removes the newline char from the end
        strcpy(commands[count++], input);     // stores your command in history

        // checks what command you entered and calls the corresponding function
        if (strcmp(input, "help") == 0) {
            help();
        } else if (strcmp(input, "tree") == 0) {
            sh_tree();
        } else if (strcmp(input, "list") == 0) {
            sh_list();
        } else if (strcmp(input, "path") == 0) {
            sh_path();
        } else if (strcmp(input, "exit") == 0) {
            sh_exit(commands, count);
            break;
        } else {
            printf("Unknown command: %s\n", input); // if command is not recognized
        }
    }
}

int main() {
    runShell();  // starts the shell
    return 0;
}
