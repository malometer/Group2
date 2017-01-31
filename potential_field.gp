set output "contour.jpg"
set term postscript color
set term jpeg
set key opaque

set title "Solution to the Second Electromagnetic Problem"
set zrange [-1:1]
set yrange [-3:3]
set xrange [-3:3]

set ylabel "y"
set xlabel "x"
set zlabel "u"
set pm3d map
set palette defined ( 0 "red", 1 "dark-red", 2 "black", 3 "blue", 4 "cyan")
set contour
unset key
set contour base
set cntrparam levels 50
set size square
splot "analytical_potential.dat" using 1:2:3 with pm3d title "analytical solution"

