#!/bin/bash
read -p "-------mount dump directory-------" dummy
sudo mount -t tmpfs none dir-dump

read -p "-------Open page-server for Disk-less migration------" dummy
sudo criu page-server --images-dir dir-dump --port 8889 -vvvv

read -p "-------list of dump file-------" dummy
cd dir-dump
ls
cd ..

read -p "Enter the pid : " var
read -p "Enter the pid : " var

read -p "------Restore process-------" dummy
sudo criu restore --tree $var --shell-job --page-server --images-dir dir-dump -vvvv -o restore.log && echo "RESTORE SUCCESS"

read -p "------Copy log file-------" dummy
sudo cp dir-dump/restore.log ./restore-$var.log

read -p "------list of dump file-------" dummy
cd dir-dump
ls
cd ..

read -p "------Umount dump directory----------" dummy
sudo umount dir-dump
