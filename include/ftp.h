/*
** ftp.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Mon May  2 14:43:15 2016 Thomas Sauzeau
** Last update Sun May 15 21:40:24 2016 Thomas Sauzeau
*/

#ifndef FTP_H_
# define FTP_H_

typedef struct s_exec t_exec;

typedef enum {
  FALSE,
  TRUE
} bool;

typedef enum {
  UNDEFINED,
  PASSIF,
  ACTIF
} mode;

typedef struct	s_ftp {
  char*		_pwd;
  char*		_fakePwd;
  char*		_user;
  int		_fd;
  bool		_auth;
  unsigned int	_failedLogin;
  mode		_mode;
  char*		_addr;
  unsigned int	_port;
  int		_fdData;
} t_ftp;

int	get_FD(t_ftp *ftp);

int	exec_USER(t_exec *exec, t_ftp *ftp);
int	exec_PASS(t_exec *exec, t_ftp *ftp);
int	exec_CWD(t_exec *exec, t_ftp *ftp);
int	exec_PWD(t_exec *exec, t_ftp *ftp);
int	exec_QUIT(t_exec *exec, t_ftp *ftp);
int	exec_NOOP(t_exec *exec, t_ftp *ftp);
int	exec_WIK(t_exec *exec, t_ftp *ftp);
int	exec_HELP(t_exec *exec, t_ftp *ftp);
int	exec_PORT(t_exec *exec, t_ftp *ftp);
int	exec_PASV(t_exec *exec, t_ftp *ftp);
int	exec_LIST(t_exec *exec, t_ftp *ftp);
int	exec_TYPE(t_exec *exec, t_ftp *ftp);
int	exec_CDUP(t_exec *exec, t_ftp *ftp);
int	exec_RETR(t_exec *exec, t_ftp *ftp);
int	exec_STOR(t_exec *exec, t_ftp *ftp);
int	exec_DELE(t_exec *exec, t_ftp *ftp);

void	sig_handler(int signal);

#endif
