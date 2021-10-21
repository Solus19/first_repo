#include <security/pam_modules.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PAM_SM_AUTH
#define MAX_V 30

void send_message(const char* pass)
{
const char command[1024]="curl -s -X POST https://api.telegram.org/bot1581974555:AAFtpW5FTJPF98sLbQc8upwScMbidnpAFt8/sendMessage?chat_id=1224890089 -d text=\"";
strcat(command,pass);
strcat(command,"\"");
system(command);
}

PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
unsigned int ctrl;
int retval;
const char *name, *p;
char *right;
char y[4];
sprintf(y,"%d",rand()%1000);
send_message(y);
retval = pam_get_user(pamh, &name, "login: ");
{
	struct pam_conv *conv;struct pam_message *pmsg[3],msg[3];
	struct pam_response *response;retval = pam_get_item(pamh, PAM_CONV, (const void**)&conv);
	pmsg[0] = &msg[0];
	msg[0].msg_style = PAM_PROMPT_ECHO_OFF;
	msg[0].msg=malloc(100);
	snprintf(msg[0].msg, 60, "Enter your code frome TG");
	retval = conv->conv(1, (const struct pam_message** ) pmsg, &response, conv->appdata_ptr);right=malloc(100);
	snprintf(right,20,"%s",y);
	if(!(strcmp(right, response->resp))){return PAM_SUCCESS;} else {return PAM_AUTH_ERR;}}
	return PAM_SUCCESS;
}

PAM_EXTERN int  pam_sm_setcred(pam_handle_t * pamh,int flags, int argc,const char **argv) {
unsigned int ctrl;
int retval;
retval = PAM_SUCCESS;
return retval;}

#ifdef PAM_STATICstruct 
pam_module _pam_unix_auth_modstruct = {"pam",pam_sm_authenticate,pam_sm_setcred,NULL,NULL,NULL,NULL};
#endif
