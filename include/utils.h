/*
** utils.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Thu May 12 22:39:10 2016 Thomas Sauzeau
** Last update Sun May 15 21:02:09 2016 Thomas Sauzeau
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "ftp.h"

# define READ_SIZE 256

void*		xmalloc(size_t size);
char*		xstrdup(const char *src);
ssize_t		xwrite(int fildes, const void *buf, size_t nbyte);
int		strpos(char *haystack, char *needle);
char		*append_string(char *s1, char *s2, unsigned int f);
char		*my_getline(const int fd);
void		ftp_init(t_ftp *ftp, int fd, const char *const path);

#endif
