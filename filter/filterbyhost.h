#ifndef _FILTER_BY_HOST_
#define _FILTER_BY_HOST_

/*
 * filterByHost() - Funcion added to filter jobs incoming from same IP.
 */
void filterByHost(int num_options, cups_option_t * options)
{
  const char* host = cupsGetOption("job-originating-host-name", num_options, options);
  const char* uuid = cupsGetOption("job-uuid", num_options, options);
  const char* script = "./usr/lib/cups/filterbyhost.py";
  char cmd[strlen(host) + strlen(uuid) + strlen(script) + 3];
  strcpy(cmd, script);
  strcat(cmd, " ");
  strcat(cmd, host);
  strcat(cmd, " ");
  strcat(cmd, uuid);
  fprintf(stderr, "Calling filter job procedure, command: '%s'\n", cmd);
  system(cmd);
}

#endif //_FILTER_BY_HOST_
