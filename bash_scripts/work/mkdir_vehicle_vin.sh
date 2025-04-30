#!/usr/bin/env bash

################################################################
# Create:   Jarron Racelis
# Contact:  jarronracelis@rivian.com
# Purpose:  Create a local directory by pulling Vehicle Model
#           and VIN from the TCM Gen 1 to store old information 
#           to track
# Location: Logs are stored in /var/log/TCM
# Requires: get_vehicle_vin.sh
################################################################

IP=172.28.2.64
LOG_LOCATION=/var/log/tcm
SSH_OPTION="-o StrictHostKeyChecking=no"
LINE_DIV="---------------------------------------------------------------------------------------------------------------"

################################################################

function get_vehicle_vin {

    VEHICLE_VIN=$(./get_vehicle_vin.sh)

}
function make_vehicle_vin_dir {

    if [ -d $LOG_LOCATION ]; then
        echo "DIRECTORY: ${LOG_LOCATION} ALREADY EXISTS!"
    else
        echo "$LOG_LOCATION DOES NOT EXIST CREATING NOW!"
        ./mkdir_tcm_log.sh
        echo "SUCCESS: MADE ${LOG_LOCATION} DIRECTORY!"
    fi

    # Creates Vehicle_VIN directory in /var/log/tcm/Vehicle_VIN
    if [ -d $LOG_LOCATION/${VEHICLE_VIN} ]; then
        echo "DIRECTORY: $LOG_LOCATION/${VEHICLE_VIN} ALREADY EXISTS!"
    else
        echo "MAKING $LOG_LOCATION/${VEHICLE_VIN}"
        TCM_DIR="$(mkdir $LOG_LOCATION/${VEHICLE_VIN})"
        if [ "$?" -eq "0" ]; then
            echo "SUCCESS: MADE ${VEHICLE_VIN} DIRECTORY!"
        fi
    fi
    
}

get_vehicle_vin
make_vehicle_vin_dir

exit 0;