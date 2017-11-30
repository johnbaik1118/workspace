#!/bin/sh
temp=$(virsh list --all)
exitquery="n"
answer="x"
vmname=""
zenity \
--info \
--text="<span size=\"xx-large\">$temp</span>\n\nHave <b>fun</b>." \
--title="VM Migration management" \
2>/dev/null

while [ $exitquery != q ] 
do

	echo "These are the VM lists"
	echo " "
	virsh list --all
	
	echo 
	echo "What do you want to do with VM? "
	read -p "(exit/start/shutdown) " answer

	if [ $answer = exit ] 
	then
		echo "exit the shell script"
		exitquery="q"
	elif [ $answer = start ]
	then 
		read -p "Which one? " vmname
		echo " "
		virsh start $vmname
		virt-viewer $vmname & 
		echo -e "$vmname is launched!"
		echo " "
	elif [ $answer = shutdown ]
	then 
		read -p "Which one? " vmname
		echo " "
		read -p "Do not shutdown when it is running! are you sure? " answer
		if [ $answer != exit ]
		then
			virsh shutdown $vmname
			echo "$vmname is shutting down!"
		else
			echo " "
		fi
		echo " "
	else
		echo "Do nothing?"
	fi
done

