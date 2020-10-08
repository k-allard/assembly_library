#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

void	blue_start()
{
	printf("\x1b[44m");
}

void	color_end()
{
	printf("\x1b[0m\n");
}

void	test_strlen()
{
	char    *string;
	int		std;
	int		my;
	blue_start();
	printf("\n\n    --->  FT_STRLEN TESTS  <---    ");
	color_end();

	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("   Test #1: null string            ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "";
	std = strlen(string);
	my = ft_strlen(string);
	printf("return value %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: [short] string        ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "short";
	std = strlen(string);
	my = ft_strlen(string);
	printf("return value %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: very long string      ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	string = "More organizations have bought insurance against cyberattacks, though that has been a double-edged sword. Insurance can help organizations, but it also guarantees a payout to criminals. And recently during the coronavirus pandemic, organizations are more vulnerable to ransomware because they are more dependent on digital systems, and computer security personnel working remotely may be less speedy or effective than usual.";
	std = strlen(string);
	my = ft_strlen(string);
	printf("return value %d = %d\n", std, my);
}

void    test_strcpy()
{
	char    *string;
	char	buffer[19] = "XXXXXXXXXXXXXXXXXX";
	char	buffer2[19] = "XXXXXXXXXXXXXXXXXX"; 
	char	*std;
	char	*my;

	blue_start();
	printf("\n\n    --->  FT_STRCPY TESTS  <---    ");
	color_end();

	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("   Test #1: null string            ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "";
	printf("Copying [%s] to [%s]\n", string, buffer);
	std = strcpy(buffer, string);
	my = ft_strcpy(buffer2, string);
	printf("Return strings are [%s] = [%s]", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: [short] string        ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "short";
	printf("Copying [%s] to [%s]\n", string, buffer);
	std = strcpy(buffer, string);
	my = ft_strcpy(buffer2, string);
	printf("Return strings are [%s] = [%s]", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: long string           ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	char	buffer3[186];
	char	buffer4[186];
	string = "More organizations have bought insurance against cyberattacks, though that has been a double-edged sword. Insurance can help organizations, but it also guarantees a payout to criminals.";
	printf("Copying [%s] to [%s]\n", string, buffer3);
	std = strcpy(buffer3, string);
	my = ft_strcpy(buffer4, string);
	printf("--> Return strings are [%s] = [%s]\n", std, my);
}

void    test_strcmp()
{
	char    *null_string;
	char    *short_string;
	char    *long_string;
	int		std;
	int		my;


	null_string = "";
	short_string = "Short string";
	long_string = "More organizations have bought insurance against cyberattacks, though that has been a double-edged sword. Insurance can help organizations, but it also guarantees a payout to criminals.";
	
	blue_start();
	printf("\n\n    --->  FT_STRCMP TESTS  <---    ");
	color_end();

	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("   Test #1: two empty strings      ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strcmp(null_string, null_string);
	my = ft_strcmp(null_string, null_string);
	printf("Return values are %d = %d", std, my);

	printf("\n\n");
	printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: empty string 1st arg  ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strcmp(null_string, short_string);
	my = ft_strcmp(null_string, short_string);
	printf("Return values are %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: empty string 2nd arg  ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strcmp(short_string, null_string);
	my = ft_strcmp(short_string, null_string);
	printf("Return values are %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #4: short + long          ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strcmp(short_string, long_string);
	my = ft_strcmp(short_string, long_string);
	printf("Return values are %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #5: long + short          ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strcmp(long_string, short_string);
	my = ft_strcmp(long_string, short_string);
	printf("Return values are %d = %d\n\n", std, my);
}

void		test_write()
{	
	int     fd;
	char    *string;
	int     std;
	int     my;


	printf("\n\n");
	blue_start();
	printf("    --->  FT_WRITE TESTS  <---    ");
	color_end();

	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\t");
	printf("Test #1: with stdout       ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "short string\n";
	std = write(1, string, strlen(string));
	my = ft_write(1, string, ft_strlen(string));
	printf("\nreturn value %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: null string to stdout ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "";
	std = write(1, string, strlen(string));
	my = ft_write(1, string, ft_strlen(string));
	printf("return value %d = %d", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: write to opened fd    ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	errno = 0;
	string = "short string\n";
	fd = open("test.txt", O_RDWR);
	printf("errno before write - %d\n", errno);
	printf("Writing . . .\n");
	std = write(fd, string, strlen(string));
	printf("errno after - %d\n", errno);
	if (errno == 0)
		printf("Success! Check test.txt\n");

	errno = 0;
	printf("\nerrno before ft_write - %d\n", errno);
	printf("Writing . . .\n");    
	std = ft_write(fd, string, strlen(string));
	printf("errno after - %d\n", errno);
	if (errno == 0)
		printf("Success! Check test.txt");
	close(fd);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\t");
	printf("Test #4: with wrong fd     ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	string = "short string\n";
	errno = 0;
	printf("errno before write - %d\n", errno);
	printf("Writing . . .\n");
	std = write(-1, string, strlen(string));
	printf("errno after - %d\n", errno);
	printf("errno transcript - %s\n", strerror(errno));

	errno = 0;
	printf("\nerrno before ft_write - %d\n", errno);
	printf("Writing . . .\n");    
	std = ft_write(-1, string, strlen(string));
	printf("errno after - %d\n", errno);
	printf("errno transcript - %s\n\n", strerror(errno));

}

void        test_read()
{	
	int     fd;
	char    string[13] = "LIBASM TESTS";
	int     std;
	int     my;

	printf("\n\n");
	blue_start();
	printf("    --->  FT_READ TESTS  <---    ");
	color_end();

	printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("  Test #1: read from stdin             ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	printf("buffer before read - [%s]\n", string);
	printf("enter your input and press Ctrl + D:  ");
	fflush(stdout);
	my = read(0, &string, 50);
	printf("\nbuffer now: [%s]\n", string);
	printf("return value: %d\n\n", my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: read from opened fd    ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	fd = open("test.txt", O_RDWR);
	printf("string before ft_read - [%s]\n", string);
	printf("Reading . . .\n");
	my = ft_read(fd, string, 5);
	printf("return value: %d\n\n", my);
	if (my == -1)
	{
		printf("error!\nerrno is - %d\n", errno);
		printf("errno transcript - %s\n\n", strerror(errno));
	}
	else
		printf("string now: [%s]\n\n", string);

	close(fd);

	printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: read from wrong fd     ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	errno = 0;
	printf("errno before read - %d\n", errno);
	printf("Reading . . .\n");
	std = ft_read(-1, string, 5);
	printf("errno after - %d\n", errno);
	printf("errno transcript - %s\n", strerror(errno));

	errno = 0;
	printf("\nerrno before ft_write - %d\n", errno);
	printf("Writing . . .\n");    
	std = ft_write(-1, string, strlen(string));
	printf("errno after - %d\n", errno);
	printf("errno transcript - %s\n\n", strerror(errno));
}

void    test_strdup()
{
	char    *null_string;
	char    *short_string;
	char    *long_string;
	char    *std;
	char    *my;


	null_string = "";
	short_string = "Short string";
	long_string = "More organizations have bought insurance against cyberattacks, though that has been a double-edged sword. Insurance can help organizations, but it also guarantees a payout to criminals.";
	
	printf("\n\n");
	blue_start();
	printf("    --->  FT_STRDUP TESTS  <---    ");
	color_end();

	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("   Test #1: empty string             ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strdup(null_string);
	my = ft_strdup(null_string);
	printf("Return strings are [%s] = [%s]", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #2: short string              ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strdup(short_string);
	my = ft_strdup(short_string);
	printf("Return strings are [%s] = [%s]", std, my);

	printf("\n\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	printf("    Test #3: looong string              ");
	printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

	std = strdup(long_string);
	my = ft_strdup(long_string);
	printf("Return strings are [%s] = [%s]\n\n", std, my);
}

int main()
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();

	return 0;
}
