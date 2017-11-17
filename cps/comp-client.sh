#!/bin/bash
read -p "-------mount dump directory-------" dummy
sudo mount -t tmpfs none dir-dump

read -p "-------Launch process-------" dummy
sudo gcc -o client client.c

read -p "-------Insert the destination IP : " ipaddress
./client $ipaddress & 

read -p "-------Check the pid-------" dummy
echo " "
sudo ps -C client

read -p "-------Insert the pid : " enter

read -p "-------Dump process--------" dummy
sudo criu dump -t $enter --shell-job --images-dir dir-dump --leave-stopped --page-server --address $ipaddress --port 8889 -vvvv -o dump.log && echo "DUMP SUCCESS"

read -p "-------List of dump file-------" dummy
cd dir-dump
ls
cd ..

read -p "-------scp rest of the process-------" dummy
sudo scp -r dir-dump/* cpslab@192.168.0.102:/home/cpslab/Documents/workspace/RCPS/dir-dump && echo "SCP SUCCESS"
sudo scp -r ./* cpslab@192.168.0.102:/home/cpslab/Documents/workspace/RCPS/ && echo "SCP SUCCESS"

read -p "-------Kill process----------" dummy
sudo kill -9 $enter

read -p "-------Copy log file---------" dummy
sudo cp dir-dump/dump.log ./dump-$enter.log

read -p "-------list of dump file--------" dummy
cd dir-dump
ls
cd ..

read -p "-------unmount directory---------" dummy
sudo umount dir-dump
