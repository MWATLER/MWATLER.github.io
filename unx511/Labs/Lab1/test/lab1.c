/*
 * Author: Daniel Pliszka
 * Contact: dpliszka@myseneca.ca
 * Title: DPS912 Lab 01
 * Date: July 13, 2019
 *
 */

// Question 1 of Lab 01
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// Variables
	int VmRSS = 0;
	char lineBuf[250];
	struct dirent *de = NULL;
	DIR *d = NULL;

	// Error Checking
	if (argc != 2) {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		return (1);
	}

	d = opendir(argv[1]);
	if (d == NULL) {
		printf("Couldn't open directory\n");
		return (2);
	}
	else { printf("Opened directory\n"); }

	// Loop while not NULL
	while (de == readdir(d)) // Searching /proc (CLI argument)
	{
		printf("%s\n",de->d_name); // Testing
		if(strpbrk(de->d_name, "0123456789")) // If de->d_name (file) contains numbers, we know it's a directory
		{
			printf("Found process directory!");
			// Open process directory
			DIR *d2 = opendir(de->d_name);
			struct dirent *de2 = NULL;

			// Scan each entry in process directory, searching for "status" file
			while(de2 == readdir(d2))
			{
				if(strcmp(de2->d_name, "status"))
				{
					// Open the file "status"
					FILE *fptr = NULL;
					if((fptr = fopen("status", "r")) == NULL)  { perror("Error accessing \'status\' file"); }

					// Scan status file for line containing "VmRSS"
					while(fptr != NULL)
					{
						fscanf(fptr, "%[^\n]", lineBuf);
						if(strpbrk(lineBuf, "VmRSS")) // If line contains "VmRSS"
						{
							// Retrieve numerical digit from line buffer
							sscanf(lineBuf, "%d", &VmRSS);

							// TODO: If VmRSS is greater than 10000 kB,
							// then print out the process name, the process id and the memory used.
						}
					}
				}
				else { printf("No status file found"); }
			}

			// Close process directory
			closedir(d2);
		}
		else { printf("Process directory not found"); }
	}

	// Close /proc directory
	closedir(d);
	return (0);
}

/* Question 2 of Lab 01: ACTION COMPLETED

   Question 3 of Lab 01: Explain the difference between virtual memory and resident memory.
                         What is virtual memory? What is resident memory?

	A: Virtual memory as the name suggests is, the virtual amount of memory (RAM) the system BELIEVES it is using.
	   Resident memory is the physical, or actual amount of memory the system is using. Due to this setup, virtual
	   memory usage is almost always larger than the value of resident memory usage.

	Question 4: Research and report on any of the three of the processes returned by your program.
	            Simply explain what these processes do.

	A: PID 1 - Reserved for the initialization process
	   PID 6 - Bash shell process
	   PID 44 - Running PS command (to see all current processes)
*/
