#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_word(const char *filepath, const char *old_str, const char *new_str)
{
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(file_size + 1);
    if (content == NULL)
    {
        fclose(file);
        return -1;
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    fclose(file);

    char *buffer = (char *)malloc(file_size * 2);
    if (buffer == NULL)
    {
        free(content);
        return -1;
    }

    char *pos = content;
    char *buffer_pos = buffer;
    int count = 0;
    size_t old_len = strlen(old_str);
    size_t new_len = strlen(new_str);

    while ((pos = strstr(pos, old_str)) != NULL)
    {
        size_t len = pos - content;
        strncpy(buffer_pos, content, len);
        buffer_pos += len;

        strcpy(buffer_pos, new_str);
        buffer_pos += new_len;

        pos += old_len;
        content = pos;

        count++;
    }

    strcpy(buffer_pos, content);

    file = fopen(filepath, "w");
    if (file == NULL)
    {
        free(buffer);
        return -1;
    }
    fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);

    free(buffer);

    return count;
}
