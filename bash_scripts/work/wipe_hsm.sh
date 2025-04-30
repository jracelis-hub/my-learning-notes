#!/usr/bin/env bash

IP="172.28.2.64"
SSH_OPTION="-o StrictHostKeyChecking=no"
SCRIPT="cryptoauth_test"
SCP_LOCATION="/mnt/ssd"

function spicy_wipe_hsm {

    test ! -e ${SCRIPT} && echo "${SCRIPT} not find in local directory" && exit 1
    echo "SUCCESS: ${SCRIPT} FOUND"
    echo "BEGIN: Copying script into ${LOCATION}"

    scp -O ${SSH_OPTION} ${SCRIPT} root@${IP}:${SCP_LOCATION} > /dev/null
    if [ "$?" -eq "0" ]; then
        echo "SUCCESS: ${SCRIPT} was copied into ${SCP_LOCATION}"
    else
        echo "FAILED: Could not copy ${SCRIPT} into ${LOCATION}"
    fi

    ssh ${SSH_OPTION} root@${IP} "ls ${SCP_LOCATION} | grep ${SCRIPT} > /dev/null"
    if [ "$?" -eq "0" ]; then
        echo "BEGIN: SPICY WIPE"
        ssh ${SSH_OPTION} root@${IP} "${SCP_LOCATION}/${SCRIPT} delete_keys"
        if [ "$?" -eq "0" ]; then
            echo "SUCCESS: HSM WIPED!"
        else
            echo "FAILED: TO WIPE HSM."
        fi
    fi
    
}

function remove_script {

    ssh ${SSH_OPTION} root@${IP} "rm -rf ${SCP_LOCATION}/${SCRIPT}"
    if [ "$?" -eq "0" ];then
        echo "SUCCESS: ${SCRIPT} REMOVED!"
    else
        echo "ERROR: COULD NOT REMOVE ${SCRIPT}"
    fi
}

spicy_wipe_hsm
remove_script