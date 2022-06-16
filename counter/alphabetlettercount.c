#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "count.h"

void alphabetlettercount(char* path, char* filetowrite, long alphabetfreq[])
{
    DIR* d;
    char* filename;
    char* fil;
    //directory opening process
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
                    if ((c >= 65) && (c <= 90))
                        c = c + 32;
                    if ((c >= 97) && (c <= 122)) { 
                        alphabetfreq[c - 97] = (long)alphabetfreq[c - 97] + 1;
                    }
                    c = fgetc(f);
                }

                fclose(f);
                FILE* g = fopen(filetowrite, "w"); //opens result.txt for writing
                for (int i = 0; i < 26; i++) { 
                    fprintf(f, "%c -> %ld\n", (char)(i + 97), alphabetfreq[i]); 
                }

                fclose(g);
            }
        }
    }
    closedir(d);
}