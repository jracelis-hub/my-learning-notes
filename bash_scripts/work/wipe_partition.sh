#!/usr/bin/env bash

IP="172.28.2.64"
SCRIPT="partition_wipe_released.sh"
LOCATION="/opt/rivian/user_data2"
SSH_OPTION="-o StrictHostKeyChecking=no"

# Directories Mounted on MMC and SSD

MMC_MNT_1="/opt/rivian/config_data"
MMC_MNT_2="/var/lib/systemd/timesync"
SSD_MNT_1="/mnt/ssd"
SSD_MNT_2="/var/volatile/log/journal"

# Device Directories

ZERO_DIR="/dev/zero"
MMC_DIR="/dev/mmcblk0p5"
SSD_DIR="/dev/nvme0n1p1"
SSD_DIR_MAIN="/dev/nvme0n1"

# Memory Blocks

MMC_LOC="$(lsblk | grep -o "mmcblk0p5")" # Output is mmcblk0p5
SSD_LOC="$(lsblk | grep -o "nvme0n1p1")" # Output is nvme0n1p1

MMC_UMOUNT="$(mount | grep mmcblk0p5 | awk {'print $3'})" # Output /opt/rivian/config_data /var/lib/systemd/timesync
SSD_UMOUNT="$(mount | grep nvme0n1p1 | awk {'print $3'})" # Output /mnt/ssd /var/volatile/log/journal

MMC_AVAILABLE="$(df -h | grep /mmcblk0p5 | awk {'print $2'})" # Output actual size of disk 4.9G
SSD_AVAILABLE="$(df -h | grep /dev/nvme0n1p1 | awk {'print $2'})" # Output actual size of disk 252G

# Disk Usage Output

DU_MMC_CUSTOMER_DATA="$(df -h | grep mmcblk0p5 | awk {'print $3'})" # Out disk usage 10K
DU_SSD_CUSTOMER_DATA="$(df -h | grep nvme0n1p1 | awk {'print $3'})" # Output disk usage 100K

# Pull Size of Memory Partition

MMC_SIZE="5G" 
SSD_SIZE="256G"

# Reboot Directory

PROC_REBOOT="/proc/sysrq-trigger" # Reboot

# Cleanlineses

LINE_DIV="---------------------------------------------------------------------------------------------------------------"
STAR_DIV="***************************************************************************************************************"

# Grabbing User Input

function permission_to_wipe {

echo ""
echo "${STAR_DIV}"
echo "CAUTION: THE FOLLOWING PARTITIONS: ${MMC_LOC} AND ${SSD_LOC} WILL BE ERASED. DO YOU WISH TO PROCEED? [Y/n] "
read USER_INPUT
}

# Scanning Mount FS

function scan_mount_fs {
	
	local DEV_DIR="$1"
	local MOUNT_BLK="$2"	
	local MOUNT_DIR_1="$3"
	local MOUNT_DIR_2="$4"
	
	echo ""
	echo "CHECKING: IF ${DEV_DIR} IS MOUNTED"

	if [ -z "${MOUNT_BLK}" ]; then
		echo "$LINE_DIV" 
		echo  "ERROR: ALREADY UMOUNT | ${MOUNT_DIR_1} and ${MOUNT_DIR_2} | from ${DEV_DIR}"
		echo "${LINE_DIV}"
		echo "REBOOT: TCM TO REMOUNT DIRECTORY"
		exit 1
	elif 	[ "${MOUNT_BLK}" = "${MOUNT_DIR_1}" ] || [ "${MOUNT_BLK}" = "${MOUNT_DIR_2}" ]; then
		echo "${LINE_DIV}"
                echo  "FAILED: ONLY THE FOLLOWING IS MOUNTED TO ${DEV_DIR}:"
                echo "${MOUNT_BLK}"
                echo "${LINE_DIV}"
                echo  "FAILED: MOUNT NEEDS THE FOLLOWING DIRECTORIES pm ${DEV_DIR}:"
                echo "${MOUNT_DIR_1}"
                echo "${MOUNT_DIR_2}"
                echo "${LINE_DIV}"
                echo "REBOOT: TCM TO REMOUNT DIRECTORY"
                exit 1
	 else
                echo "${DEV_DIR} IS STILL MOUNTED WITH:"
                echo "${LINE_DIV}"
                echo "${MOUNT_BLK}"
		echo "SUCCESS: ${DEV_DIR} STILL MOUNTED"
		echo "${LINE_DIV}"
	fi
}

