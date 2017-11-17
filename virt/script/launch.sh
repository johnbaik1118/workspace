virsh start vmone
sleep 15
virsh start vmtwo
sleep 15
virt-viewer vmone &
virt-viewer vmtwo &
