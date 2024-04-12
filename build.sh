
project="floppybird"

red_echo() {
    local text=$1
    echo -e "\e[31m$text\e[0m"
}

green_echo() {
    local text=$1
    echo -e "\e[32m$text\e[0m"
}

yellow_echo() {
    local text=$1
    echo -e "\e[33m$text\e[0m"
}

########## Compiling Binary ##########
    echo -n "Compiling all files for project "
    yellow_echo "$project"
######### Add Source Files #########
    g++ -o $project -Wextra -Wall -g -Iinclude -lraylib \
        src/main.cpp \
        src/bird.cpp \
        src/pipe.cpp
###################################
    error_code=$?
    echo -n "Compiling "
    if [ $error_code -eq 0 ]; then
        green_echo "finished" 
    else
        red_echo "failed" 
    fi
