#include "get_next_line.h"

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 5
#endif
char    *get_next_line(int fd)
{
    int sz;
    char buffer[BUFFER_SIZE + 1];
    int result;
    static char *line;
    char *returnable;

    returnable = NULL;
    while(result != -3)
    {
        sz = read(fd, buffer, BUFFER_SIZE);
        buffer[sz] = '\0';
        result = check_line_buffer(&line, &returnable, buffer);
        if (result == -1)
        {
            if (!line)
                line = ft_substr(buffer, 0, ft_strlen(buffer));
            else
                line = ft_strjoin(line, buffer);
        }
        else if (result == -3)
        {
            if(!line)
                return (NULL);
            returnable = ft_substr(line, 0, ft_strlen(line));
            line = NULL;
            return(returnable);
        }
        else if (result == -10)
            return(returnable);
        else
        {
            if(line)
                line = ft_strjoin(line, ft_substr(buffer, 0, result));
            else
                line = ft_substr(buffer, 0, result);
            returnable = ft_substr(line, 0, ft_strlen(line));
            line = ft_substr(buffer, result, ft_strlen(buffer) - result);
            return (returnable);
        }
    }
    return (NULL);
}

int main()
{
    int fd;

    fd = open("baz.txt", O_RDONLY);
    if (fd < 0)
        return 0;
    char *smth =  get_next_line(fd);
    while(smth)
    {
        printf("%s", smth);
        free(smth);
        smth = get_next_line(fd);
    }
}

