#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strchr(char *s, char c)
{
    int i = 0;
    
    if (!s)
        return NULL;
    while (s[i] != '\0')
    {
        if (s[i] == (unsigned char)c)
            return (&s[i]);
    i++;
    }
    return (0);
}
char *ft_strdup(char *str)
{
    char *dyn_point;
    size_t i;
    
    if (!str)
        return NULL;
    dyn_point = (char *)malloc(sizeof(char) *(ft_strlen(str) + 1));
    if (!dyn_point)
        return NULL;
    i = 0;
    while (i < ft_strlen(str))
    {
        dyn_point[i] = str[i];
        i++;
    }
    dyn_point[i] = '\0';
    return (dyn_point);
}

char *ft_strjoin(char *s, char *s1)
{
    size_t i;
    size_t j;
    char *joint;
    size_t v;

    v = ((ft_strlen(s) + ft_strlen(s1)) + 1);
    i = 0;
    if (!s || !s1)
        return (0);
    joint = (char *)malloc(sizeof(char) * v);
    if (!joint)
        return NULL;
    while (i < ft_strlen(s))
    {
        joint[i] = s[i];
        i++;
    }
    j = 0;
    while (j < ft_strlen(s1))
        joint[i++] = s1[j++];
    joint[i] = '\0';
    return(joint);
}

char *ft_substr(char const *s, size_t start, size_t len)
{
    char *dyn_point;
    unsigned int i;
    
    if (!s)
        return 0;
    if (start > ft_strlen(s))
        return 0;
    if (len > ft_strlen(s))
        dyn_point = (char *)malloc((sizeof(char) * ((ft_strlen(s) - start) + 1)));
    else
        dyn_point = (char *)malloc(sizeof(char) * (len + 1));
    if (!dyn_point)
        return NULL;
    i = 0;
    while (i < len)
        dyn_point[i++] = s[start++];
    dyn_point[i] = '\0';
    return (dyn_point);
}