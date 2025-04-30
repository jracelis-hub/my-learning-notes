#!/usr/bin/env bash

##############################################################
# Create:  Jarron Racelis
# Contact: jarronracelis@rivian.com
# Purpose: To make a log directory locally on (MobaXterm) 
#          the log will be stored in /var/log/tcm
##############################################################

LOG_LOCATION=/var/log/tcm

function make_tcm_log_dir {
    
    # Creates /var/log/TCM locally (MobaXterm directory)
    if [ -d ${LOG_LOCATION} ]; then
        echo "SUCCESS: LOG DIRECTORY GOOD TO GO!"
        echo "DIRECTORY: ${LOG_LOCATION} ALREADY EXISTS!"
    else
        echo "CREATING DIRECTORY ${LOG_LOCATION}"
        mkdir ${LOG_LOCATION}
        if [ "$?" -eq "0" ]; then
            echo "SUCCESS: ${LOG_LOCATION} CREATED!"
        else
            echo "FAILED: COULD NOT CREATE ${LOG_LOCATION}!"
            exit 1
        fi
    fi
}

make_tcm_log_dir

exit 0;