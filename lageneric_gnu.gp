
set output "/Users/Honi/Documents/GUIs/LinuxUiUpdate/plot1.jpg"
set term postscript color
set term jpeg enhanced

set lmargin 0
set rmargin 0

unset key
set title "Electric Potential of Electric Field"
set pm3d map
stats "/Users/Honi/Documents/GUIs/LinuxUiUpdate/lageneric_data.dat" using 3 nooutput
cbmax = (abs(STATS_min) > abs(STATS_max) ? abs(STATS_min) : abs(STATS_max))
set cbrange[-cbmax:cbmax]
set palette defined ( -4 "dark-red", -3 "red", -2 "orange", -1 "yellow", 0 "white", 1 "cyan", 2 "blue", 3 "dark-blue", 4 "black")
set size square

set format x ""
set format y ""

splot "/Users/Honi/Documents/GUIs/LinuxUiUpdate/lageneric_data.dat" using 1:2:3 with pm3d


