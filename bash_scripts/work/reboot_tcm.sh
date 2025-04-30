#!/usr/bin/env bash

IP=172.28.2.64
SSH_OPTION="-o StrictHostKeyChecking=no"

function ssh_reboot_tcm {

    echo "Rebooting TCM!"
    ssh ${SSH_OPTION} root@${IP} reboot
}

ssh_reboot_tcm