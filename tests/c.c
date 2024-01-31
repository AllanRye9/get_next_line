#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_len(char *s)
{
  int i = 0;

  while(*s)
  i++;
  return i;
}

// char borrowme(char *name, int age, int num_x)
// {



// }

int main()
{
  char oc[100];
  char cn[100];
  float earn_s;
  char rel[100];
  char pur[100];
  int dep;
  int dur_n;
  char *s;

  int age = 21;
  int num_x = 10;
  char name[20] = "alan";

//   printf("enter country:");
//   scanf("%s", cn);

//   printf("enter occupation:");
//   scanf("%s", oc);

//   printf("enter income estimation:");
//   scanf("%f", &earn_s);

//   printf("enter relationship:");
//   scanf("%s", rel);
  
//   printf("enter purpose for borrowing:");
//   scanf("%s", pur);

//   printf("enter dependencies known:");
//   scanf("%d", &dep);

//   printf("enter duration you've known each other:");
//   scanf("%i", &dur_n);

  // s = borrowme(name, age, num_x);
  // printf("%s\n%s\
  // n%s\n%s\n%f\n%d\n%s\n%s\n%s%d\n", name, cn, oc, age, earn_s, rel, pur, dep, dur_n);
  int fd;
  int n;
  char by;
  int i = 0;
  fd = open("test.txt", O_RDWR);
  while (fd)
  {
     write(fd, "hellorrr", 9);
     write(fd, "worldfggg", 10);
     write(fd, "23", 2);
     write(fd, "fkgk", 4);
     write(fd, "10340", 5);
     write(fd, "5838", 4);
     write(fd ,"16", 2);
     write(fd, "4kgk", 4);
     write(fd, "fghh", 5);
    i++;
  }
  close(fd);
//   printf("\n-----------------------------------\n");
//   printf("%s\n", name);
//   printf("%d\n", age);
//   printf("%s\n", oc);
//   printf("%4f\n", earn_s);
//   printf("%s\n", cn);
//   printf("%d\n", dur_n);
//   printf("%s\n", pur);
//   printf("%d", dep);
//   printf("%s\n", &by);
return 0;
}
