/*
** tab.h for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
**
** Made by Thomas Sauzeau
** Login   <thomas@epitech.net>
**
** Started on  Thu May 12 22:34:19 2016 Thomas Sauzeau
** Last update Thu May 12 22:35:00 2016 Thomas Sauzeau
*/

#ifndef TAB_H_
# define TAB_H_

int	tab_size(char** tab);
char	**cut_CMD(const char *const cmd, const char *const sep);

#endif
