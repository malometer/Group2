#set output "contour.jpg"
#set term postscript color
#set term jpeg
set key opaque

#set multiplot layout 1, 2 ;

set title "Solution to the Second Electromagnetic Problem"
#set style data lines

set ylabel "y"
set xlabel "x"
set zlabel "u"
unset key

#set samples 100
#set isosamples 100

stats "lageneric_data.dat" using 3 nooutput
cbmax = (abs(STATS_min) > abs(STATS_max) ? abs(STATS_min) : abs(STATS_max))
set cbrange[-cbmax:cbmax]

#set xrange [-50:150] noreverse nowriteback
#set yrange [-50:150] noreverse nowriteback
#set zrange [-1:5] noreverse nowriteback
set palette defined ( 0 "red", 1 "dark-red", 2 "black", 3 "blue", 4 "cyan")
#set palette defined ( -4 "dark-red", -3 "red", -2 "orange", -1 "yellow", 0 "white", 1 "cyan", 2 "blue", 3 "dark-blue", 4 "black")

set border 4095
set ticslevel 1
set grid
set dgrid3d 40, qnorm 4
#set hidden3d
#set pm3d at b
set contour base
set cntrparam levels incremental STATS_min, 0.1, STATS_max
unset clabel

splot "lageneric_data.dat" using 1:2:3 with lines pale title "analytical solution"
#lc rgb "dark-grey" 

#set title "test"
#set format x ""
#set format y ""
#set pm3d map
#plot "grad.dat" every 3:3 using 1:2:($3*4):($4*4) with vectors
