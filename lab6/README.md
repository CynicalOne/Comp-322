# Comp-322

First Commit 5-7-2020
	lab6 involves creating a process as a daemon. spiritd creates and destroys moles and outputs the results into a logfile
	
	Project Status: Currently, part 1 of the program completely works and when the daemon is called, it can be viewed using ps -efj. However, when i send a usr1 or usr2 signal, the daemon successfully runs the moles program(it can be seen as a defunct process also using ps -efj), but the log file is not successfully created in the same directory. I assume that the logfile is either sent to dev/null or nothing in moles is being executed at all and the process somehow dies without executing anything from moles. Part 2 of the program is mostly complete minus that last description.