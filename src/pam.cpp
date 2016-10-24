#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Logger.hh"
#include <security/pam_modules.h>
#include <Crypt.hh>

#define PAM_SM_AUTH
#define PAM_SM_SESSION

Log		logger(0);

extern int	pam_sm_open_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc,
				    __attribute__((unused)) const char **argv)
{
  const char *username;
  std::string user;
  Crypt *crypt;

  username = NULL;
  pam_get_user(pamh, &username, NULL);
  user = username;
  logger.debug << "Hello World from pam " + user;
  crypt = new Crypt(user);
  crypt->open();
  return (PAM_SUCCESS);
}

extern int	pam_sm_close_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc,
				     __attribute__((unused)) const char **argv) {
  const char *username;
  std::string user;
  Crypt *crypt;

  username = NULL;
  pam_get_user(pamh, &username, NULL);
  user = username;
  logger.debug << "Good Bye from pam " + user;
  crypt = new Crypt(user);
  crypt->close();
  return (PAM_SUCCESS);
}
