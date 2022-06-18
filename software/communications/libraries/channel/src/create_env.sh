#!/bin/bash
export PATH=$PATH:/usr/bin/date

#get the unix time stamp for the directory name
curr_time=$(date +'%m_%d_%Y_%R')
echo $curr_time

str1="Trial_"
create_dir_name=$str1$curr_time
echo $create_dir_name

#creates the folder that requires the timestamp
mkdir "${create_dir_name}"