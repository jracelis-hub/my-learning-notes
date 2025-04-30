!#/usr/bin/env bash

###########################################
# Creator: Jarron Racelis
# Contact: jarronracelis@rivian.com
# Purpose: Hold global variables to reduce 
#          repeated code and typo errors
###########################################

# Global variables

IP="172.28.2.64"
SSH_OPTION="-o StrictKeyHostingChecking=no"
LINE_DIV="---------------------------------------------------------------------------------------------------------------"

# Global Functions

function ssh_tcm {

    ssh ${SSH_OPTION} root@${IP}

}

function scp_script {

    local SCRIPT=$1
    local LOCATION=$2

    scp -O ${SSH_OPTION} ${SCRIPT} root@${IP}:${LOCATION}

}

function get_vehicle_vin {
    
    VEHICLE_VIN="$(ssh ${SSH_OPTION} root@${IP} "cat /opt/rivian/config_data/usersList.json | grep -e vin -e model | sed 's/[\" ""modelvin:,]//g' | sed -n '2p3p' | paste -s -d' ' | sed 's/[ ]/_/g'")"
    echo "${VEHICLE_VIN}"

}