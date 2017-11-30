virt-install \
--name vmone \
--ram 2048 \
--disk path=./vmone.qcow2,size=20 \
--vcpus 2 \
--os-type linux \
--location 'http://archive.ubuntu.com/ubuntu/dists/xenial/main/installer-amd64/'
