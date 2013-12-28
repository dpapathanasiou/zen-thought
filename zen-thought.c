/* A zen thought-of-the-day aphorism application based on the 
   daily paper calendar by JoTaiga (http://jotaiga.com/), and
   modeled after the old unix fortune application.

   Author: Denis Papathanasiou 
   Source & License: https://github.com/dpapathanasiou/zen-thought

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAYINGS 31
#define MAX_LENGTH 1024
#define SAYINGS_FILE "/usr/share/games/zen-thought/jotaiga-aphorisms.txt"

int get_mday_today () {
  /* Return tm_mday, which is the current
     day of the month, i.e., an int 1-31 */

  time_t rawtime;
  struct tm *timeinfo;

  time( &rawtime );
  timeinfo = localtime( &rawtime );
  return timeinfo->tm_mday;
}

void load_aphorisms (char filename[], char *sayings[]) {
  /* Load the aphorisms from the given file and
     store them in the string array */
  
  char line[MAX_LENGTH];
  int i = 0;

  FILE *infile;
  if ((infile = fopen(filename,"r")) == NULL) {
    printf("Could not open aphorisms file %s\n", filename);
    return;
  }

  /* Each line of the aphorisms file corresponds
     to the saying for one day, using pipe to 
	 separate physical lines */
  while( fgets(line, MAX_LENGTH, infile) ) {
    sayings[i] = malloc(strlen(line) + 1);
    strcpy(sayings[i], line);
    i++;
  }

  fclose(infile);
}

int main(int argc, char *argv[]) {
  /* Use the aphorisms found in the SAYINGS_FILE, unless
     there is a command line argument to use a different one */
	
  char *sayings[MAX_SAYINGS];
  if( argc > 1 ) {
    load_aphorisms(argv[1], sayings);
  } else {
	load_aphorisms(SAYINGS_FILE, sayings);
  }

  int i,
    today = get_mday_today() - 1; // sayings are 0-indexed

  /* Pick the aphorism for today, and convert each pipe
     character into a newline before writing to stdout */
  for(i=0; i<strlen(sayings[today]); i++) {
    if( sayings[today][i] == '|' ) {
      sayings[today][i] = '\n';
    }
  }
  printf("\n%s\n\n", sayings[today]);

  return 0;
}

