/*  written 2007 by Bernhard R. Link
 *  This file is in the public domain.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */
#include <config.h>

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "closeallfds.h"

void closeallopenfds(const int *exceptions, size_t count) {
#ifndef HAVE_CLOSEFROM
	long maxopen;
#endif
	int maxfd, fd;
	size_t i;

	maxfd = -1;
	for( i = 0 ; i < count ; i++ ) {
		if( exceptions[i] > maxfd )
			maxfd = exceptions[i];
	}
	for( fd = 0 ; fd < maxfd ; fd++ ) {
		for( i = 0 ; i < count ; i++ ) {
			if( exceptions[i] == fd )
				break;
		}
		if( i == count )
			close(fd);
	}
#ifdef HAVE_CLOSEFROM
	closefrom(maxfd+1);
#else
# ifdef F_CLOSEM
	if( fcntl(lowfd, F_CLOSEM, NULL) == 0 )
		return;
# endif
	maxopen = sysconf(_SC_OPEN_MAX);
	if( maxopen > INT_MAX )
		maxopen = INT_MAX;
	if( maxopen < 0 )
		maxopen = 1024;
	for( fd = maxfd + 1 ; fd <= maxopen ; fd++ )
		close(fd);
#endif
}
