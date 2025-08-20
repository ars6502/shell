#!/usr/bin/env bash

# include files
source ../styles.inc
source ../shell.inc


# default prompt
PROMPT="welcome > "

# count the greetings
greetings=0


# override function to show help as well
function command_error_message {
        echo "Inexistent command $1"
	help
}

# fancy startup screen
function startup_screen {
        figlet "Greeting Shell" | lolcat
}


# greeting function
function hello_func {
    name=$1
    echo "Hello, ${name:-anonymous}!"
}

# Help function for the 'hello' command
function hello_help {
    echo "Prints Hello!"
}

# increase the greeting counter in prompt
function __post_exec_hook__ {
    greetings=$((greetings + 1))
    PROMPT="welcome (${greetings}) > "
}

# register the command
register_command "hello" "hello_func"

# run
shell_loop

