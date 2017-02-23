
set key opaque



set title "Solution to the Second Electromagnetic Problem"


set ylabel "y"
set xlabel "x"
set zlabel "u"
unset key

set samples 30,30
set isosamples 30,30

set xrange [0:500] noreverse nowriteback
set yrange [0:500] noreverse nowriteback
#set zrange [-1:1] noreverse nowriteback
set palette defined ( 0 "red", 1 "dark-red", 2 "black", 3 "blue", 4 "cyan")


set border 4095
set ticslevel 1
set grid
set dgrid3d 41,41 

set contour base
set cntrparam levels incremental -1, 0.1, 1 
unset clabel

splot "/Users/Honi/Documents/SelfEnclosedGUI/HERE/new/lageneric_data.dat" using 1:2:3 with lines pale title "analytical solution"

