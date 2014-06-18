# Introduction
This package was built for figuring out how to distribute packets of data out to a cluster of processing computers. The ussage is simple. There are 3 parameters. Pass it a [start] an [end] and the number of machines that will be processing, it will divide up the range into chunks to pass off to the cluster of servers. 

## Building
To build the project, run as follows:

	$> make clean && make


## Usage
Example usage being passed to 8 machines with a sample space of 5000:

	$> ./master 1 5000 8
	
Output:

	Start = 1, End = 500000
	ID: 1, start = 1, end = 62500
	ID: 2, start = 62501, end = 125000
	ID: 3, start = 125001, end = 187500
	ID: 4, start = 187501, end = 250000
	ID: 5, start = 250001, end = 312500
	ID: 6, start = 312501, end = 375000
	ID: 7, start = 375001, end = 437500
	ID: 8, start = 437501, end = 500000