====================================
= author:	Thomas Lamprecht
= date:		27.11.2018
====================================

== Database for app2 ==

This program is the database for the second application.

Before you can use it you have to compile it with "make"; after that you can
start the program:
$ make
$ ./database [-v] [-f database-file] PORT

e.g., ./database 50000

OPTIONS
	-v  Verbose mode.
        In this mode the program prints more messages about the commands. This
        may be useful for debugging. can be passed multiple times to increase
        verbosity.

	-f  change backing DB file (default = channel.db)
		Allows to quickly changes a backing DB file (reading and storing)


== Debugging ==

you may want to check if DB commands get processed as you think. You can use
network helper tools like nc (netcat) or socat for this.

For example, if one started the DB server with PORT 12345 locally, you could
talk with it by issuing the following command:

# nc -u 127.0.0.1 12345

A promt opens, everything you type will get send, after you pressed enter.
Further, you will receive replies from the DB here too. Do enter a \r (carriage
return) one needs to press CTRL + V and then CTRL + M, a '^M' character will
appear then. The newline gets automatically added when pressing enter
