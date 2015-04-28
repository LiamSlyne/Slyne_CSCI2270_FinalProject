# Slyne_CSCI2270_FinalProject
Liam Slyne
Final Project Phase 1

Summary of Program:
	
The object of my program is a type of game simulation based off of
Riot Games game League of Legends map and the in game role of Jungler.  You start
off by making your username(summoner name) and choosing a champion to play.
between three different types of ways to deal damage.  There are three different
types are damage output: Physical Damage, Ability Power, and Attack Speed.  Once
you have chosen your champion the user based options of the game begins.  The
user has the option to view current gold, current location, current time, the map,
current items and buy items from the store, and to choose where to go next. 
As the user progresses through the simulation you accumulate gold by going to 
different places in the jungle and clearing the monsters there.  Each edge of
the graph is measured in game by the amount of time it takes the user to get
to one part of the Jungle to another in seconds. The game ends when you accumulate
a total time of 25 minutes or if you decide to surrender. After the 25 minutes
is up a random integer is chosen from 1-100 and you will have a 40% chance
to win.  If you have more items you will gain a better chance to win at the 
end of 25 minutes. Each item you have will give you a 10% better chance to win.
If you collect the maximum amount of items (6) you have a 100% chance to win.

How to Run:

The program is run in a code blocks project that has a driver file
named JungleGraph.cpp which has the void functions for the program.

Dependencies:
	
No known dependencies at this time.

System Requirements:

Currently the program has only been tested on the VM given to us
at the start of the semester in the Code Blocks IDE.

Known Issues and Bugs:

In the main menu of the game 5/8 options are working.
Options 1, 2, 3, 4, and 8 work while 5, 6, and 7 do not.
