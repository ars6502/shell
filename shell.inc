# Set the default prompt string
PROMPT="default > "

# set the error command
function command_error_message {
        echo "Inexistent command $1"
}

# function to register new commands dynamically
function register_command {
    local command_name=$1   # Name of the command
    local function_name=$2  # Name of the function to be associated with the command

    # Register the command and its corresponding function in an associative array
    command_table[$command_name]=$function_name
}

# Initialize an empty associative array for command registration
declare -A command_table=()


# function to parse input and execute the corresponding registered function
function execute_command {
    local input=$1  # Full user input string

    # split the input into a command and its arguments
    IFS=' ' read -r command args <<< "$input"

    if [[ -n "${command}" ]]; then
        # Check if the command is registered in the associative array
        if [[ -n "${command_table[$command]}" ]]; then
            # Call the registered function with any provided arguments
            ${command_table[$command]} $args
        else
            # call the error message function if the command is not recognized
            command_error_message "$command"
        fi
    fi
}

# function to print help information
function help {
    # loop through all keys in the associative array and call their corresponding help functions
    for key in "${!command_table[@]}"; do
                local help_func="${key}_help"
                echo -e $(style_bold "${key}")
                echo -e "\t$(${help_func})"
        echo ""  # Add a blank line between outputs
    done
}





function shell_loop { 
    # call the startup screen if it exists
    [[ $(type -t startup_screen) == function ]] && startup_screen

    # main loop to read user input and execute commands
    while true; do
        # Display the prompt and read user input
        read -p "${PROMPT}" -r -e user_input

        case "$user_input" in
        exit | quit | q)
            # Exit the loop if the user types 'exit', 'quit', or 'q'
            break
            ;;

        help | ?)
            # Call the help function for 'help' or '?'
            help
            ;;

        *)
            # For any other input, check and execute pre-execution hook if it exists
            [[ $(type -t __pre_exec_hook__) == function ]] && __pre_exec_hook__

            # Add the command to history
            history -s "$user_input"

            # Execute the parsed command with arguments
            execute_command "$user_input"

            # Check and execute post-execution hook if it exists
            [[ $(type -t __post_exec_hook__) == function ]] && __post_exec_hook__
            ;;
        esac
    done
}
