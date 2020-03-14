# Comp-322

First Commit 3-12-2020
	Launch is a commandline program that launches other programs and reports some information about PID.
	Launch completed and tested using lab0 as well as lab1
	
	
	Project Status:Completed launch, Tube is in progress

Second Commit 3-14-2020
	Added tube. memory is allocated for the arguments for both commands. Currently, child1 process feeds the output into the write end of the pipe, but i can't figure out how to utilize the read end to execute process 2. Tests have been done using linux commands "/bin/cat <text file>" piped with "grep <word in file>". process1 is able to do the first command, but is unable to grep correctly as there is an issue with the piping, even though stdin for process2 has been dup2'd with the read end of the pipe.
	Currently, all the steps asked for in the project specs have been implemented, but there is an issue with the read end of the interprocess communication in child2.
	
	
	Project Status:Completed launch, Tube has logical or syntactical errors in the read end of the pipe