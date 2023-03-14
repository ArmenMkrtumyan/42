#include "get_next_line.h"

//#define BUFFER_SIZE

char    *get_next_line(int fd)
{
    int BUFFER_SIZE = 5;
    int sz;
    char buffer[BUFFER_SIZE + 1];
    int result;
    static char *line;
    char *returnable;
    int finished;

    // if (check_line(line)==1)
    // {
    //     buffer_cut(line,buffer,)
    // }
    returnable = NULL;
    sz = read(fd, buffer, BUFFER_SIZE);
    finished = 0;
    buffer[sz] = '\0';
    result = check_buffer(buffer);
    while(finished == 0)
    {
        if (result == -1)
        {
            if (!line)
                line = ft_strdup(buffer);
            else
            {
                line = ft_strjoin(line, buffer);
            }
            sz = read(fd, buffer, BUFFER_SIZE);
            buffer[sz] = '\0';
            result = check_buffer(buffer);
        }
        else if (result == -2)
        {
            line = ft_strjoin(line, ft_substr(buffer, 0, get_the_end(buffer)));
            finished = 1;
            return (line);
        }
        else
        {
            if(line)
                line = ft_strjoin(line, ft_substr(buffer, 0, result));
            else
                line = ft_strdup(ft_substr(buffer, 0, result));
            returnable = ft_strdup(line);
            line = ft_substr(buffer, result, ft_strlen(buffer) - result);
            return (returnable);
        }
    }
    return (NULL);
}

int main()
{
    int fd;
    char    *text;

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

