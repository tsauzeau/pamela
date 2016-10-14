#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	<unistd.h>
#include	<string.h>
#include	<errno.h>
#include	<stdarg.h>

#include	<security/pam_modules.h>

#define			PAM_SM_AUTH
#define			PAM_SM_SESSION

int		is_root(void)
{
  if (getuid())
    return (printf("This module must be run as root.\n"));
  return (1);
}


extern int	pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  char		*username;

  username = NULL;
  pam_get_user(pamh, &username, NULL);
  fprintf(stdout, "Hello World from pam %s\n", username);
  return (PAM_SUCCESS);
}

extern int	pam_sm_close_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc, __attribute__((unused)) const char **argv)
{
  char		*username;

  username = NULL;
  pam_get_user(pamh, &username, NULL);
  fprintf(stdout, "Good Bye from pam %s\n", username);
  return (PAM_SUCCESS);
}
