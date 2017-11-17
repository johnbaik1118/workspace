sudo virt-install \
--name vmone \
--ram 1024 \
--disk path=./vmone.qcow2,size=20 \
--vcpus 4 \
--os-type linux \
--location 'http://archive.ubuntu.com/ubuntu/dists/xenial/main/installer-amd64/' 
