#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include    "Logger.hh"

#include	<security/pam_modules.h>

#define			PAM_SM_AUTH
#define			PAM_SM_SESSION

Log     logger(0);

int		is_root(void)
{
  if (getuid())
    return (printf("This module must be run as root.\n"));
  return (1);
}

extern int	    pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
    const char	*username;

    username = NULL;
    pam_get_user(pamh, &username, NULL);
    std::cout<< "Hello Worldddd from pam " << username << "\n";
    return (PAM_SUCCESS);
}

extern int	    pam_sm_close_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc, __attribute__((unused)) const char **argv)
{
    const char	*username;

    username = NULL;
    pam_get_user(pamh, &username, NULL);
    std::cout << "Hello Worldddd from pam " << username << "\n";
    return (PAM_SUCCESS);
}
