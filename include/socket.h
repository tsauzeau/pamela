/*
** socket.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Sun May 15 21:31:17 2016 Thomas Sauzeau
** Last update Sun May 15 21:33:44 2016 Thomas Sauzeau
*/

#ifndef SOCKET_H_
# define SOCKET_H_

# include "ftp.h"

int	start_server(const int port, const char *const path);
int	get_FD(t_ftp *ftp);

#endif
