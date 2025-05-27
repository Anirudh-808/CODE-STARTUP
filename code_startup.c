#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_file(FILE *file){
    if (file = NULL)
    {
        printf("ERROR OPENING FILE!"); 
        exit(1);
    }
}

void copy_content(FILE *source, FILE *destination)
{   
    //used to copy content of file
    char line[200];
    while (fgets(line, sizeof(line) , source) != NULL)
    {
        fprintf(destination, "%s", line);
    }
}

void check_ext_copy(char *ext, FILE *real)
{
    // Used to check the extension of file
    FILE *ref = NULL;
    if (strcmp(ext, "txt") == 0) {
        ref = fopen("ref.txt", "r");
    } else if (strcmp(ext, "py") == 0) {
        ref = fopen("ref.py", "r");
    } else if (strcmp(ext, "c") == 0) {
        ref = fopen("ref.c", "r");
    } else {
        printf("Unsupported file extension: %s\n", ext);
        return; // Exit if the extension is not supported
    }
    check_file(ref);
    copy_content(ref, real);
    fclose(ref);
}

int main(int argc, char *argv[])
{
    //file pointers for actual file
    FILE *actual;

    char actual_file[100];
    strcpy(actual_file, argv[1]);
    printf("Actual file: %s\n", actual_file);

    char ext[10];
    char actual_file_name[100];

    //trying to serparate the file name and extension
    strcpy(actual_file_name , strtok(actual_file, "."));
    strcpy(ext , strtok(NULL, "."));
    printf("Extension: %s\n", ext);

    char actual_file_path[100] = "";
    if (strcmp(ext , "c") == 0)
    {
        strcpy(actual_file_path, "D:\\CODE\\C\\");
        strcat(actual_file_path, actual_file_name);
        strcat(actual_file_path, ".c");
    }
    else if (strcmp(ext , "py") == 0)
    {
        strcpy(actual_file_path, "D:\\CODE\\PYTHON\\");
        strcat(actual_file_path, actual_file_name);
        strcat(actual_file_path, ".py");
    }

    printf("Actual file path: %s\n", actual_file_path);
    actual = fopen(actual_file_path , "w");
    check_file(actual);

    check_ext_copy(ext, actual);

    fclose(actual);
    return 0;
}