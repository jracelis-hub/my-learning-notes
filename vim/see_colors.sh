#/usr/bin/env bash

# ------------ Color Prompt Checker ----------- #
# Terms                                         #
# Foreground = text color                       #
# Background = highlight text color             #


# ---------------- How To Use ----------------- #
# At the bottom remove the '#' use use either
# check_foreground (text color)
# check_background (hightlight color)
#
# ---------------- How to Run ----------------- #
# chmod u+x see_colors.sh && ./see_colors.sh
# or
# bash see_colors.sh
# --------------------------------------------- #

black="\33[30m"

function check_foreground {
	for i in {0..255}; do 
		# Add background color here to see how foreground 
		# color looks on a specific background colors
		# printf "\e[48;5;65m"
		printf "\e[38;5;${i}m%03d " $i
		printf "\e[0m"
		if (( i % 16 == 15 )); then 
			echo
		fi
	done
}

function check_background {
	for i in {0..255}; do
		# Add foreground color here to see how background 
		# color looks on a specific foreground colors
		# I use black foreground by default
		printf "$black"
		printf "\e[48;5;${i}m%03d " $i
		printf "\e[0m"
		if (( i % 16 == 15 )); then 
			echo 
		fi
	done
}

#check_foreground
check_background
