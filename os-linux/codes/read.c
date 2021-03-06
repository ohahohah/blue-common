#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
 
int main(void) {
	const int len = 64;
	ssize_t ret;
	int fd = open("read.c", O_RDONLY);
	printf("fd=%d\n", fd);

	char buf[len]; //64byte buffer
	while ((ret = read(fd, buf, len)) != 0) {
		write(1, buf, ret);
	}
	close(fd);
	return 0;
}
