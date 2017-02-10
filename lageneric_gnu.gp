set term postscript color
set term jpeg

set output "plot1.ps"

unset key
set title "please work, please work... yey"
set pm3d map
stats "lageneric_data.dat" using 3 nooutput
cbmax = (abs(STATS_min) > abs(STATS_max) ? abs(STATS_min) : abs(STATS_max))
set cbrange[-cbmax:cbmax]
set palette defined ( -2 "red", -1 "dark-red", 0 "black", 1 "dark-blue", 2 "blue")
set size square
splot "lageneric_data.dat" using 1:2:3 with pm3d
set format x ""
set format y ""

