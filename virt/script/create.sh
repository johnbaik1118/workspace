sudo virt-install \
--name vmtwo \
--ram 2048 \
--disk path=/home/dsc/virt-images/vmtwo.qcow2,size=50 \
--vcpus 4 \
--os-type linux \
--location 'http://archive.ubuntu.com/ubuntu/dists/bionic/main/installer-amd64/' 
