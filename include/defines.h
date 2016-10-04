/*
** defines.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Mon May  2 11:55:23 2016 Thomas Sauzeau
** Last update Sun May 15 22:35:39 2016 Thomas Sauzeau
*/

#ifndef DEFINES_H_
# define DEFINES_H_

# define ANONYMOUS "Anonymous"
# define NB_FAILED_LOGIN 3

# define WELCOME_MSG "220 (myFTP, Winter is coming 1.0.0)\r\n"
# define CMD_MSG "220 (CMD OK)\r\n"
# define SPECIFY_PASSWORD "331 Please specify the password.\r\n"
# define INVALID_CMD "500 Unknown command.\r\n"
# define NOT_LOGGED "530 Please login with USER and PASS.\r\n"
# define PERMISSION_DENIED "530 Permission denied.\r\n"
# define USER_FIRST "503 Login with USER first.\r\n"
# define LOGIN_SUCCESSFUL "230 Login successful.\r\n"
# define ALREADY_LOGGED "230 Already logged in.\r\n"
# define CHANGE_FROM_GUEST "530 Can't change from guest user.\r\n"
# define INCORRECT_LOGIN "530 Login incorrect.\r\n"
# define QUIT_MSG "221 Goodbye.\r\n"
# define NOOP_MSG "200 NOOP ok.\r\n"
# define NOT_IMPLEMENTED "502 Command not implemented.\r\n"
# define HELP_HEADER "214-The following commands are recognized.\r\n"
# define HELP_CMD "214 Help OK.\r\n"
# define CMD_LIST1 "USER PASS CWD CDUP QUIT DELETE PWD "
# define CMD_LIST2 "PWD PASV PORT HELP NOOP STOR LIST\n\r"
# define PORT_CMD "200 PORT command successful. Consider using PASV.\r\n"
# define PORT_ERROR "500 Illegal PORT command.\r\n"
# define PASV_CMD "227 Entering Passive Mode (%s,%s,%s,%s,%d,%d).\r\n"
# define PORT_PASV_FIRST "425 Use PORT or PASV first.\r\n"
# define TYPE_CMD "200 Switching to Binary mode.\r\n"
# define LIST_HEADER  "150 Here comes the directory listing.\r\n"
# define LIST_CMD "226 Directory send OK.\r\n"
# define CWD_OK "250 Directory successfully changed.\r\n"
# define CWD_NOK "550 Failed to change directory.\r\n"
# define CWD_INCORRECT "501 Failed to change directory.\r\n"
# define NTW_NOK "425 Failed to establish connection.\r\n"
# define RETR_HEADER "150 Opening ASCII mode for %s (%d bytes).\r\n"
# define RETR_MODE "150 Opening ASCII mode data connection for\r\n"
# define RETR_OK "226 Transfer complete.\r\n"
# define RETR_BAD "550 Failed to open file.\r\n"
# define STOR_HEADER "150 FILE: (%s).\r\n"
# define STOR_OK "226 Transfer complete.\r\n"
# define DELE_NOK "550 Permission denied.\r\n"
# define DELE_OK "250 Delete ok.\r\n"

# define PWD_CODE 257

#endif
