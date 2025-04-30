#!/usr/bin/env bash

##############################################################
# Create:  Jarron Racelis
# Contact: jarronracelis@rivian.com
# Purpose: To get vehicle and vin from TCM
##############################################################

IP=172.28.2.64
SSH_OPTION="-o StrictHostKeyChecking=no"

function get_vehicle_vin {

    VEHICLE_VIN="$(ssh ${SSH_OPTION} root@${IP} "cat /opt/rivian/config_data/usersList.json | grep -e vin -e model | sed 's/[\" ""modelvin:,]//g' | sed -n '2p3p' | paste -s -d' ' | sed 's/[ ]/_/g'")"
    echo "${VEHICLE_VIN}"
}

get_vehicle_vin

exit 0;