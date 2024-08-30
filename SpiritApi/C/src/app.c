#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef __APPLE__
#include <libgen.h>
extern char *__progname;
#define program_invocation_short_name __progname
#else
extern char *program_invocation_short_name;
#endif

void usage(int exitCode, const char *errorMsg, ...)
{
    const char *prog_name = strrchr(program_invocation_short_name, '/');
    if (prog_name == NULL)
        prog_name = program_invocation_short_name;
    else
        prog_name++; // Skip the '/'

    if (errorMsg != NULL) {
        va_list ap;
        va_start(ap, errorMsg);
        vfprintf(stdout, errorMsg, ap);
        va_end(ap);
        fprintf(stdout, "\n\n");
    }
    fprintf(stdout,
        "Usage: %s [options] operation ...\n"
        "Options:\n"
        "  -h\t\t\tPrint usage message.\n"
        "  -c\t\t\tSet connection information, format:\n"
        "\t\t\t<tcp:host:port>, example -p tcp:localhost:1234\n"
        "\t\t\t<unix:unix-socket.file>, example -p unix:/tmp/serial.socket\n"
        "Operations:\n"
        "  user <command>\tSpawn a task and execute the command.\n"
        "  exec <command>\tExecute the command silently and return the result.\n"
        "  clip-get\t\tSet host system's clibpoard to the TempleOS clipboard content.\n"
        "  clip-set\t\tSet TempleOS clipboard content to the host system's clipboard.\n"
        ,
        prog_name);
    exit(exitCode);
}
