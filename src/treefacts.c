#include "ascii-colours.h"
#include "libtreefacts.h"
#include "help.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fetch() {
    printf(GRN);
    printf("      /\\\n"); // tree
    printf("     /\\*\\\n");
    printf("    /\\O\\*\\\n");
    printf("   /*/\\/\\/\\\n");
    printf("  /\\O\\/\\*\\/\\\n");
    printf(" /\\*\\/\\*\\/\\/\\\n");
    printf("/\\O\\/\\/O/\\/*/\\\n");
    printf(RED);
    printf("      ||//\n");
    printf("      | /\n" );
    printf("   %s@%s  ||            @           %s@\n", BLU, RED, YEL); // flower
    printf("%s__\\|/_%s||%s___________\\|/_________\\|/___\n", GRN, RED, GRN); // ground
}
 
int main(int argc, char const *argv[]) {
    fetch();
    printf(BBLU);

    for(int i = 0; i < argc; i++) {
        const char *arg = argv[i];

        if(!strcmp(arg, "--help") || !strcmp(arg, "-h")) {
            printf("\033c");

            printf(BGRN);
            printf("----------- TreeFacts Help Menu -----------");

            for(int i = 0; i < HELP_C; i++) {
                CommandInfo info = HELP_MENU[i];

                int y = i + 3;

                printf("\x1b[%d;0H", y);
                printf(YEL);
                printf("--");
                printf("%s", info.NAME);
                printf("\x1b[%d;15H", y);
                printf(GRN);
                printf("-%c", info.ALIAS);
                printf("\x1b[%d;20H", y);
                printf(BLU);
                printf("%s", info.DESC);
            }

            printf("\n");

            printf(reset);
            
            exit(0);
        }

        if(!strcmp(arg, "--randomfact") || !strcmp(arg, "-r")) {
            printf("\n"); // without this the text wont colour
            TreeFacts_RandomFact();
            printf("\n");

            printf(reset);

            exit(0);
        }

        if(!strcmp(arg, "--fact") || !strcmp(arg, "-f")) {
            printf("\n");
            TreeFacts_TodayFact();
            printf("\n");

            printf(reset);

            exit(0);
        }

        if(!strcmp(arg, "--dayfact") || !strcmp(arg, "-d")) {
            if(argc <= i + 1) {
                printf("\nPlease specify a day\n");
                exit(1);
            }
            int day = atoi(argv[i + 1]); // now the index one
            
            printf("\n");
            TreeFacts_Fact(day); // your internet's lagging again // yes
            printf("\n");

            printf(reset);

            exit(0);
        }
        
        if(!strcmp(arg, "--indexfact") || !strcmp(arg, "-i")) {
            if(argc <= i + 1) {
                printf("\nPlease specify an index\n");
                exit(1);
            }
            int index = atoi(argv[i + 1]);
            
            printf("\n");
            TreeFacts_FactFromIndex(index);
            printf("\n");

            printf(reset);

            exit(0);
        }

        if(!strcmp(arg, "--fetch") || !strcmp(arg, "-e")) {
            printf("\nWhat a wonderful day we're havin'!\n");

            printf(reset);

            exit(0);
        }
    }
    printf(RED);
    printf("\nInvalid arguments (-h for help)\n");
    printf(reset);
}
