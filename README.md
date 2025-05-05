# TCM_Gen_1_Work_Station_Setup

## :bookmark_tabs: ***Table of Contents***
* [:books: ***Introduction***](#books-introduction)
    * [:blue_book: _Description_](#blue_book-description)
    * [:green_book: _Purpose_](#green_book-purpose)
    * [:notebook: _Terminology_](#terminology)
* [:arrows_counterclockwise: ***Work Flow***](#arrows_counterclockwise-work-flow)
    * [:notebook: _Scripts_](#notebook-scripts)
* [:bust_in_silhouette: ***Contribution***](#contribution)


## :books: ***Introduction***

### :blue_book: ***Description*** 

---

The following repositiory **TCM_Gen_1_Work_Station_Setup** is the centrialized location to grab the latest versions of the TCM work bench scripts.

### :green_book: ***Purpose***

---

The purpose of creating scripts is to have an automated process when preforming the tasks needed to _"remanufacture"_ ***software*** failed TCMs. Upon creating our own scripts, the reman team can **maintain, update, add,** and **remove** specific `commands` as needed.

***Why Not Use RIDE-CLI?***  
The idea behind why our team does not want to **rely** on ***RIDE-CLI*** is due to the nature of abundant `commands` the technician can preform without knowing what it does. Since, _remanufacturing_ suits specific requirements, we want to create `commands` based on ***OUR*** requirements.

> ![NOTE]
> This does not mean we won't utilize **RIDE-CLI**. We will utilize the resource when necessary.

### :notebook: Terminology

---

|       _Commands_                  |       _Description_              |
----------------------------------|--------------------------------|
|       read      | to read information from TCM                     
|       log       | to log information from TCM 
|       scp       | to secure copy script into TCM                                       
|       wipe      | to wipe files/paritions/scripts/directories/logs from the TCM

## :arrows_counterclockwise: ***Work Flow***

---


### :notebook: ***Scripts***

---

- [tcm_work_bench_scripts](https://gitlab.com/jarronracelis/tcm_gen_1_work_station_setup/-/tree/main/tcm_work_bench_scripts) :open_file_folder:
    - [partition_wipe](https://gitlab.com/jarronracelis/tcm_gen_1_work_station_setup/-/tree/main/tcm_work_bench_scripts/partition_wipe) :open_file_folder:
    - [wipe_hsm](https://gitlab.com/jarronracelis/tcm_gen_1_work_station_setup/-/tree/main/tcm_work_bench_scripts/wipe_hsm) :open_file_folder:
    - [get_scripts](https://gitlab.com/jarronracelis/tcm_gen_1_work_station_setup/-/tree/main/tcm_work_bench_scripts/get_scripts) :open_file_folder:


### :bust_in_silhouette: Contribution
>  Information is updated and maintained by Jarron Racelis \
>  Contact: jarronracelis@rivian.com