# Scanning Disk Usage

function scan_partition {

	local CURR_DISK_USAGE="$1"
	local PARTITION_BLK="$2"	
	local PARTITION_SPACE="$3"

	echo ""
	echo "Checking: Current disk usage in partition block ${PARTITION_BLK}"
	echo "${LINE_DIV}"
	echo "USAGE:${PARITION_BLK} ${CURR_DISK_USAGE}"
	echo "MAX SPACE: ${PARTITION_SPACE}"
	echo "${LINE_DIV}"

	case "${PARTITION_BLK}" in

	"${MMC_LOC}")
	
		if [[ ${CURR_DISK_USAGE%[KMGT]} -lt 80 ]]; then
			echo "USAGE: ${PARTITION_BLK} ${CURR_DISK_USAGE} < ${PARTITION_BLK} 100K"
			echo "FAILED: PARITION ${PARTITION_BLK} PURGE HAS ALREADY BEEN PREFORMED!"
			echo "${LINE_DIV}"
			exit 1
		elif [[ ${CURR_DISK_USAGE%[KMGT]} -gt 80 ]]; then
			echo "USAGE: ${PARTITION_BLK} ${CURR_DISK_USAGE} > THRESHHOLD: ${PARTITION_BLK} 100K"
			echo "SUCCESS: PARITION ${PARTITION_BLK} HAS NOT BEEN PURGED YET!"
			echo "${LINE_DIV}"
		else
			echo  "ERROR: INVALID INPUT"
			exit 1
		fi
		;;

	"${SSD_LOC}")
	
		if [[ ${CURR_DISK_USAGE%[KMGT]} -lt 15 ]]; then
			echo "USGAGE: ${PARTITION_BLK} ${CURR_DISK_USAGE} > ${PARTITION_BLK} 20G"
            echo "FAILED: PARITION ${PARTITION_BLK} PURGE HAS ALREADY BEEN PREFORMED!"
			echo "${LINE_DIV}"
			exit 1
        elif [[ ${CURR_DISK_USAGE%[KMGT]} -gt 15 ]]; then
        	echo "USAGE: ${PARTITION_BLK} ${CURR_DISK_USAGE} < THRESHHOLD: ${PARTITION_BLK} 20G"
			echo "SUCCESS: PARITION ${PARTITION_BLK} HAS NOT BEEN PURGED YET!"
			echo "${LINE_DIV}"
        else
            echo  "ERROR: INVALID INPUT"
            exit 1
		fi
		;;
		
	*)
			echo  "ERROR: INVALID INPUT"
			exit 1
		;; 
		
	esac
}

# Remove Directory

function remove_script {

	echo "BEGIN: REMOVING ${SCRIPT} FROM TCM!"
	if [ -e ${SCRIPT} ]; then
		rm -rf ${SCRIPT}
	fi
	echo "SUCCESS: ${SCRIPT} HAS BEEN REMOVED FROM TCM!"
}
# Reboot TCM

function reboot_tcm {

	local REBOOT_DIR="$1"

	echo ""
	echo "SUCCESS: BEGIN REBOOTING TCM NOW!"
	echo b > ${REBOOT_DIR}
}

#Unmounting Directories from Partitions

function umount_fs {

        local UMNT_LOC="$1"
        local MEM_BLK="$2"

        echo "${LINE_DIV}"
        echo "BEGIN: Unmounting ${UMNT_LOC} from ${MEM_BLK}."

        umount -l ${UMNT_LOC}
        if [ $? -eq "0" ]; then
                echo "SUCCESS: ${UMNT_LOC} has been unmounted from ${MEM_BLK}!"
        else
                echo "${LINE_DIV}"
                echo "FAILED: Could not umount ${UMNT_LOC} from ${MEM_BLK}."
                exit 1
        fi
}

# Discarding Partition

