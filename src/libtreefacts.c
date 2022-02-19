#include "libtreefacts.h"
#include "ascii-colours.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define URL "https://treefacts-server.mrowllers.repl.co"
 
#define CURL_COMMAND "curl"
#define CAT "cat"
#define TEMP_RES "../../usr/tmp/temp-res.json"

void TreeFacts_RandomFact() {
    char command[128];

    snprintf(command, 128, "%s%s%s%s%s", CURL_COMMAND, " ", URL, "/fact/random -o ", TEMP_RES);

    system(command);

    char outputCommand[128];

    snprintf(outputCommand, 128, "%s%s%s", CAT, " ", TEMP_RES);

    system(outputCommand);
}

void TreeFacts_TodayFact() {
    char command[128];

    snprintf(command, 128, "%s%s%s%s%s", CURL_COMMAND, " ", URL, "/fact -o ", TEMP_RES);

    system(command);

    char outputCommand[128];

    snprintf(outputCommand, 128, "%s%s%s", CAT, " ", TEMP_RES);

    system(outputCommand);
}

void TreeFacts_Fact(int day) {
    char command[128];

    snprintf(command, 128, "%s%s%s%s%d%s%s", CURL_COMMAND, " ", URL, "/fact/day/", day, " -o ", TEMP_RES);

    system(command);

    char outputCommand[128];

    snprintf(outputCommand, 128, "%s%s%s", CAT, " ", TEMP_RES);

    system(outputCommand);
}

void TreeFacts_FactFromIndex(unsigned int index) {
    char command[128];

    snprintf(command, 128, "%s%s%s%s%d%s%s", CURL_COMMAND, " ", URL, "/fact/", index, " -o ", TEMP_RES);

    system(command);

    char outputCommand[128];

    snprintf(outputCommand, 128, "%s%s%s", CAT, " ", TEMP_RES);

    system(outputCommand);
}
