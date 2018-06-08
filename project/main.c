#include "get_next_line.h"
#include <stdio.h>

#include <time.h>
     

int	main()
{

	 clock_t start, end;
	 double time_spent;
     
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
	

	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
 	printf("%f\n",time_spent); 
	return(0);
}
