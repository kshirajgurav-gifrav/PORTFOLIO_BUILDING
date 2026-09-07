#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 500

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Insert a new line */
void insertLine(int lineNumber)
{
    if (lineCount >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Shift lines down */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    /* Remove newline */
    lines[lineNumber - 1][strcspn(lines[lineNumber - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine(int lineNumber)
{
    if (lineCount == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Shift lines up */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Display the document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Display help */
void showHelp()
{
    printf("\n===== LINE EDITOR HELP =====\n");
    printf("insert <number>  - Insert a new line\n");
    printf("delete <number>  - Delete a line\n");
    printf("display          - Display document\n");
    printf("help             - Show help\n");
    printf("exit             - Exit editor\n");
    printf("============================\n");
}

int main()
{
    char command[50];
    int lineNumber;

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");
    printf("Type 'help' to see commands.\n");

    while (1)
    {
        printf("\n> ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        /* Remove newline */
        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "insert ", 7) == 0)
        {
            lineNumber = atoi(command + 7);
            insertLine(lineNumber);
        }
        else if (strncmp(command, "delete ", 7) == 0)
        {
            lineNumber = atoi(command + 7);
            deleteLine(lineNumber);
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "help") == 0)
        {
            showHelp();
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting Line Editor...\n");
            break;
        }
        else
        {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    return 0;
}