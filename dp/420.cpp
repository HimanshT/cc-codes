A car factory has two assembly lines, each with n stations.
A station is denoted by Si, j where i is either 1 or 2 and
indicates the assembly line the station is on, and j indicates
he number of the station. The time taken per station is denoted
by ai, j. Each station is dedicated to some sort of work like
engine fitting, body fitting, painting, and so on. So, a car
chassis must pass through each of the n stations in order
before exiting the factory. The parallel stations of the
two assembly lines perform the same task. After it passes
through station Si, j, it will continue to station Si, j + 1
unless it decides to transfer to the other line. Continuing
on the same line incurs no extra cost, but transferring from
line i at station j – 1 to station j on the other line takes
time ti, j. Each assembly line takes an entry time ei and exit
ime xi which may be different for the two lines. Give an
algorithm for computing the minimum time it will take to
	build a car chassis.