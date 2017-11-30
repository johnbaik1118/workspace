virt-install \
--name vmtwo \
--ram 2048 \
--disk path=./vmtwo.qcow2,size=20 \
--vcpus 2 \
--os-type linux \
--location 'http://archive.ubuntu.com/ubuntu/dists/xenial/main/installer-amd64/'
