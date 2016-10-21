#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include    "Logger.hh"

#include	<security/pam_modules.h>

#define            PAM_SM_AUTH
#define            PAM_SM_SESSION

Log logger(0);

int is_root(void) {
    if (getuid()) {
        logger.fatal << "This module must be executed in root";
        return (0);
    }
    return (1);
}

extern int pam_sm_open_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc,
                               __attribute__((unused)) const char **argv) {
    const char *username;
    std::string user;

    username = NULL;
    pam_get_user(pamh, &username, NULL);
    user = username;
    logger.debug << "Hello Worldddd from pam " + user;
    return (PAM_SUCCESS);
}

extern int pam_sm_close_session(pam_handle_t *pamh, __attribute__((unused)) int flags, __attribute__((unused)) int argc,
                                __attribute__((unused)) const char **argv) {
    const char *username;
    std::string user;

    username = NULL;
    pam_get_user(pamh, &username, NULL);
    user = username;
    logger.debug << "Hello Worldddd from pam " + user;
    return (PAM_SUCCESS);
}
