#!/usr/bin/env bash

###############################################################
# Create:  Jarron Racelis
# Contact: jarronracelis@rivian.com
# Purpose: To archive /mnt/ssd directory into .tar.gz 
#          format and export it locally for traceability  
###############################################################

IP="172.28.2.64"
SSH_OPTION="-o StrictHostKeyChecking=no"
SSD_DIR="/mnt/ssd"
SSD_SUB_DIR="/mnt/ssd/dtcs"
SSD_ARCHIVE="mnt-ssd-archive.tar.gz"
VAR_LOG_DIR="/var/log/TCM"

function compress_dir_and_scp {

    echo "Archiving ${SSD_DIR}"
    ssh ${SSH_OPTION} root@${IP} "tar zcfv ${SSD_DIR}/${SSD_ARCHIVE} ${SSD_SUB_DIR}"
    if [ "$?" -eq "0" ]; then
        echo "SUCCESS: ${SSD_DIR}${SSD_ARCHIVE} READY TO EXPORT!"
        scp -O root@${IP}:${SSD_DIR}/${SSD_ARCHIVE} ${VAR_LOG_DIR}
        if [ "$?" -eq "0" ]; then
            echo "SUCCESS: ${SSD_DIR}${SSD_ARCHIVE} COPIED INTO ${VAR_LOG_DIR}"
        fi
    else
        echo "FAILED: TO ARCHIVE ${SSD_DIR}${SSD_ARCHIVE}."
    fi
}

function remove_archive_tar_gz {
    echo "REMOVING ${SSD_ARCHIVE} FROM TCM!"
    ssh ${SSH_OPTION} root@${IP} "rm -rf ${SSD_DIR}/${SSD_ARCHIVE}"
    if [ "$?" -eq "0" ]; then
        echo "SUCCESS: REMOVED ${SSD_ARCHIVE} from ${SSD_DIR}" 
    fi
}

compress_dir_and_scp
remove_archive_tar_gz