#!/usr/bin/env bash

IP="172.28.2.64"
SSH_OPTION="-o StrictHostKeyChecking=no"
LOCATION="/opt/rivian/user_data2"
SCRIPT="wipe_partition.sh"

function scp_partition_wipe {

    # Check if script is in local file
    test ! -e ${SCRIPT} && echo "${SCRIPT} NOT FOUND IN LOCAL FOLDER" && exit 1
    echo " SUCCESS: ${SCRIPT} FOUND!" 
    echo "Begin: Coping script into ${LOCATION}"
    
    # Copy script in the specific location
    scp -O ${SSH_OPTION} ${SCRIPT} root@${IP}:${LOCATION}
    if [ "$?" -eq "0" ]; then
        echo "SUCCESS: ${SCRIPT} is copied in ${LOCATION}"
    else
        echo "FAILED: Could not copy ${SCRIPT}"    
    fi
    
    # Run script if script is copied in the correct location
    ssh ${SSH_OPTION} root@${IP} ls ${LOCATION} | grep ${SCRIPT}
    if [ "$?" -eq "0" ];then
        clear
        echo "Begin: ${SCRIPT}"
        ssh ${SSH_OPTION} root@${IP} "cd ${LOCATION}; ./${SCRIPT}"
    fi
}

scp_partition_wipe