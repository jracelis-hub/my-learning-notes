#!/usr/bin/env bash

################################################################
# Create:   Jarron Racelis
# Contact:  jarronracelis@rivian.com
# Purpose:  To store log in /var/log/tcm/Vehicle_VIN/ssd_health
# Requirements: Needs get_ssd_health.sh
################################################################

SSH_OPTION="-o StrictHostKeyChecking=no"
IP=172.28.2.64
SSD_DEVICE=/dev/nvme0n1
SSD_LOG=ssd_health.log
TCM_DIR=/var/log/tcm/

################################################################

function get_vehicle_vin {

    # Gives Vehicle Model and VIN

    VEHICLE_VIN="$(ssh ${SSH_OPTION} root@${IP} "cat /opt/rivian/config_data/usersList.json | grep -e vin -e model | sed 's/[\" ""modelvin:,]//g' | sed -n '2p3p' | paste -s -d' ' | sed 's/[ ]/_/g'")"
}

function create_ssd_health_log {

    # Creates log /var/log/Vehicle_VIN/ssd_health.log
    touch ${TCM_DIR}${VEHICLE_VIN}/${SSD_LOG}

}

function get_ssd_health {

    # Print out SSD information
    SSD_HEALTH="$(ssh ${SSH_OPTION} root@${IP} "nvme smart-log ${SSD_DEVICE}")" 
    echo "${SSD_HEALTH}" > ${TCM_DIR}${VEHICLE_VIN}/${SSD_LOG}
}




get_vehicle_vin
create_ssd_health_log
get_ssd_health


exit 0;