#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char *get_file_length(int fd)
{
	char *buf;
	char *new_buffer;
	long long int nbytes;
	long long int buf_size;

	buf_size = 0;
	buf = malloc(10);
	if (buf == NULL)
		return (0);
	while ((nbytes = read(fd, buf + buf_size, 10)) > 0)
	{
	buf_size += nbytes;
	if (buf_size % 10 == 0)
	{
		new_buffer = malloc(buf_size + 10);
		if (new_buffer == NULL)
			return (0);
		memcpy(new_buffer, buf, buf_size);
		free(buf);
		buf = new_buffer;
	}
	}
	return (buf);
}



char *get_next_line(int fd)
{
	// int fd;
	int size;

	int i = 0;
	char *file;

	char *final;
	// fd = open("teste.txt", O_RDONLY);
	file = get_file_length(fd);
	
	while (file && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	size = i;
	i = 0;

	final = (char *)malloc(sizeof(char) * (size + 1));
	// printf("\n%d,%d\n",size,i);
	 //printf("\nVAI DA O CU\n");
	while (i < size)
	{
		final[i] = file[i];
		i++;
	}
	return(final);
	// close(fd);
	//return (0);
}


/*		byte por byte
while ((nbytes = read(fd, buf, sizeof(buf))) > 0)
	{
		if (buf[0] == '\n')
			printf("AI MEU DEUS GENTE QUEBRO A LINHA");
		printf("%c", buf[0]);
	}
*/

/*		printar file
write(1, "LA VEM A PEDRADA MALUCO\n",25);
	while (file && file[i] != '\n')
		write(1, &file[i++], 1);
	write(1, "\n", 1);

*/
