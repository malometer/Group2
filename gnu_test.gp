set output "contour.jpg"
#set term gif animate
set term jpeg
set key opaque

#set multiplot layout 1, 2 ;

set title "Solution to the Second Electromagnetic Problem"
#set style data lines

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

#set view 60, 30, 0.85, 1.1
set border 4095
set ticslevel 1
set grid
set dgrid3d 41,41 
#set pm3d at b
set contour base
set cntrparam levels incremental -1, 0.1, 1 
unset clabel

splot "lageneric_data.dat" using 1:2:3 with lines pale title "analytical solution"
#lc rgb "dark-grey" 

#set title "test"
#set format x ""
#set format y ""
#set pm3d map
#plot "lageneric_data.dat" every 3:3 using 1:2:($3*4):($4*4) with vectors
