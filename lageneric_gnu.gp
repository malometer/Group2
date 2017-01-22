set output "plot1.jpg"
set term postscript color
set term jpeg



set format x ""
set format y ""
unset key
set title "dank. fields."
set pm3d map
set palette defined ( 0 "red", 1 "dark-red", 2 "black", 3 "blue", 4 "cyan")
set size square
splot "lageneric_data.dat" using 1:2:3 with pm3d

