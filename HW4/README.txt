Written by Juan-Fernando Morales in November of 2022

FUNCTION:

Reads from file "cleaned_movielist.txt", which contains a list of movies with their corresponding actors on the same line.
sorts content of "cleaned_movielist.txt" into an adjacency list, where Actors are Vertices and Movies are Edges. 

RUN:
run command make on Makefile
run ./sixdegrees -input_file -output_file
with corresponding input and output files are text files.

Note that Sixdegrees expects each line of input file to following format:

Actor_1 Actor_2

with a new line following immediately after Actor2, and without any empty lines.