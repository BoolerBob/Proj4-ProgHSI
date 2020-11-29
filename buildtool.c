#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int PROCESSES_RUNNING = 1;

_Bool hasChild(char *path){

}

void recWalk(char *path, DIR *dir){
  if(hasChild(path)){
    recWalk(path, dir);
  }
  else{

  }
}

void walkDir(char *path, DIR *dir){

  if (!dir){
    printf("\nCould not open directory\n\n");
    return;
  }
  recWalk(path, dir);

}

int main(){

  FILE *currentFile;
  struct dirent *de;
  DIR *dir = opendir(".");
  DIR *tempDir;
  char tempName[255];

  while ((de = readdir(dir)) != NULL){

    if(de->d_name != "." || de->d_name != ".."){
      printf("%s\n", de->d_name);
      tempDir = opendir(de->d_name);
      strncpy(tempName, de->d_name, 254);
      tempName[strlen(tempName)] = '\0';

      if (!tempDir && tempName[strlen(tempName) - 1] != 'c'){
        printf("\nCould not open directory\n\n");
      }
    }

  }

  walkDir(".", dir);

  closedir(dir);



  return 0;
}
