#include "get_next_line.h"
#include <stdio.h>

#include <time.h>
     

int	main()
{

	 clock_t start, end;
     
     start = clock();
	int i;
	int fd = open("large_file.txt", O_RDONLY);
	char	**line;
	line = malloc(100000);
	*line = malloc(100000);
	i = 1;
	int count = 0;
	while (count != 783)
	{	
		count++;
		i = get_next_line(fd, line);
		printf("%d: Buff: {%d}  len: %zu [%s]\n",i ,BUFF_SIZE,ft_strlen(*line), *line);
	}
	 end = clock();
	printf("%lu\n",end );

	return(0);
     // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

}
