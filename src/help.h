#ifndef _HELP_H
#define _HELP_H

typedef struct t_commandInfo {
    const char *NAME;
    const char *DESC;
    const char ALIAS;
} CommandInfo;

#define HELP_C 6

#define HELP_MENU (CommandInfo[]) {\
    { "help", "Displays this help menu", 'h' },\
    { "randomfact", "Get a randomfact", 'r' },\
    { "fact", "Gets today's fact", 'f' },\
    { "dayfact", "Gets the fact of the specified day", 'd' },\
    { "indexfact", "Gets a fact by index", 'i' },\
    { "fetch", "Fetches tree ASCII art", 'e' }\
}

#endif