function discard_partition {
	
	local DEV_DIR="$1"
	
	echo "${LINE_DIV}"
	echo "BEGIN: ${DEV_DIR} Purging ---------> 000000000000."
	
	blkdiscard ${DEV_DIR} -f
	if [ $? -eq "0" ]; then
			echo "${LINE_DIV}"
			echo "FINISHED: ${DEV_DIR} HAS BEEN WIPED!"
			echo "${LINE_DIV}"
	else
			echo "${LINE_DIV}"
			echo "FAILED: ${DEV_DIR} COULD NOT BE WIPED!"
			exit 1
	fi
}

# Partition Wiping

function wipe_partition {

        local DEV_ZERO="$1"
        local DEV_DIR="$2"
        local MEM_BLK="$3"

        echo "${LINE_DIV}"
        echo "BEGIN: ${DEV_DIR} Purging ---------> 000000000000."
        echo "INPUT: GRABBING ZEROS FROM ${DEV_ZERO} PURGING ${DEV_DIR} BLKSIZE= ${MEM_BLK}"

        dd if=${DEV_ZERO} of=${DEV_DIR} bs=${MEM_BLK} count=1 status=progress
        if [ $? -eq "0" ]; then
                echo "${LINE_DIV}"
                echo "FINISHED: ${DEV_DIR} HAS BEEN WIPED!"
                echo "${LINE_DIV}"
        else
                echo "$LINE_DIV"
                echo "FAILED: ${DEV_DIR} COULD NOT BE WIPED!"
                exit 1
        fi
}

# Allowing Only Unwiped Data

function initial_check {

while true; 
	do
	scan_mount_fs "${MMC_DIR}" "${MMC_UMOUNT}" "${MMC_MNT_1}" "${MMC_MNT_2}"
	scan_mount_fs "${SSD_DIR}" "${SSD_UMOUNT}" "${SSD_MNT_1}" "${SSD_MNT_2}"
	echo ""
	echo "SUCCESS: READY TO UNMOUNT"
	scan_partition ${DU_MMC_CUSTOMER_DATA} ${MMC_LOC} ${MMC_AVAILABLE}
	scan_partition ${DU_SSD_CUSTOMER_DATA} ${SSD_LOC} ${SSD_AVAILABLE}
	echo ""
	echo "SUCCESS: READY TO CLEAR DATA"
	break
done
}

#Begin Script

initial_check
permission_to_wipe
if [ "$USER_INPUT" = "Y" ] || [ "$USER_INPUT" = "y" ]; then
    clear
	echo "$STAR_DIV"
	echo "CONTINUING: Wiping out partitions: ${MMC_LOC} AND ${SSD_LOC}."
	# UMOUNTING DIRECTORIES ON MMC0BLK0P5
	if umount_fs ${MMC_MNT_1} ${MMC_LOC}; then
		if umount_fs ${MMC_MNT_2} ${MMC_LOC}; then
			echo "$LINE_DIV"
			echo "FINISHED: ${MMC_LOC} is unmounted!"
			echo "$LINE_DIV"
			wipe_partition ${ZERO_DIR} ${MMC_DIR} ${MMC_SIZE} 
		fi
			# UMOUNTING DIRECTORIES ON NVME0N1P1
			if umount_fs ${SSD_MNT_1} ${SSD_LOC}; then
				if umount_fs ${SSD_MNT_2} ${SSD_LOC}; then
					echo "$LINE_DIV"
					echo "FINISHED: ${SSD_LOC} is umounted!"
					echo "$LINE_DIV"
					discard_partition ${SSD_DIR_MAIN}
					if [ $? -eq "0" ]; then 
					remove_script
					reboot_tcm ${PROC_REBOOT}
					else
						echo  "ERROR: COULD NOT WIPE CUSTOMER DATA. COULD NOT REBOOT"
						exit 1
					fi
				fi
			fi
	fi
elif [ "$USER_INPUT" = "n" ] || [ "$USER_INPUT" = "N" ]; then
	echo "${STAR_DIV}"
    echo ""
	echo "INPUT: $USER_INPUT"
	remove_script
	echo "EXITING: Okay will not wipe out partitions: ${MMC_LOC} AND ${SSD_LOC}. LEAVING NOW!"
else
	echo "${STAR_DIV}"
	echo ""
    echo "INPUT: $USER_INPUT"
	remove_script
	echo "ERROR: "$USER_INPUT" IS AN INVALID INPUT. PLEASE ENTER [Y/n]"
fi

























