#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h> 

void serverInteractionLoop(int serverSocket);
void readHiddenInput(char *buffer, int bufSize);

int main(int argc, char *argv[])
{
    int serverSocket;
    int connectStatus;
    struct sockaddr_in serverAddress;
    const char *serverIP = "127.0.0.1"; 
    int serverPort = 8080; 

    //Allow specifying server IP and Port via command line otherwise default ones are used
    if(argc>1){
        serverIP = argv[1];
    }
    if(argc>2){
        serverPort = atoi(argv[2]);
        if (serverPort <= 0 || serverPort > 65535) {
            fprintf(stderr, "Invalid port number: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    //create socket
    serverSocket = socket(AF_INET,SOCK_STREAM,0);
    if (serverSocket == -1)
    {
        perror("Client socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Client socket created!\n");

    //configure server
    serverAddress.sin_addr.s_addr = inet_addr(serverIP); // Use specific IP
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);

    printf("Attempting to connect to %s:%d...\n", serverIP, serverPort);
    //connect to server
    connectStatus = connect(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if(connectStatus == -1)
    {
        perror("Client connection to server failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
    printf("Connected to server successfully!\n");

    //server interaction function
    serverInteractionLoop(serverSocket);

    close(serverSocket);
    printf("Connection closed.\n");
    return 0; // Use return 0 for success
}

// Handles reading prompts from server and sending user input
void serverInteractionLoop(int serverSocket)
{
    char inBuffer[4096], outBuffer[4096], displayBuffer[4096];
    int readBytes, writeBytes;
    ssize_t inputLen; // For getline

    do
    {
        bzero(inBuffer, sizeof(inBuffer));
        readBytes = read(serverSocket, inBuffer, sizeof(inBuffer) - 1); // Leave space for null term

        if(readBytes <= 0)
        {
            if(readBytes == 0){
                printf("\nServer closed the connection.\n");
            } 
            else{
                perror("\nRead from server failed");
            }
            break;
        }
        inBuffer[readBytes] = '\0'; // Null-terminate received data

        // Check for password prompt
        int isPasswordPrompt = (strstr(inBuffer, "password:") != NULL || strstr(inBuffer, "Password:") != NULL);

        //Exit Signal Check
        if(strcmp(inBuffer, "Client logging out...\n") == 0)
        {
            printf("%s", inBuffer); // Show the logout message
            break; 
        }

        // Check if server sent a message ending with '^' (our signal for needing an ACK)
        char *ackSignal = strchr(inBuffer, '^');
        if (ackSignal != NULL) {
            *ackSignal = '\0'; // Replace '^' with null terminator to print message cleanly
            if(strlen(inBuffer) > 0){
                printf("%s\n", inBuffer); // Print message before the '^'
            }
            // Send an ACK back to the server
            strcpy(outBuffer, "ACK");
        } 
        else if(isPasswordPrompt){
            printf("%s", inBuffer);
            fflush(stdout); 
            readHiddenInput(outBuffer, sizeof(outBuffer)); // Get masked input
        } 
        else{
            //Regular prompt
            printf("%s", inBuffer); // Print the prompt
            fflush(stdout);
            if(fgets(outBuffer, sizeof(outBuffer), stdin) == NULL) {
                // Handle EOF or read error
                printf("\nInput error or EOF detected. Exiting.\n");
                break;
            }
            // Remove trailing newline from fgets
            outBuffer[strcspn(outBuffer, "\r\n")] = 0;
        }

        // Send the response (ACK, password, or regular input)
        writeBytes = write(serverSocket, outBuffer, strlen(outBuffer)); // Send exact length
        if(writeBytes < 0) // Check for write error
        {
            perror("Client write to server failed");
            break;
        }
        if (writeBytes < strlen(outBuffer)) {
            fprintf(stderr, "Warning: Partial write to server occurred.\n");
            // Handle partial write? Maybe retry or exit.
        }


    } while(readBytes > 0); // Continue loop as long as server is sending data
}

// Reads password input without echoing characters to the terminal
void readHiddenInput(char *buffer, int bufSize){
    struct termios oldt,newt;
    int nread;

    //Turn off echo
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable echo and canonical mode
    newt.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newt);

    // Read input (fgets is generally safer than scanf)
    if(fgets(buffer, bufSize, stdin) != NULL){
        buffer[strcspn(buffer, "\r\n")] = 0;
    } 
    // Restore original settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
}
