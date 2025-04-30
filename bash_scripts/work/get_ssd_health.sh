#!/usr/bin/env bash

################################################################
# Create:   Jarron Racelis
# Contact:  jarronracelis@rivian.com
# Purpose:  To get the health of ssd
################################################################

SSH_OPTION="-o StrictHostKeyChecking=no"
SSD_DEVICE_DIR="/dev/nvme0n1"
IP=172.28.2.64

function get_ssd_health {

    ssh ${SSH_OPTION} root@${IP} "nvme smart-log ${SSD_DEVICE_DIR}"

}

get_ssd_health

exit 0;