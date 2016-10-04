/*
** cmd.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Mon May  2 13:42:33 2016 Thomas Sauzeau
** Last update Sun May 15 14:34:39 2016 Thomas Sauzeau
*/

#ifndef CMD_H_
# define CMD_H_

#include "ftp.h"

typedef enum {
  USER = 1,
  PASS,
  CWD,
  CDUP,
  QUIT,
  DELE,
  PWD,
  PASV,
  PORT,
  HELP,
  NOOP,
  RETR,
  STOR,
  LIST,
  TYPE
} cmd;

typedef struct	s_cmd {
  cmd		_cmd;
  char*       	_txt;
  int		(*_exec)(t_exec*, t_ftp*);
  bool		_needAuth;
} t_cmd;

typedef struct	s_exec {
  cmd		_cmd;
  char**	_argv;
  unsigned int	_argc;
  t_cmd*	_exec;
} t_exec;

static const t_cmd cmd_array[] = {
  {USER, "USER", exec_USER, FALSE},
  {PASS, "PASS", exec_PASS, FALSE},
  {CWD, "CWD", exec_CWD, TRUE},
  {CDUP, "CDUP", exec_CDUP, TRUE},
  {QUIT, "QUIT", exec_QUIT, FALSE},
  {DELE, "DELE", exec_DELE, TRUE},
  {PWD, "PWD", exec_PWD, TRUE},
  {PASV, "PASV", exec_PASV, TRUE},
  {PORT, "PORT", exec_PORT, TRUE},
  {HELP, "HELP", exec_HELP, TRUE},
  {NOOP, "NOOP", exec_NOOP, TRUE},
  {RETR, "RETR", exec_RETR, TRUE},
  {STOR, "STOR", exec_STOR, TRUE},
  {LIST, "LIST", exec_LIST, TRUE},
  {TYPE, "TYPE", exec_TYPE, TRUE},
  {0, 0, NULL, FALSE}
};

t_exec	*check_CMD(const char *const cmd);
int	chek_auth(const t_ftp * const ftp);
void	exec_CMD(t_exec *exec, t_ftp *ftp);

#endif
