#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "count.h"

void specialcharcount(char* path, char* filetowrite, long charfreq[])
{
    DIR* d;
    char* filename;
    //stored filename
    char* fil;
    struct dirent* dir;
    d = opendir(path);
    if (d != NULL) {
        while ((dir = readdir(d)) != NULL) {
            filename = dir->d_name;
            size_t t = strlen(filename) - 3;
            int ctr = 0;
            while (t < strlen(filename)) {
                if (!(filename[t] == 't' || filename[t] == 'x'))
                    continue;
                else {
                    ctr++;
                }
                t++;
            }
            if (ctr == 3) { 
                fil = dir->d_name; 
                char p[256];
                strcpy(p, path); 
                strcat(p, "/");
                strcat(p, fil);
                FILE* f = fopen(p, "r");
                if (f == NULL) { 
                    return;
                }
                int c = fgetc(f); 
                while (!feof(f)) {
                    if (c == 44) {
                        charfreq[0] = (long)charfreq[0] + 1; 
                    }
                    else if (c == 46) {
                        charfreq[1] = (long)charfreq[1] + 1;
                    }
                    else if (c == 58) {
                        charfreq[2] = (long)charfreq[2] + 1;
                    }
                    else if (c == 59) {
                        charfreq[3] = (long)charfreq[3] + 1;
                    }
                    else if (c == 33) {
                        charfreq[4] = (long)charfreq[4] + 1;
                    }
                    c = fgetc(f); 
                }

                fclose(f);
                FILE* g = fopen(filetowrite, "w");
                fprintf(f, ", -> %ld\n", charfreq[0]);
                fprintf(f, ". -> %ld\n", charfreq[1]);
                fprintf(f, ": -> %ld\n", charfreq[2]);
                fprintf(f, "; -> %ld\n", charfreq[3]);
                fprintf(f, "! -> %ld\n", charfreq[4]);
                fclose(g);

            }
        }
    }
    closedir(d); 

}