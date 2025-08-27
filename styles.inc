# function to print message in bold style
function style_bold {
    local message="$1"
    echo -e "\033[1m${message}\033[0m"
}

# function to print message in underline style
function style_underline {
    echo -e "\033[4m$1\033[0m"
}

# function to print message in strikethrough style
function style_strikethrough {
    echo -e "\033[9m$1\033[0m"
}

# function to print message in italics style
function style_italics {
    echo -e "\033[3m$1\033[0m"
}

# function to print message in blinking style
function style_blinking {
    echo -e "\033[5m$1\033[0m"
}

# function to print message in red color
function colour_red {
    echo -e "\033[31m$1\033[0m"
}

# function to print message in green color
function colour_green {
    echo -e "\033[32m$1\033[0m"
}

# function to print message in yellow color
function colour_yellow {
    echo -e "\033[33m$1\033[0m"
}

# function to print message in blue color
function colour_blue {
    echo -e "\033[34m$1\033[0m"
}

# function to print message in magenta color
function colour_magenta {
    echo -e "\033[35m$1\033[0m"
}

# function to print message in cyan color
function colour_cyan {
    echo -e "\033[36m$1\033[0m"
}

# function to print message in white color
function colour_white {
    echo -e "\033[37m$1\033[0m"
}

# function to print message in black color 
function colour_black {
    echo -e "\033[30m$1\033[0m"
}


